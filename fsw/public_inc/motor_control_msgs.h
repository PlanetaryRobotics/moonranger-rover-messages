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

#include "master_comms_bus_protocol.h"

typedef enum
{
    MOTOR_1 = 3,    // 0b00000011,
    MOTOR_2 = 5,    // 0b00000101,
    MOTOR_3 = 6,    // 0b00001010,
    MOTOR_4 = 15,   // 0b00001111
} motor_id_t;

typedef enum
{
    RAISED = 3,    // 0b00000011,
    LOWERED = 5,   // 0b00000101
} solar_panel_state_t;

typedef enum
{
    ENABLE = 3,    // 0b00000011,
    DISABLE = 5,   // 0b00000101
} brake_state_t;

typedef struct {
    int32_t p_gain;   // p gain scaled down by 100
    int32_t i_gain;   // i gain scaled down by 100
    int32_t d_gain;   // d gain scaled down by 100
} pid_gains_t;

typedef struct {
    volatile pid_gains_t motor_gains;            // The current motor PID gains
    volatile int32_t motor_hall_sensor;          // the ticks from hall sensor
    volatile int16_t motor_commanded_velocity;   // The commanded velocity
    volatile int16_t motor_actual_velocity;      // The actual velocity
    volatile int16_t motor_pwm;                  // The motor pwm duty cycle
    volatile int16_t motor_current;   // The current drawn by the motor
} wheel_motor_health_t;

typedef struct {
    volatile int16_t motor_actual_velocity;   // The actual velocity
    volatile int16_t motor_current;           // The current drawn by the motor
    volatile int8_t encoder_position;         // the encoder reading
    volatile int8_t curr_state;               // the solar panel state
} solar_panel_motor_health_t;
/**************************************************************************
 * MOONRANGER MESSAGE PAYLOADS
 **************************************************************************/

// set motor speed command
typedef struct {
    int16_t motor_speed;
    motor_id_t motor_id;
} set_wheel_speed_payload_t;

#define SET_MOTOR_SPEED_PAYLOAD_LEN sizeof(set_wheel_speed_payload_t)

// set motor speed all command
typedef struct {
    int16_t motor1_speed;
    int16_t motor2_speed;
    int16_t motor3_speed;
    int16_t motor4_speed;
} set_wheel_speed_all_payload_t;

#define SET_MOTOR_SPEED_ALL_PAYLOAD_LEN sizeof(set_wheel_speed_all_payload_t)

// set motor PID command
typedef struct {
    pid_gains_t motor_pid_gains;
    motor_id_t motor_id;
} set_motor_pid_payload_t;

#define SET_MOTOR_PID_PAYLOAD_LEN sizeof(set_motor_pid_payload_t)

// set solar panel state command
typedef struct {
    solar_panel_state_t panel_state;
} set_solar_panel_state_payload_t;

#define SET_SOLAR_PANEL_STATE_PAYLOAD_LEN \
    sizeof(set_solar_panel_state_payload_t)

// motor health message
typedef struct {
    wheel_motor_health_t motor_1;
    wheel_motor_health_t motor_2;
    wheel_motor_health_t motor_3;
    wheel_motor_health_t motor_4;
    solar_panel_motor_health_t motor_5;
    msp_health_payload_t msp_health;
} motor_health_payload_t;

#define MOTOR_HEALTH_PAYLOAD_LEN sizeof(motor_health_payload_t)

/**************************************************************************
 * MASTER COMMS BUS UART MESSAGE DEFINITIONS
 **************************************************************************/
// get motor health command
typedef struct {
    main_bus_hdr_t msg_hdr;
    uint16_t checksum;
} get_motor_health_msg_t;

#define GET_MOTOR_HEALTH_MSG_LEN sizeof(get_motor_health_msg_t)

typedef struct {
    main_bus_hdr_t msg_hdr;
    set_wheel_speed_payload_t payload;
    uint16_t checksum;
} set_motor_speed_msg_t;

#define SET_MOTOR_SPEED_MSG_LEN sizeof(set_motor_speed_msg_t)

typedef struct {
    main_bus_hdr_t msg_hdr;
    set_wheel_speed_all_payload_t payload;
    uint16_t checksum;
} set_motor_speed_all_msg_t;

#define SET_MOTOR_SPEED_ALL_MSG_LEN sizeof(set_motor_speed_all_msg_t)

typedef struct {
    main_bus_hdr_t msg_hdr;
    set_motor_pid_payload_t payload;
    uint16_t checksum;
} set_motor_pid_msg_t;

#define SET_MOTOR_PID_MSG_LEN sizeof(set_motor_pid_msg_t)

typedef struct {
    main_bus_hdr_t msg_hdr;
    set_solar_panel_state_payload_t payload;
    uint16_t checksum;
} set_solar_panel_state_msg_t;

#define SET_SOLAR_PANEL_STATE_MSG_LEN sizeof(set_solar_panel_state_msg_t)

typedef struct {
    main_bus_hdr_t msg_hdr;
    motor_health_payload_t payload;
    int16_t checksum;
} motor_health_msg_t;

#define MOTOR_HEALTH_MSG_LEN sizeof(motor_health_msg_t)

#endif /* _motor_controller_msgs_h */
