/****************************************************************
 *
 * @file     master_comms_msgs.h
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

#ifndef master_comms_msgs_h
#define master_comms_msgs_h

#include "heater_control_msgs.h"
#include "master_comms_bus_protocol.h"
#include "moonranger_common_types.h"
#include "motor_control_msgs.h"
#include "nss_msgs.h"
#include "power_switching_msgs.h"
#include "sunsensor_msgs.h"

// SPI header definition
typedef struct {
    uint16 msg_seq;
    master_comms_bus_msg_id_t msg_id;
} periph_main_link_hdr_t;

/**************************************************************************
 * MOONRANGER MESSAGE PAYLOADS
 **************************************************************************/
typedef struct {
    motor_health_payload_t motor_health_data;
    nss_telem_payload_t nss_telem;
    sunsensor_telem_payload_t sunsensor_data;
    power_switch_telem_payload_t power_switch_telem;
    heater_telem_payload_t heater_telem;
    msp_health_payload_t msp_health;
    uint16 inv_spi_msg_ctr;   // count of invalid messages SPI received by
                              // master MSP
} sensor_telem_payload_t;

#define SENSOR_TELEM_PAYLOAD_LEN sizeof(sensor_telem_payload_t);

/**************************************************************************
 * PERIPHERAL-MASTER COMMS LINK MESSAGE DEFINITIONS
 **************************************************************************/
typedef struct {
    periph_main_link_hdr_t msg_hdr;
    uint16 checksum;
} get_peripheral_sensor_telem_msg_t;

#define GET_PERIPHERAL_SENSOR_TELEM_MSG_LEN \
    sizeof(get_peripheral_sensor_telem_msg_t);

typedef struct {
    periph_main_link_hdr_t msg_hdr;
    sensor_telem_payload_t payload;
    uint16 checksum;
} peripheral_sensor_telem_msg_t;

#define SENSOR_PERIPHERAL_TELEM_MSG_LEN sizeof(peripheral_sensor_telem_msg_t);

#endif /* master_comms_msgs_h */