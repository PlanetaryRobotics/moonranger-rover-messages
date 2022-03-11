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
    uint16 spi_msg_ctr;   // count of valid messages SPI received by
    // master MSP
    uint16_t __padding;   // ensure messages are 32 bit aligned for consistency
} sensor_telem_payload_t;

#define SENSOR_TELEM_PAYLOAD_LEN sizeof(sensor_telem_payload_t)

/**************************************************************************
 * PERIPHERAL-MASTER COMMS LINK MESSAGE DEFINITIONS
 **************************************************************************/
typedef union {
    get_motor_telem_cmd_t get_motor_telem_cmd;
    set_motor_pid_cmd_t set_motor_pid_cmd;
    set_solar_panel_state_cmd_t set_solar_panel_state_cmd;
    get_nss_telem_cmd_t get_nss_telem_cmd;
    set_nss_params_cmd_t set_nss_params_cmd;
    get_sunsensor_data_cmd_t get_sunsensor_data_cmd;
    get_switch_telem_cmd_t get_switch_telem_cmd;
    set_switch_state_cmd_t set_switch_state_cmd;
    set_switch_state_all_cmd_t set_switch_state_all_cmd;
    reset_switch_cmd_t reset_switch_cmd;
    get_heater_telem_cmd_t get_heater_telem_cmd;
    set_heater_state_cmd_t set_heater_state_cmd;
    set_heater_state_all_cmd_t set_heater_state_all_cmd;
} second_cmd_t;

typedef struct {
    sensor_telem_payload_t payload;
    uint16_t checksum;
    uint16_t __padding;
} peripheral_sensor_telem_msg_t;

#define PERIPHERAL_SENSOR_TELEM_MSG_LEN sizeof(peripheral_sensor_telem_msg_t)

typedef struct {
    set_wheel_speed_all_cmd_t wheel_speed_cmd;
    second_cmd_t second_cmd;
    uint16_t checksum;
    uint8_t
        padding[(PERIPHERAL_SENSOR_TELEM_MSG_LEN - SET_WHEEL_SPEED_ALL_CMD_LEN -
                 sizeof(second_cmd_t) - sizeof(uint16_t))];
} obc_spi_cmd_t;

#define OBC_SPI_CMD_LEN sizeof(obc_spi_cmd_t)

#endif /* master_comms_msgs_h */
