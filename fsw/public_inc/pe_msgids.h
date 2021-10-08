/****************************************************************
 * 
 * @file 		pe_msgids.h
 * 
 * @brief 		The message definitions IDS for the pose estimation app
 * 
 * @version 	1.0
 * @date 		10/8/2021
 * 
 * @authors 	Ben Kolligs, ...
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 * 
 ****************************************************************/
#ifndef _pe_msgids_h_
#define _pe_msgids_h_

/**
 * Pose estimator message IDs
 */
#define POSE_SEND_HK_MID       0x18E3
#define POSE_CMD_MID           0x18E4
#define POSE_HK_TLM_MID        0x18E5

/**
 * Pose estimation app command codes
 */
#define POSE_NOOP_CC               0
#define POSE_RESET_COUNTERS_CC     1
#define POSE_UPDATE_PARAMS_CC      2

#endif //_pe_msgids_h_ header

/* EOF */