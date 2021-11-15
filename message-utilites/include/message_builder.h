#ifndef _message_builder_h
#define _message_builder_h
#include "common_types.h"
#include "cfe_sb.h"
#include "ccsds.h"
#include "moonranger_msgids.h"
#include "pose_msg.h"
#include "wheel_velocity_msg.h"
#include "teleop_msg.h"


/*
 * Function: BuildPoseMsg -
 */
void BuildPoseMsg(void *MsgPtr, int32 msgId, MOONRANGER_Pose_t *poseData) ;

/*
 * Function: BuildWheelVelMsg -
 */
void BuildWheelVelMsg(void *MsgPtr, int32 msgId, MOONRANGER_WheelVelocity_t *wheelVelData) ;

void BuildTeleopCmd(void *MsgPtr, int32 msgId, MOONRANGER_Teleop_t *data);

void ExtractPoseMsg(void *MsgPtr, MOONRANGER_Pose_t *poseData);

CFE_SB_MsgId_t GetMsgId(void *MsgPtr);

#endif