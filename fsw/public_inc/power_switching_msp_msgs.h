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
** Type definition (MOONRANGER power switching command packet)
*/

typedef struct {
  uint8 power_group;

} MOONRANGER_PowerSwitching_t;

/**
 * Type definition (MOONRANGER power switching command telemetry)
 * @note includes CFS TLM Header with timestamp
 */
typedef struct {
  uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
  MOONRANGER_PowerSwitching_t data;
} OS_PACK MOONRANGER_PowerSwitching_Tlm_t;

/**
 * Buffer to hold power switching data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union
{
    CFE_SB_Msg_t           MsgHdr;
    MOONRANGER_PowerSwitching_Tlm_t  PowerSwitchingTlm;
} MOONRANGER_PowerSwitchingBuffer_t;

// Message sizes
#define MOONRANGER_POWER_SWITCH_LNGTH sizeof(MOONRANGER_PowerSwitching_t)
#define MOONRANGER_POWER_SWITCH_TLM_LNGTH sizeof(MOONRANGER_PowerSwitching_Tlm_t)

/*************************************************************************/
/*
** Type definition (MOONRANGER reset component command packet)
*/

typedef struct {
  uint8 component_id;

} MOONRANGER_ResetComponent_t;

/**
 * Type definition (MOONRANGER reset component command telemetry)
 * @note includes CFS TLM Header with timestamp
 */
typedef struct {
  uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
  MOONRANGER_ResetComponent_t data;
} OS_PACK MOONRANGER_ResetComponent_Tlm_t;

/**
 * Buffer to hold reset component data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union
{
    CFE_SB_Msg_t           MsgHdr;
    MOONRANGER_ResetComponent_Tlm_t  ResetComponentTlm;
} MOONRANGER_ResetComponentBuffer_t;

// Message sizes
#define MOONRANGER_RESET_COMPONENT_LNGTH sizeof(MOONRANGER_ResetComponent_t)
#define MOONRANGER_RESET_COMPONENT_TLM_LNGTH sizeof(MOONRANGER_ResetComponent_Tlm_t)

#endif /* _power_switching_msgs_h */
