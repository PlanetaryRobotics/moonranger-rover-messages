#ifndef _message_builder_h
#define _message_builder_h
#include "camera_if_msgs.h"
#include "ccsds.h"
#include "cfe_evs_msg.h"
#include "cfe_msgids.h"
#include "cfe_sb.h"
#include "common_types.h"
#include "drive_arc_msg.h"
#include "goal_msg.h"
#include "imu_driver_msgs.h"
#include "mapper_msgs.h"
#include "moonranger_msgids.h"
#include "obc_msgs.h"
#include "planner_msgs.h"
#include "pose_estimator_msgs.h"
#include "pose_msg.h"
#include "rover_init_msg.h"
#include "stereo_reconstructor_msgs.h"
#include "tbl_manager_msgs.h"
#include "teleop_msg.h"
#include "tlm_output_msgs.h"
#include "vehicle_controller_msg.h"
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

    // telemetry messages
    MOONRANGER_Pose_Tlm_t Pose_Tlm;
    MOONRANGER_RoverInit_Tlm_t RoverInit_Tlm;
    MOONRANGER_Goal_Tlm_t Goal_Tlm;
    MOONRANGER_DriveArc_Tlm_t DriveArc_Tlm;

    OBC_Peripheral_Sensor_Tlm_t PeripheralSensor_Tlm;

    STEREO_HkTlm_t StereoHk_Tlm;
    STEREO_SendPclMsgTlm_t StereoSendPcl_Tlm;

    TLM_OUTPUT_HkTlm_t TlmOutputHk_Tlm;
    TLM_OUTPUT_DataTypes_t TlmOutputDataTypes_Tlm;

    POSE_HkTlm_t Pose_estimator_Tlm;

    IMU_DRIVER_HkTlm_t Imu_driver_Tlm;

    PLANNER_HkTlm_t PlannerHk_Tlm;

    CAMERA_IF_HkTlm_t CameraIFHk_Tlm;
    CAMERA_IF_ImgSavedTlm_t CameraIFImgSaved_Tlm;

    MAPPER_HkTlm_t MapperHk_Tlm;

    VEHICLE_HkTlm_t VehicleHk_Tlm;

    TBL_MANAGER_HkTlm_t TblManager_Tlm;

    CFE_EVS_LongEventTlm_t CFELongEvent_Tlm;
    CFE_EVS_ShortEventTlm_t CFEShortEvent_Tlm;

    // command messages
    MOONRANGER_Teleop_Cmd_t Teleop_Cmd;

    PLANNER_Eval_Trigger_t Planner_Eval_Trigger_Cmd;
    PLANNER_Noop_t Planner_NoOp_Cmd;
    PLANNER_ResetCounters_t Planner_ResetCounters_Cmd;
    PLANNER_Start_t Planner_Start_Cmd;
    PLANNER_Stop_t Planner_Stop_Cmd;
    PLANNER_Process_t Planner_Process_Cmd;

    OBC_Set_Heater_State_Cmd_t HeaterControl_Cmd;
    OBC_Set_Heater_State_All_Cmd_t HeaterControlAll_Cmd;
    OBC_Set_Switch_State_Cmd_t PowerSwitching_Cmd;
    OBC_Set_Switch_State_All_Cmd_t PowerSwitchingAll_Cmd;
    OBC_Reset_Switch_Cmd_t ResetPowerSwitch_Cmd;
    OBC_NSS_Set_Params_Cmd_t NSSSetParams_Cmd;
    OBC_Set_Solar_Panel_State_Cmd_t SolarPanel_Cmd;
    OBC_Set_Motor_PID_Cmd_t Set_Motor_Pid_Cmd;
    OBC_Set_Solar_Panel_State_Cmd_t Set_Solar_Panel_State_Cmd;
    OBC_Set_Wheel_Speed_All_Cmd_t Set_Wheel_Speed_All_Cmd;
    OBC_BatteryEnable_Cmd_t BatteryEnable_Cmd;
    OBC_WifiEnable_Cmd_t WifiEnable_Cmd;

    STEREO_Noop_t StereoNoOp_Cmd;
    STEREO_ResetCounters_t StereoResetCounters_Cmd;
    STEREO_Process_t StereoProcess_Cmd;
    STEREO_Receive_Camera_Calib_t StereoReceiveCameraCalib_Cmd;
    STEREO_NoArgsCmd_t StereoNoArgs_Cmd;

    TLM_OUTPUT_Noop_t TlmOutputNoOp_Cmd;
    TLM_OUTPUT_ResetCounters_t TlmOutputResetCounters_Cmd;
    TLM_OUTPUT_RemoveAll_t TlmOutputRemoveAll_Cmd;
    TLM_OUTPUT_SendDataTypes_t TlmOutputSendDataTypes_Cmd;
    TLM_OUTPUT_AddPacket_t TlmOutputAddPacket_Cmd;
    TLM_OUTPUT_RemovePacket_t TlmOutputRemovePacket_Cmd;
    TLM_OUTPUT_EnableOutput_t TlmOutputEnableOutput_Cmd;

    CAMERA_IF_Noop_t CameraIFNoOp_Cmd;
    CAMERA_IF_ResetCounters_t CameraIFResetCounters_Cmd;
    CAMERA_IF_SaveImage_t CameraIFSaveImage_Cmd;
    CAMERA_IF_NoArgsCmd_t CameraIFNoArgs_Cmd;

    MAPPER_Noop_t MapperNoOp_Cmd;
    MAPPER_ResetCounters_t MapperReseteCounters_Cmd;
    MAPPER_NoArgsCmd_t MapperNoArgs_Cmd;

    OBC_I2C_USER_DEFINED_TX_t I2C_user_defined_Cmd;
    OBC_I2C_USER_DEFINED_RX_t I2C_user_defined_Telem;
    OBC_BM_Status_t BM_status_Telem;
    OBC_EPSM_ConverterStatus_t EPSM_Converter_Telem;
    OBC_EPSM_SAIStatus_t EPSM_SAI_Telem;

    VEHICLE_CONTROLLER_Noop_t VehicleControllerNoOp_Cmd;
    VEHICLE_CONTROLLER_ResetCounters_t VehicleControllerResetCounters_Cmd;
    VEHICLE_CONTROLLER_UpdateParams_t VehicleControllerUpdateParams_Cmd;
    VEHICLE_CONTROLLER_NoArgsCmd_t VehicleControllerNoargs_Cmd;

    TBL_MANAGER_Noop_t TblManagerNoOp_Cmd;
    TBL_MANAGER_ResetCounters_t TblmanagerResetCounters_Cmd;
    TBL_MANAGER_Update_t TblManagerUpdate_Cmd;
    TBL_MANAGER_NoArgsCmd_t TblManagerNoargs_Cmd;

} message_builder_u;

int messageExtract(void* MsgPtr, int msg_len_bytes,
                   message_builder_u* msg_container);

int messageBuildTlm(void* dataPtr, message_builder_u* msg_container,
                    int data_len_bytes, int32 msgId);
int messageBuildCmd(void* dataPtr, message_builder_u* msg_container,
                    int data_len_bytes, int32 msgId);
int messageBuildCmdWithCode(void* dataPtr, message_builder_u* msg_container,
                            int data_len_bytes, int32 msgId, uint16 cmdCode);

CFE_SB_MsgId_t GetMsgId(void* MsgPtr);
uint16 GetCmdCode(void* MsgPtr);

#endif
