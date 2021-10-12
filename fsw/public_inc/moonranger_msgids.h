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
** File: moonranger_msgids.h
**
** Purpose: 
**  Define MoonRanger Message IDs
**
** Notes:
**
**
*************************************************************************/
#ifndef _moonranger_msgids_h_
#define _moonranger_msgids_h_

/* MOONRANGER Message IDs */
#define MOONRANGER_GOAL_MID		0x0100
#define MOONRANGER_POSE_MID		0x0101
#define MOONRANGER_POINT_CLOUD_MID	0x0102
#define MOONRANGER_MESH_MID		0x0103
#define MOONRANGER_BODY_VELOCITY_MID 0x0890
#define MOONRANGER_WHEEL_VEL_CMD_MID 0x0891
#define MOONRANGER_DRIVE_ARC_MID     0x0892

#define MOONRANGER_SUNSEEKER_MID 0x0104
#define MOONRANGER_CMD_VEL_MID 0x0105

/* FAUXRANGER Message IDs (these messages originate from the Unreal Simulation) */
#define FAUXRANGER_F_L_CAM_INFO_MID 0x0501 //front left camera info
#define FAUXRANGER_F_R_CAM_INFO_MID 0x0502 //front right camera info
#define FAUXRANGER_B_L_CAM_INFO_MID 0x0503 //back left camera info
#define FAUXRANGER_B_R_CAM_INFO_MID 0x0504 //back right camera info
#define FAUXRANGER_F_L_CAM_DATA_MID 0x0505 //front left camera data
#define FAUXRANGER_F_R_CAM_DATA_MID 0x0506 //front right camera data
#define FAUXRANGER_B_L_CAM_DATA_MID 0x0507 //back left camera data
#define FAUXRANGER_B_R_CAM_DATA_MID 0x0508 //back right camera data
#define FAUXRANGER_IMU_MID 0x0509
#define FAUXRANGER_WHEELS_MID 0x0510
#define FAUXRANGER_ODOM_MID 0x0511

#endif /* _moonranger_msgids_h_ */

/************************/
/*  End of File Comment */
/************************/
