cmake_minimum_required(VERSION 3.10.2)
project(CommandTestTools)

include_directories(../fsw/public_inc)
include_directories(../fsw/src)
include_directories(../message-utilities/cfe_components)
include_directories(../message-utilities/include)
include_directories(../include/)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS "-fshort-enums -Wall -Werror")

add_executable(CommandTest
        src/command_tester.c
        ../../message-utilities/src/message_builder.c
        ../../message-utilities/cfe_components/cfe_sb_util.c
        ../../message-utilities/cfe_components/cfe_sb_msg_id_util.c
        )

