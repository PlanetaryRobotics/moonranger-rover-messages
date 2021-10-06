/****************************************************************
 * 
 * @file 		mapper_msgids.h
 * 
 * @brief 		Message IDs for mapper app.
 * 
 * @version 		1.0
 * @date 		10/05/2021
 * 
 * @authors 		Margaret Hansen
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 * 
 ****************************************************************/

#ifndef _mapper_msgids_h_
#define _mapper_msgids_h_

/**
 * Mapper command codes
 */

#define MAPPER_NOOP_CC 			0
#define MAPPER_RESET_COUNTERS_CC	1

/**
 * Mapper Message IDs
 */

#define MAPPER_CMD_MID            	0x1882
#define MAPPER_SEND_HK_MID        	0x1883
#define MAPPER_HK_TLM_MID		0x0883

#endif /* _mapper_msgids_h_ */

/* EOF */
