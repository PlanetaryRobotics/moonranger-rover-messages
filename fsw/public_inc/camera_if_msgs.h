/****************************************************************
 * 
 * @file 		camera_if.h
 * 
 * @brief 		Message typedefs for camera interface app.
 * 
 * @version 		1.0
 * @date 		10/09/2021
 * 
 * @authors 	Kelvin Kang
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 * 
 * @note		This file only contains app specific command and 
 * 				telemetry message definitions and command codes.
 * 
 ****************************************************************/
#ifndef _camera_if_msgs_h
#define _camera_if_msgs_h

#include "cfe_sb.h"
#include "common_types.h"

/*
** CAMERA_IF app command codes
*/
#define CAMERA_IF_NOOP_CC                   0
#define CAMERA_IF_RESET_COUNTERS_CC         1
#define CAMERA_IF_SAVE_IMAGE_CC             2
#define CAMERA_IF_SEND_STEREO_IMAGE_CC      3

/*************************************************************************/
/*
** Type definition Commands Msg Types
*/

/* Generic "no arguments" command */
typedef struct
{
  uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
} CAMERA_IF_NoArgsCmd_t;

typedef CAMERA_IF_NoArgsCmd_t CAMERA_IF_Noop_t;
typedef CAMERA_IF_NoArgsCmd_t CAMERA_IF_ResetCounters_t;
typedef CAMERA_IF_NoArgsCmd_t CAMERA_IF_SaveImage_t;
typedef CAMERA_IF_NoArgsCmd_t CAMERA_IF_SendStereoImg_t;

/*************************************************************************/
/*
** Type definition Camera Interface Housekeeping Telemetry
*/

/* Housekeeping payload */
typedef struct
{
  uint8 CommandErrorCounter;
  uint8 CommandCounter;
  uint16 LeftImgReadCentiHz;
  uint16 RightImgReadCentiHz;
  uint16 PublishImgPairCentiHz;
  uint32 MaxImgPairTimeStampDeltaNs;
} CAMERA_IF_HkTlm_Payload_t;

typedef struct
{
  uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
  CAMERA_IF_HkTlm_Payload_t Payload;
} OS_PACK CAMERA_IF_HkTlm_t;

typedef struct
{
  uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
} OS_PACK CAMERA_IF_ImgSavedTlm_t;

#endif /* _camera_if_msgs_h */
