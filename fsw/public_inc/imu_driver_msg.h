/**
 * @file TODO
 * 
 * @brief TODO
 * 
 * @note this file should only contain housekeeping and telemetry message definitions for IMU driver app.
 * All shared messages are defined in separate headers.
 *
 */
#ifndef IMU_DRIVER_MSG_H
#define IMU_DRIVER_MSG_H

// Common includes
#include "cfe_sb.h"
#include "common_types.h"

/*
** app command codes
*/
#define IMU_DRIVER_NOOP_CC                   0

/*************************************************************************/
/*
** Type definition Commands Msg Types
*/

/* Generic "no arguments" command */
typedef struct
{
  uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
} IMU_DRIVER_NoArgsCmd_t;

typedef IMU_DRIVER_NoArgsCmd_t IMU_DRIVER_Noop_t;

/*************************************************************************/
/*
** Type definition Housekeeping Telemetry
*/

/* Housekeeping payload */
typedef struct
{
  //TODO
} IMU_DRIVER_HkTlm_Payload_t;

typedef struct
{
  uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
  IMU_DRIVER_HkTlm_Payload_t Payload;
} OS_PACK IMU_DRIVER_HkTlm_t;


#endif /* IMU_DRIVER_MSG_H */
