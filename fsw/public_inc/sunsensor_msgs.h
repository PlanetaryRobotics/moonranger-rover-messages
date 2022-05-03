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
    uint32_t alpha;         // alpha angle in degrees
    uint32_t beta;          // beta angle in degrees
    uint8_t err_code;       // error code as specified in datasheet
    uint8_t __padding[3];   // ensure 32 bit alignment
} sun_sensor_angles_t;

#define SUN_SENS_ANGLES_LEN sizeof(sun_sensor_angles_t)

// Preprocessor check of struct size
static_assert((12 == SUN_SENS_ANGLES_LEN),
              "sun_sensor_angles_t struct size incorrect (expected 12 bytes)");

typedef struct {
    uint32_t uSSA1F;   // filtered voltage 1
    uint32_t uSSA2F;   // filtered voltage 2
    uint32_t uSSA3F;   // filtered voltage 3
    uint32_t uSSA4F;   // filtered voltage 4
} sun_sensor_filtered_volts_t;

typedef struct {
    uint32_t uSSA1;   // unfiltered voltage 1
    uint32_t uSSA2;   // unfiltered voltage 2
    uint32_t uSSA3;   // unfiltered voltage 3
    uint32_t uSSA4;   // unfiltered voltage 4
} sun_sensor_unfiltered_volts_t;

/**************************************************************************
 * MOONRANGER MESSAGE PAYLOADS
 **************************************************************************/
typedef struct {
    sun_sensor_angles_t angles;
    sun_sensor_filtered_volts_t filtered_volts;
    sun_sensor_unfiltered_volts_t unfiltered_volts;
    uint8_t status;         // flag used to indicate valid/invalid data from SS
    uint8_t __padding[3];   // ensure 32 bit alignment
    msp_health_payload_t msp_health;
} sunsensor_telem_payload_t;

#define SUNSENSOR_TELEM_PAYLOAD_LEN sizeof(sunsensor_telem_payload_t)

// Preprocessor check of struct size
static_assert(
    (52 == SUNSENSOR_TELEM_PAYLOAD_LEN),
    "sunsensor_telem_payload_t struct size incorrect (expected 52 bytes)");

/**************************************************************************
 * MASTER COMMS BUS UART MESSAGE DEFINITIONS
 **************************************************************************/
// get sun sensor data message
typedef struct {
    main_bus_hdr_t msg_hdr;
    uint16_t checksum;
    uint16_t __padding;   // ensure messages are 32 bit aligned for consistency
} get_sunsensor_data_cmd_t;

#define GET_SUNSENSOR_DATA_CMD_LEN sizeof(get_sunsensor_data_cmd_t)

// Preprocessor check of struct size
static_assert(
    (12 == GET_SUNSENSOR_DATA_CMD_LEN),
    "get_sunsensor_data_cmd_t struct size incorrect (expected 12 bytes)");

// sun sensor telem message
typedef struct {
    main_bus_hdr_t msg_hdr;
    sunsensor_telem_payload_t payload;
    uint16_t checksum;
    uint16_t __padding;   // ensure messages are 32 bit aligned for consistency
} sunsensor_telem_msg_t;

#define SUNSENSOR_TELEM_LEN sizeof(sunsensor_telem_msg_t)

// Preprocessor check of struct size
static_assert(
    (64 == SUNSENSOR_TELEM_LEN),
    "sunsensor_telem_msg_t struct size incorrect (expected 64 bytes)");
#define GET_SUNSENSOR_TELEM_LEN sizeof(sunsensor_telem_msg_t)

#endif /* _sunsensor_msgs_h */
