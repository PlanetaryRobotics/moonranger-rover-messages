/****************************************************************
 * 
 * @file      point_cloud_msg.h
 * 
 * @brief     Type definition for Moonranger point cloud message
 * 
 * @version   1.0
 * @date      4 Nov 2021
 * 
 * @authors 	Tenzin Crouch, Ankur Bodhe
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 * 
 ****************************************************************/


#ifndef _point_cloud_msg_h_
#define _point_cloud_msg_h_

#include "cfe_sb.h"
#include "common_types.h"
/*************************************************************************/
/*
** Type definition (MOONRANGER Point cloud)
** TODO: define actual structure
*/

#define IMG_WIDTH  644
#define IMG_HEIGHT 366

typedef struct point_cloud_msg
{
    
    CFE_TIME_SysTime_t  timestamp;
    char*  cameraLabel;
    float32 pointCloud[IMG_WIDTH][IMG_HEIGHT][3];

}MOONRANGER_Pcl_t;

/**
 * Type definition (MOONRANGER pointCloud telemetry)
 * @note includes CFS TLM Header with timestamp
 */
typedef struct {
  uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
  MOONRANGER_Pcl_t pcl_data;
} OS_PACK MOONRANGER_Pcl_Tlm_t;

// Message sizes
#define MOONRANGER_POSE_LNGTH sizeof(MOONRANGER_Pcl_t)
#define MOONRANGER_POSE_TLM_LNGTH sizeof(MOONRANGER_Pcl_Tlm_t)

#endif /* _point_cloud_msg_h_ */

