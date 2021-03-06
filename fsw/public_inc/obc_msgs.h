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
#define OBC_RESET_COUNTERS_CC 3         // 0b00000011,
#define OBC_BATT_ENABLE_CC 5            // 0b00000101,
#define OBC_WIFI_ENABLE_CC 6            // 0b00000110,
#define OBC_MASTER_COMMS_ENABLE 9       // 0b00001001
#define OBC_POWER_SWITCHING_ENABLE 10   // 0b00001010

/*
** Type definition (generic "no arguments" command)
*/
typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
} OBC_NoArgsCmd_t;

// separate typedefs for open mode & future changes
typedef OBC_NoArgsCmd_t OBC_BatteryEnable_Cmd_t;
typedef OBC_NoArgsCmd_t OBC_WifiEnable_Cmd_t;
typedef OBC_NoArgsCmd_t OBC_MasterCommsEnable_Cmd_t;
typedef OBC_NoArgsCmd_t OBC_PowerSwitchingEnable_Cmd_t;
typedef OBC_NoArgsCmd_t OBC_GetEPSMSAIStatus_Cmd_t;
typedef OBC_NoArgsCmd_t OBC_GetEPSMConverter_Cmd_t;

// TODO - do we need the buffer definitions as per messages below?

// Message sizes
#define BATTERY_ENABLE_CMD_LNGTH sizeof(OBC_BatteryEnable_Cmd_t)
#define EPSM_GET_SAI_LNGTH sizeof(OBC_GetEPSMSAIStatus_Cmd_t)
#define EPSM_GET_CONVERTER_LNGTH sizeof(OBC_GetEPSMConverter_Cmd_t)
#define WIFI_ENABLE_CMD_LNGTH sizeof(OBC_WifiEnable_Cmd_t)
#define POWER_SWITCHING_ENABLE_CMD_LNGTH sizeof(OBC_PowerSwitchingEnable_Cmd_t)
#define MASTER_COMMS_ENABLE_CMD_LNGTH sizeof(OBC_MasterCommsEnable_Cmd_t)

typedef struct {
    uint16 obc_reboot_counter;
    uint16 iobc_wifi_strenght;
    uint16 spi_invalid_msg_counter;
} OBC_Health_Payload_t;

typedef struct {
    uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];   // note Tlm Header has timestamp
    OBC_Health_Payload_t payload;
} OS_PACK OBC_Health_Tlm_t;

#define OBC_HEALTH_TLM_LEN sizeof(OBC_Health_Tlm_t)

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
#define OBC_SENSOR_TELEM_LEN sizeof(OBC_Peripheral_Sensor_Tlm_t)

/**************************************************************************
 * Motor Controller (E5) Message Definitions
 **************************************************************************/

// command structure
typedef struct {
    set_wheel_speed_all_payload_t uart_payload;
    uint32_t duration;   // seconds
} Set_Wheel_Speed_All_Cmd_Payload;

#define OBC_SET_WHEEL_SPEED_ALL_PAYLOAD_LEN \
    sizeof(Set_Wheel_Speed_All_Cmd_Payload)

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

#define OBC_SET_WHEEL_SPEED_ALL_CMD_LEN sizeof(OBC_Set_Wheel_Speed_All_Cmd_t)

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
#define OBC_SET_MOTOR_PID_CMD_LEN sizeof(OBC_Set_Motor_PID_Cmd_t)

// cFS command structure
typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
    set_solar_panel_state_payload_t payload;
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
#define OBC_SET_SOLAR_PANEL_STATE_LEN sizeof(OBC_Set_Solar_Panel_State_Cmd_t)

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
#define OBC_NSS_SET_PARAMS_CMD_LEN sizeof(OBC_NSS_Set_Params_Cmd_t)

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
    OBC_Set_Switch_State_Cmd_t set_switch_cmd;
} OBC_Set_Switch_State_Buffer_t;

// Message sizes
#define OBC_SET_SWITCH_STATE_CMD_LEN sizeof(OBC_Set_Switch_State_Cmd_t)

typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
    set_switch_state_all_payload_t payload;
} OS_PACK OBC_Set_Switch_State_All_Cmd_t;

/**
 * Buffer to hold data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    OBC_Set_Switch_State_All_Cmd_t set_switch_state_all;
} OBC_Set_Switch_State_All_Buffer_t;

// Message sizes
#define OBC_SET_SWITCH_STATE_ALL_CMD_LEN sizeof(OBC_Set_Switch_State_All_Cmd_t)

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
#define OBC_RESET_SWITCH_CMD_LEN sizeof(OBC_Reset_Switch_Cmd_t)

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
#define OBC_SET_HEATER_STATE_CMD_LEN sizeof(OBC_Set_Heater_State_Cmd_t)

typedef struct {
    uint8_t CmdHeader[CFE_SB_CMD_HDR_SIZE];
    set_heater_state_all_payload_t payload;
} OS_PACK OBC_Set_Heater_State_All_Cmd_t;

/**
 * Buffer to hold data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    OBC_Set_Heater_State_All_Cmd_t set_heater_state_all_cmd;
} OBC_Set_Heater_State_All_Buffer_t;

// Message sizes
#define OBC_SET_HEATER_STATE_ALL_CMD_LEN sizeof(OBC_Set_Heater_State_All_Cmd_t)

/**************************************************************************
 * EPSM Message Definitions
 **************************************************************************/
#define NUM_POWER_RAILS 4   // 3.3V, 5V, 12V, AUX in order
#define NUM_BATT_MODULES 2
#define MAX_USER_CMD_LEN 46   // max length of user defined I2C command

typedef struct {
    uint16_t volt;       // units are millivolts
    int16_t amps;        // units are milliamps
    uint8_t SAI_state;   // see EPSM:TEL? 0 documentation
    uint8_t valid;       // if this SAI's data is valid
} SAIStatus_t;

typedef struct {
    uint8_t TlmHdr[CFE_SB_TLM_HDR_SIZE];
    SAIStatus_t Status[6];
} OS_PACK OBC_EPSM_SAIStatus_t;

typedef union {
    CFE_SB_Msg_t MsgHdr;
    OBC_EPSM_SAIStatus_t OBC_EPSM_response;
} OBC_EPSM_SAIStatus_buffer_t;

#define OBC_EPSM_SAI_STATUS_TELEM_LEN sizeof(OBC_EPSM_SAIStatus_t)

typedef struct {
    uint16_t volt;             // units are millivolts
    int16_t amps;              // units are milliamps
    uint8_t converter_state;   // see EPSM:TEL? 8 documentation
    uint8_t valid;             // if this converter's data is valid
} ConverterState_t;

typedef struct {
    uint8_t TlmHdr[CFE_SB_TLM_HDR_SIZE];
    ConverterState_t Status[NUM_POWER_RAILS];   // 3.3V, 5V, 12V, AUX in order
} OS_PACK OBC_EPSM_ConverterStatus_t;

typedef union {
    CFE_SB_Msg_t MsgHdr;
    ConverterState_t OBC_EPSM_response;
} OBC_EPSM_ConverterState_buffer_t;

#define OBC_EPSM_CONVERTER_STATUS_TELEM_LEN sizeof(OBC_EPSM_ConverterStatus_t)

typedef struct {
    uint16_t time_to_full;    // in minutes 65535 means not charging
    uint16_t time_to_empty;   // in minutes 6555 means not discharing
    uint8_t charge_state;     // 0-100% charge state
    uint8_t valid;            // if the msg is valid;
} BatteryModuleState_t;

typedef struct {
    uint8_t TlmHdr[CFE_SB_TLM_HDR_SIZE];
    BatteryModuleState_t battery_module[NUM_BATT_MODULES];
} OS_PACK OBC_BM_Status_t;

typedef union {
    CFE_SB_Msg_t MsgHdr;
    OBC_BM_Status_t OBC_BM_response;
} OBC_EPSM_BM_Status_buffer_t;

#define OBC_EPSM_BM_STATUS_TELEM_LEN sizeof(OBC_BM_Status_t)

typedef struct {
    uint8_t tx_data[MAX_USER_CMD_LEN];
    uint8_t i2c_slave_addr;
    uint8_t tx_bytes;
    uint8_t rx_bytes;
} user_tx_data_t;

typedef struct {
    uint8_t TlmHdr[CFE_SB_TLM_HDR_SIZE];
    user_tx_data_t tx_data;
} OS_PACK OBC_I2C_USER_DEFINED_TX_t;

typedef union {
    CFE_SB_Msg_t MsgHdr;
    OBC_I2C_USER_DEFINED_TX_t user_tx;
} OBC_I2C_USER_DEFINED_TX_buffer_t;

#define OBC_I2C_USER_DEFINED_LEN sizeof(OBC_I2C_USER_DEFINED_TX_t)

typedef struct {
    uint8_t rx_data[MAX_USER_CMD_LEN];
} user_rx_data_t;

typedef struct {
    uint8_t TlmHdr[CFE_SB_TLM_HDR_SIZE];
    user_rx_data_t rx_data;
} OS_PACK OBC_I2C_USER_DEFINED_RX_t;

typedef union {
    CFE_SB_Msg_t MsgHdr;
    OBC_I2C_USER_DEFINED_RX_t user_tx;
} OBC_I2C_USER_DEFINED_RX_buffer_t;

#define OBC_I2C_USER_DEFINED_TELEM_LEN sizeof(OBC_I2C_USER_DEFINED_RX_t)

#endif /* _obc_msgs_h */
