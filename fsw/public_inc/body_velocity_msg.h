/****************************************************************
 *
 * @file      body_velocity_msg.h
 *
 * @brief     Type definition for Moonranger body velocity message
 *
 * @version   1.0
 * @date      19 Oct 2021
 *
 * @authors 	Tenzin Crouch
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 ****************************************************************/

#ifndef _body_velocity_h_
#define _body_velocity_h_

#include "cfe_sb.h"
#include "common_types.h"

/*************************************************************************/
/**
 * Type definition (MOONRANGER body velocity packet)
 */
typedef struct {
  uint64 timeStamp;   // nanoseconds
  float32 xVelocity;  // m/s
  float32 yawVelocity; // rads/s
} MOONRANGER_BodyVelocity_t;

/**
 * Type definition (MOONRANGER body velocity telemetry)
 * @note includes CFS TLM Header with timestamp
 */
typedef struct {
  uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
  MOONRANGER_BodyVelocity_t pose_data;
} OS_PACK MOONRANGER_BodyVelocity_Tlm_t;

// Message sizes
#define MOONRANGER_BODYVEL_LNGTH sizeof(MOONRANGER_BodyVelocity_t)
#define MOONRANGER_BODYVEL_TLM_LNGTH sizeof(MOONRANGER_BodyVelocity_Tlm_t)

#endif /* _body_velocity_h_ */
