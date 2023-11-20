#include <stdlib.h>

#include "cursor.h"
#include "qip_path.h"
#include "dbg.h"

//==============================================================================
//
// Functions
//
//==============================================================================

//--------------------------------------
// Lifecycle
//--------------------------------------

// Creates a path.
sky_qip_path *sky_qip_path_create()
{
    sky_qip_path *path = malloc(sizeof(sky_qip_path));
    path->path_ptr = NULL;
    return path;
}

// Frees a path.
//
// path - The path to free.
void sky_qip_path_free(sky_qip_path *path)
{
    if(path) {
        path->path_ptr = NULL;
        free(path);
    }
}


//--------------------------------------
// Cursor Management
//--------------------------------------

// Retrieves a cursor for the current path.
//
// module - The module.
// path   - The path.
//
// Returns a new cursor.
sky_qip_cursor *sky_qip_path_events(qip_module *module, sky_qip_path *path)
{
    check(module != NULL, "Module required");
    
    // Initialize cursor with path.
    sky_qip_cursor *cursor = sky_qip_cursor_create();
    sky_cursor_set_path(cursor->cursor, path->path_ptr);
    
    return cursor;

error:
    return NULL;
}
