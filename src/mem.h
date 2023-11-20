#ifndef _mem_h
#define _mem_h

#include <string.h>

//==============================================================================
//
// Overview
//
//==============================================================================

// This file contains a collection of useful utility functions for reading and
// writing to memory-backed data. This is commonly used for serialization and
// deserialization of the Sky data types.


//==============================================================================
//
// Definitions
//
//==============================================================================

//--------------------------------------
// MREMAP
//--------------------------------------

#ifdef __linux
#define MREMAP_AVAILABLE 1
#else
#define MREMAP_AVAILABLE 0
#endif


//--------------------------------------
// Memory writes
//--------------------------------------

// Writes "n" bytes from the source memory location to the destination memory
// location. If successful, the destination location is incremented by "n"
// bytes.
//
// DEST - The memory location to be written to.
// SRC  - The memory location to be read from.
// N    - The number of bytes to write.
// MSG  - The error message to display if the write fails.
#define memwrite(DEST, SRC, N, MSG) do {\
    void *result = memcpy(DEST, SRC, N);\
    check(result != NULL, "Unable to write " MSG);\
    DEST += N;\
} while(0)\

// Writes a bstring to memory.
#define memwrite_bstr(DEST, SRC, N, MSG)\
    if(N > 0) {\
        memwrite(DEST, bdata(SRC), N, MSG);\
    }


//--------------------------------------
// Memory reads
//--------------------------------------

// Reads "n" bytes from the source memory location to the destination memory
// location. If successful, the source location is incremented by "n"
// bytes.
//
// SRC  - The memory location to be read from.
// DEST - The memory location to be written to.
// N    - The number of bytes to write.
// MSG  - The error message to display if the write fails.
#define memread(SRC, DEST, N, MSG) do {\
    void *result = memcpy(DEST, SRC, N);\
    check(result != NULL, "Unable to read " MSG);\
    SRC += N;\
} while(0)\

// Reads a bstring from memory.
#define memread_bstr(SRC, DEST, N, MSG) do {\
    if(DEST != NULL) {\
        bdestroy(DEST);\
        DEST = NULL;\
    }\
    char *str = calloc(1, N+1); check_mem(str);\
    memread(SRC, str, N, MSG);\
    DEST = bfromcstr(str);\
    free(str);\
    check_mem(DEST);\
} while(0)
    

//--------------------------------------
// Memory dump
//--------------------------------------

#define memdump(PTR, LENGTH) do {\
    char *address = (char*)PTR;\
    int length = LENGTH;\
    int i = 0;\
    char *line = (char*)address;\
    unsigned char ch;\
    fprintf(stderr, "%08X | ", (int)address);\
    while (length-- > 0) {\
        fprintf(stderr, "%02X ", (unsigned char)*address++);\
        if (!(++i % 16) || (length == 0 && i % 16)) {\
            if (length == 0) { while (i++ % 16) { fprintf(stderr, "__ "); } }\
            fprintf(stderr, "| ");\
            while (line < address) {\
                ch = *line++;\
                fprintf(stderr, "%c", (ch < 33 || ch == 255) ? 0x2E : ch);\
            }\
            if (length > 0) { fprintf(stderr, "\n%08X | ", (int)address); }\
        }\
    }\
    fprintf(stderr, "\n\n");\
} while(0)


#endif
