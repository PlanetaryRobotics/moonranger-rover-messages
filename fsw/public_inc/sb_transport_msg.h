/****************************************************************
 *
 * @file      sb_transport_msg.h
 *
 * @brief     The software bus msg definition file
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
 */
typedef struct {
    CFE_SB_Msg_t MsgHdr;   // cFE generic msg header.
    void* DataHandle;      // Pointer to the data.
    size_t DataSize;       // Size of the data in bytes.
    bool IsValid;          // Flag to check if msg is valid.
} SB_Transport_Msg_t;

#endif   //_moonranger_sb_transport_lib_msg_h_
