/****************************************************************
 * 
 * @file      peripheral_msg_ids.h
 * 
 * @brief     File containing message ids for messages between MSPs and Peripheral Computer
 * 
 * @version     1
 * @date   		11/15/2021
 * 
 * @authors 	Vikram Bhat
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 * 
 * @note		This file only contains app specific command and 
 * 				telemetry message definitions and command codes.
 * 
 ****************************************************************/


/*********************************************************************
 * INSTRUCTIONS
 * 
 * This file should contain all the type definitions for app specific messages such as
 * housekeeping / telemetry.
 * 
 * It should also contain definitions for all command messages and command codes.
 * 
 * All message IDs should be placed in moonranger_messageids.h in the appropriately marked location
 * 
 * DELETE THIS BLOCK ONCE COMPLETE
 *******************************************************************/

#ifndef _peripheral_msg_ids_h
#define _peripheral_msg_ids_h

#define MASTER_CMD_MSG 1
#define SENSOR_DATA_MSG 2
#define GET_MOTOR_HEALTH_ALL_MSG 3
#define GET_MOTOR_HEALTH_MSG 4
#define SET_MOTOR_SPEED_ALL_MSG 5
#define SET_MOTOR_SPEED_MSG 6
#define SET_PID_PARAMS_MSG 7
#define SETUP_MOTOR_CONTROLLER_MSG 8
#define GET_SUN_SENSOR_ANGLE_MSG 9
#define GET_FILTERED_PHOTOCELL_VOLTS_MSG 10
#define GET_UNFILTERED_PHOTOCELL_VOLTS_MSG 11
#define SET_NSS_PARAMS 12
#define GET_NSS_TELEMETRY 13
#define SET_SWITCH_GROUP_STATE 14
#define GET_SWITCH_STATUS 15
#define SET_HEATER_STATE 16
#define GET_HEATER_STATUS 17
#define GET_THERMISTOR_VALUE 18
#define GET_ALL_THERMISTOR_VALUES 19




#endif /* _peripheral_msg_ids_h */
