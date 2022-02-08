#ifndef _message_builder_h
#define _message_builder_h
#include "ccsds.h"
#include "cfe_sb.h"
#include "common_types.h"
#include "goal_msg.h"
#include "moonranger_msgids.h"
#include "pose_msg.h"
#include "teleop_msg.h"
#include "battery_enable_msg.h"
#include "wheel_velocity_command_msg.h"
#include "heater_control_msp_msgs.h"
#include "power_switching_msp_msgs.h"
#include "nss_if_msp_msgs.h"

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
    BatteryEnable_Cmd_t battery_en;
    MOONRANGER_Goal_Tlm_t Goal_Tlm;
    PERIPHERAL_MANAGER_HeaterControl_Tlm_t HeaterControl_Tlm;
    PERIPHERAL_MANAGER_PowerSwitching_Tlm_t PowerSwitching_Tlm;
    PERIPHERAL_MANAGER_ResetComponent_Tlm_t ResetComponent_Tlm;
    PERIPHERAL_MANAGER_SetComms_Tlm_t SetPeripheralComms_Tlm;
    NSS_HealthMsg_Tlm_t NSSHealthMsg_Tlm;
    NSS_SetParams_Tlm_t NSSSetParams_Tlm;

} message_builder_u;

int messageExtract(void* MsgPtr, int msg_len_bytes,
                   message_builder_u* msg_container);

int messageBuild(void* dataPtr, message_builder_u* msg_container,
                 int data_len_bytes, int32 msgId);

CFE_SB_MsgId_t GetMsgId(void* MsgPtr);

#endif