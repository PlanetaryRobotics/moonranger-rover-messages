/****************************************************************
 *
 * @file      moonranger_msgids.h
 *
 * @brief     Defines all of MoonRanger's Message IDs.
 *
 *            Default cFS's apps (such as scheduler and cmd_ingest) will have
 *            0x18xx and 0x08xx addresses for commands and telemetry.
 *
 *            Custom Moonranger apps (such as camera_if and mapper) will use
 *            0x1900 to 0x1FFF addresses for commands and 0x0900 to 0x0FFF
 *            addresses for telemetry
 *
 * @version   1.0
 * @date      11/24/2021
 *
 * @author    Carnegie Mellon University, Planetary Robotics Lab
 *
 ****************************************************************/

#ifndef _moonranger_msgids_h_
#define _moonranger_msgids_h_

/**
 * IMU Driver Message IDs
 * @note Command message IDs in this section should fit within
 * 0x1900-0x193F inclusive.
 * @note Telemetry message IDs in this section should fit within
 * 0x0900-0x093F inclusive.
 */
#define IMU_DRIVER_CMD_MID 0x1900
#define IMU_DRIVER_SEND_HK_MID 0x1901
#define IMU_DRIVER_HK_TLM_MID 0x0901

/**
 * Camera Driver & Camera Interface Message IDs
 * @note Command message IDs in this section should fit within
 * 0x1940-0x197F inclusive.
 * @note Telemetry message IDs in this section should fit within
 * 0x0940-0x097F inclusive.
 */

/* Command to save the next available image captured from camera to disk */
#define CAMERA_IF_CMD_MID 0x1940
/* Telemetry that indicates image has been saved to disk and that image needs to
 * be sent back to earth */
#define CAMERA_IF_IMG_SAVED_TLM_MID 0x0940

/* Housekeeping */
#define CAMERA_IF_SEND_HK_MID 0x1941
#define CAMERA_IF_HK_TLM_MID 0x0941

/* Stereo Msg sent */
#define CAMERA_IF_NEW_STEREO_IMG_TLM_MID 0x0942

/* Unused, but needs to be reserved */
#define SB_TRANSPORT_LIB_CMD_MID 0x197F

/**
 * Pose Estimator Message IDs
 * @note Command message IDs in this section should fit within
 * 0x1980-0x19BF inclusive.
 * @note Telemetry message IDs in this section should fit within
 * 0x0980-0x09BF inclusive.
 */
#define POSE_CMD_MID 0x1980
#define POSE_SEND_HK_MID 0x1981
#define POSE_HK_TLM_MID 0x0981

/**
 * Stereo Reconstructor Message IDs
 * @note Command message IDs in this section should fit within
 * 0x19C0-0x19FF inclusive.
 * @note Telemetry message IDs in this section should fit within
 * 0x09C0-0x09FF inclusive.
 */
#define STEREO_CMD_MID 0x19C0
#define STEREO_SEND_HK_MID 0x19C1
#define STEREO_HK_TLM_MID 0x09C1
#define STEREO_NEW_PCL_TLM_MID 0x09C2
#define STEREO_NEW_DISP_TLM_MID 0x09C3

/**
 * Planner Message IDs
 * @note Command message IDs in this section should fit within
 * 0x1A00-0x1A3F inclusive.
 * @note Telemetry message IDs in this section should fit within
 * 0x0A00-0x0A3F inclusive.
 */
#define PLANNER_CMD_MID 0x1A00
#define PLANNER_SEND_HK_MID 0x1A01
#define PLANNER_HK_TLM_MID 0x0A01

/**
 * Mapper Message IDs
 * @note Command message IDs in this section should fit within
 * 0x1A40-0x1A7F inclusive.
 * @note Telemetry message IDs in this section should fit within
 * 0x0A40-0x0A7F inclusive.
 */
#define MAPPER_CMD_MID 0x1A40
#define MAPPER_SEND_HK_MID 0x1A41
#define MAPPER_HK_TLM_MID 0x0A41
/* Telemetry that indicates a new mesh has been saved */
#define MOONRANGER_MESH_SAVED_MID 0x0A42

/**
 * Vehicle Controller Message IDs
 * @note Command message IDs in this section should fit within
 * 0x1A80-0x1ABF inclusive.
 * @note Telemetry message IDs in this section should fit within
 * 0x0A80-0x0ABF inclusive.
 */
#define VEHICLE_CMD_MID 0x1A80
#define VEHICLE_SEND_HK_MID 0x1A81
#define VEHICLE_HK_TLM_MID 0x0A81

/**
 * Peripheral Data Manager Message IDs
 * @note Command message IDs in this section should fit within
 * 0x1AC0-0x1AFF inclusive.
 * @note Telemetry message IDs in this section should fit within
 * 0x0AC0-0x0AFF inclusive.
 */
#define OBC_SET_WHEEL_SPEED_ALL_CMD_MID 0x1AC1     // set all wheel speeds
#define OBC_SET_MOTOR_PID_CMD_MID 0x1AC2           // set the pid values
#define OBC_SET_SOLAR_PANEL_STATE_CMD_MID 0x1AC3   // set panel up or down
#define OBC_NSS_SET_PARAMS_CMD_MID 0x1AC4          // set the NSS parameters
#define OBC_SET_SWITCH_STATE_CMD_MID 0x1AC5        // set switch on power msp
#define OBC_SET_SWITCH_STATE_ALL_CMD_MID 0x1AC6   // set all switch on power msp
#define OBC_RESET_SWITCH_CMD_MID 0x1AC7           // reset switch on power msp
#define OBC_SET_HEATER_STATE_CMD_MID 0x1AC8       // set heater state
#define OBC_SET_HEATER_STATE_ALL_CMD_MID 0x1AC9   // set all heater states
#define OBC_WIFI_ENABLE_CMD_MID 0x1ACA            // enable wifi
#define OBC_BATT_ENABLE_CMD_MID 0x1ACB            // enable battery
#define OBC_MASTER_COMM_ENABLE_CMD_MID 0x1ACC     // enable master msp
#define OBC_POWER_SWITCH_ENABLE_CMD_MID 0x1ACD    // enable power switching msp
#define OBC_PERIPHERAL_SENSOR_TLM_MID \
    0x0AC0   // receive all peripheral sensor data
#define OBC_HEALTH_TLM_MID \
    0x0AC1   // receive all peripheral computer health data
/**
 * GROUND Command Message IDs
 * @note Command message IDs in this section should fit within
 * 0x1B00-0x1B3F inclusive.
 * @note Telemetry message IDs in this section should fit within
 * 0x0B00-0x0B3F inclusive.
 */

/**
 * Table Manager Message IDs
 * @note Command message IDs in this section should fit within
 * 0x1B80-0x1BBF inclusive.
 * @note Telemetry message IDs in this section should fit within
 * 0x0B80-0x0BBF inclusive.
 */
#define TBL_MANAGER_CMD_MID 0x1B80
#define TBL_MANAGER_SEND_HK_MID 0x1B81
#define TBL_MANAGER_SEND_UPDATE_MID 0x1B82
#define TBL_MANAGER_HK_TLM_MID 0x0B81

/**
 * Logger App IDs
 * @note Command message IDs in this section should fit within
 * 0x1BC0-0x1BDF inclusive.
 * @note Telemetry message IDs in this section should fit within
 * 0x0BC0-0x0BFF inclusive.
 */

#define LOGGER_CMD_MID 0x1BC0
#define LOGGER_SEND_HK_MID 0x1BC1
#define LOGGER_HK_TLM_MID 0x0BC0

/**
 * FTP App IDs
 * @note Command message IDs in this section should fit within
 * 0x1BD0-0x1BDF inclusive.
 * @note Telemetry message IDs in this section should fit within
 * 0x0BC0-0x0BFF inclusive.
 */

#define FTP_CMD_MID 0x1BD0
#define FTP_SEND_HK_MID 0x1BD1
#define FTP_CONTROL 0x1BD2
#define FTP_SEND_ALL 0x1BD3
#define FTP_INIT 0x1BD4
#define FTP_HK_TLM_MID 0x0BD0

/**
 * MOONRANGER Common Message IDs
 * @note Command message IDs in this section should fit within
 * 0x1C00-0x1C3F inclusive.
 * @note Telemetry message IDs in this section should fit within
 * 0x0C00-0x0C3F inclusive.
 */
#define MOONRANGER_GOAL_MID 0x0C00
#define MOONRANGER_POSE_MID 0x0C01
#define MOONRANGER_POINT_CLOUD_MID 0x0C02
#define MOONRANGER_MESH_MID 0x0C03
#define MOONRANGER_BODY_VELOCITY_MID 0x0C04
#define MOONRANGER_WHEEL_VEL_CMD_MID 0x0C05
#define MOONRANGER_DRIVE_ARC_MID 0x0C06
#define MOONRANGER_SUNSENSOR_MID 0x0C07
#define MOONRANGER_CMD_VEL_MID 0x0C08
#define MOONRANGER_WHEEL_VEL_CUR_MID 0x0C09
#define MOONRANGER_ROVER_INIT_MID 0x0C0B
#define MOONRANGER_IMU_DATA_MID 0x0C10

/* FAUXRANGER Message IDs (these messages originate from the Unreal Simulation)
 */
#define FAUXRANGER_F_L_CAM_INFO_MID 0x0C21   // front left camera info
#define FAUXRANGER_F_R_CAM_INFO_MID 0x0C22   // front right camera info
#define FAUXRANGER_B_L_CAM_INFO_MID 0x0C23   // back left camera info
#define FAUXRANGER_B_R_CAM_INFO_MID 0x0C24   // back right camera info
#define FAUXRANGER_F_L_CAM_DATA_MID 0x0C25   // front left camera data
#define FAUXRANGER_F_R_CAM_DATA_MID 0x0C26   // front right camera data
#define FAUXRANGER_B_L_CAM_DATA_MID 0x0C27   // back left camera data
#define FAUXRANGER_B_R_CAM_DATA_MID 0x0C28   // back right camera data
#define FAUXRANGER_IMU_MID 0x0C29
#define FAUXRANGER_WHEELS_MID 0x0C2A
#define FAUXRANGER_ODOM_MID 0x0C2B
/* Command to save the next available point cloud captured from ROS to disk */
#define FAUXRANGER_PCL_CMD_MID 0x0C2C
/* Telemetry that indicates point cloud has been saved to disk */
#define FAUXRANGER_PCL_SAVED_TLM_MID 0x0940
/***************************************************************************/
/************************* Default cFS Apps ********************************/
/***************************************************************************/

/**
 * cFS Telemetry Output Message IDs
 * @note Message IDs are left to the default values because some of the
 * addresses are hard coded in the repo. It is safer to leave them as it is.
 */
#define TLM_OUTPUT_CMD_MID 0x1880
#define TLM_OUTPUT_SEND_HK_MID 0x1881

#define TLM_OUTPUT_HK_TLM_MID 0x0880
#define TLM_OUTPUT_DATA_TYPES_MID 0x0881

/**
 * Command Ingestion Message IDs
 * @note Message IDs are left to the default values because some of the
 * addresses are hard coded in the repo. It is safer to leave them as it is.
 */
#define CMD_INGEST_CMD_MID 0x1884
#define CMD_INGEST_SEND_HK_MID 0x1885
#define CMD_INGEST_HK_TLM_MID 0x0884

/**
 * Health and Safety Message IDs
 * @note Message IDs are left to the default values because some of the
 * addresses are hard coded in the repo. It is safer to leave them as it is.
 */
/** Msg ID for cmds to HS */
#define HS_CMD_MID 0x18AE
/** Msg ID to request HS housekeeping */
#define HS_SEND_HK_MID 0x18AF
/** Msg ID to wake up HS */
#define HS_WAKEUP_MID 0x18B0
/** HS Housekeeping Telemetry */
#define HS_HK_TLM_MID 0x08AD

/**
 * Scheduler Message IDs
 * @note Message IDs are left to the default values because some of the
 * addresses are hard coded into unit tests. It is safer to leave them as it is.
 */
/** SCH Ground Commands Message ID */
#define SCH_CMD_MID 0x1895
/** SCH Send Housekeeping Message ID */
#define SCH_SEND_HK_MID 0x1896
/** SCH MDT Unused Message Message ID */
#define SCH_UNUSED_MID 0x1897
/*
#define SCH_SPARE1                     0x1898
#define SCH_SPARE2                     0x1899
*/

/** SCH Housekeeping Telemetry Message ID */
#define SCH_HK_TLM_MID 0x0897
/** SCH Diagnostic Telemetry Message ID */
#define SCH_DIAG_TLM_MID 0x0898

/*
#define SCH_TLM_SPARE1                 0x0899
#define SCH_TLM_SPARE2                 0x089A
*/

#endif /* _moonranger_msgids_h_ */

/************************/
/*  End of File Comment */
/************************/
