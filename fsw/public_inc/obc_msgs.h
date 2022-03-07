/****************************************************************
 *
 * @file        obc_msgs.h
 *
 * @brief       This file contains all the message definitions for data coming
 *              to/from the peripheral computer
 *
 * @date   		27 Feb 2022
 *
 * @authors 	Tenzin Crouch
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 * @note		This file contains all of the cFS implementations for
 *              peripheral device commands.
 *
 * @note        Copyright 2022 Carnegie Mellon University. All rights reserved.
 ****************************************************************/

#ifndef _obc_msgs_h
#define _obc_msgs_h

#include "cfe_sb.h"
#include "common_types.h"
#include "master_comms_msgs.h"

/**************************************************************************
 * OBC (Peripheral Computer) (E1) Message Definitions
 **************************************************************************/
/**
 * OBC Command Codes
 * @note code numbers have been selected for dual bit changes.
 */
#define OBC_NOOP_CC 0
#define OBC_RESET_COUNTERS_CC 3   // 0b00000011,
#define OBC_BATT_ENABLE_CC 5      // 0b00000101,
#define OBC_WIFI_ENABLE_CC 6      // 0b00000110,

/*
** Type definition (generic "no arguments" command)
*/
typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
} OBC_NoArgsCmd_t;

// separate typedefs for open mode & future changes
typedef OBC_NoArgsCmd_t BatteryEnable_Cmd_t;
typedef OBC_NoArgsCmd_t WifiEnable_Cmd_t;

// TODO - do we need the buffer definitions as per messages below?

// Message sizes
#define BATTERY_ENABLE_CMD_LNGTH sizeof(BatteryEnable_Cmd_t)
#define BATTERY_ENABLE_CMD_LNGTH sizeof(BatteryEnable_Cmd_t)

typedef struct {
} OBC_Health_Tlm_t;

typedef struct {
    uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];   // note Tlm Header has timestamp
    OBC_Health_Tlm_t payload;
} OS_PACK OBC_Health_Tlm_t;

#define OBC_HEALTH_TLM_LEN sizeof(OBC_Health_Tlm_t);

/**************************************************************************
 * Master Comms Controller (E3) Message Definitions
 **************************************************************************/
typedef struct {
    uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];   // note Tlm Header has timestamp
    sensor_telem_payload_t payload;
} OS_PACK OBC_Peripheral_Sensor_Tlm_t;

/**
 * Buffer to hold data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    OBC_Peripheral_Sensor_Tlm_t peripheral_telem;
} OBC_Peripheral_Sensor_Tlm_Buffer_t;

// Message sizes
#define OBC_SENSOR_TELEM_LEN sizeof(OBC_Peripheral_Sensor_Tlm_t);

/**************************************************************************
 * Motor Controller (E5) Message Definitions
 **************************************************************************/
// command structure
typedef struct {
    set_wheel_speed_payload_t uart_payload;
    uint32_t duration;   // seconds
} Set_Wheel_Speed_Cmd_Payload;

// cFS command structure
typedef struct {
    uint8 CmdHeader[CFE_SB_TLM_HDR_SIZE];
    Set_Wheel_Speed_Cmd_Payload payload;
} OS_PACK OBC_Set_Wheel_Speed_Cmd_t;

/**
 * Buffer to hold data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    OBC_Set_Wheel_Speed_Cmd_t set_motor_speed_cmd;
} Set_Wheel_Speed_Buffer_t;

#define OBC_SET_WHEEL_SPEED_CMD_LEN sizeof(OBC_Set_Wheel_Speed_Cmd_t);

// command structure
typedef struct {
    set_wheel_speed_all_payload_t uart_payload;
    uint32_t duration;   // seconds
} Set_Wheel_Speed_All_Cmd_Payload;

// cFS command structure
typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
    Set_Wheel_Speed_All_Cmd_Payload payload;
} OS_PACK OBC_Set_Wheel_Speed_All_Cmd_t;

/**
 * Buffer to hold data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    OBC_Set_Wheel_Speed_All_Cmd_t set_motor_speed_all_cmd;
} Set_Wheel_Speed_All_Buffer_t;

#define OBC_SET_WHEEL_SPEED_ALL_CMD_LEN sizeof(OBC_Set_Wheel_Speed_All_Cmd_t);

// cFS command structure
typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
    set_motor_pid_payload_t payload;
} OS_PACK OBC_Set_Motor_PID_Cmd_t;

/**
 * Buffer to hold data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    OBC_Set_Motor_PID_Cmd_t set_motor_PID_cmd;
} Set_Motor_PID_Buffer_All_t;

// Message sizes
#define OBC_SET_MOTOR_PID_CMD_LEN sizeof(OBC_Set_Motor_PID_Cmd_t);

// cFS command structure
typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
    set_motor_pid_payload_t payload;
} OS_PACK OBC_Set_Solar_Panel_State_Cmd_t;

/**
 * Buffer to hold data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    OBC_Set_Solar_Panel_State_Cmd_t set_solar_panel_state_cmd;
} Set_Solar_Panel_State_Buffer_t;

// Message sizes
#define OBC_SET_SOLAR_PANEL_STATE_LEN sizeof(OBC_Set_Solar_Panel_State_Cmd_t);

/**************************************************************************
 * NSS Interface (E6) Message Definitions
 **************************************************************************/

/**
 */
typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
    set_nss_params_payload_t payload;
} OS_PACK OBC_NSS_Set_Params_Cmd_t;

/**
 * Buffer to hold NSS set params data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    OBC_NSS_Set_Params_Cmd_t nss_set_params_cmd;
} NSS_Set_Params_Buffer_t;

// Message sizes
#define OBC_NSS_SET_PARAMS_CMD_LEN sizeof(OBC_NSS_Set_Params_Cmd_t);

/**************************************************************************
 * Power Switching Controller (E8) Message Definitions
 **************************************************************************/
typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
    set_switch_state_payload_t payload;
} OS_PACK OBC_Set_Switch_State_Cmd_t;

/**
 * Buffer to hold data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    OBC_Set_Switch_State_Cmd_t nss_set_params_cmd;
} OBC_Set_Switch_State_Buffer_t;

// Message sizes
#define OBC_SET_SWITCH_STATE_CMD_LEN sizeof(OBC_Set_Switch_State_Cmd_t);

typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
    reset_switch_payload_t payload;
} OS_PACK OBC_Reset_Switch_Cmd_t;

/**
 * Buffer to hold data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    OBC_Reset_Switch_Cmd_t reset_switch_cmd;
} OBC_Reset_Switch_Buffer_t;

// Message sizes
#define OBC_RESET_SWITCH_CMD_LEN sizeof(OBC_Reset_Switch_Cmd_t);

/**************************************************************************
 * Heater Controller (E9) Message Definitions
 **************************************************************************/
typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
    set_heater_state_payload_t payload;
} OS_PACK OBC_Set_Heater_State_Cmd_t;

/**
 * Buffer to hold data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    OBC_Set_Heater_State_Cmd_t set_heater_state_cmd;
} OBC_Set_Heater_State_Buffer_t;

// Message sizes
#define OBC_SET_SWITCH_STATE_CMD_LEN sizeof(OBC_Set_Heater_State_Cmd_t);

#endif /* _obc_msgs_h */
