/****************************************************************
 *
 * @file      pose_msg.h
 *
 * @brief     Type definition for Moonranger pose message
 *
 * @version   1.0
 * @date      10 Oct 2021
 *
 * @authors 	Tenzin Crouch
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
  uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
  float64 x_pos;  // meters
  float64 y_pos;  // meters
  float64 z_pos;  // meters
  float64 x_quat; // quaternion
  float64 y_quat; // quaternion
  float64 z_quat; // quaternion
  float64 w_quat; // quaternion
  float64 covariance[36];
} MOONRANGER_Pose_t;

/**
 * Type definition (MOONRANGER pose telemetry)
 * @note includes CFS TLM Header with timestamp
 */
typedef struct {
  uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
  MOONRANGER_Pose_t pose_data;
} OS_PACK MOONRANGER_Pose_Tlm_t;

// Message sizes
#define MOONRANGER_POSE_LNGTH sizeof(MOONRANGER_Pose_t)
#define MOONRANGER_POSE_TLM_LNGTH sizeof(MOONRANGER_Pose_Tlm_t)

#endif /* _pose_msg_h_ */
