/****************************************************************
 * 
 * @file      TODO
 * 
 * @brief     TODO
 * 
 * @version   TODO
 * @date   		TODO
 * 
 * @authors 	TODO
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 * 
 * @note		This file only contains app specific command and 
 * 				telemetry message definitions and command codes.
 * 
 ****************************************************************/

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
 */
typedef struct
{
    uint64   timeStamp;  // nanoseconds
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


#endif /* _moonranger_msg_h_ */

/************************/
/*  End of File Comment */
/************************/
