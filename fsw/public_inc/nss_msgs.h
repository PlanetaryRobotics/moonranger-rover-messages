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
    int8 command_1;
    int8 command_2;
} set_nss_params_payload_t;

#define SET_NSS_PARAMS_PAYLOAD_LEN sizeof(set_nss_params_payload_t);

// NSS telemetry message
typedef struct {
    uint8 nss_data[89];   // data from sensor
    uint16 reboot_ctr;   // counter of number of times NSS IF has rebooted since
                         // last software load
    uint16 inv_msg_ctr;   // count of invalid messages received by NSS IF
} nss_telem_payload_t;

#define NSS_TELEM_PAYLOAD_LEN sizeof(nss_telem_payload_t);

/**************************************************************************
 * MASTER COMMS BUS UART MESSAGE DEFINITIONS
 **************************************************************************/
// get NSS telemetry message
typedef struct {
    main_bus_hdr_t msg_hdr;
    uint16 checksum;
} get_nss_telem_msg_t;

#define GET_NSS_TELEM_MSG_LEN sizeof(get_nss_telem_msg_t);

typedef struct {
    main_bus_hdr_t msg_hdr;
    set_nss_params_payload_t payload;
    uint16 checksum;
} set_nss_params_msg_t;

#define SET_NSS_PARAMS_MSG_LEN sizeof(set_nss_params_msg_t);

typedef struct {
    main_bus_hdr_t msg_hdr;
    nss_telem_payload_t payload;
    uint16 checksum;
} nss_telem_msg_t;

#define NSS_TELEM_MSG_LEN sizeof(nss_telem_msg_t);

/**************************************************************************
 * CFS SB MESSAGE DEFINITIONS
 **************************************************************************/

/**
 */
typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
    set_nss_params_payload_t payload;
} OS_PACK CFS_NSS_Set_Params_Cmd_t;

/**
 * Buffer to hold NSS set params data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    CFS_NSS_Set_Params_Cmd_t nss_set_params_cmd;
} NSS_Set_Params_Buffer_t;

// Message sizes
#define CFS_NSS_SET_PARAMS_CMD_LEN sizeof(CFS_NSS_Set_Params_Cmd_t);

#endif /* _nss_msgs_h */
