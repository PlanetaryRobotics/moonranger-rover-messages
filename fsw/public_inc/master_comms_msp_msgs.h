/****************************************************************
 * 
 * @file      TODO
 * 
 * @brief     TODO
 * 
 * @version   TODO
 * @date   		TODO
 * 
 * @authors 	TODO
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 * 
 * @note		This file only contains app specific command and 
 * 				telemetry message definitions and command codes.
 * 
 ****************************************************************/


/*********************************************************************
 * INSTRUCTIONS
 * 
 * This file should contain all the type definitions for app specific messages such as
 * housekeeping / telemetry.
 * 
 * It should also contain definitions for all command messages and command codes.
 * 
 * All message IDs should be placed in moonranger_messageids.h in the appropriately marked location
 * 
 * DELETE THIS BLOCK ONCE COMPLETE
 *******************************************************************/

#ifndef master_comms_msp_msgs_h
#define master_comms_msp_msgs_h

#include <stdint.h>

typedef enum {
    ADDR_ID_PERIPH = 0xE1,
    ADDR_ID_COMM_BUS = 0xE3,
    ADDR_ID_MOTOR = 0xE5,
    ADDR_ID_NSS,
    ADDR_ID_SUN,
    ADDR_ID_PWR_SWITCH,
    ADDR_ID_HEATER
} AddressId_t;

typedef struct {
    int32_t hall_sensor;
    int32_t cmd_velocity;
    int32_t actual_velocity;
    int32_t pwm_voltage;
    int32_t current;
    int32_t p_gain;
    int32_t i_gain;
    int32_t d_gain;
    uint8_t rc_brake;
    uint8_t reserve[3];
} MotorHealthData_t; // 36 bytes

typedef struct {
    uint8_t data[89];
    uint8_t reserve[3];
} NssTelemetry_t;

typedef struct {
    float alpha;
    float beta;
} SunSensorData_t;

typedef struct {
    MotorHealthData_t motor_health[5]; // 36 * 5 = 180 bytes
    NssTelemetry_t nss_tele;           // 92 bytes
    uint32_t switch_status;            // 4 bytes
    uint32_t heater_status;            // 4 bytes
    uint32_t therm_val;                // 4 bytes
    SunSensorData_t sun_data;          // 8 bytes
    uint32_t msp_comm_status;          // 4 bytes
    uint32_t checksum;                 // 4 bytes
} CommBusDataPkt_t; // 300 bytes

typedef struct {
    uint8_t src;
    uint8_t dest;
    uint8_t len;
    uint8_t msg_id;
    int32_t motor_speed[5]; // 20 bytes
    uint8_t reserve[2];
    int16_t crc;
} MotorSpeedCmd_t;

typedef struct {
    uint8_t src;
    uint8_t dest;
    uint16_t len;
    uint8_t msg_id;
    uint8_t reserve[3];
    MotorSpeedCmd_t motor_spd_cmd;
    uint8_t other_payload[sizeof(CommBusDataPkt_t) - 8 - 
                          sizeof(MotorSpeedCmd_t) - 4]; // 260
    uint32_t checksum;
} CommBusCmdMsg_t; // 300 bytes

#endif /* master_comms_msp_msgs_h */