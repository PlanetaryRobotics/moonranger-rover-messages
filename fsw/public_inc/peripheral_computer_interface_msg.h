/****************************************************************
 * 
 * @file      peripheral_computer_interface_msg.h
 * 
 * @brief     Message types for the peripheral computer interface app
 * 
 * @version   1.0
 * @date   		10/19/21
 * 
 * @authors 	Bill Drozd
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

#ifndef _peripheral_computer_interface_msgs_h
#define _peripheral_computer_interface_msgs_h

#include "cfe_sb.h"
#include "common_types.h"


/*
** INTERCOM App command codes
*/
#define INTERCOM_APP_NOOP_CC                 0
#define INTERCOM_APP_RESET_COUNTERS_CC       1
#define INTERCOM_APP_PROCESS_CC              2
#define INTERCOM_APP_READ_SERIAL_CC          3
#define INTERCOM_APP_PROCESS_MOTOR_HEALTH_CC 4


/*
** Type definition (generic "no arguments" command)
*/
typedef struct
{
   uint8    CmdHeader[CFE_SB_CMD_HDR_SIZE];

} INTERCOM_NoArgsCmd_t;

/*
** The following commands all share the "NoArgs" format
**
** They are each given their own type name matching the command name, which_open_mode
** allows them to change independently in the future without changing the prototype
** of the handler function
*/
typedef INTERCOM_NoArgsCmd_t      INTERCOM_Noop_t;
typedef INTERCOM_NoArgsCmd_t      INTERCOM_ResetCounters_t;
typedef INTERCOM_NoArgsCmd_t      INTERCOM_Process_t;
typedef INTERCOM_NoArgsCmd_t      GetMotorHealthAll;


/* Enum definitions */
typedef enum _MotorID { 
    MotorID_FRONT_LEFT = 1, 
    MotorID_FRONT_RIGHT = 2, 
    MotorID_BACK_LEFT = 3, 
    MotorID_BACK_RIGHT = 4, 
    MotorID_OTHER = 5 
} MotorID;

/* Struct definitions */
typedef struct _GetMotorHealth { 
    MotorID motor_id; 
} GetMotorHealth;

typedef struct _MotorHealth { 
    int32_t hall_sensor; 
    int32_t commanded_velocity; 
    int32_t actual_velocity; 
    int32_t pwm_voltage; 
    int32_t current; 
    int32_t p_gain; 
    int32_t i_gain; 
    int32_t d_gain; 
    bool rc_brake; /* This is legal we don't need the enum, but is it correct? */
} MotorHealth;

typedef struct _SetMotorSpeed { 
    MotorID motor_id; 
    int32_t motor_speed; 
    int32_t crc; 
} SetMotorSpeed;

typedef struct _SetMotorSpeedAll { 
    int32_t motor_speed_1; 
    int32_t motor_speed_2; 
    int32_t motor_speed_3; 
    int32_t motor_speed_4; 
    int32_t crc; 
} SetMotorSpeedAll;

typedef struct _SetPIDParams { 
    MotorID motorID; 
    int32_t p_gain; 
    int32_t i_gain; 
    int32_t d_gain; 
    int32_t crc; 
} SetPIDParams;

/* Helper constants for enums */
#define _MotorID_MIN MotorID_FRONT_LEFT
#define _MotorID_MAX MotorID_OTHER
#define _MotorID_ARRAYSIZE ((MotorID)(MotorID_OTHER+1))



#endif /* _peripheral_computer_interface_msgs_h */
