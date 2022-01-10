/****************************************************************
 * 
 * @file      TODO
 * 
 * @brief     TODO
 * 
 * @version   TODO
 * @date   		TODO
 * 
 * @authors 	TODO
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 * 
 * @note		This file only contains app specific command and 
 * 				telemetry message definitions and command codes.
 * 
 ****************************************************************/
#ifndef _cmd_ingest_msgs_h_
#define _cmd_ingest_msgs_h_

/*
** CMD_INGEST command codes
*/
#define CMD_INGEST_NOOP_CC           0
#define CMD_INGEST_RESET_COUNTERS_CC 1

/*************************************************************************/
/*
** Type definition (generic "no arguments" command)
*/
typedef struct
{
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];

} CMD_INGEST_NoArgsCmd_t;

/*
 * Neither the Noop nor ResetCounters command
 * have any payload, but should still "reserve" a unique
 * structure type to employ a consistent handler pattern.
 *
 * This matches the pattern in CFE core and other modules.
 */
typedef CMD_INGEST_NoArgsCmd_t CMD_INGEST_Noop_t;
typedef CMD_INGEST_NoArgsCmd_t CMD_INGEST_ResetCounters_t;

/*************************************************************************/
/*
** Type definition (CMD_INGEST housekeeping)...
*/
typedef struct
{
    uint8  CommandErrorCounter;
    uint8  CommandCounter;
    uint8  EnableChecksums;
    uint8  SocketConnected;
    uint8  Spare1[8];
    uint32 IngestPackets;
    uint32 IngestErrors;
    uint32 Spare2;

} CMD_INGEST_HkTlm_Payload_t;

typedef struct
{
    uint8                  TlmHeader[CFE_SB_TLM_HDR_SIZE];
    CMD_INGEST_HkTlm_Payload_t Payload;
} OS_PACK CMD_INGEST_HkTlm_t;
/*
 * Declaring the CMD_INGEST_IngestBuffer as a union
 * ensures it is aligned appropriately to
 * store a CFE_SB_Msg_t type.
 */
typedef union
{
    CFE_SB_Msg_t MsgHdr;
    uint8        bytes[CMD_INGEST_MAX_INGEST];
    uint16       hwords[2];
} CMD_INGEST_IngestBuffer_t;

typedef union
{
    CFE_SB_Msg_t   MsgHdr;
    CMD_INGEST_HkTlm_t HkTlm;
} CMD_INGEST_HkTlm_Buffer_t;

#define CMD_INGEST_HK_TLM_LNGTH sizeof(CMD_INGEST_HkTlm_t)

#endif /* _cmd_ingest_msgs_h_ */

/************************/
/*  End of File Comment */
/************************/
