/****************************************************************
 *
 * @file     power_switching_msgs.h
 *
 * @brief     definitions for all messages related to power switching master
 *comms bus
 *
 * @date   		20 Feb 2022
 *
 * @authors 	Tenzin Crouch
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 * @note        Copyright 2022 Carnegie Mellon University. All rights reserved.
 ****************************************************************/

#ifndef _power_switching_msgs_h
#define _power_switching_msgs_h

#include "cfe_sb.h"
#include "master_comms_bus_protocol.h"
#include "moonranger_common_types.h"

#define NUM_SWITCH_GROUPS 15

typedef enum
{
    POWER_ON = 3,    // 0b00000011,
    POWER_OFF = 5,   // 0b00000101
} switch_state_t;

/**
 * Switching groups corresponding to MR-AVI-0168
 * @note does not include groups not controlled by power switching MSP
 */
typedef enum
{
    PSW_3 = 3,     // 0b00000011
    PSW_4 = 5,     // 0b00000101
    PSW_5 = 6,     // 0b00000110
    PSW_6 = 9,     // 0b00001001
    PSW_7 = 10,    // 0b00001010
    PSW_8 = 12,    // 0b00001100
    PSW_9 = 15,    // 0b00001111
    PSW_10 = 17,   // 0b00010001
    PSW_11 = 20,   // 0b00010100
    PSW_12 = 23,   // 0b00010111
    PSW_13 = 24,   // 0b00011000
    PSW_14 = 27,   // 0b00011011
    PSW_15 = 28,   // 0b00011100
    PSW_18 = 33,   // 0b00100001
    PSW_19 = 34    // 0b00100010
} switch_group_id_t;

/**************************************************************************
 * MOONRANGER MESSAGE PAYLOADS
 **************************************************************************/
// set power switching state command payload
typedef struct {
    switch_group_id_t switch_group_id;
    switch_state_t switch_state;
} set_switch_state_payload_t;

#define SET_SWITCH_STATE_PAYLOAD_LEN sizeof(set_switch_state_payload_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert(
    (2 == SET_SWITCH_STATE_PAYLOAD_LEN),
    "set_switch_state_payload_t struct size incorrect (expected 2 bytes)");

static_assert(((SET_SWITCH_STATE_PAYLOAD_LEN % 2) == 0),
              "set_switch_state_payload_t struct not 16 bit aligned");
#endif

// set power switching state all command payload
typedef struct {
    switch_state_t switch_state[NUM_SWITCH_GROUPS];
    uint8_t __padding;   // ensure 16 bit alignment
} set_switch_state_all_payload_t;

#define SET_SWITCH_STATE_ALL_PAYLOAD_LEN sizeof(set_switch_state_all_payload_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert(
    (16 == SET_SWITCH_STATE_ALL_PAYLOAD_LEN),
    "set_switch_state_all_payload_t struct size incorrect (expected 16 bytes)");

static_assert(((SET_SWITCH_STATE_PAYLOAD_LEN % 2) == 0),
              "set_switch_state_all_payload_t struct not 16 bit aligned");
#endif

// reset power switch command payload
typedef struct {
    switch_group_id_t switch_group_id;
    uint8_t __padding;   // ensure 16 bit alignment
} reset_switch_payload_t;

#define RESET_SWITCH_PAYLOAD_LEN sizeof(reset_switch_payload_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert(
    (2 == RESET_SWITCH_PAYLOAD_LEN),
    "reset_switch_payload_t struct size incorrect (expected 2 bytes)");

static_assert(((SET_SWITCH_STATE_PAYLOAD_LEN % 2) == 0),
              "set_switch_state_all_payload_t struct not 16 bit aligned");
#endif

// power switching telemetry payload
typedef struct {
    msp_health_payload_t msp_health;
    uint16_t switch_current[NUM_SWITCH_GROUPS];   // array current measurements.
    switch_state_t switch_state[NUM_SWITCH_GROUPS];   // array switch states.
    uint8_t __padding[3];                             // ensure 32 bit alignment
} power_switch_telem_payload_t;

#define POWER_SWITCH_TELEM_LEN sizeof(power_switch_telem_payload_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert(
    (52 == POWER_SWITCH_TELEM_LEN),
    "power_switch_telem_payload_t struct size incorrect (expected 52 bytes)");

static_assert(((POWER_SWITCH_TELEM_LEN % 4) == 0),
              "power_switch_telem_payload_t struct not 32 bit aligned");
#endif

/**************************************************************************
 * MASTER COMMS BUS UART MESSAGE DEFINITIONS
 **************************************************************************/
// get power switching telemtry command
typedef struct {
    main_bus_hdr_t msg_hdr;
    uint16_t checksum;
    uint16_t __padding;   // for consistent footer on MSPs commands
} get_switch_telem_cmd_t;

#define GET_SWITCH_TELEM_CMD_LEN sizeof(get_switch_telem_cmd_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert(
    (12 == GET_SWITCH_TELEM_CMD_LEN),
    "get_switch_telem_cmd_t struct size incorrect (expected 12 bytes)");

static_assert(((GET_SWITCH_TELEM_CMD_LEN % 4) == 0),
              "get_switch_telem_cmd_t struct not 32 bit aligned");
#endif

// set power switching state command
typedef struct {
    main_bus_hdr_t msg_hdr;
    set_switch_state_payload_t payload;
    uint16_t checksum;
    uint16_t __padding;   // for consistent footer on MSPs commands
} set_switch_state_cmd_t;

#define SET_SWITCH_STATE_CMD_LEN sizeof(set_switch_state_cmd_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert(
    (14 == SET_SWITCH_STATE_CMD_LEN),
    "set_switch_state_cmd_t struct size incorrect (expected 14 bytes)");

static_assert(((SET_SWITCH_STATE_CMD_LEN % 2) == 0),
              "set_switch_state_cmd_t struct not 16 bit aligned");
#endif

// set power switching state command
typedef struct {
    main_bus_hdr_t msg_hdr;
    set_switch_state_all_payload_t payload;
    uint16_t checksum;
    uint16_t __padding;   // for consistent footer on MSPs commands
} set_switch_state_all_cmd_t;

#define SET_SWITCH_STATE_ALL_CMD_LEN sizeof(set_switch_state_all_cmd_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert(
    (28 == SET_SWITCH_STATE_ALL_CMD_LEN),
    "set_switch_state_all_cmd_t struct size incorrect (expected 28 bytes)");

static_assert(((SET_SWITCH_STATE_ALL_CMD_LEN % 2) == 0),
              "set_switch_state_all_cmd_t struct not 16 bit aligned");
#endif

// reset power switch command
typedef struct {
    main_bus_hdr_t msg_hdr;
    reset_switch_payload_t payload;
    uint16_t checksum;
    uint16_t __padding;   // for consistent footer on MSPs
} reset_switch_cmd_t;

#define RESET_SWITCH_CMD_LEN sizeof(reset_switch_cmd_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert((14 == RESET_SWITCH_CMD_LEN),
              "reset_switch_cmd_t struct size incorrect (expected 14 bytes)");

static_assert(((RESET_SWITCH_CMD_LEN % 2) == 0),
              "reset_switch_cmd_t struct not 16 bit aligned");
#endif

// power switch telemetry message
typedef struct {
    main_bus_hdr_t msg_hdr;
    power_switch_telem_payload_t payload;
    uint16_t checksum;
    uint16_t __padding;   // for consistent footer on MSPs commands
} power_switch_telem_msg_t;

#define POWER_SWITCH_TELEM_MSG_LEN sizeof(power_switch_telem_msg_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert(
    (64 == POWER_SWITCH_TELEM_MSG_LEN),
    "power_switch_telem_msg_t struct size incorrect (expected 64 bytes)");

static_assert(((POWER_SWITCH_TELEM_MSG_LEN % 4) == 0),
              "power_switch_telem_msg_t struct not 32 bit aligned");
#endif
#endif /* _power_switching_msgs_h */
