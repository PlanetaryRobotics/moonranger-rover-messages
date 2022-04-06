/****************************************************************
 *
 * @file      moonranger_common_types.h
 *
 * @brief     This file contains all common type definitions for the
 *            MoonRanger software. It extends the cFS common_types.h
 *            found in the OSAL module.
 *
 * @version   1.0
 * @date      16 Nov 2021
 *
 * @authors   Tenzin Crouch
 * @author 	  Carnegie Mellon University, Planetary Robotics Lab
 *
 ****************************************************************/

// include for all common types from the OSAL.
#include "common_types.h"

/**
 * Float definitions for MoonRanger mission
 */
typedef double float64;
typedef float float32;

/**
 * Camera ID definitions
 */
/* Defines the number of cameras on the robot. Used for the length of the camera
   calibration data structures. */
#define STEREO_NUMBER_OF_CAMERAS 4
// the left camera of the robot as seen facing forwards
// adjacent to "front right", and diagonally opposite "rear left"
#define STEREO_FRONT_LEFT_CAMERA_ID 1
// the right camera of the robot as seen facing forwards
// adjacent to "front left", and diagonally opposite "rear right"
#define STEREO_FRONT_RIGHT_CAMERA_ID 2
// the left camera of the robot as seen facing rearwards
// adjacent to "rear right", and diagonally opposite "front left"
#define STEREO_REAR_LEFT_CAMERA_ID 4
// the right camera of the robot as seen facing rearwards
// adjacent to "rear left", and diagonally opposite "front right"
#define STEREO_REAR_RIGHT_CAMERA_ID 3
// these temporary defintions exist to get perception running as quickly as
// possible. They are obsolete and eventually all of the perception code should
// move to using the definitons above
#define STEREO_HISTORICAL_FRONT_LEFT_CAMERA_ID 0
#define STEREO_HISTORICAL_FRONT_RIGHT_CAMERA_ID 1
#define STEREO_HISTORICAL_REAR_LEFT_CAMERA_ID 2
#define STEREO_HISTORICAL_REAR_RIGHT_CAMERA_ID 3