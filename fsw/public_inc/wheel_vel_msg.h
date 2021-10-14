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


#ifndef _wheel_spd_msg_h_
#define _wheel_spd_msg_h_

#include "cfe_sb.h"
#include "common_types.h"


//*************************************************************************/
/**
 * Type definition (MOONRANGER wheel velocity packet)
 */
typedef struct
{
    uint64  timeStamp;  // nanoseconds
    float32 leftFront;  // rad/s
    float32 rightFront; // rad/s
    float32 leftBack;   // rad/s
    float32 rightBack;  // rad/s
} MOONRANGER_WheelVelocity_t;

/**
 * Type definition (MOONRANGER pose telemetry)
 * @note includes CFS TLM Header with timestamp
*/
typedef struct {
{
    uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
    MOONRANGER_Pose_t pose_data;
} OS_PACK MOONRANGER_WheelVelocity_Tlm_t;

// Message sizes
#define MOONRANGER_WHEEL_VEL_LNGTH sizeof(MOONRANGER_WheelVelocity_t)
#define MOONRANGER_WHEEL_VEL_TLM_LNGTH sizeof(MOONRANGER_WheelVelocity_Tlm_t)

#endif /* _wheel_spd_msg_h_ */

