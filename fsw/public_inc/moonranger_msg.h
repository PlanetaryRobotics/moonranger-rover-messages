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


#endif /* _moonranger_msg_h_ */

/************************/
/*  End of File Comment */
/************************/
