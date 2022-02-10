/****************************************************************
 * 
 * @file      nss_if_msp_msgs.h
 * 
 * @brief     messages between master msp (E3) and nss msp (E6)
 * 
 * @version   1.0
 * @date   		2/6/2021
 * 
 * @authors 	KJ Newman, Ashwin Rao
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 * 
 * @note		This file only contains app specific command and 
 * 				telemetry message definitions and command codes.
 * 
 ****************************************************************/

#ifndef _nss_if_msp_msgs_h
#define _nss_if_msp_msgs_h

#include "cfe_sb.h"
#include "moonranger_common_types.h"

/*************************************************************************/
/**
 * Type definition (NSS set params command)
 * 
 * command1 bit 2~0: Detector Tube #2 Scalar threshold
 * command1 bit 5~3: Detector Tube #1 Scalar threshold
 * command2 LSB and command1 bit 7~6: Detector tube (both) HV setting
 * 
 * @note bytes indexed from right to left (0: LSB, 7: MSB)
 */
typedef struct {
	volatile int8_t command1; // first command byte
	volatile int8_t command2; // second command byte
	uint8_t _padding[2]; // empty

} NSS_SetParams_t;

/**
 * Type definition (NSS set params telemetry)
 * @note includes CFS TLM Header with timestamp
 */
typedef struct {
  uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
  NSS_SetParams_t data;
} OS_PACK NSS_SetParams_Tlm_t;

/**
 * Buffer to hold NSS set params data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union
{
    CFE_SB_Msg_t           MsgHdr;
    NSS_SetParams_Tlm_t    NSSSetParamsTlm;
} NSS_SetParamsBuffer_t;

// Message sizes
#define NSS_SET_PARAMS_LNGTH sizeof(NSS_SetParams_t)
#define NSS_SET_PARAMS_TLM_LNGTH sizeof(NSS_SetParams_Tlm_t)

/*************************************************************************/
/*
** Type definition (NSS health message data)
*/
typedef struct {
	volatile int8_t telemetry[89]; // nss telemetry data
	uint8_t reboot_counter; // median reboot counter from FRAM
	uint8_t message_counter; // message counter incremented each time this is sent
	uint8_t _padding; // empty
} NSS_HealthMsg_t;

/**
 * Type definition (NSS health message telemetry)
 * @note includes CFS TLM Header with timestamp
 */
typedef struct {
  uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
  NSS_HealthMsg_t data;
} OS_PACK NSS_HealthMsg_Tlm_t;

/**
 * Buffer to hold NSS health data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union
{
    CFE_SB_Msg_t           MsgHdr;
    NSS_HealthMsg_Tlm_t    NSSHealthMsgTlm;
} NSS_HealthMsgBuffer_t;

// Message sizes
#define NSS_HEALTH_MSG_LNGTH sizeof(NSS_HealthMsg_t)
#define NSS_HEALTH_MSG_TLM_LNGTH sizeof(NSS_HealthMsg_Tlm_t)

#endif /* _nss_if_msp_msgs_h */
