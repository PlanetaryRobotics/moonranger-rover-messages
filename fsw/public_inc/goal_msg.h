/****************************************************************
 *
 * @file        goal_msg.h
 *
 * @brief       Type definition for Moonranger goal message
 *
 * @version     1.0
 * @date        19 Oct 2021
 *
 * @authors     Tenzin Crouch
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 ****************************************************************/

#ifndef _goal_msg_h_
#define _goal_msg_h_

#include "cfe_sb.h"
#include "moonranger_common_types.h"

/*************************************************************************/
/*
** Type definition (MOONRANGER goal)
*/

typedef struct {
  float32 x_coord;     // meters
  float32 y_coord;     // meters
  float32 x_radius;    // meters
  float32 y_radius;    // meters
  float32 orientation; // radians
  bool blind_nav;      // switch for blind navigation
} MOONRANGER_Goal_t;

/**
 * Type definition (MOONRANGER goal telemetry)
 * @note includes CFS TLM Header with timestamp
 */
typedef struct {
    uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
    MOONRANGER_Goal_t data;
} OS_PACK MOONRANGER_Goal_Tlm_t;

/**
 * Buffer to hold goal data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    MOONRANGER_Goal_Tlm_t GoalTlm;
} MOONRANGER_GoalBuffer_t;

// Message sizes
#define MOONRANGER_GOAL_LNGTH sizeof(MOONRANGER_Goal_t)
#define MOONRANGER_GOAL_TLM_LNGTH sizeof(MOONRANGER_Goal_Tlm_t)

#endif /* _goal_msg_h_ */
