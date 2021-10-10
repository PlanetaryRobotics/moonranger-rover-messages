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
 ****************************************************************/
#ifndef _pe_msg_h_
#define _pe_msg_h_


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
#endif //_pe_msg_h_ header

/* EOF */