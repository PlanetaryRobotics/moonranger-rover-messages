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

typedef enum
{
    POWER_ON = 0b00000011,
    POWER_OFF = 0b00000101
} switch_state_t;

/**
 * @todo ADD DESCRIPTIVE COMMENTS HERE
 */

typedef enum
{
    GROUP1 = 0b00000011,   // CONTROLLED BY IOBC
    GROUP2 = 0b00000101,   // CONTROLLED BY IOBC
    GROUP3 = 0b00000110,
    GROUP4 = 0b00001001,
    GROUP5 = 0b00001010,
    GROUP6 = 0b00001100,
    GROUP7 = 0b00001111,
    GROUP8 = 0b00010001,
    GROUP9 = 0b00010100,
    GROUP10 = 0b00010111,
    GROUP11 = 0b00011000,
    GROUP12 = 0b00011011,
    GROUP13 = 0b00011100,
    GROUP14 = 0b00100001,
    GROUP15 = 0b00100010,
    GROUP16 = 0b00100100,   // CONTROLLED BY IOBC
    GROUP17 = 0b00100111,
    GROUP18 = 0b00101000,
    GROUP19 = 0b00101011,
    GROUP20 = 0b00110000
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

// reset power switch command payload
typedef struct {
    switch_group_id_t switch_group_id;
} reset_switch_payload_t;

#define RESET_SWITCH_PAYLOAD_LEN sizeof(reset_switch_payload_t);

// power switching telemetry payload
typedef struct {
    switch_state_t switch_state_t[20];   // array of power switch states.
                                         // Switching group IDis index +1
    uint16 switch_current[20];   // array of current measurements. Current group
                                 // ID is index +1
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
} get_switch_telem_msg_t;

#define GET_SWITCH_TELEM_MSG_LEN sizeof(get_switch_telem_msg_t);

// set power switching state command
typedef struct {
    main_bus_hdr_t msg_hdr;
    set_switch_state_payload_t payload;
    uint16 checksum;
} set_switch_state_msg_t;

#define SET_SWITCH_STATE_MSG_LEN sizeof(set_switch_state_msg_t);

// reset power switch command
typedef struct {
    main_bus_hdr_t msg_hdr;
    reset_switch_payload_t payload;
    uint16 checksum;
} reset_switch_msg_t;

#define RESET_SWITCH_MSG_LEN sizeof(reset_switch_msg_t);

// power switch telemetry message
typedef struct {
    main_bus_hdr_t msg_hdr;
    power_switch_telem_payload_t payload;
    uint16 checksum;
} power_switch_telem_msg_t;

#define POWER_SWITCH_TELEM_MSG_LEN sizeof(power_switch_telem_msg_t);

/**************************************************************************
 * CFS SB MESSAGE DEFINITIONS
 **************************************************************************/
typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
    set_switch_state_payload_t payload;
} OS_PACK CFS_Set_Switch_State_Cmd_t;

/**
 * Buffer to hold data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    CFS_Set_Switch_State_Cmd_t nss_set_params_cmd;
} CFS_Set_Switch_State_Buffer_t;

// Message sizes
#define CFS_SET_SWITCH_STATE_CMD_LEN sizeof(CFS_Set_Switch_State_Cmd_t);

typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
    reset_switch_payload_t payload;
} OS_PACK CFS_Reset_Switch_Cmd_t;

/**
 * Buffer to hold data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    CFS_Reset_Switch_Cmd_t nss_set_params_cmd;
} CFS_Reset_Switch_Buffer_t;

// Message sizes
#define CFS_RESET_SWITCH_CMD_LEN sizeof(CFS_Reset_Switch_Cmd_t);

#endif /* _power_switching_msgs_h */
