/*/****************************************************************
 * 
 * @file 		vc_msgids.h
 * 
 * @brief 		The message id definitions for the vehicle controller app
 * 
 * @version 	1.0
 * @date 		10/7/2021
 * 
 * @authors 	Ben Kolligs, ...
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 * 
 ****************************************************************/
#ifndef _vc_msgids_h_
#define _vc_msgids_h_


/*
 * Vehicle Controller Message IDS
 */
#define VEHICLE_SEND_HK_MID       0x1888
#define VEHICLE_CMD_MID           0x1889
#define VEHICLE_HK_TLM_MID        0x1890
/**
 * Vehicle App command codes
 */
#define VEHICLE_NOOP_CC               0
#define VEHICLE_RESET_COUNTERS_CC     1
#define VEHICLE_UPDATE_PARAMS_CC      2

#endif //_vc_msgids_h_ header

/* EOF */