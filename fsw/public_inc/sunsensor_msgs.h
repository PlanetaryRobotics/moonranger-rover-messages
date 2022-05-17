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
    uint32_t sun_detect;    // sun detection percentage
    uint8_t err_code;       // error code as specified in datasheet
    uint8_t __padding[3];   // ensure 32 bit alignment
} sun_sensor_angles_t;

#define SUNSENSOR_ANGLES_LEN sizeof(sun_sensor_angles_t)

// static_assert((16 == SUNSENSOR_ANGLES_LEN),
//               "sun_sensor_angles_t struct size incorrect (expected 16
//               bytes)");

typedef struct {
    uint32_t uSSA1F;   // filtered voltage 1
    uint32_t uSSA2F;   // filtered voltage 2
    uint32_t uSSA3F;   // filtered voltage 3
    uint32_t uSSA4F;   // filtered voltage 4
} sun_sensor_filtered_volts_t;

#define SUNSENSOR_FILTERED_VOLTS_LEN sizeof(sun_sensor_filtered_volts_t)

// static_assert(
//     (16 == SUNSENSOR_FILTERED_VOLTS_LEN),
//     "sun_sensor_filtered_volts_t struct size incorrect (expected 16 bytes)");

typedef struct {
    uint32_t uSSA1;   // unfiltered voltage 1
    uint32_t uSSA2;   // unfiltered voltage 2
    uint32_t uSSA3;   // unfiltered voltage 3
    uint32_t uSSA4;   // unfiltered voltage 4
} sun_sensor_unfiltered_volts_t;

#define SUNSENSOR_UNFILTERED_VOLTS_LEN sizeof(sun_sensor_unfiltered_volts_t)

// static_assert(
//     (16 == SUNSENSOR_UNFILTERED_VOLTS_LEN),
//     "sun_sensor_unfiltered_volts_t struct size incorrect (expected 16
//     bytes)");

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

// static_assert(
//     (16 == SUNSENSOR_UNFILTERED_VOLTS_LEN),
//     "sun_sensor_unfiltered_volts_t struct size incorrect (expected 16
//     bytes)");
/**************************************************************************
 * MASTER COMMS BUS UART MESSAGE DEFINITIONS
 **************************************************************************/
// get sun sensor data message
typedef struct {
    main_bus_hdr_t msg_hdr;
    uint16_t checksum;
    uint16_t __padding;   // ensure messages are 32 bit aligned for consistency
} get_sunsensor_data_cmd_t;

#define SUNSENSOR_DATA_CMD_LEN sizeof(get_sunsensor_data_cmd_t)

// static_assert(
//     (16 == SUNSENSOR_DATA_CMD_LEN),
//     "get_sunsensor_data_cmd_t struct size incorrect (expected 68 bytes)");

// sun sensor telem message
typedef struct {
    main_bus_hdr_t msg_hdr;
    sunsensor_telem_payload_t payload;
    uint16_t checksum;
    uint16_t __padding;   // ensure messages are 32 bit aligned for consistency
} sunsensor_telem_msg_t;

#define SUNSENSOR_TELEM_LEN sizeof(sunsensor_telem_msg_t)

// static_assert(
//     (68 == SUNSENSOR_TELEM_LEN),
//     "sunsensor_telem_msg_t struct size incorrect (expected 68 bytes)");

#endif /* _sunsensor_msgs_h */
