/****************************************************************
 * 
 * @file 		mapper_msg.h
 * 
 * @brief 		Message typedefs for mapper app.
 * 
 * @version 		1.0
 * @date 		10/05/2021
 * 
 * @authors 		Margaret Hansen
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 * 
 ****************************************************************/

#ifndef _mapper_msg_h_
#define _mapper_msg_h_

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

#endif /* _mapper_msg_h_*/

/* EOF */
