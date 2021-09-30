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
 ****************************************************************/
#ifndef _VEHICLE_MSG_
#define _VEHICLE_MSG_
#include <cinttypes>
extern "C" {
    #include "cfe.h"
}

/**
 * Vehicle App command codes
 */
#define VEHICLE_NOOP_CC           0
#define VEHICLE_RESET_COUNTERS_CC 1
#define VEHICLE_ACTUATION_CC      2
#define VEHICLE_NAVIGATION_CC 	  3

/**
 * Generic "no arguments" command	
 */ 
typedef struct
{
	uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
} VEHICLE_NoArgsCmd_t;

/*
** The following commands all share the "NoArgs" format
**
** They are each given their own type name matching the command name, which_open_mode
** allows them to change independently in the future without changing the prototype
** of the handler function
*/

typedef struct
{
    uint8              CommandCounter;
    uint8              CommandErrorCounter;
    uint8              spare[2];
} VEHICLE_HkTlm_Payload_t;

typedef struct
{
    uint8              TlmHeader[CFE_SB_TLM_HDR_SIZE];
    VEHICLE_HkTlm_Payload_t  Payload;

} OS_PACK VEHICLE_HkTlm_t;

#endif //_VEHICLE_MSG_ header