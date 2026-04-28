# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.2.0)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.2.0-a4)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
#set(PICO_BOARD pico CACHE STRING "Board type")

set(PICO_PLATFORM rp2040)
set(PICO_BOARD "pico_w")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(host_cdc_msc_hid C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

cmake_minimum_required(VERSION 3.13)

add_executable(pico_ble_keyboard_adapter)

# Example source
target_sources(pico_ble_keyboard_adapter PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/main.c
        ${CMAKE_CURRENT_LIST_DIR}/hog_keyboard.c
        ${CMAKE_CURRENT_LIST_DIR}/usb_hid_host.c
        )

# Make sure TinyUSB can find tusb_config.h
target_include_directories(pico_ble_keyboard_adapter PUBLIC
        ${CMAKE_CURRENT_LIST_DIR})

# In addition to pico_stdlib required for common PicoSDK functionality, add dependency on tinyusb_host
# for TinyUSB device support and tinyusb_board for the additional board support library used by the example
target_link_libraries(pico_ble_keyboard_adapter PUBLIC 
    pico_stdlib
    tinyusb_host
    tinyusb_board
    pico_btstack_ble
    pico_btstack_cyw43
    pico_cyw43_arch_none
    )

pico_btstack_make_gatt_header(pico_ble_keyboard_adapter PRIVATE "${CMAKE_CURRENT_LIST_DIR}/hog_keyboard_profile.gatt")

pico_add_extra_outputs(pico_ble_keyboard_adapter)

# add url via pico_set_program_url
