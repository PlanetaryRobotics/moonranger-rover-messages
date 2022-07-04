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

#define WHEEL_MOTOR_HEALTH_LEN sizeof(wheel_motor_health_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert((24 == WHEEL_MOTOR_HEALTH_LEN),
              "wheel_motor_health_t struct size incorrect (expected 24 bytes)");

static_assert(((WHEEL_MOTOR_HEALTH_LEN % 4) == 0),
              "wheel_motor_health_t struct not 32 bit aligned");
#endif

typedef struct {
    volatile int16_t motor_actual_velocity;    // The actual velocity
    volatile int16_t motor_current;            // The current drawn by the motor
    volatile int8_t encoder_position;          // the encoder reading
    volatile solar_panel_state_t curr_state;   // the solar panel state
    uint16_t __padding;                        // ensure 32 bit alignment
} solar_panel_motor_health_t;

#define SOLAR_PANEL_MOTOR_HEALTH_LEN sizeof(solar_panel_motor_health_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert(
    (8 == SOLAR_PANEL_MOTOR_HEALTH_LEN),
    "solar_panel_motor_health_t struct size incorrect (expected 8 bytes)");

static_assert(((SOLAR_PANEL_MOTOR_HEALTH_LEN % 4) == 0),
              "solar_panel_motor_health_t struct not 32 bit aligned");
#endif

/**************************************************************************
 * MOONRANGER MESSAGE PAYLOADS
 **************************************************************************/
// set motor speed all command
typedef struct {
    int16_t motor1_speed;
    int16_t motor2_speed;
    int16_t motor3_speed;
    int16_t motor4_speed;
} set_wheel_speed_all_payload_t;

#define SET_WHEEL_SPEED_ALL_PAYLOAD_LEN sizeof(set_wheel_speed_all_payload_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert(
    (8 == SET_WHEEL_SPEED_ALL_PAYLOAD_LEN),
    "set_wheel_speed_all_payload_t struct size incorrect (expected 8 bytes)");

static_assert(((SET_WHEEL_SPEED_ALL_PAYLOAD_LEN % 4) == 0),
              "set_wheel_speed_all_payload_t struct not 32 bit aligned");
#endif

// set motor PID command
typedef struct {
    pid_gains_t motor_pid_gains;
    motor_id_t motor_id;
    uint8_t __padding[3];   // ensure 16 bit alignment
} set_motor_pid_payload_t;

#define SET_MOTOR_PID_PAYLOAD_LEN sizeof(set_motor_pid_payload_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert(
    (16 == SET_MOTOR_PID_PAYLOAD_LEN),
    "set_motor_pid_payload_t struct size incorrect (expected 16 bytes)");

static_assert(((SET_MOTOR_PID_PAYLOAD_LEN % 4) == 0),
              "set_motor_pid_payload_t struct not 32 bit aligned");
#endif

// set solar panel state command
typedef struct {
    solar_panel_state_t panel_state;
    uint8_t __padding;   // ensure 16 bit alignment
} set_solar_panel_state_payload_t;

#define SET_SOLAR_PANEL_STATE_PAYLOAD_LEN \
    sizeof(set_solar_panel_state_payload_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert(
    (2 == SET_SOLAR_PANEL_STATE_PAYLOAD_LEN),
    "set_solar_panel_state_payload_t struct size incorrect (expected 2 bytes)");

static_assert(((SET_SOLAR_PANEL_STATE_PAYLOAD_LEN % 2) == 0),
              "set_solar_panel_state_payload_t struct not 16 bit aligned");
#endif

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

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert(
    (108 == MOTOR_HEALTH_PAYLOAD_LEN),
    "motor_health_payload_t struct size incorrect (expected 108 bytes)");

static_assert(((MOTOR_HEALTH_PAYLOAD_LEN % 4) == 0),
              "motor_health_payload_t struct not 32 bit aligned");
#endif

/**************************************************************************
 * MASTER COMMS BUS UART MESSAGE DEFINITIONS
 **************************************************************************/
typedef struct {
    main_bus_hdr_t msg_hdr;
    uint16_t checksum;
    uint16_t __padding;   // for consistent footer on MSPs commands
} get_motor_telem_cmd_t;

#define GET_MOTOR_TELEM_CMD_LEN sizeof(get_motor_telem_cmd_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert(
    (12 == GET_MOTOR_TELEM_CMD_LEN),
    "motor_health_payload_t struct size incorrect (expected 12 bytes)");
#endif

static_assert(((GET_MOTOR_TELEM_CMD_LEN % 4) == 0),
              "set_motor_pid_payload_t struct not 32 bit aligned");

typedef struct {
    main_bus_hdr_t msg_hdr;
    set_wheel_speed_all_payload_t payload;
    uint16_t checksum;
    uint16_t __padding;   // for consistent footer on MSPs commands
} set_wheel_speed_all_cmd_t;

#define SET_WHEEL_SPEED_ALL_CMD_LEN sizeof(set_wheel_speed_all_cmd_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert(
    (20 == SET_WHEEL_SPEED_ALL_CMD_LEN),
    "set_wheel_speed_all_cmd_t struct size incorrect (expected 20 bytes)");

static_assert(((SET_WHEEL_SPEED_ALL_CMD_LEN % 4) == 0),
              "set_wheel_speed_all_cmd_t struct not 32 bit aligned");
#endif

typedef struct {
    main_bus_hdr_t msg_hdr;
    set_motor_pid_payload_t payload;
    uint16_t checksum;
    uint16_t __padding;   // for consistent footer on MSPs commands
} set_motor_pid_cmd_t;

#define SET_MOTOR_PID_CMD_LEN sizeof(set_motor_pid_cmd_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert((28 == SET_MOTOR_PID_CMD_LEN),
              "set_motor_pid_cmd_t struct size incorrect (expected 28 bytes)");

static_assert(((SET_MOTOR_PID_CMD_LEN % 4) == 0),
              "set_motor_pid_cmd_t struct not 32 bit aligned");
#endif

typedef struct {
    main_bus_hdr_t msg_hdr;
    set_solar_panel_state_payload_t payload;
    uint16_t checksum;
    uint16_t __padding;   // for consistent footer on MSPs commands
} set_solar_panel_state_cmd_t;

#define SET_SOLAR_PANEL_STATE_CMD_LEN sizeof(set_solar_panel_state_cmd_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert(
    (14 == SET_SOLAR_PANEL_STATE_CMD_LEN),
    "set_solar_panel_state_cmd_t struct size incorrect (expected 14 bytes)");

static_assert(((SET_SOLAR_PANEL_STATE_CMD_LEN % 2) == 0),
              "set_solar_panel_state_cmd_t struct not 16 bit aligned");
#endif

typedef struct {
    main_bus_hdr_t msg_hdr;
    motor_health_payload_t payload;
    int16_t checksum;
    uint16_t __padding;   // ensure messages are 32 bit aligned for consistency
} motor_health_msg_t;

#define MOTOR_HEALTH_MSG_LEN sizeof(motor_health_msg_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert((120 == MOTOR_HEALTH_MSG_LEN),
              "motor_health_msg_t struct size incorrect (expected 120 bytes)");

static_assert(((MOTOR_HEALTH_MSG_LEN % 4) == 0),
              "motor_health_msg_t struct not 32 bit aligned");
#endif

#endif /* _motor_controller_msgs_h */
