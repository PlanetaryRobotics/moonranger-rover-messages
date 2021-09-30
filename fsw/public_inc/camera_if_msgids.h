/**
 * @file
 * Define Camera Interface Messages ID's
 */
#ifndef CAMERA_IF_MSGIDS_H
#define CAMERA_IF_MSGIDS_H

/*
** CAMERA_IF app command Message Id's
*/
/* Command to save the next available image captured from camera to disk */
#define CAMERA_IF_CMD_MID                            0x1886
/* Telemetry that indicates image has been saved to disk and that image needs to be sent back to earth */
#define CAMERA_IF_IMG_SAVED_TLM_MID                  0x0886

/* Housekeeping */
#define CAMERA_IF_SEND_HK_MID                        0x1887
#define CAMERA_IF_HK_TLM_MID                         0x0887

#endif /* CAMERA_IF_MSGIDS_H */
