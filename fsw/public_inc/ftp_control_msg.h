/****************************************************************
 *
 * @file      ftp_control_msg.h
 *
 * @brief     Type definition for Moonranger FTP control message
 *
 * @version   1.0
 * @date      2 March 2021
 *
 * @authors 	Ethan Muchnik
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 ****************************************************************/

#ifndef _pose_msg_h_
#define _pose_msg_h_

#include "cfe_sb.h"
#include "common_types.h"

/*
** Type definition (MOONRANGER pose)
*/

// TODO move this to common location
typedef double float64;

typedef struct {
    CFE_TIME_SysTime_t timeStamp;
    uint8 firstFlag;        // s,d,r -> 0,1,2
    char localPath[512];    // path to local file
    char landerPath[512];   // path to server file
} MOONRANGER_FTP_Control_t;

/**
 * Type definition (MOONRANGER pose telemetry)
 * @note includes CFS TLM Header with timestamp
 */
typedef struct {
    uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
    MOONRANGER_FTP_Control_t data;
} OS_PACK MOONRANGER_FTP_Control_Tlm_t;

/**
 * Buffer to hold pose data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    MOONRANGER_FTP_Control_Tlm_t FTPControlTlm;
} MOONRANGER_FTP_ControlBuffer_t;

// Message sizes
#define MOONRANGER_FTP_CONTROL_LNGTH sizeof(MOONRANGER_FTP_Control_t)
#define MOONRANGER_FTP_CONTROL_TLM_LNGTH sizeof(MOONRANGER_FTP_Control_Tlm_t)

#endif /* _pose_msg_h_ */
