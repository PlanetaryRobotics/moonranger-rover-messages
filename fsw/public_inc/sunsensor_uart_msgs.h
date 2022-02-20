/****************************************************************
 *
 * @file      sunsensor_msg.h
 *
 * @brief     Type definition for sun sensor telemetry and command messages
 *betweem Suns Sensor Interface and Sun sensor
 *
 * @version   1.0
 * @date      07 Feb 2022
 *
 * @authors 	Saksham Khurana
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 ****************************************************************/

#ifndef _sunsensor_msg_h
#define _sunsensor_msg_h

#include "cfe_sb.h"
#include "moonranger_common_types.h"

#define WORD_LEN 4
#define SYNC_WORD 0x1ACFFC1D   // for use while sending messages

/*************************************************************************/
/**
 * @struct SunSensorCmd_t
 * @brief  Type definition for Sun sensor command
 * @TODO: Should the sync_word be included in the message structure or
 *        should there be a separate base message without sync word for
 *        use by cFS and another one with sync word for use by MSP?
 * */
typedef struct {
    unsigned char sync_word[WORD_LEN];   // sync word to indicate start of new
                                         // frame, 0x1ACFFC1D
    unsigned char
        cmd_code;   // command code in 0xXX format
                    // allowed values:
                    // 0x01 - request for voltages values of photocells without
                    // filtering 0x03 - request for voltages values of
                    // photocells with filtering 0x04 - request for angular
                    // positions (alpha, beta) and error code
    unsigned char msg_len;   // length of command message, always 0x1
    unsigned char
        checksum;   // dependent on command code, see struct description
                    // allowed values:
                    // 0x02 - when command code 0x01
                    // 0x04 - when command code 0x03
                    // 0x05 - when command code 0x04

} SunSensorCmd_t;

#endif /* _sunsensor_msg_h */
