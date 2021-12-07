/****************************************************************
 *
 * @file      drive_arc_msg.h
 *
 * @brief     Type definition for Moonranger drive arc message
 *
 * @version   1.0
 * @date      19 Oct 2021
 *
 * @authors 	Tenzin Crouch
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 ****************************************************************/

#ifndef _drive_arc_msg_h_
#define _drive_arc_msg_h_

#include "cfe_sb.h"
#include "common_types.h"

typedef float float32;

/*************************************************************************/
/**
 * Type definition (MOONRANGER drive arc packet)
 */
typedef struct {
  CFE_TIME_SysTime_t timeStamp; 
  float32            speed;    // m/s
  float32            duration; // seconds
  float32            radius;   // meters

} MOONRANGER_DriveArc_t;

/**
 * Type definition (MOONRANGER drive arc telemetry)
 * @note includes CFS TLM Header with timestamp
 */
typedef struct {
  uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
  MOONRANGER_DriveArc_t data;
} OS_PACK MOONRANGER_DriveArc_Tlm_t;

/**
 * Buffer to hold drive arc data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union
{
    CFE_SB_Msg_t               MsgHdr;
    MOONRANGER_DriveArc_Tlm_t  DriveArcTlm;
} MOONRANGER_DriveArcBuffer_t;

// Message sizes
#define MOONRANGER_DRIVE_ARC_LNGTH sizeof(MOONRANGER_DriveArc_t)
#define MOONRANGER_DRIVE_ARC_TLM_LNGTH sizeof(MOONRANGER_DriveArc_Tlm_t)

#endif /* _drive_arc_msg_h_ */
