/**
 *
 * \file mapper_msgs.h
 *
 * \purpose Define messages and info for mapper app
 *
 */

#ifndef _mapper_msgs_h_
#define _mapper_msgs_h_

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


/***************************************************
/*
** Type definition (MAPPER housekeeping/telemetry)
*/

typedef struct 
{
	uint8			CommandCounter;
	uint8			CommandErrorCounter;
	uint8			PoseCounter;
	uint8			GoalCounter;
	uint8			PclCounter;
	uint8			MeshCounter;
	uint8			spare[2];
} MAPPER_HkTlm_Payload_t;

typedef struct
{
	uint8			TlmHeader[CFE_SB_TLM_HDR_SIZE];
	MAPPER_HkTlm_Payload_t	Payload;
} OS_PACK MAPPER_HkTlm_t;


#endif /* _mapper_msgs_h_ */

/* EOF */
