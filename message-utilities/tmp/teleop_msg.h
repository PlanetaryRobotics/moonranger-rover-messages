/****************************************************************
 *
 * @file      teleop_msgs.h
 *
 * @brief     THIS IS A TEMPORARY MESSAGE TYPE TO ENABLE EASY COMMANDING DURING
 *PAPER MISSION 3
 *
 * @version   1.0
 * @date      28 Oct 2021
 *
 * @authors 	Tenzin Crouch
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 ****************************************************************/

#ifndef _teleop_msgs_h_
#define _teleop_msgs_h_

#include "common_types.h"

#define MOONRANGER_TELEOP_MID 0x0895


typedef double float64;

/**
 * Type definition (MOONRANGER teleop data)
 */

typedef struct {
  float64 rover_x_vel;   // cm /s
  float64 rover_rot_vel; // rads/s
  float64 duration;      // seconds
} MOONRANGER_Teleop_t;

/**
 * Type definition (MOONRANGER teleop command)
 * @note includes CFS TLM Header with timestamp
 */
typedef struct {
  uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
  MOONRANGER_Teleop_t data;
} OS_PACK MOONRANGER_Teleop_Cmd_t;

// Message sizes
#define MOONRANGER_TELEOP_LNGTH sizeof(MOONRANGER_Teleop_t)
#define MOONRANGER_TELEOP_CMD_LNGTH sizeof(MOONRANGER_Teleop_Cmd_t)

#endif /* _teleop_msgs_ */
