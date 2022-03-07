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
    PSW_12 = 23,   // 0b00010100
    PSW_13 = 24,   // 0b00010111
    PSW_14 = 27,   // 0b00011000
    PSW_15 = 28,   // 0b00011011
    PSW_18 = 33,   // 0b00011100
    PSW_19 = 34    // 0b00100001
} switch_group_id_t;

/**************************************************************************
 * MOONRANGER MESSAGE PAYLOADS
 **************************************************************************/
// set power switching state command payload
typedef struct {
    switch_group_id_t switch_group_id;
    switch_state_t switch_state;
} set_switch_state_payload_t;

#define SET_SWITCH_STATE_PAYLOAD_LEN sizeof(set_switch_state_payload_t);

// set power switching state all command payload
typedef struct {
    switch_state_t switch_state[NUM_SWITCH_GROUPS];
} set_switch_state_all_payload_t;

#define SET_SWITCH_STATE_ALL_PAYLOAD_LEN sizeof(set_switch_state_all_payload_t);

// reset power switch command payload
typedef struct {
    switch_group_id_t switch_group_id;
} reset_switch_payload_t;

#define RESET_SWITCH_PAYLOAD_LEN sizeof(reset_switch_payload_t);

// power switching telemetry payload
typedef struct {
    uint16 switch_current[NUM_SWITCH_GROUPS];   // array current measurements.
    switch_state_t switch_state[NUM_SWITCH_GROUPS];   // array switch states.
    msp_health_payload_t msp_health;
} power_switch_telem_payload_t;

#define POWER_SWITCH_TELEM_LEN sizeof(power_switch_telem_payload_t);

/**************************************************************************
 * MASTER COMMS BUS UART MESSAGE DEFINITIONS
 **************************************************************************/
// get power switching telemtry command
typedef struct {
    main_bus_hdr_t msg_hdr;
    uint16 checksum;
} get_switch_telem_cmd_t;

#define GET_SWITCH_TELEM_CMD_LEN sizeof(get_switch_telem_cmd_t);

// set power switching state command
typedef struct {
    main_bus_hdr_t msg_hdr;
    set_switch_state_payload_t payload;
    uint16 checksum;
} set_switch_state_cmd_t;

#define SET_SWITCH_STATE_CMD_LEN sizeof(set_switch_state_cmd_t);

// set power switching state command
typedef struct {
    main_bus_hdr_t msg_hdr;
    set_switch_state_all_payload_t payload;
    uint16 checksum;
} set_switch_state_all_cmd_t;

#define SET_SWITCH_STATE_ALL_CMD_LEN sizeof(set_switch_state_all_cmd_t);

// reset power switch command
typedef struct {
    main_bus_hdr_t msg_hdr;
    reset_switch_payload_t payload;
    uint16 checksum;
} reset_switch_cmd_t;

#define RESET_SWITCH_CMD_LEN sizeof(reset_switch_cmd_t);

// power switch telemetry message
typedef struct {
    main_bus_hdr_t msg_hdr;
    power_switch_telem_payload_t payload;
    uint16 checksum;
} power_switch_telem_msg_t;

#define POWER_SWITCH_TELEM_MSG_LEN sizeof(power_switch_telem_msg_t);

#endif /* _power_switching_msgs_h */
