/**
 * @file moonranger_msgids.h
 *
 * @brief defines all MoonRanger Message IDs
 *
 *
 * @author Carnegie Mellon University Planetary Robotics Lab
 * @note
 */

#ifndef _moonranger_msgids_h_
#define _moonranger_msgids_h_

/**
 * GROUND Command Message IDs
 * @note Message IDS in this section should fit within
 * 0x0F00-0xFFF inclusive.
 */

/**
 * IMU Driver Message IDs
 * @note  Message IDS in this section should fit within
 * 0x0100-0x01FF inclusive.
 */

/**
 * Camera Interface Message IDs
 * @note  Message IDS in this section should fit within
 * 0x0200-0x02FF inclusive.
 */
/* Command to save the next available image captured from camera to disk */
#define CAMERA_IF_CMD_MID 0x1886
/* Telemetry that indicates image has been saved to disk and that image needs to
 * be sent back to earth */
#define CAMERA_IF_IMG_SAVED_TLM_MID 0x0886

/* Housekeeping */
#define CAMERA_IF_SEND_HK_MID 0x1887
#define CAMERA_IF_HK_TLM_MID 0x0887

/**
 * State Estimator Message IDs
 * @note  Message IDS in this section should fit within
 * 0x0300-0x03FF inclusive.
 */

/**
 * Stereo Reconstructor Message IDs
 * @note  Message IDS in this section should fit within
 * 0x0400-0x04FF inclusive.
 */

/**
 * Mapper Message IDs
 * @note  Message IDS in this section should fit within
 * 0x0500-0x05FF inclusive.
 */
#define MAPPER_CMD_MID 0x1882
#define MAPPER_SEND_HK_MID 0x1883
#define MAPPER_HK_TLM_MID 0x0883

/**
 * Planner Message IDs
 * @note  Message IDS in this section should fit within
 * 0x0600-0x06FF inclusive.
 */

/**
 * Vehicle Controller Message IDs
 * @note  Message IDS in this section should fit within
 * 0x0700-0x07FF inclusive.
 */

/**
 * Peripheral Data Manager Message IDs
 * @note  Message IDS in this section should fit within
 * 0x0800-0x08FF inclusive.
 */

/**
 * Telemetry Output Message IDs
 * @note  Message IDS in this section should fit within
 * 0x0900-0x09FF inclusive.
 */

/**
 * Command Ingestion Message IDs
 * @note  Message IDS in this section should fit within
 * 0x0A00-0x0AFF inclusive.
 */

/**
 * Health and Safety Message IDs
 * @note  Message IDS in this section should fit within
 * 0x0B00-0x0BFF inclusive.
 */

/**
 * MOONRANGER Common Message IDs
 * @note  Message IDS in this section should fit within
 * 0x0C00-0x0CFF inclusive.
 */
#define MOONRANGER_GOAL_MID 0x0100
#define MOONRANGER_POSE_MID 0x0101
#define MOONRANGER_POINT_CLOUD_MID 0x0102
#define MOONRANGER_MESH_MID 0x0103
#define MOONRANGER_BODY_VELOCITY_MID 0x0890
#define MOONRANGER_WHEEL_VEL_CMD_MID 0x0891
#define MOONRANGER_DRIVE_ARC_MID 0x0892

#endif /* _moonranger_msgids_h_ */

/************************/
/*  End of File Comment */
/************************/
