/****************************************************************
 *
 * @file 		mapper_msg.h
 *
 * @brief 		Message typedefs for mapper app.
 *
 * @version 		1.0
 * @date 		10/05/2021
 *
 * @authors 		Margaret Hansen
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 * @note		This file only contains app specific command and
 * 				telemetry message definitions and command codes.
 *
 ****************************************************************/

#ifndef _mapper_msgs_h_
#define _mapper_msgs_h_

#include "cfe_sb.h"
#include "common_types.h"

/*
** Mapper app command codes
*/

#define MAPPER_NOOP_CC 0
#define MAPPER_RESET_COUNTERS_CC 1

typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
} MAPPER_NoArgsCmd_t;

typedef MAPPER_NoArgsCmd_t MAPPER_Noop_t;
typedef MAPPER_NoArgsCmd_t MAPPER_ResetCounters_t;

#define MAPPER_CMD_LNGTH sizeof(MAPPER_NoArgsCmd_t)

/***************************************************/
/*
** Type definition (MAPPER housekeeping/telemetry)
*/

typedef struct {
    uint8 CommandCounter;
    uint8 CommandErrorCounter;
    uint8 PoseCounter;
    uint8 ValidPoseCounter;
    uint8 GoalCounter;
    uint8 PclCounter;
    uint8 MeshCounter;
    uint8 spare[2];
} MAPPER_HkTlm_Payload_t;

typedef struct {
    uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
    MAPPER_HkTlm_Payload_t Payload;
} OS_PACK MAPPER_HkTlm_t;

/**
 * Type definition - buffer for telemetry data before sending
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    MAPPER_HkTlm_t HkTlm;
} MAPPER_HkBuffer_t;

/***************************************************/
/*
** Type definition (MAPPER mesh saved buffer)
*/

typedef struct {
    uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
} OS_PACK MAPPER_MeshTlm_t;

typedef union {
    CFE_SB_Msg_t MsgHdr;
    MAPPER_MeshTlm_t MeshTlm;
} MAPPER_MeshBuffer_t;

#define MAPPER_HK_PAYLOAD_LNGTH sizeof(MAPPER_HkTlm_Payload_t)
#define MAPPER_HK_TLM_LNGTH sizeof(MAPPER_HkTlm_t)

#endif /* _mapper_msgs_h_*/

/* EOF */
