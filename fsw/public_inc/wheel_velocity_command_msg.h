/****************************************************************
 *
 * @file      wheel_velocity_command_msg.h
 *
 * @brief     Type definition for Moonranger wheel velocity command message to
 *be sent from the ground station or central computer to the peripheral
 *computer.
 *
 * @version   1.0
 * @date      16 Nov 2021
 *
 * @authors 	Tenzin Crouch
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 ****************************************************************/

#ifndef _wheel_velocity_command_msg_h_
#define _wheel_velocity_command_msg_h_

#include "cfe_sb.h"
#include "moonranger_common_types.h"


//*************************************************************************/
/**
 * Type definition (MOONRANGER wheel velocity command packet)
 */
typedef struct OS_PACK {
    uint32_t duration;   //seconds
    float32 leftFront;    // rad/s
    float32 rightFront;   // rad/s
    float32 leftBack;     // rad/s
    float32 rightBack;    // rad/s
} MOONRANGER_WheelVelocityCmd_t;

/**
 * Type definition (MOONRANGER wheel velocity command message)
 */
typedef struct {
    uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
    MOONRANGER_WheelVelocityCmd_t data;
} OS_PACK MOONRANGER_WheelVelocity_Command_t;

// Message sizes
#define MOONRANGER_WHEEL_VEL_CMD_DATA_LNGTH sizeof(MOONRANGER_WheelVelocityCmd_t)
#define MOONRANGER_WHEEL_VEL_CMD_MSG_LNGTH sizeof(MOONRANGER_WheelVelocity_Command_t)

#endif /* _wheel_velocity_command_msg_h_ */
