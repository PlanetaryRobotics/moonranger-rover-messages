#ifndef _message_builder_h
#define _message_builder_h
#include "ccsds.h"
#include "cfe_sb.h"
#include "common_types.h"
#include "goal_msg.h"
#include "moonranger_msgids.h"
#include "pose_msg.h"
#include "teleop_msg.h"
#include "wheel_velocity_command_msg.h"

#define SUCCESS 1
#define FAILURE 0

/**
 *
 * A message consists of header + data
 * addressof(msg_buf_ptr) points to start of message (useful for receiving)
 * addressof(data_buf_ptr) points to start of data for all messages (useful for
 * building)
 *
 * */
typedef union {
    uint8_t msg_buf_ptr;

    struct {
        uint8_t TlmHeader[CFE_SB_TLM_HDR_SIZE];
        uint8_t data_buf_ptr;
    };

    MOONRANGER_Pose_Tlm_t Pose_Tlm;
    MOONRANGER_WheelVelocity_Command_t WheelVelocity_Command;
    MOONRANGER_Teleop_Cmd_t Teleop_Cmd;
    MOONRANGER_Goal_Tlm_t Goal_Tlm;

} MOONRANGER_Message_u;

int messageExtract(void* MsgPtr, int msg_len_bytes,
                   MOONRANGER_Message_u* msg_container);

int messageBuild(void* dataPtr, MOONRANGER_Message_u* msg_container,
                 int data_len_bytes, int32 msgId);

CFE_SB_MsgId_t GetMsgId(void* MsgPtr);

#endif