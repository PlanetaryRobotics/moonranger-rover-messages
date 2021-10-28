/****************************************************************
 *
 * @file      sb_transport_msg.h
 *
 * @brief     The software bus large data transport msg definition file.
 *            This msg and the API defined in sb_transport_lib is to be used
 *            when you want to send a msg over SB that exceeds the size limit
 *            of cFS' SB (65536 bytes).
 *
 * @version   1.0
 * @date      10/21/2021
 *
 * @authors   Kelvin Kang, ...
 * @author    Carnegie Mellon University, Planetary Robotics Lab
 *
 ****************************************************************/

#ifndef _moonranger_sb_transport_lib_msg_h_
#define _moonranger_sb_transport_lib_msg_h_

#include <stdio.h>
#include "cfe_sb.h"

/**
 * @brief Generic Msg type for Software Bus Transport Library.
 *
 * Send this msg to inform other apps that you have written new data to the
 * shared memory buffer.
 * WARNING: use the API of sb_transport_lib for read/write.
 */
typedef struct {
    CFE_SB_Msg_t MsgHdr;   // cFE generic msg header.
} SB_Transport_Msg_t;

typedef SB_Transport_Msg_t SB_Stereo_Img_Transport_Msg_t;
typedef SB_Transport_Msg_t SB_Pcl_Transport_Msg_t;

#endif   //_moonranger_sb_transport_lib_msg_h_
