/****************************************************************
 *
 * @file      motor_controller_msgs.h
 *
 * @brief     definitions for all messages related to motor control
 *
 * @date   		20 Feb 2022
 *
 * @authors 	Tenzin Crouch
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 * @note        Copyright 2022 Carnegie Mellon University. All rights reserved.
 ****************************************************************/

#ifndef _motor_controller_msgs_h
#define _motor_controller_msgs_h

#include "cfe_sb.h"
#include "master_comms_bus_protocol.h"
#include "moonranger_common_types.h"

typedef enum
{
    MOTOR_1 = 0b00000011,
    MOTOR_2 = 0b00000101,
    MOTOR_3 = 0b00001010,
    MOTOR_4 = 0b00001111,
    MOTOR_5 = 0b00010100
} motor_id_t;

typedef enum
{
    RAISED = 0b00000011,
    LOWERED = 0b00000101
} solar_panel_state_t;

typedef enum
{
    ENABLE = 0b00000011,
    DISABLE = 0b00000101
} brake_state_t;

typedef struct {
    int32 p_gain;   // p gain scaled down by 100
    int32 i_gain;   // i gain scaled down by 100
    int32 d_gain;   // d gain scaled down by 100
} pid_gains_t;

typedef struct {
    volatile int32 motor_hall_sensor;          // the ticks from hall sensor
    volatile int16 motor_commanded_velocity;   // The commanded velocity
    volatile int16 motor_actual_velocity;      // The actual velocity
    volatile int8 motor_pwm;                   // The motor pwm duty cycle
    volatile int16 motor_current;              // The current drawn by the motor
    volatile pid_gains_t motor_gains;          // The current motor PID gains
} motor_health_t;

/**************************************************************************
 * MOONRANGER MESSAGE PAYLOADS
 **************************************************************************/

// set motor speed command
typedef struct {
    motor_id_t motor_id;
    int16 motor_speed;
} set_wheel_speed_payload_t;

#define SET_MOTOR_SPEED_PAYLOAD_LEN sizeof(set_motor_speed_payload_t);

// set motor speed all command
typedef struct {
    int16 motor1_speed;
    int16 motor2_speed;
    int16 motor3_speed;
    int16 motor4_speed;
} set_wheel_speed_all_payload_t;

#define SET_MOTOR_SPEED_ALL_PAYLOAD_LEN sizeof(set_motor_speed_all_payload_t);

// set motor PID command
typedef struct {
    motor_id_t motor_id;
    pid_gains_t motor_pid_gains;
} set_motor_pid_payload_t;

#define SET_MOTOR_PID_PAYLOAD_LEN sizeof(set_motor_pid_payload_t);

// set solar panel state command
typedef struct {
    solar_panel_state_t panel_state;
} set_solar_panel_state_payload_t;

#define SET_SOLAR_PANEL_STATE_PAYLOAD_LEN \
    sizeof(set_solar_panel_state_payload_t);

// motor health message
typedef struct {
    motor_health_t motor_1;
    motor_health_t motor_2;
    motor_health_t motor_3;
    motor_health_t motor_4;
    motor_health_t motor_5;
    msp_health_payload_t msp_health;
} motor_health_payload_t;

#define MOTOR_HEALTH_PAYLOAD_LEN sizeof(motor_health_payload_t);

/**************************************************************************
 * MASTER COMMS BUS UART MESSAGE DEFINITIONS
 **************************************************************************/
// get motor health command
typedef struct {
    main_bus_hdr_t msg_hdr;
    uint16 checksum;
} get_motor_health_msg_t;

#define GET_MOTOR_HEALTH_MSG_LEN sizeof(get_motor_health_msg_t);

typedef struct {
    main_bus_hdr_t msg_hdr;
    set_wheel_speed_payload_t payload;
    uint16 checksum;
} set_motor_speed_msg_t;

#define SET_MOTOR_SPEED_MSG_LEN sizeof(set_motor_speed_msg_t);

typedef struct {
    main_bus_hdr_t msg_hdr;
    set_wheel_speed_all_payload_t payload;
    uint16 checksum;
} set_motor_speed_all_msg_t;

#define SET_MOTOR_SPEED_ALL_MSG_LEN sizeof(set_motor_speed_all_msg_t;);

typedef struct {
    main_bus_hdr_t msg_hdr;
    set_motor_pid_payload_t payload;
    uint16 checksum;
} set_motor_pid_msg_t;

#define SET_MOTOR_PID_MSG_LEN sizeof(set_motor_pid_msg_t);

typedef struct {
    main_bus_hdr_t msg_hdr;
    set_solar_panel_state_payload_t payload;
    uint16 checksum;
} set_solar_panel_state_msg_t;

#define SET_SOLAR_PANEL_STATE_MSG_LEN sizeof(set_solar_panel_state_msg_t);

typedef struct {
    main_bus_hdr_t msg_hdr;
    motor_health_payload_t payload;
    int16 checksum;
} motor_health_msg_t;

#define MOTOR_HEALTH_MSG_LEN sizeof(motor_health_msg_t);

/**************************************************************************
 * CFS MESSAGE DEFINITIONS
 **************************************************************************/
// cFS command structure
typedef struct {
    uint8 CmdHeader[CFE_SB_TLM_HDR_SIZE];
    set_wheel_speed_payload_t payload;
} OS_PACK CFS_Set_Wheel_Speed_Cmd_t;

/**
 * Buffer to hold data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    CFS_Set_Wheel_Speed_Cmd_t set_motor_speed_cmd;
} Set_Motor_Speed_Buffer_t;

#define CFS_SET_WHEEL_SPEED_CMD_LEN sizeof(CFS_Set_Wheel_Speed_Cmd_t);

// cFS command structure
typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
    set_wheel_speed_all_payload_t payload;
} OS_PACK CFS_Set_Wheel_Speed_All_Cmd_t;

/**
 * Buffer to hold data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    CFS_Set_Wheel_Speed_All_Cmd_t set_motor_speed_all_cmd;
} Set_Wheel_Speed_All_Buffer_t;

#define CFS_SET_WHEEL_SPEED_ALL_CMD_LEN sizeof(CFS_Set_Wheel_Speed_All_Cmd_t);

// cFS command structure
typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
    set_motor_pid_payload_t payload;
} OS_PACK CFS_Set_Motor_PID_Cmd_t;

/**
 * Buffer to hold data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    CFS_Set_Motor_PID_Cmd_t set_motor_PID_cmd;
} Set_Motor_Speed_Buffer_All_t;

// Message sizes
#define CFS_SET_MOTOR_PID_CMD_LEN sizeof(CFS_Set_Motor_PID_Cmd_t);

// cFS command structure
typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
    set_motor_pid_payload_t payload;
} OS_PACK CFS_Set_Solar_Panel_State_Cmd_t;

/**
 * Buffer to hold data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    CFS_Set_Solar_Panel_State_Cmd_t set_solar_panel_state_cmd;
} Set_Solar_Panel_State_Buffer_t;

// Message sizes
#define CFS_SET_SOLAR_PANEL_STATE_LEN sizeof(CFS_Set_Solar_Panel_State_Cmd_t);

#endif /* _motor_controller_msgs_h */
