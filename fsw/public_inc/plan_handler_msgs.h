/****************************************************************
 *
 * @file        plan_handler_msgs.h
 *
 * @brief       Message types for the plan_handler app
 *
 * @version     1.0
 * @date   	    06/13/2022
 *
 * @authors 	Srinivasan Vijayarangan
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 * @note		This file only contains app specific command and
 * 				telemetry message definitions and command codes.
 ****************************************************************/


#ifndef PLAN_HANDLER_MSG_H
#define PLAN_HANDLER_MSG_H

#include "cfe_sb.h"
#include "common_types.h"

/*
** Plan Handler command codes
*/
#define PLAN_HANDLER_NOOP_CC                0
#define PLAN_HANDLER_RESET_COUNTERS_CC      1
#define PLAN_HANDLER_PROCESS_PLAN_CC        2

/*************************************************************************/
/*
** Type definition (Plan Handler housekeeping)
*/

typedef struct {

    uint8 CommandErrorCounter;
    uint8 CommandCounter;
    uint8 spare[2];
} PLAN_HANDLER_HkTlm_Payload_t;

typedef struct {

    uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE]; /**< \brief Telemetry header */
    PLAN_HANDLER_HkTlm_Payload_t Payload;         /**< \brief Telemetry payload */
} OS_PACK PLAN_HANDLER_HkTlm_t;

/**
 * Type definition - buffer for telemetry data before sending
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    PLAN_HANDLER_HkTlm_t HkTlm;
} PLAN_HANDLER_HkBuffer_t;


/*************************************************************************/
/*
** Type definition (Plan Handler - Information pertaining to a plan table)
*/

typedef struct {

    char filename[64];
    char locaton[64];

} PLAN_HANDLER_PlanInfo_t;

#endif /* PLAN_HANDLER_MSG_H */
