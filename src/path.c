#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>

#include "dbg.h"
#include "path.h"
#include "cursor.h"
#include "mem.h"

//==============================================================================
//
// Functions
//
//==============================================================================

//--------------------------------------
// Event Sorting
//--------------------------------------

// Compares two events and sorts them by timestamp and then orders data events
// before action events.
int compare_events(const void *_a, const void *_b)
{
    sky_event **a = (sky_event**)_a;
    sky_event **b = (sky_event**)_b;

    // Sort by timestamp first.
    if((*a)->timestamp > (*b)->timestamp) {
        return 1;
    }
    else if((*a)->timestamp < (*b)->timestamp) {
        return -1;
    }
    else {
        // Place data items first.
        int ad = ((*a)->data_count > 0);
        int bd = ((*b)->data_count > 0);

        if(ad > bd) {
            return 1;
        }
        else if(ad < bd) {
            return -1;
        }
        else {
            return 0;
        }
    }
}

// Sorts events in a path.
//
// path - The path containing the events.
void sort_events(sky_path *path)
{
    qsort(path->events, path->event_count, sizeof(sky_event*), compare_events);
}


//--------------------------------------
// Lifecycle
//--------------------------------------

// Creates a reference to a path.
//
// object_id - The object identifier associated with the path.
//
// Returns a new path.
sky_path *sky_path_create(sky_object_id_t object_id)
{
    sky_path *path = calloc(sizeof(sky_path), 1); check_mem(path);
    path->object_id = object_id;
    return path;
    
error:
    sky_path_free(path);
    return NULL;
}

// Removes a path reference from memory.
//
// path - The path to free.
void sky_path_free(sky_path *path)
{
    if(path) {
        // Destroy events.
        uint32_t i=0;
        for(i=0; i<path->event_count; i++) {
            sky_event_free(path->events[i]);
            path->events[i] = NULL;
        }
        
        if(path->events) free(path->events);
        path->events = NULL;
        path->event_count = 0;

        free(path);
    }
}


//--------------------------------------
// Serialization
//--------------------------------------

// Calculates the total number of bytes needed to store just the events section
// of the path.
size_t get_event_data_length(sky_path *path)
{
    uint64_t i;
    size_t sz = 0;
    
    // Add size for each event.
    for(i=0; i<path->event_count; i++) {
        sz += sky_event_sizeof(path->events[i]);
    }
    
    return sz;
}

// Calculates the total number of bytes needed to store a path and its events.
//
// path - The path.
size_t sky_path_sizeof(sky_path *path)
{
    size_t sz = 0;

    // Compute total event length.
    size_t event_data_length = get_event_data_length(path);

    // Add header and event data length together.
    sz += SKY_PATH_HEADER_LENGTH;
    sz += event_data_length;
    
    return sz;
}

// Calculates the full length of a path at a given pointer address.
// 
// ptr - A pointer to raw, packed path data.
//
// Returns the length of the path.
size_t sky_path_sizeof_raw(void *ptr)
{
    size_t sz = 0;
        
    // Read object id to determine element size.
    sz += sizeof(sky_object_id_t);
    
    // Read events length.
    size_t event_data_length = *((sky_path_event_data_length_t*)(ptr + sz));
    sz += sizeof(sky_path_event_data_length_t);
    sz += event_data_length;
    
    return sz;
}

// Serializes a path at a given memory location.
//
// path - The path to pack.
// ptr  - The pointer to the current location.
// sz   - The number of bytes written.
//
// Returns 0 if successful, otherwise returns -1.
int sky_path_pack(sky_path *path, void *ptr, size_t *sz)
{
    int rc;
    size_t _sz;
    void *start = ptr;
    
    // Validate.
    check(path != NULL, "Path required");
    check(ptr != NULL, "Pointer required");

    // Write header.
    size_t event_data_length = get_event_data_length(path);
    rc = sky_path_pack_hdr(path->object_id, event_data_length, ptr, &_sz);
    ptr += _sz;

    // Pack events.
    uint32_t i;
    for(i=0; i<path->event_count; i++) {
        rc = sky_event_pack(path->events[i], ptr, &_sz);
        check(rc == 0, "Unable to pack path event at %p", ptr);
        ptr += _sz;
    }

    // Store number of bytes written.
    if(sz != NULL) {
        *sz = (ptr-start);
    }

    return 0;

error:
    *sz = 0;
    return -1;
}

// Serializes a path header at a given memory location. This function is
// called using only the basic path info (object id, event data length).
//
// object_id         - The object id of the path.
// event_data_length - The size, in bytes, of the events.
// ptr               - The pointer to the current location.
// sz                - The number of bytes written.
//
// Returns 0 if successful, otherwise returns -1.
int sky_path_pack_hdr(sky_object_id_t object_id, uint32_t event_data_length,
                      void *ptr, size_t *sz)
{
    // Validate.
    check(ptr != NULL, "Pointer required");
    check(object_id != 0, "Object ID cannot be zero");
    check(event_data_length > 0, "Event data length cannot be zero");

    // Write object id & event data length.
    *((sky_object_id_t*)ptr) = object_id;
    ptr += sizeof(sky_object_id_t);
    *((sky_path_event_data_length_t*)ptr) = event_data_length;

    // Store number of bytes written.
    if(sz != NULL) {
        *sz = SKY_PATH_HEADER_LENGTH;
    }

    return 0;

error:
    *sz = 0;
    return -1;
}

// Deserializes a path to a memory location.
//
// path - The path to unpack.
// ptr  - The pointer to the current location.
// sz   - The number of bytes written.
//
// Returns 0 if successful, otherwise returns -1.
int sky_path_unpack(sky_path *path, void *ptr, size_t *sz)
{
    int rc;
    size_t _sz;
    void *start = ptr;

    // Validate.
    check(path != NULL, "Path required");
    check(ptr != NULL, "Pointer required");

    // Read object id & event data length.
    path->object_id = *((sky_object_id_t*)ptr);
    ptr += sizeof(sky_object_id_t);
    size_t event_data_length = *((sky_path_event_data_length_t*)ptr);
    ptr += sizeof(sky_path_event_data_length_t);

    // Unpack events.
    int index = 0;
    void *endptr = ptr + event_data_length;
    while(ptr < endptr) {
        path->event_count++;
        path->events = realloc(path->events, sizeof(sky_event*) * path->event_count);
        check_mem(path->events);

        path->events[index] = sky_event_create(path->object_id, 0, 0);
        rc = sky_event_unpack(path->events[index], ptr, &_sz);
        check(rc == 0, "Unable to unpack event at %p", ptr);
        ptr += _sz;
        
        index++;
    }

    // Store number of bytes read.
    if(sz != NULL) {
        *sz = (ptr-start);
    }

    return 0;

error:
    *sz = 0;
    return -1;
}

//--------------------------------------
// Stats
//--------------------------------------

// Generates an index of stats on all the events in a raw path. If an event is
// passed in then it also generates stats and includes the event where it
// would be added.
//
// path_ptr    - The start of the raw path data.
// event       - A soon-to-be-added event to calculate into the stats. If null
//               then the stats are calculated as they exist in the raw data.
// event       - A pointer to where the stats should be returned.
// event_count - A pointer to where the number of events should be returned.
int sky_path_get_event_stats(void *path_ptr, sky_event *event,
                             sky_path_event_stat **events,
                             uint32_t *event_count)
{
    int rc;
    check(path_ptr != NULL, "Path pointer required");
    check(events != NULL, "Events return address required");
    check(event_count != NULL, "Event count return address required");

    // Initialize cursor.
    sky_cursor cursor;
    sky_cursor_init(&cursor);
    rc = sky_cursor_set_path(&cursor, path_ptr);
    check(rc == 0, "Unable to set cursor for path");

    // Calculate size of the event and path.
    size_t path_length = sky_path_sizeof_raw(path_ptr);
    size_t event_length = (event != NULL ? sky_event_sizeof(event) : 0);

    // Initialize return values.
    *event_count = 0;
    *events = NULL;
 
    // Loop over cursor to calculate sizes of the events.
    sky_timestamp_t last_timestamp = SKY_TIMESTAMP_MIN;
    while(!cursor.eof) {
        // Retrieve timestamp from current event.
        sky_timestamp_t timestamp;
        sky_action_id_t action_id;
        sky_event_data_length_t data_length;
        size_t sz;
        rc = sky_event_unpack_hdr(&timestamp, &action_id, &data_length, cursor.ptr, &sz);
        check(rc == 0, "Unable to unpack current event header");
        
        // Check if event is inserted between the last event and current event.
        if(event != NULL && event->timestamp >= last_timestamp && event->timestamp < timestamp) {
            (*event_count)++;
            *events = realloc(*events, sizeof(sky_path_event_stat) * (*event_count));
            sky_path_event_stat *stat = &((*events)[(*event_count)-1]);
            stat->timestamp = event->timestamp;
            stat->start_pos = stat->end_pos = cursor.ptr - path_ptr;
            stat->sz = event_length;
        }
        
        // Calculate current event stats.
        size_t current_event_length = sky_event_sizeof_raw(cursor.ptr);
        (*event_count)++;
        *events = realloc(*events, sizeof(sky_path_event_stat) * (*event_count));
        sky_path_event_stat *stat = &((*events)[(*event_count)-1]);
        stat->timestamp = timestamp;
        stat->start_pos = cursor.ptr - path_ptr;
        stat->end_pos = stat->start_pos + current_event_length;
        stat->sz = current_event_length;
    
        // Save off this timestamp.
        last_timestamp = timestamp;
    
        // Move to next event.
        rc = sky_cursor_next(&cursor);
        check(rc == 0, "Unable to move to next event");
    }

    // Check if event is inserted at the end.
    if(event != NULL && event->timestamp >= last_timestamp) {
        (*event_count)++;
        *events = realloc(*events, sizeof(sky_path_event_stat) * (*event_count));
        sky_path_event_stat *stat = &((*events)[(*event_count)-1]);
        stat->timestamp = event->timestamp;
        stat->start_pos = stat->end_pos = path_length;
        stat->sz = event_length;
    }
    
    return 0;

error:
    free(*events);
    *events = NULL;
    *event_count = 0;
    return -1;
}


//--------------------------------------
// Event Management
//--------------------------------------

// Adds an event to a path. An event can only be added if the event's object id
// matches the path's object id.
//
// path  - The path to add the event to.
// event - The event to add to the path.
//
// Returns 0 if successful, otherwise returns -1.
int sky_path_add_event(sky_path *path, sky_event *event)
{
    // Validation.
    check(path != NULL, "Path required");
    check(path->object_id != 0, "Path object id cannot be null");
    check(event != NULL, "Event required");
    check(path->object_id == event->object_id, "Event object id (%d) does not match path object id (%d)", event->object_id, path->object_id);

    // Raise error if event has already been added.
    unsigned int i;
    for(i=0; i<path->event_count; i++) {
        if(path->events[i] == event) {
            sentinel("Event has already been added to path");
        }
    }

    // Allocate space for event.
    path->event_count++;
    path->events = realloc(path->events, sizeof(sky_event*) * path->event_count);
    check_mem(path->events);

    // Append event to the end.
    path->events[path->event_count-1] = event;

    // Sort events.
    sort_events(path);

    return 0;

error:
    return -1;
}

// Removes an event from a path.
//
// path  - The path that contains the event.
// event - The event to remove.
//
// Returns 0 if successful, otherwise returns -1.
int sky_path_remove_event(sky_path *path, sky_event *event)
{
    // Validation.
    check(path != NULL, "Path required");
    check(event != NULL, "Event required");

    // Find event.
    unsigned int i, j;
    for(i=0; i<path->event_count; i++) {
        if(path->events[i] == event) {
            // Shift events over.
            for(j=i+1; j<path->event_count; j++) {
                path->events[j-1] = path->events[j];
            }
            
            // Reallocate memory.
            path->event_count--;
            path->events = realloc(path->events, sizeof(sky_event*) * path->event_count);
            check_mem(path->events);
            
            break;
        }
    }

    // Sort events.
    sort_events(path);

    return 0;

error:
    return -1;
}
