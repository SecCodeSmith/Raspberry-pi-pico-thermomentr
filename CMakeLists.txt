cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)
include(pico_extras_import_optional.cmake)
include(FreeRTOS_Kernel_import.cmake)

project(Proj C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_RELEASE "-pipe -Os -fno-builtin")
set(CMAKE_C_FLAGS_RELEASE "-pipe -Os -fno-builtin")

#set(PICO_BOARD pico_w)
set(PICO_SDK_FETCH_FROM_GIT on)
set(PICO_SDK_PATH "${CMAKE_CURRENT_LIST_DIR}/../pico-sdk" CACHE PATH "Path to the Raspberry Pi Pico SDK")

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

set(FREERTOS_KERNEL_PATH "${CMAKE_CURRENT_LIST_DIR}/../FreeRTOS-Kernel" CACHE PATH "Path to the FreeRTOS kernel sources")
add_subdirectory(../pi-pico-LCD/lcd_display build)


pico_sdk_init()

add_executable(Proj
                main.cpp
                lm35.cpp
                diode.cpp
                )

target_link_libraries(Proj
                      pico_stdlib
                      hardware_adc
                      lcd_display
                      )

add_compile_options(-Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function # we have some for the docs that aren't called
        -Wno-maybe-uninitialized
        )

pico_add_extra_outputs(Proj)

pico_enable_stdio_usb(Proj 1)
pico_enable_stdio_uart(Proj 0)
