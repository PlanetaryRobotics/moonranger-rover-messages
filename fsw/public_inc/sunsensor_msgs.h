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
    uint32 alpha;     // alpha angle in degrees
    uint32 beta;      // beta angle in degrees
    uint8 err_code;   // error code as specified in datasheet
} sun_sensor_angles_t;

typedef struct {
    uint32 uSSA1F;   // filtered voltage 1
    uint32 uSSA2F;   // filtered voltage 2
    uint32 uSSA3F;   // filtered voltage 3
    uint32 uSSA4F;   // filtered voltage 4
} sun_sensor_filtered_volts_t;

typedef struct {
    uint32 uSSA1;   // unfiltered voltage 1
    uint32 uSSA2;   // unfiltered voltage 2
    uint32 uSSA3;   // unfiltered voltage 3
    uint32 uSSA4;   // unfiltered voltage 4
} sun_sensor_unfiltered_volts_t;

/**************************************************************************
 * MOONRANGER MESSAGE PAYLOADS
 **************************************************************************/
typedef struct {
    sun_sensor_angles_t angles;
    sun_sensor_filtered_volts_t filtered_volts;
    sun_sensor_unfiltered_volts_t unfiltered_volts;
    uint16 reboot_ctr;   // counter of number of times NSS IF has rebooted since
                         // last software load
    uint16 inv_msg_ctr;   // count of invalid messages received by NSS IF
} sunsensor_data_payload_t;

#define SET_SUNSENSOR_DATA_PAYLOAD_LEN sizeof(set_sunsensor_data_payload_t);

/**************************************************************************
 * MASTER COMMS BUS UART MESSAGE DEFINITIONS
 **************************************************************************/
// get sun sensor data message
typedef struct {
    main_bus_hdr_t msg_hdr;
    uint16 checksum;
} get_sunsensor_data_msg_t;

#define GET_SUNSENSOR_DATA_MSG_LEN sizeof(get_sunsensor_data_msg_t);

// sun sensor telem message
typedef struct {
    main_bus_hdr_t msg_hdr;
    sunsensor_data_payload_t payload;
    uint16 checksum;
} sunsensor_telem_msg_t;

#define GET_SUNSENSOR_TELEM_LEN sizeof(sunsensor_telem_msg_t);

#endif /* _sunsensor_msgs_h */
