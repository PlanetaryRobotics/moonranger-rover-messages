/****************************************************************
 *
 * @file      rover_init_msg.h
 *
 * @brief     Type definition for Moonranger rover init message
 *
 * @version   1.0
 * @date      09 Feb 2022
 *
 * @authors 	Jacky Wang
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 ****************************************************************/

#ifndef _rover_init_h_
#define _rover_init_h_

#include "cfe_sb.h"
#include "moonranger_common_types.h"

/*************************************************************************/
/**
 * Type definition rover init message
 */
typedef struct {
    uint8 CmdHeader[CFE_SB_TLM_HDR_SIZE];
} OS_PACK MOONRANGER_RoverInit_Tlm_t;

// Message sizes
#define MOONRANGER_ROVER_INIT_TLM_LNGTH sizeof(MOONRANGER_RoverInit_Tlm_t)

#endif /* _rover_init_h_ */
