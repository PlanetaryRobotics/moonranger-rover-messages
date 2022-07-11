/****************************************************************
 *
 * @file      moonranger_generic_msgs.h
 *
 * @brief     Type definitions for basic general moonranger messages
 *
 * @version   1.0
 * @date   		19 Oct 2021
 *
 * @authors 	Tenzin Crouch
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 * @note		This file only contains app specific command and
 * 				telemetry message definitions and command codes.
 *
 ****************************************************************/

#ifndef _moonranger_msg_h_
#define _moonranger_msg_h_

/*
** MOONRANGER command codes
*/

/*************************************************************************/

/*
** Type definition (generic "no arguments" command)
*/
typedef struct {
    uint8 CmdHeader[CFE_SB_CMD_HDR_SIZE];

} MOONRANGER_NoArgsCmd_t;

/*
** The following commands all share the "NoArgs" format
**
** They are each given their own type name matching the command name,
*which_open_mode
** allows them to change independently in the future without changing the
*prototype
** of the handler function
*/
typedef MOONRANGER_NoArgsCmd_t MOONRANGER_Noop_t;
typedef MOONRANGER_NoArgsCmd_t MOONRANGER_ResetCounters_t;
typedef MOONRANGER_NoArgsCmd_t MOONRANGER_Process_t;

#endif /* _moonranger_msg_h_ */

/************************/
/*  End of File Comment */
/************************/