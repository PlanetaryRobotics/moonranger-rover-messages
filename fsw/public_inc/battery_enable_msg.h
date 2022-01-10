/****************************************************************
 *
 * @file      battery_enable_msg.h
 *
 * @brief     Type definition for Moonranger battery enable message
 *
 * @version   1.0
 * @date      20 Dec 2021
 *
 * @authors 	Saksham Khurana
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 ****************************************************************/

#ifndef _battery_enable_h_
#define _battery_enable_h_

#include "cfe_sb.h"
#include "moonranger_common_types.h"

/*************************************************************************/
/**
 * Type definition battery enable command
 */
typedef struct
{
  uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
} BatteryEnable_Cmd_t;

// Message sizes
#define BATTERY_ENABLE_CMD_LNGTH sizeof(BatteryEnable_Cmd_t)

#endif /* _battery_enable_h_ */
