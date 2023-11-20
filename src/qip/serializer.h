#ifndef _qip_serializer_h
#define _qip_serializer_h

#include <inttypes.h>

#include "minipack.h"
#include "qip_string.h"
#include "module.h"


//==============================================================================
//
// Definitions
//
//==============================================================================

// The serializer packs qip objects into MsgPack format.
typedef struct {
    void *ptr;
    void *data;
    int64_t length;
    int64_t blength;
} qip_serializer;


//==============================================================================
//
// Functions
//
//==============================================================================

//======================================
// Lifecycle
//======================================

qip_serializer *qip_serializer_create();

void qip_serializer_free(qip_serializer *serializer);


//======================================
// Packing
//======================================

void qip_serializer_pack_int(qip_module *module, qip_serializer *serializer,
    int64_t value);

void qip_serializer_pack_float(qip_module *module, qip_serializer *serializer,
    double value);

void qip_serializer_pack_string(qip_module *module, qip_serializer *serializer,
    qip_string value);

void qip_serializer_pack_raw(qip_module *module, qip_serializer *serializer,
    void *value, uint64_t length);

void qip_serializer_pack_map(qip_module *module, qip_serializer *serializer,
    int64_t count);

#endif
