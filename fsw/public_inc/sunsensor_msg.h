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

#define WORD_LEN 4
#define SYNC_WORD 0x1ACFFC1D // for use while sending messages

/*************************************************************************/
/**
 * @struct SunSensorCmd_t
 * @brief  Type definition for Sun sensor command
 * @TODO: Should the sync_word be included in the message structure or 
 *        should there be a separate base message without sync word for
 *        use by cFS and another one with sync word for use by MSP?
 * */
typedef struct {
    unsigned char sync_word[WORD_LEN];  // sync word to indicate start of new frame, 0x1ACFFC1D
    unsigned char cmd_code;   // command code in 0xXX format
                              // allowed values: 
                              // 0x01 - request for voltages values of photocells without filtering
                              // 0x03 - request for voltages values of photocells with filtering
                              // 0x04 - request for angular positions (alpha, beta) and error code
    unsigned char msg_len;    // length of command message, always 0x1
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
 * @struct  voltage_data
 * @brief   Type definition for Sun sensor voltage data field
 * */
typedef struct {
    unsigned char uSSA1F[WORD_LEN];  // voltages are reported as 4 chunks of 4 bytes each
    unsigned char uSSA2F[WORD_LEN];  // voltages are reported as 4 chunks of 4 bytes each
    unsigned char uSSA3F[WORD_LEN];  // voltages are reported as 4 chunks of 4 bytes each
    unsigned char uSSA4F[WORD_LEN];  // voltages are reported as 4 chunks of 4 bytes each
    
} voltage_data_t;

/**
 * @struct  app_data
 * @brief   Type definition for Sun sensor voltage data field
 * */
typedef struct {
    unsigned char alpha[WORD_LEN];     // alpha angle
    unsigned char beta[WORD_LEN];      // beta angle
    unsigned char err_code;  // error code
                             // 0 No error. Angles were calculated successfully
                             // 11 Albedo: Earth; Sun sensor does not see the Sun, but Earth, and 
                             // the reflected sun-light is affecting measurement of the sensor.
                             // 12 Albedo: Earth + Sun; Sun sensor sees the Sun and the Earth, 
                             // because received solar radiation level is higher than 1360 
                             // W/m2, with a tolerance of 10%, so a reflected sun-light is 
                             // affecting measurement.
                             // Other values: internal mfg error codes
    
} app_data_t;

/**
 * @union  sun_sensor_data_t
 * @brief  Type definition for Sun sensor core data field
 * @TODO:  get this reviewed if there is a better way to do this
 * */
typedef union {
    voltage_data_t voltage_data;    // voltages are reported as 4 chunks of 4 bytes each
    app_data_t app_data;            // sun angles reported with error code
}  sun_sensor_data_t;

/**
 * @struct SunSensorTlm_t
 * @brief  Type definition for Sun sensor response
 * 
 * */
typedef struct {
    unsigned char sync_word[WORD_LEN];  // sync word to indicate start of new frame, 0x1ACFFC1D
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
