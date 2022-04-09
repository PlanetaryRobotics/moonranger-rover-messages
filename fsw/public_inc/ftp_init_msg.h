/****************************************************************
 *
 * @file      ftp_init_msg.h
 *
 * @brief     Type definition for Moonranger FTP sync message
 *
 * @version   1.0
 * @date      2 March 2021
 *
 * @authors 	Ethan Muchnik
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 ****************************************************************/

#ifndef _ftp_init_h_
#define _ftp_init_h_

#include "cfe_sb.h"
#include "common_types.h"

/*
** Type definition (MOONRANGER pose)
*/

// TODO move this to common location
typedef double float64;

typedef struct {
    CFE_TIME_SysTime_t timeStamp;
} MOONRANGER_FTP_Init_t;

/**
 * Type definition (MOONRANGER pose telemetry)
 * @note includes CFS TLM Header with timestamp
 */
typedef struct {
    uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
    MOONRANGER_FTP_Init_t data;
} OS_PACK MOONRANGER_FTP_Init_Tlm_t;

/**
 * Buffer to hold pose data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    MOONRANGER_FTP_Init_Tlm_t FTPSyncTlm;
} MOONRANGER_FTP_Init_Buffer_t;

// Message sizes
#define MOONRANGER_FTP_INIT_LNGTH sizeof(MOONRANGER_FTP_Init_t)
#define MOONRANGER_FTP_INIT_TLM_LNGTH sizeof(MOONRANGER_FTP_Init_Tlm_t)

#endif /* ftp_send_all_h_ */
