/****************************************************************
 *
 * @file      sunsensor_msg.h
 *
 * @brief     Type definition for sun sensor telemetry and command messages
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

#define SYNC_WORD_LEN 4
#define APP_DATA_LEN 9
#define PHOTO_VOLT_DATA_LEN 16

/*************************************************************************/
/**
 * @struct SunSensorCmd_t
 * @brief  Type definition for Sun sensor command
 * 
 * */
typedef struct {
    unsigned char sync_word[SYNC_WORD_LEN];  // sync word to indicate start of new frame, 0x1ACFFC1D
    unsigned char cmd_code;   // command code in 0xXX format
                            // allowed values: 
                            // 0x01 - request for voltages values of photocells without filtering
                            // 0x03 - request for voltages values of photocells with filtering
                            // 0x04 - request for angular positions (alpha, beta) and error code
    unsigned char msg_len;    // length of commange message, always 0x1
    unsigned char checksum;   // dependent on command code, see struct description
                            // allowed values: 
                            // 0x02 - when command code 0x01
                            // 0x04 - when command code 0x03
                            // 0x05 - when command code 0x04
} SunSensorCmd_t;

/**
 * Type definition (SunSensor command)
 * @note includes CFS CMD Header with timestamp
 */
typedef struct {
  uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
  SunSensorCmd_t data;
} SunSensorCmd_Cmd_t;

#define SUNSENSOR_CMD_LNGTH sizeof(SunSensorCmd_Cmd_t)

/**
 * @union  sun_sensor_data_t
 * @brief  Type definition for Sun sensor core data field
 * @TODO:  get this reviewed if there is a better way to do this
 * */
typedef union {
    unsigned char voltage_data[PHOTO_VOLT_DATA_LEN];  // magic number 16 comes from data sheet where
                                           // voltages are reported as 4 chunks of 4 bytes each
    unsigned char app_data[APP_DATA_LEN];  // magic number 9 comes from data sheet where alpha
                                           // and beta angles are 4 bytes each, error code is 1 byte
}  sun_sensor_data_t;

/**
 * @struct SunSensorTlm_t
 * @brief  Type definition for Sun sensor response
 * 
 * */
typedef struct {
    unsigned char sync_word[SYNC_WORD_LEN];  // sync word to indicate start of new frame, 0x1ACFFC1D
    unsigned char cmd_code; // command code in 0xXX format
                            // expected values: 
                            // 0x01 - request for voltages values of photocells without filtering
                            // 0x03 - request for voltages values of photocells with filtering
                            // 0x04 - request for angular positions (alpha, beta) and error code
    unsigned char msg_len;  // length of response message, integer between [3-17] (inclusive)
                            // 0x11 - when command code 0x01 or 0x03
                            // 0x0A - when command code 0x04
    sun_sensor_data_t sun_sensor_data;  // data corresponding to last request made through the command
    unsigned char checksum;   // add all bytes in cmd_code, msg_len, app_data
                              // and extract LSB
} SunSensorTlm_t;

/**
 * Type definition (SunSensor telemetry)
 * @note includes CFS TLM Header with timestamp
 */
typedef struct {
  uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];;
  SunSensorTlm_t data;
} SunSensorTlm_Tlm_t;

/**
 * Buffer to hold goal data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union
{
    CFE_SB_Msg_t           MsgHdr;
    SunSensorTlm_Tlm_t     SunSensorTlm;
} MOONRANGER_SunSensorBuffer_t;

// Message sizes
#define MOONRANGER_SUNSENSOR_LNGTH sizeof(SunSensorTlm_t)
#define MOONRANGER_SUNSENSOR_TLM_LNGTH sizeof(SunSensorTlm_Tlm_t)



#endif /* _sunsensor_msg_h */
