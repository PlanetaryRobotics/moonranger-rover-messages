#ifndef _message_builder_h
#define _message_builder_h
#include "ccsds.h"
#include "cfe_sb.h"
#include "common_types.h"
#include "goal_msg.h"
#include "planner_msgs.h"
#include "moonranger_msgids.h"
#include "pose_estimator_msgs.h"
#include "pose_msg.h"
#include "rover_init_msg.h"
#include "stereo_reconstructor_msgs.h"
#include "teleop_msg.h"
#include "wheel_velocity_command_msg.h"
#include "imu_driver_msgs.h"
#include "obc_msgs.h"
#include "drive_arc_msg.h"
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
        uint8_t tlm_data_buf_ptr;
    };

    struct {
        uint8_t CmdHeader[CFE_SB_CMD_HDR_SIZE];
        uint8_t cmd_data_buf_ptr;
    };

    MOONRANGER_Pose_Tlm_t Pose_Tlm;
    POSE_HkTlm_t Pose_estimator_Tlm;
    MOONRANGER_WheelVelocity_Command_t WheelVelocity_Command;
    MOONRANGER_Teleop_Cmd_t Teleop_Cmd;
    OBC_BatteryEnable_Cmd_t Battery_En_Cmd;
    MOONRANGER_RoverInit_Tlm_t rover_init_indicator;
    MOONRANGER_Goal_Tlm_t Goal_Tlm;
    OBC_Set_Heater_State_Cmd_t HeaterControl_Cmd;
    OBC_Set_Switch_State_Cmd_t PowerSwitching_Cmd;
    OBC_Reset_Switch_Cmd_t ResetPowerSwitch_Cmd;
    OBC_WifiEnable_Cmd_t WiFi_Enable_Cmd;
    OBC_NSS_Set_Params_Cmd_t NSSSetParams_Cmd;
    OBC_Set_Motor_PID_Cmd_t Set_Motor_Pid_Cmd;
    OBC_Set_Solar_Panel_State_Cmd_t Set_Solar_Panel_State_Cmd;
    OBC_Set_Wheel_Speed_All_Cmd_t Set_Wheel_Speed_All_Cmd;
    PLANNER_HkTlm_t PlannerHk_Tlm;
    PLANNER_Noop_t Planner_NoOp_Cmd;
    PLANNER_ResetCounters_t Planner_ResetCounters_Cmd;
    PLANNER_Start_t Planner_Start_Cmd;
    PLANNER_Stop_t Planner_Stop_Cmd;
    PLANNER_Eval_Trigger_t Planner_Eval_Trigger_Cmd;
    PLANNER_Process_t Planner_Process_Cmd;
    STEREO_HkTlm_t StereoHk_Tlm;
    STEREO_SendPclMsgTlm_t StereoSendPcl_Tlm;
    STEREO_Noop_t StereoNoOp_Tlm;
    STEREO_ResetCounters_t StereoResetCounters_Tlm;
    STEREO_Process_t StereoProcess_Tlm;
    STEREO_Receive_Camera_Calib_t StereoReceiveCameraCalib_Tlm;
    STEREO_NoArgsCmd_t StereoNoArgs_Tlm;
    IMU_DRIVER_HkTlm_t Imu_driver_Tlm;
    MOONRANGER_DriveArc_Tlm_t DriveArc_Tlm;
    OBC_Peripheral_Sensor_Tlm_t PeripheralSensor_Tlm;
    OBC_BatteryEnable_Cmd_t BatteryEnable_Tlm;
    OBC_WifiEnable_Cmd_t WifiEnable_Tlm;
} message_builder_u;

int messageExtract(void* MsgPtr, int msg_len_bytes,
                   message_builder_u* msg_container);

int messageBuildTlm(void* dataPtr, message_builder_u* msg_container,
                    int data_len_bytes, int32 msgId);
int messageBuildCmd(void* dataPtr, message_builder_u* msg_container,
                    int data_len_bytes, int32 msgId);

CFE_SB_MsgId_t GetMsgId(void* MsgPtr);

#endif