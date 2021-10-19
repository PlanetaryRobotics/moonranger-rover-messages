/****************************************************************
 * 
 * @file 		vc_msg.h
 * 
 * @brief 		The message definitions for the vehicle controller app
 * 
 * @version 	1.0
 * @date 		09/19/2021
 * 
 * @authors 	Ben Kolligs, ...
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 * 
 * @note		This file only contains app specific command and 
 * 				telemetry message definitions and command codes.
 * 
 ****************************************************************/
#ifndef _vehicle_controller_msgs_h_
#define _vehicle_controller_msgs_h_
#include <cinttypes>
extern "C" {
    #include "cfe.h"
}

/**
 * Vehicle App command codes
 */
#define VEHICLE_NOOP_CC               0
#define VEHICLE_RESET_COUNTERS_CC     1
#define VEHICLE_UPDATE_PARAMS_CC      2



typedef struct
{
    uint8              CommandCounter;
    uint8              CommandErrorCounter;
    uint8              WheelCounter;
    uint8              ArcCounter;
    uint8              spare[2];
} VEHICLE_HkTlm_Payload_t;

typedef struct
{
    uint8              TlmHeader[CFE_SB_TLM_HDR_SIZE];
    VEHICLE_HkTlm_Payload_t  Payload;

} OS_PACK VEHICLE_HkTlm_t;

#endif //_vehicle_controller_msgs_h_ header

/* EOF */