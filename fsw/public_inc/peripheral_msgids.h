/************************************************************************
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
** File: INTERCOM_app_msgids.h
**
** Purpose: 
**  Define INTERCOM App  Message IDs
**
** Notes:
**
**
*************************************************************************/
#ifndef _INTERCOM_app_msgids_h_
#define _INTERCOM_app_msgids_h_

#define INTERCOM_APP_CMD_MID            	0x1982
#define INTERCOM_APP_GET_MOTOR_HEALTH       0x1983
#define INTERCOM_APP_MOTOR_HEALTH_DATA      0x1984
#define INTERCOM_APP_SET_PID_PARAMS         0x1985
#define INTERCOM_APP_SET_MOTOR_SPEED        0x1986
#define INTERCOM_APP_SET_MOTOR_SPEED_ALL    0x1987

#define INTERCOM_APP_SEND_HK_MID        	0x1883
#define INTERCOM_APP_READ_SERIAL            0x1884

#define INTERCOM_APP_HK_TLM_MID		0x0883
#define INTERCOM_APP_MOTOR_HEALTH     0x1887


/*
** INTERCOM App command codes
*/
#define INTERCOM_APP_NOOP_CC                 0
#define INTERCOM_APP_RESET_COUNTERS_CC       1
#define INTERCOM_APP_PROCESS_CC              2
#define INTERCOM_APP_READ_SERIAL_CC          3
#define INTERCOM_APP_PROCESS_MOTOR_HEALTH_CC 4



#endif /* _INTERCOM_app_msgids_h_ */

/************************/
/*  End of File Comment */
/************************/
