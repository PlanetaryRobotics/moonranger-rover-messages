/****************************************************************
 *
 * @file 		imu_data_msg.h
 *
 * @brief 		The message definitions for the IMU data
 *
 * @version 	1.0
 * @date 		12/06/2021
 *
 * @authors 	Ben Kolligs, ...
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 * @note		This file only contains app specific command and
 * 				telemetry message definitions and command codes.
 *
 ****************************************************************/
#ifndef _imu_data_msg_h_
#define _imu_data_msg_h_

#include "cfe.h"

typedef float float32;
/**
 * Type definition (MOONRANGER IMU packet)
 * This data structure is inspired by the ROS sensor_msgs/Imu.msg file
 */
typedef struct {
    /**
     * The type of the timeStamp is "OS_time_t" because it is set using the
     * return value of the "CFE_PSP_GetTime()" function. If I were to use the
     * "CFE_TIME_GetTime()" function to set the timestamp instead, then the type
     * of the timestamp would have to be "CFE_TIME_SysTime_t". I use
     * "CFE_PSP_GetTime()" because it guarantees monotonic timestamps whereas
     * "CFE_TIME_GetTime()" does not
     */
    OS_time_t timeStamp;

    /* The orientation of the rover is given by a quaternion */
    float32 orientation_x;
    float32 orientation_y;
    float32 orientation_z;
    float32 orientation_w;
    float32 orientation_covariance[9];

    /* Angular velocity is in rad/s */
    float32 angular_velocity_x;
    float32 angular_velocity_y;
    float32 angular_velocity_z;
    float32 angular_velocity_covariance[9];

    /* Linear acceleration is given in m/s^2 */
    float32 linear_acceleration_x;
    float32 linear_acceleration_y;
    float32 linear_acceleration_z;
    float32 linear_acceleration_covariance[9];

    /* Inclinometer is given in m/s^2 */
    float32 inclinometer_x;
    float32 inclinometer_y;
    float32 inclinometer_z;

} MOONRANGER_IMUData_t;

/* Type definition for the IMU Data telemetry */
typedef struct {
    uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
    MOONRANGER_IMUData_t data;
} OS_PACK MOONRANGER_IMUData_Tlm_t;

/**
 * Buffer to hold the IMU Data packet prior to publishing on the software bus
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    MOONRANGER_IMUData_Tlm_t IMUTlm;
} MOONRANGER_IMUDataBuffer_t;

/* Message sizes */
#define MOONRANGER_IMU_DATA_LNGTH sizeof(MOONRANGER_IMUData_t)
#define MOONRANGER_IMU_DATA_TLM_LNGTH sizeof(MOONRANGER_IMUData_Tlm_t)
#endif   //_imu_data_msg_h_ header