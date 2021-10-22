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
 * WARNING: do not use this msg directly, it is recommended to use
 * the API of sb_transport_lib to read/write the data as it provides
 * mutex locks to prevent data race conditions.
 */
typedef struct {
    CFE_SB_Msg_t MsgHdr;   // cFE generic msg header.
    void* DataHandle;      // Pointer to the data.
    size_t DataSize;       // Size of the data in bytes.
    bool IsValid;          // Flag to check if msg is valid.
} SB_Transport_Msg_t;

#endif   //_moonranger_sb_transport_lib_msg_h_
