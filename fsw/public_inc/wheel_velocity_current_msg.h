/****************************************************************
 *
 * @file      wheel_velocity_current_msg.h
 *
 * @brief     Type definition for Moonranger current wheel velocity from the
 *peripheral computer obtained from the wheel sensors
 *
 * @version   1.0
 * @date      Dec 2 2021
 *
 * @authors 	Ben Kolligs
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 ****************************************************************/
#ifndef _wheel_velocity_current_msg_h_
#define _wheel_velocity_current_msg_h_

#include "cfe_sb.h"
#include "common_types.h"
typedef float float32;

/* The Incoming wheel velocity packet */
typedef struct {
    CFE_TIME_SysTime_t timeStamp;
    float32 leftFront;    // rad/s
    float32 rightFront;   // rad/s
    float32 leftBack;     // rad/s
    float32 rightBack;    // rad/s
} MOONRANGER_WheelVelocityCurrent_t;

/* Type definition for wheel velocity telemetry */
typedef struct {
	uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
	MOONRANGER_WheelVelocityCurrent_t data;
} OS_PACK MOONRANGER_WheelVelocityCurrent_Tlm_t;


/**
 * Buffer to hold the wheel packet data prior to sending
 */

typedef union
{
	CFE_SB_Msg_t MsgHdr;
	MOONRANGER_WheelVelocityCurrent_Tlm_t WheelTlm;
} MOONRANGER_WheelBuffer_t;

/* Message sizes */
#define MOONRANGER_WHEEL_VEL_CUR_LNGTH sizeof(MOONRANGER_WheelVelocityCurrent_t)
#define MOONRANGER_WHEEL_VEL_CUR_TLM_LNGTH sizeof(MOONRANGER_WheelVelocityCurrent_Tlm_t)

#endif   //_wheel_velocity_current_msg_h_ header