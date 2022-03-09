cmake_minimum_required(VERSION 3.10.2)

project(MOONRANGER_MSG_UTILS C)

include_directories(../fsw/public_inc)
include_directories(cfe_components)
include_directories(tmp)
include_directories(include)

file(GLOB SOURCES "src/*.c" "cfe_components/*.c")
 
add_library(msg SHARED ${SOURCES})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_FLAGS "-fshort-enums")

target_include_directories(msg PUBLIC cfe_components)
# target_link_directories(msg PRIVATE cfe_components)

install(TARGETS msg DESTINATION ${PROJECT_SOURCE_DIR}/dist)

add_executable(test_builder.elf test/test_builder.c)

target_link_libraries(test_builder.elf msg)