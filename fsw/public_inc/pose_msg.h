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

#ifdef __cplusplus
extern "C" {
#endif
#include "cfe_sb.h"
#ifdef __cplusplus
}
#endif
#include "moonranger_common_types.h"

/*
** Type definition (MOONRANGER pose)
*/
typedef struct OS_PACK {
    CFE_TIME_SysTime_t timeStamp;
    float64 x_pos;    // meters
    float64 y_pos;    // meters
    float64 z_pos;    // meters
    float64 x_quat;   // quaternion
    float64 y_quat;   // quaternion
    float64 z_quat;   // quaternion
    float64 w_quat;   // quaternion
    float64 covariance[36];
} MOONRANGER_Pose_t;

/**
 * Type definition (MOONRANGER pose telemetry)
 * @note includes CFS TLM Header with timestamp
 */
typedef struct {
    uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
    MOONRANGER_Pose_t data;
} OS_PACK MOONRANGER_Pose_Tlm_t;

/**
 * Buffer to hold pose data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    MOONRANGER_Pose_Tlm_t PoseTlm;
} MOONRANGER_PoseBuffer_t;

// Message sizes
#define MOONRANGER_POSE_LNGTH sizeof(MOONRANGER_Pose_t)
#define MOONRANGER_POSE_TLM_LNGTH sizeof(MOONRANGER_Pose_Tlm_t)

#endif /* _pose_msg_h_ */
