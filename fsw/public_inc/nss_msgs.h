/****************************************************************
 *
 * @file      nss_msgs.h
 *
 * @brief     all NSS related messages
 *
 * @date   		20 Feb 2022
 *
 * @authors 	Tenzin Crouch
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 * @note        Copyright 2022 Carnegie Mellon University. All rights reserved.
 ****************************************************************/

#ifndef _nss_msgs_h
#define _nss_msgs_h

#include "cfe_sb.h"
#include "master_comms_bus_protocol.h"
#include "moonranger_common_types.h"

#define NSS_DATA_LEN 89

/**************************************************************************
 * MOONRANGER MESSAGE PAYLOADS
 **************************************************************************/
// set NSS parameters message
/**
 * command1 bit 2~0: Detector Tube #2 Scalar threshold
 * command1 bit 5~3: Detector Tube #1 Scalar threshold
 * command2 LSB and command1 bit 7~6: Detector tube (both) HV setting
 *
 * @note bytes indexed from right to left (0: LSB, 7: MSB)
 */
typedef struct {
    uint8_t command_1;
    uint8_t command_2;
} set_nss_params_payload_t;

#define SET_NSS_PARAMS_PAYLOAD_LEN sizeof(set_nss_params_payload_t)

// NSS telemetry message
typedef struct {
    uint8_t nss_data[NSS_DATA_LEN];   // data from sensor
    uint8_t status;   // status byte: bit 0 = no telemetry, TODO: add more flags
                      // here
    msp_health_payload_t msp_health;
    uint16_t __padding;   // ensure 32 bit alignment for telemetry struct
} nss_telem_payload_t;

#define NSS_TELEM_PAYLOAD_LEN sizeof(nss_telem_payload_t)

// Preprocessor check of struct size
static_assert((96 == NSS_TELEM_PAYLOAD_LEN),
              "nss_telem_payload_t struct size incorrect (expected 96 bytes)");

static_assert(((NSS_TELEM_PAYLOAD_LEN % 4) == 0),
              "nss_telem_payload_t struct not 32 bit aligned");

/**************************************************************************
 * MASTER COMMS BUS UART MESSAGE DEFINITIONS
 **************************************************************************/
// get NSS telemetry message
typedef struct {
    main_bus_hdr_t msg_hdr;
    uint16_t checksum;
    uint16_t __padding;   // ensure messages are 32 bit aligned for consistency
} get_nss_telem_cmd_t;

#define GET_NSS_TELEM_CMD_LEN sizeof(get_nss_telem_cmd_t)

// Preprocessor check of struct size
static_assert((12 == GET_NSS_TELEM_CMD_LEN),
              "get_nss_telem_cmd_t struct size incorrect (expected 12 bytes)");

static_assert(((GET_NSS_TELEM_CMD_LEN % 4) == 0),
              "get_nss_telem_cmd_t struct not 32 bit aligned");

typedef struct {
    main_bus_hdr_t msg_hdr;
    set_nss_params_payload_t payload;
    uint16_t checksum;
    uint16_t __padding; //for consistent footer on MSPs commands
} set_nss_params_cmd_t;

#define SET_NSS_PARAMS_CMD_LEN sizeof(set_nss_params_cmd_t)

// Preprocessor check of struct size
static_assert((14 == SET_NSS_PARAMS_CMD_LEN),
              "set_nss_params_cmd_t struct size incorrect (expected 14 bytes)");

static_assert(((SET_NSS_PARAMS_CMD_LEN % 2) == 0),
              "set_nss_params_cmd_t struct not 16 bit aligned");

typedef struct {
    main_bus_hdr_t msg_hdr;
    nss_telem_payload_t payload;
    uint16_t checksum;
    uint16_t __padding;   // ensure messages are 32 bit aligned for consistency
} nss_telem_msg_t;

#define NSS_TELEM_MSG_LEN sizeof(nss_telem_msg_t)

// Preprocessor check of struct size
static_assert((108 == NSS_TELEM_MSG_LEN),
              "nss_telem_msg_t struct size incorrect (expected 108 bytes)");

static_assert(((NSS_TELEM_MSG_LEN % 4) == 0),
              "nss_telem_msg_t struct not 32 bit aligned");

#endif /* _nss_msgs_h */
