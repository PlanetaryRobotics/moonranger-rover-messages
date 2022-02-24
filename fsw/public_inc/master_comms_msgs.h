/****************************************************************
 *
 * @file     master_comms_msgs.h
 *
 * @brief     definitions for all messages related to power switching master
 *comms bus
 *
 * @date   		20 Feb 2022
 *
 * @authors 	Tenzin Crouch
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 * @note        Copyright 2022 Carnegie Mellon University. All rights reserved.
 ****************************************************************/

#ifndef master_comms_msgs_h
#define master_comms_msgs_h

#include "cfe_sb.h"
#include "heater_control_msgs.h"
#include "master_comms_bus_protocol.h"
#include "moonranger_common_types.h"
#include "motor_control_msgs.h"
#include "nss_msgs.h"
#include "power_switching_msgs.h"
#include "sunsensor_msgs.h"

// SPI header definition
typedef struct {
    uint16 msg_seq;
    master_comms_bus_msg_id_t msg_id;
} periph_main_link_hdr_t;

/**************************************************************************
 * MOONRANGER MESSAGE PAYLOADS
 **************************************************************************/
typedef struct {
    motor_health_payload_t motor_health_data;
    nss_telem_payload_t nss_telem;
    sunsensor_data_payload_t sunsensor_data;
    power_switch_telem_payload_t power_switch_telem;
    heater_telem_payload_t heater_telem;
    uint16 reboot_ctr;         // counter of number of times master MSP has
                               // rebooted since last software load
    uint16 inv_uart_msg_ctr;   // count of invalid UART messages received by
                               // master MSP
    uint16 inv_spi_msg_ctr;    // count of invalid messages SPI received by
                               // master MSP
} peripheral_data_payload_t;

#define PERIPHERAL_DATA_PAYLOAD_LEN sizeof(peripheral_data_payload_t);

/**************************************************************************
 * PERIPHERAL-MASTER COMMS LINK MESSAGE DEFINITIONS
 **************************************************************************/
typedef struct {
    periph_main_link_hdr_t msg_hdr;
    uint16 checksum;
} get_peripheral_data_msg_t;

#define GET_PERIPHERAL_DATA_MSG_LEN sizeof(get_peripheral_data_msg_t);

typedef struct {
    periph_main_link_hdr_t msg_hdr;
    peripheral_data_payload_t payload;
    uint16 checksum;
} peripheral_data_msg_t;

#define PERIPHERAL_DATA_MSG_LEN sizeof(peripheral_data_msg_t);

/**************************************************************************
 * CFS SB MESSAGE DEFINITIONS
 **************************************************************************/
typedef struct {
    uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
    peripheral_data_payload_t payload;
} OS_PACK CFS_Peripheral_Tlm_t;

/**
 * Buffer to hold data prior to sending
 * Defined as a union to ensure proper alignment for a CFE_SB_Msg_t type
 */
typedef union {
    CFE_SB_Msg_t MsgHdr;
    CFS_Peripheral_Tlm_t peripheral_telem;
} CFS_Peripheral_Tlm_Buffer_t;

// Message sizes
#define CFS_PERIPHERAL_TELEM_LEN sizeof(CFS_Peripheral_Tlm_t);
#endif /* master_comms_msgs_h */