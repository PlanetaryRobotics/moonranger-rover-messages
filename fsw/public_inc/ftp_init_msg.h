/****************************************************************
 *
 * @file      ftp_init_msg.h
 *
 * @brief     Type definition for Moonranger FTP Init message
 *
 * @authors 	Ethan Muchnik
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 ****************************************************************/

#ifndef _ftp_init_h_
#define _ftp_init_h_

#include "cfe_sb.h"
#include "common_types.h"

typedef struct {
    CFE_TIME_SysTime_t timeStamp;
} MOONRANGER_FTP_Init_t;

/**
 * Type definition (MOONRANGER Init telemetry)
 * @note includes CFS TLM Header with timestamp
 */
typedef struct {
    uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
    MOONRANGER_FTP_Init_t data;
} OS_PACK MOONRANGER_FTP_Init_Tlm_t;

/**
 * Buffer to hold init data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    MOONRANGER_FTP_Init_Tlm_t FTPSyncTlm;
} MOONRANGER_FTP_Init_Buffer_t;

// Message sizes
#define MOONRANGER_FTP_INIT_LNGTH sizeof(MOONRANGER_FTP_Init_t)
#define MOONRANGER_FTP_INIT_TLM_LNGTH sizeof(MOONRANGER_FTP_Init_Tlm_t)

#endif /* ftp_init_all_h_ */
