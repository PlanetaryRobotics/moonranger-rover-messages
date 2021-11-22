/****************************************************************
 * 
 * @file 		imu_driver_msgs.h
 * 
 * @brief 		The message definitions for the IMU driver application
 * 
 * @version 	1.0
 * @date 		11/16/2021
 * 
 * @authors 	Ben Kolligs, ...
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 * 
 * @note		This file only contains app specific command and 
 * 				telemetry message definitions and command codes.
 * 
 ****************************************************************/
#ifndef _imu_driver_msgs_h_
#define _imu_driver_msgs_h_


#include "cfe.h"


/**
 * app command codes
 */
#define IMU_DRIVER_NOOP_CC               0
#define IMU_DRIVER_RESET_COUNTERS_CC     1
#define IMU_DRIVER_UPDATE_PARAMS_CC      2

/***************************************************
/*
** Type definition Housekeeping Telemetry
*/
typedef struct
{
    uint8              CommandCounter;
    uint8              CommandErrorCounter;
    uint8              spare[2];
} IMU_DRIVER_HkTlm_Payload_t;

typedef struct
{
    uint8              TlmHeader[CFE_SB_TLM_HDR_SIZE];
    IMU_DRIVER_HkTlm_Payload_t  Payload;

} OS_PACK IMU_DRIVER_HkTlm_t;
#endif //_imu_driver_msgs_h_ header

/* EOF */
