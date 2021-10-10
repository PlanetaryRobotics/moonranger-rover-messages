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
 * @note		This file only contains app specific command and 
 * 				telemetry message definitions and command codes.
 * 
 ****************************************************************/

#ifndef _health_safety_msg_h_
#define _health_safety_msg_h_

/************************************************************************
** Includes
*************************************************************************/
#include "hs_msgdefs.h"
#include "hs_platform_cfg.h"
#include "cfe.h"

/************************************************************************
** Macro Definitions
*************************************************************************/
/**
** \brief HS Bits per AppMon Enable entry */
/** \{ */
#define HS_BITS_PER_APPMON_ENABLE 32
/** \} */

/************************************************************************
** Type Definitions
*************************************************************************/
/**
**  \brief No Arguments Command
**  For command details see #HS_NOOP_CC, #HS_RESET_CC, #HS_ENABLE_APPMON_CC, #HS_DISABLE_APPMON_CC,
**  #HS_ENABLE_EVENTMON_CC, #HS_DISABLE_EVENTMON_CC, #HS_ENABLE_ALIVENESS_CC, #HS_DISABLE_ALIVENESS_CC,
**  #HS_RESET_RESETS_PERFORMED_CC
**  Also see #HS_SEND_HK_MID
*/
typedef struct
{
    CFE_SB_CmdHdr_t  CmdHeader;
} HS_NoArgsCmd_t;

/**
**  \brief Set Max Resets Command
**  For command details see #HS_SET_MAX_RESETS_CC
*/
typedef struct
{
    CFE_SB_CmdHdr_t  CmdHeader;
    uint16           MaxResets;
    uint16           Padding;     /**< \brief Structure padding */
} HS_SetMaxResetsCmd_t;

/**
**  \hstlm Housekeeping Packet Structure
*/
typedef struct
{
    CFE_SB_TlmHdr_t   TlmHeader; /**< \brief cFE SB Tlm Msg Hdr */

    uint8     CmdCount;                       /**< \hstlmmnemonic \HS_CMDPC
                                                        \brief HS Application Command Counter       */
    uint8     CmdErrCount;                    /**< \hstlmmnemonic \HS_CMDEC
                                                        \brief HS Application Command Error Counter */
    uint8     CurrentAppMonState;             /**< \hstlmmnemonic \HS_APPMONSTATE
                                                        \brief Status of HS Application Monitor     */
    uint8     CurrentEventMonState;           /**< \hstlmmnemonic \HS_EVTMONSTATE
                                                        \brief Status of HS Event Monitor */
    uint8     CurrentAlivenessState;          /**< \hstlmmnemonic \HS_CPUALIVESTATE
                                                        \brief Status of HS Aliveness Indicator     */
    uint8     CurrentCPUHogState;             /**< \hstlmmnemonic \HS_CPUHOGSTATE
                                                        \brief Status of HS Hogging Indicator     */
    uint8     StatusFlags;                    /**< \hstlmmnemonic \HS_STATUSFLAGS
                                                        \brief Internal HS Error States*/
    uint8     SpareBytes;                     /**< \hstlmmnemonic \HS_SPAREBYTES
                                                        \brief Alignment Spares*/
    uint16    ResetsPerformed;                /**< \hstlmmnemonic \HS_PRRESETCNT
                                                        \brief HS Performed Processor Reset Count   */
    uint16    MaxResets;                      /**< \hstlmmnemonic \HS_MAXRESETCNT
                                                        \brief HS Maximum Processor Reset Count   */
    uint32    EventsMonitoredCount;           /**< \hstlmmnemonic \HS_EVTMONCNT
                                                        \brief Total count of Event Messages
                                                         Monitored by the Events Monitor   */
    uint32    InvalidEventMonCount;           /**< \hstlmmnemonic \HS_INVALIDEVTAPPCNT
                                                        \brief Total count of Invalid Event Monitors
                                                         Monitored by the Events Monitor   */
    uint32    AppMonEnables[((HS_MAX_MONITORED_APPS - 1) / HS_BITS_PER_APPMON_ENABLE)+1];/**< \hstlmmnemonic \HS_APPSTATUS
                                                        \brief Enable states of App Monitor Entries */
    uint32    MsgActExec;                     /**< \hstlmmnemonic \HS_MSGACTEXEC
                                                        \brief Number of Software Bus Message Actions Executed */
    uint32    UtilCpuAvg;                     /**< \hstlmmnemonic \HS_UTILAVG
                                                        \brief Current CPU Utilization Average */
    uint32    UtilCpuPeak;                    /**< \hstlmmnemonic \HS_UTILPEAK
                                                        \brief Current CPU Utilization Peak */
#if HS_MAX_EXEC_CNT_SLOTS != 0
    uint32    ExeCounts[HS_MAX_EXEC_CNT_SLOTS]; /**< \hstlmmnemonic \HS_EXECUTIONCTR
                                                             \brief Execution Counters              */
#endif

} HS_HkPacket_t;

#endif /* _health_safety_msg_h_ */

/************************/
/*  End of File Comment */
/************************/

