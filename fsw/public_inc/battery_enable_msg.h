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
typedef struct {
  CFE_TIME_SysTime_t timeStamp;   // nanoseconds
  uint8_t            battEnable;  // will look for uint8_max for enabling battery
} MOONRANGER_battery_enable_t;

/**
 * Type definition (battery enable telemetry)
 * @note includes CFS TLM Header with timestamp
 */
typedef struct {
  uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
  MOONRANGER_battery_enable_t batt_en_data;
} MOONRANGER_battery_enable_t_Tlm_t;

// Message sizes
#define MOONRANGER_BATTERY_ENABLE_LNGTH sizeof(battery_enable_t)
#define MOONRANGER_BATTERY_ENABLE_TLM_LNGTH sizeof(battery_enable_t_Tlm_t)

#endif /* _battery_enable_h_ */
