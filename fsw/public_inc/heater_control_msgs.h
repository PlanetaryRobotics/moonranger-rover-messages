/****************************************************************
 *
 * @file     heater_controller_msgs.h
 *
 * @brief     definitions for all messages related to heater controller master
 *comms bus
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

#include "cfe_sb.h"
#include "master_comms_bus_protocol.h"
#include "moonranger_common_types.h"

typedef enum
{
    HEATER_ON = 0b00000011,
    HEATER_OFF = 0b00000101,
    SCHMIDT_ON = 0b00000110
} heater_state_t;

/**
 * @todo ADD DESCRIPTIVE COMMENTS HERE
 */

typedef enum
{
    HEATER1 = 0b00000011,
    HEATER2 = 0b00000101,
    HEATER3 = 0b00000110,
    HEATER4 = 0b00001001,
    HEATER5 = 0b00001010,
    HEATER6 = 0b00001100,
    HEATER7 = 0b00001111,
    HEATER8 = 0b00010001,
    HEATER9 = 0b00010100,
    HEATER10 = 0b00010111,
    HEATER11 = 0b00011000,
    HEATER12 = 0b00011011,
    HEATER13 = 0b00011100,
    HEATER14 = 0b00100001
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
    heater_state_t heater_state_t[14];   // array of heater states.
                                         // heare ID is index +1
    uint16 temperature[13];              // array of temperature measurements.
                                         // ID is index +1
    uint16 reboot_ctr;   // counter of number of times heater controller MSP has
                         // rebooted since last software load
    uint16 inv_msg_ctr;   // count of invalid messages received by heater
                          // controller MSP
} heater_telem_payload_t;

#define HEATER_TELEM_LEN sizeof(heater_telem_payload_t);

/**************************************************************************
 * MASTER COMMS BUS UART MESSAGE DEFINITIONS
 **************************************************************************/
// get heater telemtry command
typedef struct {
    main_bus_hdr_t msg_hdr;
    uint16 checksum;
} get_heater_telem_msg_t;

#define GET_HEATER_TELEM_MSG_LEN sizeof(get_heater_telem_msg_t);

// set heater state command
typedef struct {
    main_bus_hdr_t msg_hdr;
    set_heater_state_payload_t payload;
    uint16 checksum;
} set_heater_state_msg_t;

#define SET_HEATER_STATE_MSG_LEN sizeof(set_heater_state_msg_t);

// power switch telemetry message
typedef struct {
    main_bus_hdr_t msg_hdr;
    heater_telem_payload_t payload;
    uint16 checksum;
} heater_telem_msg_t;

#define HEATER_TELEM_MSG_LEN sizeof(heater_telem_msg_t);

/**************************************************************************
 * CFS SB MESSAGE DEFINITIONS
 **************************************************************************/
typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
    set_heater_state_payload_t payload;
} OS_PACK CFS_Set_Heater_State_Cmd_t;

/**
 * Buffer to hold data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    CFS_Set_Heater_State_Cmd_t nss_set_params_cmd;
} CFS_Set_Heater_State_Buffer_t;

// Message sizes
#define CFS_SET_SWITCH_STATE_CMD_LEN sizeof(CFS_Set_Heater_State_Cmd_t);

#endif /* _power_switching_msgs_h */
