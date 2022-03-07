/****************************************************************
 *
 * @file     heater_controller_msgs.h
 *
 * @brief     definitions for all master comms bus messages for heater
 *controller
 *
 * @date   		20 Feb 2022
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

#define NUM_HEATERS 14
#define NUM_THERMISTORS 13

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
    HEATER14 = 33,   // 0b00100001
} heater_id_t;

/**************************************************************************
 * MOONRANGER MESSAGE PAYLOADS
 **************************************************************************/
// set heater state command payload
typedef struct {
    heater_id_t heater_id;
    heater_state_t heater_state;
} set_heater_state_payload_t;

#define SET_HEATER_STATE_PAYLOAD_LEN sizeof(set_heater_state_payload_t);

// heater telemetry payload
typedef struct {
    heater_state_t heater_state[NUM_HEATERS];   // array of heater states.
                                                // heare ID is index +1
    uint16 temperature[NUM_THERMISTORS];   // array of temperature measurements.
                                           // ID is index +1
    msp_health_payload_t msp_health;
} heater_telem_payload_t;

#define HEATER_TELEM_LEN sizeof(heater_telem_payload_t);

/**************************************************************************
 * MASTER COMMS BUS UART MESSAGE DEFINITIONS
 **************************************************************************/
// get heater telemtry command
typedef struct {
    main_bus_hdr_t msg_hdr;
    uint16 checksum;
} get_heater_telem_cmd_t;

#define GET_HEATER_TELEM_MSG_LEN sizeof(get_heater_telem_cmd_t);

// set heater state command
typedef struct {
    main_bus_hdr_t msg_hdr;
    set_heater_state_payload_t payload;
    uint16 checksum;
} set_heater_state_cmd_t;

#define SET_HEATER_STATE_MSG_LEN sizeof(set_heater_state_cmd_t);

// heater telemetry message
typedef struct {
    main_bus_hdr_t msg_hdr;
    heater_telem_payload_t payload;
    uint16 checksum;
} heater_telem_msg_t;

#define HEATER_TELEM_MSG_LEN sizeof(heater_telem_msg_t);

#endif /* _heater_control_msgs_h */
