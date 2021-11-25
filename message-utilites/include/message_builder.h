#ifndef _message_builder_h
#define _message_builder_h
#include "common_types.h"
#include "cfe_sb.h"
#include "ccsds.h"
#include "moonranger_msgids.h"
#include "pose_msg.h"
#include "wheel_velocity_command_msg.h"
#include "teleop_msg.h"

/**
 * 
 * A message consists of header + data
 * addressof(msg_buf_ptr) points to start of message (useful for receiving)
 * addressof(data_buf_ptr) points to start of data for all messages (useful for building)
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

} message_builder_u;

void messageExtract(void *MsgPtr,int num_bytes, message_builder_u* msg_container);

void messageBuild(void *DataPtr,message_builder_u* msg_container,int data_len_bytes, int32 msgId);

CFE_SB_MsgId_t GetMsgId(void *MsgPtr);

#endif