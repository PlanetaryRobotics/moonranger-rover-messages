/****************************************************************
 * 
 * @file 		pe_msg.h
 * 
 * @brief 		The message definitions for the pose estimation app
 * 
 * @version 	1.0
 * @date 		10/8/2021
 * 
 * @authors 	Ben Kolligs, ...
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 * 
 * @note		This file only contains app specific command and 
 * 				telemetry message definitions and command codes.
 * 
 ****************************************************************/
#ifndef _pose_estimator_msgs_h_
#define _pose_estimator_msgs_h_


#include <cinttypes>
extern "C" {
	#include "cfe.h"
}


/**
 * app command codes
 */
#define POSE_NOOP_CC               0
#define POSE_RESET_COUNTERS_CC     1
#define POSE_UPDATE_PARAMS_CC      2

/***************************************************
/*
** Type definition Housekeeping Telemetry
*/
typedef struct
{
    uint8              CommandCounter;
    uint8              CommandErrorCounter;
    uint8              WheelCounter;
    uint8              ArcCounter;
    uint8              spare[2];
} POSE_HkTlm_Payload_t;

typedef struct
{
    uint8              TlmHeader[CFE_SB_TLM_HDR_SIZE];
    POSE_HkTlm_Payload_t  Payload;

} OS_PACK POSE_HkTlm_t;

typedef struct 
{
	CFE_SB_Msg_t	MsgHdr;
	POSE_HkTlm_t	HkTlm;
} POSE_HkBuffer_t;

#endif //_pose_estimator_msgs_h_ header

/* EOF */