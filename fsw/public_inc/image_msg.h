/****************************************************************
 * 
 * @file      TODO
 * 
 * @brief     TODO
 * 
 * @version   TODO
 * @date   		TODO
 * 
 * @authors 	TODO
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 * 
 * @note		This file only contains app specific command and 
 * 				telemetry message definitions and command codes.
 * 
 ****************************************************************/


/*********************************************************************
 * INSTRUCTIONS
 * 
 * This file should contain all the type definitions for app specific messages such as
 * housekeeping / telemetry.
 * 
 * It should also contain definitions for all command messages and command codes.
 * 
 * All message IDs should be placed in moonranger_messageids.h in the appropriately marked location
 * 
 * DELETE THIS BLOCK ONCE COMPLETE
 *******************************************************************/

#ifndef _image_msg_h_
#define _image_msg_h_


#include "cfe_sb.h"
#include "common_types.h"


/**
 * @brief Image transport base msg.
 * 
 * DO NOT use this struct as msgs, use the derived msgs below.
 */
typedef struct
{
  uint64    Timestamp;          // nanoseconds on when img is captured
  uint32    SeqId;              // counter, the n-th img captured
  int       CamId;              // ID number of the camera
  int       ImgWidth;           // number of pixels
  int       ImgHeight;          // number of pixels
  int       ImgType;            // cv::Mat img type
  size_t    ImgSize;            // size of image data in bytes
  void*     ImgHandle;          // ptr to img data
  bool      IsValid;            // flag to check if img msg is valid
} MOONRANGER_Img_Base_t;

/**
 * @brief Image transport msg to pass mono image between cFE apps.
 * 
 * For SB transport, not to be used for algorithm in your app.
 * 
 * DO NOT use the struct directly to access images, use image_lib library.
 */
typedef struct
{
  CFE_SB_Msg_t          MsgHdr;
  MOONRANGER_Img_Base_t ImgBase;   // Image bas struct
  uint32                Mutex;     // mutex to access the data
} MOONRANGER_Mono_Img_Msg_t;


/**
 * @brief Stereo image transport msg to pass stereo image pair between cFE apps
 * 
 * For SB transport, not to be used for algorithm in your app
 * 
 * DO NOT use the struct directly to access images, use image_lib library.
 */
typedef struct
{
  CFE_SB_Msg_t          MsgHdr;
  MOONRANGER_Img_Base_t LeftImgBase;  // Left image base struct
  MOONRANGER_Img_Base_t RightImgBase; // Right image base struct
  uint32                Mutex;        // mutex to access the data
} MOONRANGER_Stereo_Img_Msg_t;

#endif /* _image_msg_h_ */

/************************/
/*  End of File Comment */
/************************/