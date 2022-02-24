/****************************************************************
 *
 * @file        master_comms_bus_protocol.h.h
 *
 * @brief       definitions for master comms bus protocol
 *
 * @date   		20 Feb 2022
 *
 * @authors 	Tenzin Crouch
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 * @note		This file contains all common definitiosn for the master
 *              comms bus protocol.
 *
 * @note        Copyright 2022 Carnegie Mellon University. All rights reserved.
 *
 ****************************************************************/

#ifndef _master_comms_bus_protocol_h
#define _master_comms_bus_protocol_h

// note: IDs selected to have minimum 2 bits difference for reliability
typedef enum
{
    E3 = 0b00000011,   // E3 - Master Comms Bus Controller Address
    E5 = 0b00000101,   // E5 - Motor Controller Address
    E6 = 0b00000110,   // E6 - NSS Interface Address
    E7 = 0b00001001,   // E7 - Sun Sensor Interface Address
    E8 = 0b00001010,   // E8 - Power Switching Address
    E9 = 0b00001100    // E9 - Heater Controller Address
} uart_address_t;

typedef enum
{
    GET_MOTOR_HEALTH_MID = 0b00000011,
    SET_MOTOR_SPEED_MID = 0b00000101,
    SET_MOTOR_SPEED_ALL_MID = 0b00000110,
    SET_MOTOR_PID_MID = 0b00001001,
    SET_SOLAR_PANEL_STATE_MID = 0b00001010,
    MOTOR_HEALTH_MID = 0b00001100,
    GET_NSS_TELEM_MID = 0b00001111,
    SET_NSS_PARAMS_MID = 0b00010001,
    NSS_TELEM_MID = 0b00010100,
    GET_SUN_SENSOR_DATA_MID = 0b00010111,
    SUN_SENSOR_TELEM_MID = 0b00011000,
    GET_SWITCH_TELEM_MID = 0b00011011,
    SET_SWITCH_STATE_MID = 0b00011100,
    RESET_SWITCH_MID = 0b00100001,
    SWITCH_TELEM_MID = 0b00100010,
    GET_HEATER_TELEM_MID = 0b00100100,
    SET_HEATER_STATE_MID = 0b00100111,
    HEATER_TELEM_MID = 0b00101000,
    GET_PERIPHERAL_DATA_MID = 0b00101011,
    PERIPHERAL_DATA_MID = 0b00110000
} master_comms_bus_msg_id_t;

#include "common_types.h"
typedef struct {
    uart_address_t src;                 // source address
    uart_address_t dest;                // destination address
    uint16 msg_seq;                     // message sequence numebr
    master_comms_bus_msg_id_t msg_id;   // message id
    uint8 len;                          // payload lenght
} main_bus_hdr_t;

typedef struct {
    int16 reboot_counter;        // the number of times MSP has rebooted
    int16 invalid_msg_counter;   // the number of times an MSP has received
                                 // invalid msgs
} msp_health_payload_t;

#endif /* _master_comms_bus_protocol_h */
