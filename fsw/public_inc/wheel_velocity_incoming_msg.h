/****************************************************************
 *
 * @file      wheel_velocity_incoming_msg.h
 *
 * @brief     Type definition for Moonranger incoming wheel velocity from the
 *peripheral computer
 *
 * @version   1.0
 * @date      Dec 2 2021
 *
 * @authors 	Ben Kolligs
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 ****************************************************************/
#ifndef _wheel_velocity_incoming_msg_h_
#define _wheel_velocity_incoming_msg_h_

#include "cfe_sb.h"
#include "common_types.h"

/* The Incoming wheel velocity packet */
typedef struct {
    CFE_TIME_SysTime_t timeStamp;
    float64 leftFront;    // rad/s
    float64 rightFront;   // rad/s
    float64 leftBack;     // rad/s
    float64 rightBack;    // rad/s
} MOONRANGER_WheelVelocityIncoming_t;

/* Type definition for wheel velocity telemetry */
typedef struct {
	uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
	MOONRANGER_WheelVelocityIncoming_t data;
} OS_PACK MOONRANGER_WheelVelocityIncoming_Tlm_t;

/* Message sizes */
#define MOONRANGER_WHEEL_INC_LNGTH sizeof(MOONRANGER_WheelVelocityIncoming_t)
#define MOONRANGER_WHEEL_INC_TLM_LNGTH sizeof(MOONRANGER_WheelVelocityIncoming_Tlm_t)

#endif   //_wheel_velocity_incoming_msg_h_ header