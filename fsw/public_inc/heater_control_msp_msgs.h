/****************************************************************
 * 
 * @file      heater_control_msp_msgs.h
 * 
 * @brief     Type definition for Moonranger set heater message
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

#ifndef _heater_control_msp_msgs_h
#define _heater_control_msp_msgs_h

#include "cfe_sb.h"
#include "moonranger_common_types.h"

/*************************************************************************/
/*
** Type definition (heater control message packet)
*/

typedef struct {
  uint8 heater_id;
  uint8 mode;
  uint8 setting;

} PERIPHERAL_MANAGER_HeaterControl_t;

/**
 * Type definition (heater control message telemetry)
 * @note includes CFS TLM Header with timestamp
 */
typedef struct {
  uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
  PERIPHERAL_MANAGER_HeaterControl_t data;
} OS_PACK PERIPHERAL_MANAGER_HeaterControl_Tlm_t;

/**
 * Buffer to hold heater control data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union
{
    CFE_SB_Msg_t           MsgHdr;
    PERIPHERAL_MANAGER_HeaterControl_Tlm_t  HeaterControlTlm;
} PERIPHERAL_MANAGER_HeaterControlBuffer_t;

// Message sizes
#define PERIPHERAL_MANAGER_HEATER_CONTROL_LNGTH sizeof(PERIPHERAL_MANAGER_HeaterControl_t)
#define PERIPHERAL_MANAGER_HEATER_CONTROL_TLM_LNGTH sizeof(PERIPHERAL_MANAGER_HeaterControl_Tlm_t)


#endif /* _heater_control_msp_msgs_h */