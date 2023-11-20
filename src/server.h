#ifndef _server_h
#define _server_h

#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <netinet/in.h>

#include "bstring.h"
#include "database.h"
#include "table.h"
#include "event.h"


//==============================================================================
//
// Overview
//
//==============================================================================

// The server acts as the interface to external applications. It communicates
// over TCP sockets using a specific Sky protocol. See the message.h file for
// more detail on the protocol.


//==============================================================================
//
// Definitions
//
//==============================================================================

#define SKY_DEFAULT_PORT 8585

#define SKY_LISTEN_BACKLOG 511


//==============================================================================
//
// Typedefs
//
//==============================================================================

// The various states that the server can be in.
typedef enum sky_server_state_e {
    SKY_SERVER_STATE_STOPPED,
    SKY_SERVER_STATE_RUNNING,
} sky_server_state_e;


typedef struct {
    sky_server_state_e state;
    bstring path;
    int port;
    struct sockaddr_in* sockaddr;
    int socket;
    sky_database *last_database;
    sky_table *last_table;
} sky_server;




//==============================================================================
//
// Functions
//
//==============================================================================

//--------------------------------------
// Lifecycle
//--------------------------------------

sky_server *sky_server_create(bstring path);

void sky_server_free(sky_server *server);


//--------------------------------------
// State
//--------------------------------------

int sky_server_start(sky_server *server);

int sky_server_stop(sky_server *server);


//--------------------------------------
// Connection Management
//--------------------------------------

int sky_server_accept(sky_server *server);


//--------------------------------------
// Event Messages
//--------------------------------------

int sky_server_process_eadd_message(sky_server *server, sky_table *table,
    FILE *input, FILE *output);

//--------------------------------------
// Path Messages
//--------------------------------------

int sky_server_process_peach_message(sky_server *server, sky_table *table,
    FILE *input, FILE *output);

//--------------------------------------
// Action Messages
//--------------------------------------

int sky_server_process_aadd_message(sky_server *server, sky_table *table,
    FILE *input, FILE *output);

int sky_server_process_aget_message(sky_server *server, sky_table *table,
    FILE *input, FILE *output);

int sky_server_process_aall_message(sky_server *server, sky_table *table,
    FILE *input, FILE *output);

//--------------------------------------
// Property Messages
//--------------------------------------

int sky_server_process_padd_message(sky_server *server, sky_table *table,
    FILE *input, FILE *output);

int sky_server_process_pget_message(sky_server *server, sky_table *table,
    FILE *input, FILE *output);

int sky_server_process_pall_message(sky_server *server, sky_table *table,
    FILE *input, FILE *output);

#endif
