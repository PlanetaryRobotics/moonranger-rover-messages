/*******************************************************************************
**
**      GSC-18128-1, "Core Flight Executive Version 6.7"
**
**      Copyright (c) 2006-2019 United States Government as represented by
**      the Administrator of the National Aeronautics and Space Administration.
**      All Rights Reserved.
**
**      Licensed under the Apache License, Version 2.0 (the "License");
**      you may not use this file except in compliance with the License.
**      You may obtain a copy of the License at
**
**        http://www.apache.org/licenses/LICENSE-2.0
**
**      Unless required by applicable law or agreed to in writing, software
**      distributed under the License is distributed on an "AS IS" BASIS,
**      WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
**      See the License for the specific language governing permissions and
**      limitations under the License.
**
** File: INTERCOM_app_msg.h
**
** Purpose:
**  Define INTERCOM App  Messages and info
**
** Notes:
**
**
*******************************************************************************/
#ifndef _INTERCOM_app_msg_h_
#define _INTERCOM_app_msg_h_

/*
** INTERCOM App command codes
*/
#define INTERCOM_APP_NOOP_CC                 0
#define INTERCOM_APP_RESET_COUNTERS_CC       1
#define INTERCOM_APP_PROCESS_CC              2
#define INTERCOM_APP_READ_SERIAL_CC          3
#define INTERCOM_APP_PROCESS_MOTOR_HEALTH_CC 4

//#include "central_to_peripheral.pb.h"
/*************************************************************************/

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



/*************************************************************************/
/*
** Type definition (INTERCOM App housekeeping)
*/

typedef struct
{
    uint8              CommandErrorCounter;
    uint8              CommandCounter;
    uint8              spare[2];
} INTERCOM_HkTlm_Payload_t;

typedef struct
{
    uint8              TlmHeader[CFE_SB_TLM_HDR_SIZE];
    INTERCOM_HkTlm_Payload_t  Payload;

} OS_PACK INTERCOM_HkTlm_t;


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
    uint8 TlmHeader[CFE_SB_TLM_HDR_SIZE];
    //int32_t hall_sensor; 
    int32_t commanded_velocity; 
    int32_t actual_velocity; 
    // int32_t pwm_voltage; 
    // int32_t current; 
    //int32_t p_gain; 
    // int32_t i_gain; 
    //int32_t d_gain; 
    // bool rc_brake; /* This is legal we don't need the enum, but is it correct? */
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

#endif /* _INTERCOM_app_msg_h_ */

/************************/
/*  End of File Comment */
/************************/
