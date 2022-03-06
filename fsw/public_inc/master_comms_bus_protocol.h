/****************************************************************
 *
 * @file        master_comms_bus_protocol.h
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

#include "common_types.h"

// note: IDs selected to have minimum 2 bits difference for reliability
typedef enum
{
    E3 = 3,    // 0b00000011  E3 - Master Comms Bus Controller Address
    E5 = 5,    // 0b00000101, E5 - Motor Controller Address
    E6 = 6,    // 0b00000110, E6 - NSS Interface Address
    E7 = 9,    // 0b00001001, E7 - Sun Sensor Interface Address
    E8 = 10,   // 0b00001010, E8 - Power Switching Address
    E9 = 12,   // 0b00001100  E9 - Heater Controller Address
} msp_address_t;

typedef enum
{
    GET_MOTOR_HEALTH_MID = 3,         // 0b00000011,
    SET_MOTOR_SPEED_MID = 5,          // 0b00000101,
    SET_MOTOR_SPEED_ALL_MID = 6,      // 0b00000110,
    SET_MOTOR_PID_MID = 9,            // 0b00001001,
    SET_SOLAR_PANEL_STATE_MID = 10,   // 0b00001010,
    MOTOR_HEALTH_MID = 12,            // 0b00001100,
    GET_NSS_TELEM_MID = 15,           // 0b00001111,
    SET_NSS_PARAMS_MID = 17,          // 0b00010001,
    NSS_TELEM_MID = 20,               // 0b00010100,
    GET_SUN_SENSOR_DATA_MID = 23,     // 0b00010111,
    SUN_SENSOR_TELEM_MID = 24,        // 0b00011000,
    GET_SWITCH_TELEM_MID = 27,        // 0b00011011,
    SET_SWITCH_STATE_MID = 28,        // 0b00011100,
    RESET_SWITCH_MID = 33,            // 0b00100001,
    SWITCH_TELEM_MID = 34,            // 0b00100010,
    GET_HEATER_TELEM_MID = 36,        // 0b00100100,
    SET_HEATER_STATE_MID = 39,        // 0b00100111,
    HEATER_TELEM_MID = 40,            // 0b00101000,
    GET_PERIPHERAL_DATA_MID = 43,     // 0b00101011,
    PERIPHERAL_DATA_MID = 48,         // 0b00110000
} master_comms_bus_msg_id_t;

typedef struct {
    msp_address_t src;                  // source address
    msp_address_t dest;                 // destination address
    uint16_t msg_seq;                   // message sequence number
    master_comms_bus_msg_id_t msg_id;   // message id
    uint8_t len;                        // payload lenght
} main_bus_hdr_t;

typedef struct {
    int16_t reboot_counter;        // the number of times MSP has rebooted
    int16_t invalid_msg_counter;   // the number of times an MSP has received
                                   // invalid msgs
} msp_health_payload_t;

#endif /* _master_comms_bus_protocol_h */
