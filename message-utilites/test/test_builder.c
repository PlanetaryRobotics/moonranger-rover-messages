// Created by Indraneel on 25/11/2021

#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "message_builder.h"

/*

This file contains a CFS message to be used for testing.

The message was built using the backend with the following parameters

Message Name: MOONRANGER_WheelVelocity_Command_t
Message Len: MOONRANGER_WHEEL_VEL_CMD_MSG_LNGTH (this is a constant that is declared)
Message ID: 0x0D09 
Message Data:
    Duration - 10
    leftFront - 8.0
    rightFront - 4.0
    leftBack - 6.0 
    rightBack - 2.0

Hex encoding of CCSDS Packed Message (this is the payload of the UDP packet)
0d05c000001d0000000000000a00000000000041000080400000c04000000040




*/

void test_message_builder_extract(void) {
    //test stuff
    message_builder_u msg_container;

    unsigned char test_data[32] = {0x0d,0x05,0xc0,0x00,0x00,0x1d,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0x00,0x00,0x00,0x00,0x00,0x00,0x41,0x00,0x00,0x80,0x40,0x00,0x00,0xc0,0x40,0x00,0x00,0x00,0x40};

    messageExtract(&test_data,32, &msg_container);
    
    printf("%d\n",msg_container.WheelVelocity_Command.data.duration);
    printf("%f\n",msg_container.WheelVelocity_Command.data.leftFront);
    printf("%f\n",msg_container.WheelVelocity_Command.data.rightFront);
    printf("%f\n",msg_container.WheelVelocity_Command.data.leftBack);
    printf("%f\n",msg_container.WheelVelocity_Command.data.rightBack);


}

void test_message_builder_build(void) {

    message_builder_u msg_container;

    unsigned char test_data[32] = {0x0d,0x05,0xc0,0x00,0x00,0x1d,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0x00,0x00,0x00,0x00,0x00,0x00,0x41,0x00,0x00,0x80,0x40,0x00,0x00,0xc0,0x40,0x00,0x00,0x00,0x40};

    messageBuild(&msg_container,sizeof(msg_container.WheelVelocity_Command.data), 0x0D05);

    msg_container.WheelVelocity_Command.data.duration = 10;
    msg_container.WheelVelocity_Command.data.leftFront = 8.0f;
    msg_container.WheelVelocity_Command.data.rightFront = 4.0f;
    msg_container.WheelVelocity_Command.data.leftBack = 6.0f;
    msg_container.WheelVelocity_Command.data.rightBack = 2.0f;

    unsigned char* ptr = &msg_container.msg_buf_ptr;

    for(int i=0;i<32;i++)
        printf("%x ",*(ptr+i));
    printf("\n");

}



int main() 
{

    test_message_builder_extract();
    test_message_builder_build();


    return 0;
}