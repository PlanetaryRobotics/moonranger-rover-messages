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
** File: moonranger_msg.h
**
** Purpose:
**  Define MoonRanger Messages and info
**
** Notes:
**
**
*******************************************************************************/
#ifndef _moonranger_msg_h_
#define _moonranger_msg_h_

/*
** MOONRANGER command codes
*/

/*************************************************************************/

/*
** Type definition (generic "no arguments" command)
*/
typedef struct
{
   uint8    CmdHeader[CFE_SB_CMD_HDR_SIZE];

} MOONRANGER_NoArgsCmd_t;

/*
** The following commands all share the "NoArgs" format
**
** They are each given their own type name matching the command name, which_open_mode
** allows them to change independently in the future without changing the prototype
** of the handler function
*/
typedef MOONRANGER_NoArgsCmd_t      MOONRANGER_Noop_t;
typedef MOONRANGER_NoArgsCmd_t      MOONRANGER_ResetCounters_t;
typedef MOONRANGER_NoArgsCmd_t      MOONRANGER_Process_t;

/*************************************************************************/
/*
** Type definition (MOONRANGER goal)
*/

typedef float float32;

typedef struct
{
    float32		x_coord;     // meters
    float32		y_coord;     // meters
    float32		x_radius;    // meters
    float32		y_radius;    // meters
    float32		orientation; // radians

} MOONRANGER_Goal_t;

/*************************************************************************/
/*
** Type definition (MOONRANGER pose)
*/

typedef double float64;

typedef struct
{
    uint64		timestamp;      // nanoseconds
    float64		x_pos;          // meters
    float64		y_pos;          // meters
    float64		z_pos;          // meters
    float64		x_quat;         // quaternion
    float64		y_quat;         // quaternion
    float64		z_quat;         // quaternion
    float64		w_quat;         // quaternion
    float64		covariance[36];

} MOONRANGER_Pose_t;

/*************************************************************************/
/**
 * Type definition (MOONRANGER body velocity)
 */

typedef struct
{
    uint64  timeStamp;   // nanoseconds
    float32 xVelocity;   // m/s
    float32 yawVelocity; // rad/s
} MOONRANGER_BodyVelocity_t;

/*************************************************************************/
/**
 * Type definition (MOONRANGER wheel velocity packet)
 * If duration field is NULL, motor should run last recieved command, otherwise run for specified duration
 */
typedef struct
{
    uint64   timeStamp;  // nanoseconds
    float32 duration;   // seconds. 
    float32 leftFront;  // rad/s
    float32 rightFront; // rad/s
    float32 leftBack;   // rad/s
    float32 rightBack;  // rad/s
} MOONRANGER_WheelVelocity_t;

/*************************************************************************/
/**
 * Type definition (MOONRANGER wheel velocity packet)
 */
typedef struct
{
    uint64  timeStamp; // nanoseconds
    float32 speed;     // m/s
    float32 duration;  // seconds
    float32 radius;    // meters

} MOONRANGER_OptimalDriveArc_t;

/*************************************************************************/
/*
** Type definition (MOONRANGER point cloud)
** TODO: define actual structure
*/

typedef MOONRANGER_NoArgsCmd_t MOONRANGER_Pcl_t;

/*************************************************************************/
/*
** Type definition (MOONRANGER mesh)
** TODO: define actual structure
*/

typedef MOONRANGER_NoArgsCmd_t MOONRANGER_Mesh_t;


/*************************************************************************/
/*
** Type definition (MOONRANGER SIM MESSAGES)
** TODO: separate into sim messages file
*/
typedef struct {
  CFE_SB_TlmHdr_t TlmHeader;
  MOONRANGER_Goal_t Goal;
} MOONRANGER_GoalMsg_t;

typedef struct {
  float32 x_coord;
  float32 y_coord;
  float32 z_coord;
} MOONRANGER_Sunseeker_t;

typedef struct {
  CFE_SB_TlmHdr_t TlmHeader;
  MOONRANGER_Sunseeker_t Sunseeker;
} MOONRANGER_SunseekerMsg_t;

typedef struct {
  float32 x_linear;
  float32 y_linear;
  float32 z_linear;
  float32 x_angular;
  float32 y_angular;
  float32 z_angular;
} MOONRANGER_CmdVel_t;

typedef struct {
  CFE_SB_TlmHdr_t TlmHeader;
  MOONRANGER_CmdVel_t CmdVel;
} MOONRANGER_CmdVelMsg_t;

typedef struct {
  float64 x_quat;
  float64 y_quat;
  float64 z_quat;
  float64 w_quat;
  float64 ori_covariance[9];

  float64 x_angVel;
  float64 y_angVel;
  float64 z_angVel;
  float64 angVel_covariance[9];

  float64 x_linAcc;
  float64 y_linAcc;
  float64 z_linAcc;
  float64 linAcc_covariance[9];
} MOONRANGER_Imu_t;

typedef struct {
  CFE_SB_TlmHdr_t TlmHeader;
  MOONRANGER_Imu_t Imu;
} MOONRANGER_ImuMsg_t;


#endif /* _moonranger_msg_h_ */

/************************/
/*  End of File Comment */
/************************/
