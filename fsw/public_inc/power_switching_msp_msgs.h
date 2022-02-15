/****************************************************************
 * 
 * @file      power_switching_msp_msg.h
 * 
 * @brief     Type definition for Moonranger power switching message
 * 
 * @version   1.0
 * @date   	  10 Jan 2022
 * 
 * @authors 	Ashwin Rao
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 * 
 * @note		This file only contains app specific command and 
 * 				telemetry message definitions and command codes.
 * 
 ****************************************************************/

#ifndef _power_switching_msgs_h
#define _power_switching_msgs_h

#include "cfe_sb.h"
#include "moonranger_common_types.h"

/*************************************************************************/
/*
** Type definition (power switching command packet)
*/

typedef struct {
  uint8 cmd_state;
  uint8 power_group;
} PERIPHERAL_MANAGER_PowerSwitching_t;

/**
 * Type definition (power switching command telemetry)
 * @note includes CFS TLM Header with timestamp
 */
typedef struct {
  uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
  PERIPHERAL_MANAGER_PowerSwitching_t data;
} OS_PACK PERIPHERAL_MANAGER_PowerSwitching_Tlm_t;

/**
 * Buffer to hold power switching data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union
{
    CFE_SB_Msg_t           MsgHdr;
    PERIPHERAL_MANAGER_PowerSwitching_Tlm_t  PowerSwitchingTlm;
} PERIPHERAL_MANAGER_PowerSwitchingBuffer_t;

// Message sizes
#define PERIPHERAL_MANAGER_POWER_SWITCH_LNGTH sizeof(PERIPHERAL_MANAGER_PowerSwitching_t)
#define PERIPHERAL_MANAGER_POWER_SWITCH_TLM_LNGTH sizeof(PERIPHERAL_MANAGER_PowerSwitching_Tlm_t)

/*************************************************************************/
/*
** Type definition (reset component command packet)
*/

typedef struct {
  uint8 component_id;

} PERIPHERAL_MANAGER_ResetComponent_t;

/**
 * Type definition (reset component command telemetry)
 * @note includes CFS TLM Header with timestamp
 */
typedef struct {
  uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
  PERIPHERAL_MANAGER_ResetComponent_t data;
} OS_PACK PERIPHERAL_MANAGER_ResetComponent_Tlm_t;

/**
 * Buffer to hold reset component data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union
{
    CFE_SB_Msg_t           MsgHdr;
    PERIPHERAL_MANAGER_ResetComponent_Tlm_t  ResetComponentTlm;
} PERIPHERAL_MANAGER_ResetComponentBuffer_t;

// Message sizes
#define PERIPHERAL_MANAGER_RESET_COMPONENT_LNGTH sizeof(PERIPHERAL_MANAGER_ResetComponent_t)
#define PERIPHERAL_MANAGER_RESET_COMPONENT_TLM_LNGTH sizeof(PERIPHERAL_MANAGER_ResetComponent_Tlm_t)

/*************************************************************************/
/*
** Type definition (set peripheral comms command packet)
*/

typedef struct {
  uint8 channel;

} PERIPHERAL_MANAGER_SetComms_t;

/**
 * Type definition (set peripheral comms command telemetry)
 * @note includes CFS TLM Header with timestamp
 */
typedef struct {
  uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
  PERIPHERAL_MANAGER_SetComms_t data;
} OS_PACK PERIPHERAL_MANAGER_SetComms_Tlm_t;

/**
 * Buffer to hold set peripheral comms data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union
{
    CFE_SB_Msg_t           MsgHdr;
    PERIPHERAL_MANAGER_SetComms_Tlm_t  SetPeripheralCommsTlm;
} PERIPHERAL_MANAGER_SetCommsBuffer_t;

// Message sizes
#define PERIPHERAL_MANAGER_SET_COMMS_LNGTH sizeof(PERIPHERAL_MANAGER_SetComms_t)
#define PERIPHERAL_MANAGER_SET_COMMS_TLM_LNGTH sizeof(PERIPHERAL_MANAGER_SetComms_Tlm_t)

#endif /* _power_switching_msgs_h */
