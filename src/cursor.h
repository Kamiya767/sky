#ifndef _cursor_h
#define _cursor_h

#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>

#include "bstring.h"
#include "types.h"


//==============================================================================
//
// Overview
//
//==============================================================================

// The cursor is used to iterate over the events of a path. It provides fast
// access to events in a path by performing data access on the raw bytes of the
// data file. It also abstracts away the underlying storage of the events by
// seamlessly combining spanned blocks into a single path.
//
// The current API to the cursor is simple. It provides forward-only access to
// basic event data in a path. However, future releases will allow bidirectional
// traversal, event search, & object state management.


//==============================================================================
//
// Typedefs
//
//==============================================================================

typedef struct sky_cursor {
    void **paths;
    uint32_t path_count;
    uint32_t path_index;
    uint32_t event_index;
    void *ptr;
    void *endptr;
    bool eof;
} sky_cursor;


//==============================================================================
//
// Functions
//
//==============================================================================

//--------------------------------------
// Lifecycle
//--------------------------------------

sky_cursor *sky_cursor_create();

sky_cursor *sky_cursor_alloc();

void sky_cursor_init(sky_cursor *);

void sky_cursor_free(sky_cursor *cursor);


//--------------------------------------
// Path Management
//--------------------------------------

int sky_cursor_set_path(sky_cursor *cursor, void *ptr);

int sky_cursor_set_paths(sky_cursor *cursor, void **ptrs, int count);


//--------------------------------------
// Iteration
//--------------------------------------

int sky_cursor_next(sky_cursor *cursor);


//--------------------------------------
// Event Management
//--------------------------------------

int sky_cursor_get_action_id(sky_cursor *cursor, sky_action_id_t *action_id);

int sky_cursor_get_data_ptr(sky_cursor *cursor, void **data_ptr,
    uint32_t *data_length);


#endif
