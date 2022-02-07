/****************************************************************
 * 
 * @file      nss_if_msp_msgs.h
 * 
 * @brief     messages between master msp (E3) and nss msp (E6)
 * 
 * @version   1.0
 * @date   		2/6/2021
 * 
 * @authors 	KJ Newman
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 * 
 * @note		This file only contains app specific command and 
 * 				telemetry message definitions and command codes.
 * 
 ****************************************************************/

#ifndef _nss_if_msp_msgs_h
#define _nss_if_msp_msgs_h

typedef struct {
	volatile int8_t command1; // first command byte
	volatile int8_t command2; // second command byte
	uint8_t _padding[2];

} set_nss_params_t;

typedef struct {
	volatile int8_t telemetry[89]; // nss telemetry data
	uint8_t reboot_counter; // median reboot counter from FRAM
	uint8_t message_counter; // message counter incremented each time this is sent
	uint8_t _padding;
} nss_health_msg_t;


#endif /* _nss_if_msp_msgs_h */
