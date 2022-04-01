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
 * 
 * @note		This file only contains app specific command and 
 * 				telemetry message definitions and command codes.
 ****************************************************************/


/*************************************************************************/
#ifndef _tlm_output_msg_h_
#define _tlm_output_msg_h_

#include "cfe_sb.h"
#include "moonranger_common_types.h"

#define TO_NOP_CC             0 /*  no-op command     */
#define TO_RESET_STATUS_CC    1 /*  reset status      */
#define TO_ADD_PKT_CC         2 /*  add packet        */
#define TO_SEND_DATA_TYPES_CC 3 /*  send data types   */
#define TO_REMOVE_PKT_CC      4 /*  remove packet     */
#define TO_REMOVE_ALL_PKT_CC  5 /*  remove all packet */
#define TO_OUTPUT_ENABLE_CC   6 /*  output enable     */

/******************************************************************************/

typedef struct
{
    uint8 CommandCounter;
    uint8 CommandErrorCounter;
    uint8 spareToAlign[2];
} TLM_OUTPUT_HkTlm_Payload_t;


typedef struct
{
    uint8                  TlmHeader[CFE_SB_TLM_HDR_SIZE];
    TLM_OUTPUT_HkTlm_Payload_t Payload;
} TLM_OUTPUT_HkTlm_t;

#define TO_HK_TLM_LNGTH sizeof(TLM_OUTPUT_HkTlm_t)

/******************************************************************************/

typedef struct
{
    uint16 synch;
#if 0
    bit_field          bit1:1;
    bit_field          bit2:1;
    bit_field          bit34:2;
    bit_field          bit56:2;
    bit_field          bit78:2;

    bit_field          nibble1:4;
    bit_field          nibble2:4;
#endif
    uint8  bl1, bl2; /* boolean */
    int8   b1, b2, b3, b4;
    int16  w1, w2;
    int32  dw1, dw2;
    float  f1, f2;
    double df1, df2;
    char   str[10];
} TLM_OUTPUT_DataTypes_Payload_t;

typedef struct
{
    uint8                      TlmHeader[CFE_SB_TLM_HDR_SIZE];
    TLM_OUTPUT_DataTypes_Payload_t Payload;
} TLM_OUTPUT_DataTypes_t;

#define TO_DATA_TYPES_LNGTH sizeof(TLM_OUTPUT_DataTypes_t)

/******************************************************************************/

typedef struct
{
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];

} TLM_OUTPUT_NoArgsCmd_t;

/*
 * The following commands do not have any payload,
 * but should still "reserve" a unique structure type to
 * employ a consistent handler pattern.
 *
 * This matches the pattern in CFE core and other modules.
 */
typedef TLM_OUTPUT_NoArgsCmd_t TLM_OUTPUT_Noop_t;
typedef TLM_OUTPUT_NoArgsCmd_t TLM_OUTPUT_ResetCounters_t;
typedef TLM_OUTPUT_NoArgsCmd_t TLM_OUTPUT_RemoveAll_t;
typedef TLM_OUTPUT_NoArgsCmd_t TLM_OUTPUT_SendDataTypes_t;

#define TLM_OUTPUT_CMD_TLM_LNGTH sizeof(TLM_OUTPUT_NoArgsCmd_t)

typedef struct
{
    CFE_SB_MsgId_t Stream;
    uint16         PktSize;
    CFE_SB_Qos_t   Flags;
    uint8          BufLimit;
} TLM_OUTPUT_AddPacket_Payload_t;

typedef struct
{
    uint8                      CmdHeader[CFE_SB_CMD_HDR_SIZE];
    TLM_OUTPUT_AddPacket_Payload_t Payload;
} TLM_OUTPUT_AddPacket_t;

/*****************************************************************************/

typedef struct
{
    CFE_SB_MsgId_t Stream;
    CFE_SB_Qos_t   Flags;
    uint16         BufLimit;
} TO_subscription_t;

/******************************************************************************/

typedef struct
{
    CFE_SB_MsgId_t Stream;
} TLM_OUTPUT_RemovePacket_Payload_t;

typedef struct
{
    uint8                         CmdHeader[CFE_SB_CMD_HDR_SIZE];
    TLM_OUTPUT_RemovePacket_Payload_t Payload;
} TLM_OUTPUT_RemovePacket_t;

/******************************************************************************/

typedef struct
{
    char dest_IP[16];
} TLM_OUTPUT_EnableOutput_Payload_t;

typedef struct
{
    uint8                         CmdHeader[CFE_SB_CMD_HDR_SIZE];
    TLM_OUTPUT_EnableOutput_Payload_t Payload;
} TLM_OUTPUT_EnableOutput_t;

typedef union
{
    CFE_SB_Msg_t   MsgHdr;
    TLM_OUTPUT_HkTlm_t HkTlm;
} TLM_OUTPUT_HkTlm_Buffer_t;

typedef union
{
    CFE_SB_Msg_t       MsgHdr;
    TLM_OUTPUT_DataTypes_t DataTypes;
} TLM_OUTPUT_DataTypes_Buffer_t;
/******************************************************************************/

#endif /* _tlm_output_msg_h_ */

/************************/
/*  End of File Comment */
/************************/
