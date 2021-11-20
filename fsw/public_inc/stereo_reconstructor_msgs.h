/**************************************************************** * *
 * @file stereo_reconstructor_msgs.h
 * @brief stereo reconstructor msgs
 * @version 1.0 *
 * @date 11/13 * *
 * @authors Amy Lin *
 * @author Carnegie Mellon University, Planetary Robotics Lab * * *
 * @note This file only contains app
 * specific command and * telemetry message definitions and command codes.
 * ****************************************************************/
#ifndef _stereo_reconstructor_msgs_h
#define _stereo_reconstructor_msgs_h

/*************************************************************************/
/*** STEREO App command codes*/
#define STEREO_NOOP_CC 0
#define STEREO_RESET_COUNTERS_CC 1

/*************************************************************************/
/*** Msg IDs*/

#define STEREO_CMD_MID 0x18A0
#define STEREO_SEND_HK_MID 0x18A1
#define STEREO_HK_TLM_MID 0x18A2

/*************************************************************************/
/*** Type definition (generic "no arguments" command)*/

typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];
} STEREO_NoArgsCmd_t;

/*** The following commands all share the "NoArgs" format**** They are each
 * given their own type name matching the command name, which_open_mode** allows
 * them to change independently in the future without changing the prototype**
 * of the handler function*/
typedef STEREO_NoArgsCmd_t STEREO_Noop_t;
typedef STEREO_NoArgsCmd_t STEREO_ResetCounters_t;
typedef STEREO_NoArgsCmd_t STEREO_Process_t;
/*************************************************************************/ /***
                                                                               Type definition (STEREO App housekeeping)*/
typedef struct {
    uint8 CommandErrorCounter;
    uint8 CommandCounter;
    uint8 spare[2];
} STEREO_HkTlm_Payload_t;
typedef struct {
    uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
    STEREO_HkTlm_Payload_t Payload;
} OS_PACK STEREO_HkTlm_t;
#endif /* _stereo_reconstructor_msg_h_ */
