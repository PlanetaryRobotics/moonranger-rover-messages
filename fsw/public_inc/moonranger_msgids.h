/**
 * @file moonranger_msgids.h
 *
 * @brief defines all MoonRanger Message IDs
 *
 *
 * @authors
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
 * Camera Driver Message IDs
 * @note  Command messages IDs in this section must be selected from 
 * usused numbers between 0x1200 and 0x127F inclusive
 * 
 * @note Telemetry Message IDs in this section must be selected from 
 * usused numbers between 0x0200 and 0x027F inclusive
  */



/**
 * Camera Interface Message IDs
 * @note  Command messages IDs in this section must be selected from 
 * usused numbers between 0x1280 and 0x12FF inclusive
 * 
 * @note Telemetry Message IDs in this section must be selected from 
 * usused numbers between 0x0280 and 0x02FF inclusive
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
#define POSE_SEND_HK_MID       0x18E3
#define POSE_CMD_MID           0x18E4
#define POSE_HK_TLM_MID        0x18E5

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
#define VEHICLE_SEND_HK_MID       0x1888
#define VEHICLE_CMD_MID           0x1889
#define VEHICLE_HK_TLM_MID        0x1890

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
#define TLM_OUTPUT_CMD_MID     0x1880
#define TLM_OUTPUT_SEND_HK_MID 0x1881

#define TLM_OUTPUT_HK_TLM_MID     0x0880
#define TLM_OUTPUT_DATA_TYPES_MID 0x0881


/**
 * Command Ingestion Message IDs
 * @note  Message IDS in this section should fit within
 * 0x0A00-0x0AFF inclusive.
 */
#define CMD_INGEST_CMD_MID     0x1884
#define CMD_INGEST_SEND_HK_MID 0x1885

#define CMD_INGEST_HK_TLM_MID 0x0884


/**
 * Health and Safety Message IDs
 * @note  Message IDS in this section should fit within
 * 0x0B00-0x0BFF inclusive.
 */
#define HS_CMD_MID           0x18AE    /**< \brief Msg ID for cmds to HS                */
#define HS_SEND_HK_MID       0x18AF    /**< \brief Msg ID to request HS housekeeping    */
#define HS_WAKEUP_MID        0x18B0    /**< \brief Msg ID to wake up HS                 */

/**
 * MOONRANGER Common Message IDs
 * @note  Message IDS in this section should fit within
 * 0x0C00-0x0CFF inclusive.
 */
#define MOONRANGER_GOAL_MID 0x0C00
#define MOONRANGER_POSE_MID 0x0C01
#define MOONRANGER_POINT_CLOUD_MID 0x0C02
#define MOONRANGER_MESH_MID 0x0C03
#define MOONRANGER_BODY_VELOCITY_MID 0x0890
#define MOONRANGER_WHEEL_VEL_CMD_MID 0x0891
#define MOONRANGER_DRIVE_ARC_MID 0x0892

#endif /* _moonranger_msgids_h_ */

/************************/
/*  End of File Comment */
/************************/