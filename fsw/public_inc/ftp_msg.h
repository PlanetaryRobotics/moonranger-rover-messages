/****************************************************************
 *
 * @file      ftp_msg.h
 *
 * @brief     Message types for the ftp app
 *
 * @version     1.0
 * @date   		3/12/2021
 *
 * @authors 	Ethan Muchnik
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 * @note		This file only contains app specific command and
 * 				telemetry message definitions and command codes.
 ****************************************************************/

#ifndef FTP_MSG_H
#define FTP_MSG_H

/*
** FTP App command codes
*/
#define FTP_NOOP_CC                 0
#define FTP_RESET_COUNTERS_CC       1
#define FTP_PROCESS_CC              2

/*************************************************************************/

/*
** Type definition (generic "no arguments" command)
*/
typedef struct {
    CFE_SB_CmdHdr_t CmdHeader; /**< \brief Command header */
} FTP_NoArgsCmd_t;

/*
** The following commands all share the "NoArgs" format
**
** They are each given their own type name matching the command name, which
** allows them to change independently in the future without changing the
*prototype
** of the handler function
*/
typedef FTP_NoArgsCmd_t FTP_NoopCmd_t;
typedef FTP_NoArgsCmd_t FTP_ResetCountersCmd_t;
typedef FTP_NoArgsCmd_t FTP_ProcessCmd_t;

/*************************************************************************/
/*
** Type definition (FTP App housekeeping)
*/

typedef struct {
    uint8 CommandErrorCounter;
    uint8 CommandCounter;
    uint8 FTPMsgCounter;
    uint8 spare;
} FTP_HkTlm_Payload_t;

typedef struct {
    uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE]; /**< \brief Telemetry header */
    FTP_HkTlm_Payload_t Payload;       /**< \brief Telemetry payload */
} FTP_HkTlm_t;

#endif /* FTP_MSG_H */
