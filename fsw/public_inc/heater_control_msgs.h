/****************************************************************
 *
 * @file     heater_controller_msgs.h
 *
 * @brief     definitions for all master comms bus messages for heater
 *controller
 *
 * @authors 	Tenzin Crouch
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 * @note        Copyright 2022 Carnegie Mellon University. All rights reserved.
 ****************************************************************/

#ifndef _heater_controller_msgs_h
#define _heater_controller_msgs_h

#include "master_comms_bus_protocol.h"
#include "moonranger_common_types.h"

#define NUM_HEATERS 16
#define NUM_THERMISTORS 16

// note: IDs selected to have minimum 2 bits difference for reliability
typedef enum
{
    HEATER_ON = 3,    // 0b00000011,
    HEATER_OFF = 5,   // 0b00000101,
    SCHMIDT_ON = 6,   // 0b00000110
} heater_state_t;

/**
 * Heaters as specified in MR-SYS-0161
 */
typedef enum
{
    HEATER1 = 3,     // 0b00000011,
    HEATER2 = 5,     // 0b00000101,
    HEATER3 = 6,     // 0b00000110,
    HEATER4 = 9,     // 0b00001001,
    HEATER5 = 10,    // 0b00001010,
    HEATER6 = 12,    // 0b00001100,
    HEATER7 = 15,    // 0b00001111,
    HEATER8 = 17,    // 0b00010001,
    HEATER9 = 20,    // 0b00010100,
    HEATER10 = 23,   // 0b00010111,
    HEATER11 = 24,   // 0b00011000,
    HEATER12 = 27,   // 0b00011011,
    HEATER13 = 28,   // 0b00011100,
    HEATER14 = 33,   // 0b00100001,
    HEATER15 = 34,   // 0b00100010,
    HEATER16 = 36    // 0b00100100
} heater_id_t;

/**************************************************************************
 * MOONRANGER MESSAGE PAYLOADS
 **************************************************************************/
// set heater state command payload
typedef struct {
    heater_id_t heater_id;
    heater_state_t heater_state;
} set_heater_state_payload_t;

#define SET_HEATER_STATE_PAYLOAD_LEN sizeof(set_heater_state_payload_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert(
    (2 == SET_HEATER_STATE_PAYLOAD_LEN),
    "set_heater_state_payload_t struct size incorrect (expected 2 bytes)");

static_assert(((SET_HEATER_STATE_PAYLOAD_LEN % 2) == 0),
              "set_heater_state_payload_t not 16 bit aligned");
#endif

// set all heater state command payload
typedef struct {
    heater_state_t heater_state[NUM_HEATERS];
} set_heater_state_all_payload_t;

#define SET_HEATER_STATE_ALL_PAYLOAD_LEN sizeof(set_heater_state_all_payload_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert(
    (16 == SET_HEATER_STATE_ALL_PAYLOAD_LEN),
    "set_heater_state_payload_all_t struct size incorrect (expected 16 bytes)");

static_assert(((SET_HEATER_STATE_ALL_PAYLOAD_LEN % 2) == 0),
              "set_heater_state_payload_all_t struct not 16 bit aligned");
#endif

// heater telemetry payload
typedef struct {
    heater_state_t heater_state[NUM_HEATERS];   // array of heater states.
                                                // heater ID is index +1
    uint16_t temperature[NUM_THERMISTORS];      // array of temperature
                                                // measurements. ID is index +1
    msp_health_payload_t msp_health;
} heater_telem_payload_t;

#define HEATER_TELEM_PAYLOAD_LEN sizeof(heater_telem_payload_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert(
    (52 == HEATER_TELEM_PAYLOAD_LEN),
    "heater_telem_payload_t struct size incorrect (expected 52 bytes)");

static_assert(((HEATER_TELEM_PAYLOAD_LEN % 2) == 0),
              "heater_telem_payload_t struct not 16 bit aligned");
#endif

/**************************************************************************
 * MASTER COMMS BUS UART MESSAGE DEFINITIONS
 **************************************************************************/
// get heater telemtry command
typedef struct {
    main_bus_hdr_t msg_hdr;
    uint16_t checksum;
    uint16_t __padding;   // for consistent footer on MSPs commands
} get_heater_telem_cmd_t;

#define GET_HEATER_TELEM_CMD_LEN sizeof(get_heater_telem_cmd_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert(
    (12 == GET_HEATER_TELEM_CMD_LEN),
    "get_heater_telem_cmd_t struct size incorrect (expected 12 bytes)");

static_assert(((GET_HEATER_TELEM_CMD_LEN % 4) == 0),
              "get_heater_telem_cmd_t struct not 32 bit aligned");
#endif

// set heater state command
typedef struct {
    main_bus_hdr_t msg_hdr;
    set_heater_state_payload_t payload;
    uint16_t checksum;
    uint16_t __padding;   // for consistent footer on MSPs commands
} set_heater_state_cmd_t;

#define SET_HEATER_STATE_CMD_LEN sizeof(set_heater_state_cmd_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert(
    (14 == SET_HEATER_STATE_CMD_LEN),
    "set_heater_state_cmd_t struct size incorrect (expected 14 bytes)");

static_assert(((SET_HEATER_STATE_CMD_LEN % 2) == 0),
              "set_heater_state_cmd_t struct not 16 bit aligned");
#endif

// set heater state command
typedef struct {
    main_bus_hdr_t msg_hdr;
    set_heater_state_all_payload_t payload;
    uint16_t checksum;
    uint16_t __padding;   // for consistent footer on MSPs commands
} set_heater_state_all_cmd_t;

#define SET_HEATER_STATE_ALL_CMD_LEN sizeof(set_heater_state_all_cmd_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert(
    (28 == SET_HEATER_STATE_ALL_CMD_LEN),
    "set_heater_state_all_cmd_t struct size incorrect (expected 28 bytes)");

static_assert(((SET_HEATER_STATE_ALL_CMD_LEN % 4) == 0),
              "set_heater_state_all_cmd_t struct not 32 bit aligned");
#endif

// heater telemetry message
typedef struct {
    main_bus_hdr_t msg_hdr;
    heater_telem_payload_t payload;
    uint16_t checksum;
    uint16_t __padding;   // for consistent footer on MSPs commands
} heater_telem_msg_t;


#define HEATER_TELEM_MSG_LEN sizeof(heater_telem_msg_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert((64 == HEATER_TELEM_MSG_LEN),
              "heater_telem_msg_t struct size incorrect (expected 64 bytes)");

static_assert(((HEATER_TELEM_MSG_LEN % 4) == 0),
              "heater_telem_msg_t struct not 32 bit aligned");
#endif

#endif /* _heater_control_msgs_h */
