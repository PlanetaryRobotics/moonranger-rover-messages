/****************************************************************
 *
 * @file        command_tester.c
 *
 * @brief       This is a small program which builds cFS messages and sends them
 *              over UDP. Currently it implements OBC commands only.
 *
 * @authors 	Tenzin Crouch
 * @author 		Carnegie Mellon University, Planetary Robotics Lab
 *
 * @note        Copyright 2022 Carnegie Mellon University. All rights reserved.
 ****************************************************************/

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "message_builder.h"

#define PORT 9095
#define SERVER_ADDRESS " 127.0.0.1"
#define BUF_LEN 1024
#define ERR -1

// Prints hex of uint8.
void printCommandHex(uint8 *buf_ptr, int buf_len) {
    printf("Command hex: ");
    size_t i = 0;
    for (i = 0; i < buf_len; ++i) {
        printf("%02X", *buf_ptr);
        buf_ptr += 1;
    }
    printf("\n");
}

// Driver code
int main(int argc, char **argv) {
    printf("Welcome the OBC message tester for MoonRanger\n");

    int sockfd;
    struct sockaddr_in servaddr;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_ADDRESS,
              &(servaddr.sin_addr));   // convert dotted decimal to AF type
    printf("Sending commands to %s:%d\n", SERVER_ADDRESS, PORT);

    // main execution loop, iterate here until break.
    int command_selection, command_len;
    char buf[BUF_LEN];

    message_builder_u command_data;
    void *data_ptr = &command_data;
    while (TRUE) {
        // wait for CLI input
        printf("Please select from the following command list\n");
        printf("1 - OBC_MasterCommsEnable_Cmd_t\n");
        // 2 - OBC_WifiEnable_Cmd_t\n
        // 3 - OBC_BatteryEnable_Cmd_t\n
        // 4 - OBC_PowerSwitchingEnable_Cmd_t\n
        // 5 - OBC_Set_Wheel_Speed_All_Cmd_t\n
        // 6 - OBC_Set_Motor_PID_Cmd_t\n
        // 7 - OBC_Set_Solar_Panel_State_Cmd_t\n
        // 8 - OBC_NSS_Set_Params_Cmd_t\n
        // 9 - OBC_Set_Switch_State_Cmd_t\n
        // 10 - OBC_Set_Switch_State_All_Cmd_t\n
        // 11 - OBC_Reset_Switch_Cmd_t\n
        // 12 - OBC_Set_Heater_State_Cmd_t\n
        // 13 - OBC_Set_Heater_State_All_Cmd_t\n");

        // read input
        if (!fgets(buf, BUF_LEN, stdin)) {
            return ERR;
        }
        command_selection = atoi(buf);

        switch (command_selection) {
            case 1:

                command_len = messageBuildCmdWithCode(
                    data_ptr, &command_data, 0, OBC_MASTER_COMM_ENABLE_CMD_MID,
                    OBC_MASTER_COMMS_ENABLE);
                printf(
                    "Sending OBC_MasterCommsEnable_Cmd_t, length %d bytes.\n",
                    command_len);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                break;
            case 13:
                break;
            default:
                printf("Unknown command entered, please try again.\n");
        }

        printCommandHex(&command_data.msg_buf_ptr, command_len);
        connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
        send(sockfd, &command_data, command_len, 0);

        // TODO: add logic for quit
        if (FALSE) {
            break;
        }
    }

    close(sockfd);
    return 0;
}