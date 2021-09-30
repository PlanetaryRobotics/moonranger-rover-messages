cmake_minimum_required(VERSION 2.6.4)
project(MOONRANGER_MSGS C)

include_directories(fsw/public_inc)

# The shared OSAL and cFE include directories should always be used
# Note that this intentionally does NOT include PSP-specific includes, just the generic
include_directories(${CFECORE_SOURCE_DIR}/src/inc)
include_directories(${CFEPSP_SOURCE_DIR}/fsw/inc)

# Create the app module
add_cfe_app(moonranger_msgs fsw/src/moonranger_msgs.c)


