#include "message_builder.h"

#ifdef _WIN32

#include <stdlib.h>
#define bswap_32(x) _byteswap_ulong(x)
#define bswap_64(x) _byteswap_uint64(x)

#elif defined(__APPLE__)

// Mac OS X / Darwin features
#include <libkern/OSByteOrder.h>
#define bswap_32(x) OSSwapInt32(x)
#define bswap_64(x) OSSwapInt64(x)

#else

#include <byteswap.h>

#endif
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

/*
 * Function: BuildPoseMsg -
 */
void BuildPoseMsg(void *MsgPtr, int32 msgId, MOONRANGER_Pose_t *poseData) {
  MOONRANGER_Pose_Tlm_t *ptr = MsgPtr;
  CFE_SB_InitMsg(ptr, (CFE_SB_MsgId_t)msgId, MOONRANGER_POSE_TLM_LNGTH, true);

  ptr->pose_data = *poseData;

  return;
}

/*
 * Function: ExtractPoseMsg -
 */
void ExtractPoseMsg(void *MsgPtr, MOONRANGER_Pose_t *poseData) {
    MOONRANGER_Pose_Tlm_t *poseMsg = MsgPtr;
    *poseData = poseMsg->pose_data;
}

void BuildWheelVelMsg(void *MsgPtr, int32 msgId, MOONRANGER_WheelVelocity_t *wheelVelData){
  MOONRANGER_WheelVelocity_Tlm_t *ptr = MsgPtr;
  CFE_SB_InitMsg(ptr, (CFE_SB_MsgId_t)msgId, MOONRANGER_WHEEL_VEL_TLM_LNGTH, true);

  ptr->data = *wheelVelData;

  return;
}

void BuildTeleopCmd(void *MsgPtr, int32 msgId, MOONRANGER_Teleop_t *data){
  MOONRANGER_Teleop_Cmd_t *ptr = MsgPtr;
  CFE_SB_InitMsg(ptr, (CFE_SB_MsgId_t)msgId, MOONRANGER_TELEOP_CMD_LNGTH, true);

  ptr->data = *data;

  return;
}