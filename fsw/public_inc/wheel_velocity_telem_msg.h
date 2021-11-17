/****************************************************************
 *
 * @file      wheel_velocity_telem_msg.h
 *
 * @brief     Type definition for Moonranger wheel velocity telemetry message to
 *be sent from the peripheral computer to the central computer.
 *
 * @version   1.0
 * @date      19 Oct 2021
 *
 * @authors 	Tenzin Crouch
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 ****************************************************************/

#ifndef _wheel_velocity_telem_msg_h_
#define _wheel_velocity_telem_msg_h_

#include "cfe_sb.h"
#include "moonranger_common_types.h"

//*************************************************************************/
/**
 * Type definition (MOONRANGER wheel velocity telemetry packet)
 */
typedef struct {
    CFE_TIME_SysTime_t timeStamp;
    float32 leftFront;    // rad/s
    float32 rightFront;   // rad/s
    float32 leftBack;     // rad/s
    float32 rightBack;    // rad/s
} MOONRANGER_WheelVelocity_t;

/**
 * Type definition (MOONRANGER wheel velocity telemetry)
 * @note includes CFS TLM Header with timestamp
 */
typedef struct {
    uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
    MOONRANGER_WheelVelocity_t data;
} OS_PACK MOONRANGER_WheelVelocity_Tlm_t;

// Message sizes
#define MOONRANGER_WHEEL_VEL_LNGTH sizeof(MOONRANGER_WheelVelocity_t)
#define MOONRANGER_WHEEL_VEL_TLM_LNGTH sizeof(MOONRANGER_WheelVelocity_Tlm_t)

#endif /* _wheel_velocity_telem_msg_h_ */
