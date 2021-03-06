/****************************************************************
 *
 * @file     sunsensor_msgs.h
 *
 * @brief     definitions for all messages related to sunsensor master comms bus
 *
 * @date   		20 Feb 2022
 *
 * @authors 	Tenzin Crouch
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 * @note        Copyright 2022 Carnegie Mellon University. All rights reserved.
 ****************************************************************/

#ifndef _sunsensor_msgs_h
#define _sunsensor_msgs_h

#include "cfe_sb.h"
#include "master_comms_bus_protocol.h"
#include "moonranger_common_types.h"

typedef struct {
    uint32_t alpha;        // alpha angle in degrees
    uint32_t beta;         // beta angle in degrees
    uint32_t sun_detect;   // sun detection percentage
    uint8_t err_code;      // error code as specified in datasheet
    uint8_t status;        // error code as specified in datasheet
    uint16_t __padding;    // ensure 32 bit alignment
} sun_sensor_angles_t;

#define SUNSENSOR_ANGLES_LEN sizeof(sun_sensor_angles_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert((16 == SUNSENSOR_ANGLES_LEN),
              "sun_sensor_angles_t struct size incorrect (expected 16 bytes)");

static_assert(((SUNSENSOR_ANGLES_LEN % 4) == 0),
              "sun_sensor_angles_t struct not 32 bit aligned");
#endif

#define SUN_SENS_UNFILTERED_VOLTS_LEN sizeof(sun_sensor_unfiltered_volts_t)

/**************************************************************************
 * MOONRANGER MESSAGE PAYLOADS
 **************************************************************************/
typedef struct {
    sun_sensor_angles_t angles;
    msp_health_payload_t msp_health;
} sunsensor_telem_payload_t;

#define SUNSENSOR_TELEM_PAYLOAD_LEN sizeof(sunsensor_telem_payload_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert(
    (20 == SUNSENSOR_TELEM_PAYLOAD_LEN),
    "sunsensor_telem_payload_t struct size incorrect (expected 20 bytes)");

static_assert(((SUNSENSOR_TELEM_PAYLOAD_LEN % 4) == 0),
              "sunsensor_telem_payload_t struct not 32 bit aligned");
#endif

/**************************************************************************
 * MASTER COMMS BUS UART MESSAGE DEFINITIONS
 **************************************************************************/
// get sun sensor data message
typedef struct {
    main_bus_hdr_t msg_hdr;
    uint16_t checksum;
    uint16_t __padding;   // for consistent footer on MSPs commands
} get_sunsensor_data_cmd_t;

#define GET_SUNSENSOR_DATA_CMD_LEN sizeof(get_sunsensor_data_cmd_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert(
    (12 == GET_SUNSENSOR_DATA_CMD_LEN),
    "get_sunsensor_data_cmd_t struct size incorrect (expected 12 bytes)");

static_assert(((GET_SUNSENSOR_DATA_CMD_LEN % 4) == 0),
              "get_sunsensor_data_cmd_t struct not 32 bit aligned");
#endif

// sun sensor telem message
typedef struct {
    main_bus_hdr_t msg_hdr;
    sunsensor_telem_payload_t payload;
    uint16_t checksum;
    uint16_t __padding;   // for consistent footer on MSPs commands
} sunsensor_telem_msg_t;

#define SUNSENSOR_TELEM_LEN sizeof(sunsensor_telem_msg_t)

#if (__STDC_VERSION__ >= 201112L)   // check if compiling with C11 or newer
// Preprocessor struct size and alignment checks
static_assert(
    (32 == SUNSENSOR_TELEM_LEN),
    "sunsensor_telem_msg_t struct size incorrect (expected 64 bytes)");
#define GET_SUNSENSOR_TELEM_LEN sizeof(sunsensor_telem_msg_t)

static_assert(((SUNSENSOR_TELEM_LEN % 4) == 0),
              "sunsensor_telem_msg_t struct not 32 bit aligned");
#endif

#endif /* _sunsensor_msgs_h */
