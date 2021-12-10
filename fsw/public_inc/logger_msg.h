/**
 * @file
 *
 * Define LOGGER App  Messages and info
 */

#ifndef LOGGER_MSG_H
#define LOGGER_MSG_H

/*
** LOGGER App command codes
*/
#define LOGGER_NOOP_CC 0
#define LOGGER_RESET_COUNTERS_CC 1
#define LOGGER_G_CC 1
#define LOGGER_P_CC 1

/*************************************************************************/

/*
** Type definition (generic "no arguments" command)
*/
typedef struct {
    CFE_SB_CmdHdr_t CmdHeader; /**< \brief Command header */
} LOGGER_NoArgsCmd_t;

/*
** The following commands all share the "NoArgs" format
**
** They are each given their own type name matching the command name, which
** allows them to change independently in the future without changing the
*prototype
** of the handler function
*/
typedef LOGGER_NoArgsCmd_t LOGGER_NoopCmd_t;
typedef LOGGER_NoArgsCmd_t LOGGER_ResetCountersCmd_t;
typedef LOGGER_NoArgsCmd_t LOGGER_ProcessCmd_t;

/*************************************************************************/
/*
** Type definition (LOGGER App housekeeping)
*/

typedef struct {
    uint8 CommandErrorCounter;
    uint8 CommandCounter;
    uint8 LogMsgCounter;
    uint8 spare[2];
} LOGGER_HkTlm_Payload_t;

typedef struct {
    uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE]; /**< \brief Telemetry header */
    LOGGER_HkTlm_Payload_t Payload;       /**< \brief Telemetry payload */
} LOGGER_HkTlm_t;

#endif /* LOGGER_MSG_H */
