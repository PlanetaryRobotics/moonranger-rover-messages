/****************************************************************
 *
 * @file      planner_msg.h
 *
 * @brief     Message types for the planner app
 *
 * @version   1.0
 * @date   		10/13/2021
 *
 * @authors 	Abby Breitfeld
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 * @note		This file only contains app specific command and
 * 				telemetry message definitions and command codes.
 ****************************************************************/
#ifndef __planner_msgs_h
#define _planner_msgs_h

#include "cfe_sb.h"
#include "common_types.h"

/**
 * PLANNER command codes
 */
#define PLANNER_NOOP_CC 0
#define PLANNER_RESET_COUNTERS_CC 1
#define PLANNER_PROCESS_CC 2
#define PLANNER_START_CC 3
#define PLANNER_STOP_CC 4
#define PLANNER_EVAL_TRIGGER_CC 5

/**
 * Type definition (generic "no arguments" command)
 */
typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];

} PLANNER_NoArgsCmd_t;

/**
 * The following commands all share the "NoArgs" format
 *
 * They are each given their own type name matching the command name,
 * which_open_mode allows them to change independently in the future without
 * changing the prototype of the handler function
 */
typedef PLANNER_NoArgsCmd_t PLANNER_Noop_t;
typedef PLANNER_NoArgsCmd_t PLANNER_ResetCounters_t;
typedef PLANNER_NoArgsCmd_t PLANNER_Process_t;
typedef PLANNER_NoArgsCmd_t PLANNER_Start_t;
typedef PLANNER_NoArgsCmd_t PLANNER_Stop_t;
typedef PLANNER_NoArgsCmd_t PLANNER_Eval_Trigger_t;

#define PLANNER_CMD_TLM_LNGTH sizeof(PLANNER_NoArgsCmd_t)

/*************************************************************************/

/**
 * Type definition (PLANNER App housekeeping)
 */

#define PLANNER_HK_PAYLOAD_LEN sizeof(PLANNER_HkTlm_Payload_t)
#define PLANNER_HK_TLM_LEN sizeof(PLANNER_HkTlm_t)

typedef struct {
    uint8 CommandErrorCounter;
    uint8 CommandCounter;
    uint8 GoalCounter;
    uint8 PoseCounter;
    uint8 ValidPoseCounter;
    uint8 MeshCounter;

} PLANNER_HkTlm_Payload_t;

typedef struct {
    uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
    PLANNER_HkTlm_Payload_t Payload;

} OS_PACK PLANNER_HkTlm_t;

/**
 * Buffer to hold telemetry data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union
{
    CFE_SB_Msg_t         MsgHdr;
    PLANNER_HkTlm_t      HkTlm;
} PLANNER_HkBuffer_t;

#endif /* _planner_msgs_h */

/************************/
/*  End of File Comment */
/************************/