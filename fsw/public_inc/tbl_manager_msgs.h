/****************************************************************
 *
 * @file 		tbl_manager_msg.h
 *
 * @brief 		Housekeeping/telem message type definition for table
 * manager.
 *
 * @version 		1.0
 * @date 		10/20/2021
 *
 * @authors 	Amy Lin, Margaret Hansen
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 ****************************************************************/

#ifndef _tbl_manager_msg_h_
#define _tbl_manager_msg_h_

#include "cfe_sb.h"
#include "common_types.h"

/**
 * Table manager command codes
 */

#define TBL_MANAGER_NOOP_CC 0
#define TBL_MANAGER_RESET_COUNTERS_CC 1
#define TBL_MANAGER_RECEIVE_UPDATE_CC 2

/**
 * Command data structure
 */

typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
} TBL_MANAGER_NoArgsCmd_t;

typedef TBL_MANAGER_NoArgsCmd_t TBL_MANAGER_Noop_t;
typedef TBL_MANAGER_NoArgsCmd_t TBL_MANAGER_ResetCounters_t;
typedef TBL_MANAGER_NoArgsCmd_t TBL_MANAGER_Update_t;

#define TBL_MANAGER_CMD_TLM_LNGTH sizeof(TBL_MANAGER_NoArgsCmd_t)

/***************************************************
/*
** Type definition (TBL_MANAGER housekeeping/telemetry)
*/

typedef struct {
    uint8 TblUpdateCounter;
    uint8 spare[2];
} TBL_MANAGER_HkTlm_Payload_t;

typedef struct {
    uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
    TBL_MANAGER_HkTlm_Payload_t Payload;
} OS_PACK TBL_MANAGER_HkTlm_t;

/**
 * Type definition - buffer for telemetry data before sending
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    TBL_MANAGER_HkTlm_t HkTlm;
} TBL_MANAGER_HkBuffer_t;

#define TBL_MANAGER_HK_TLM_LEN sizeof(TBL_MANAGER_HkTlm_t)
#define TBL_MANAGER_HK_PAYLOAD_LEN sizeof(TBL_MANAGER_HkTlm_Payload_t)

#endif /* _tbl_manager_msg_h_ */

/* EOF */
