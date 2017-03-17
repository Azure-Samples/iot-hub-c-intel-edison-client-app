#Copyright (c) Microsoft. All rights reserved.
#Licensed under the MIT license. See LICENSE file in the project root for full license information.
cmake_minimum_required(VERSION 2.8)

set (CMAKE_C_FLAGS "--std=gnu99 ${CMAKE_C_FLAGS}")

option(azure_IoT_Sdk_c "passes path of azure iot sdks build libs source path" OFF)

if(NOT "${azure_IoT_Sdk_c}" STREQUAL "OFF")
    include_directories(${azure_IoT_Sdk_c}/c-utility/inc
                        ${azure_IoT_Sdk_c}/iothub_client/inc)
    link_directories(${azure_IoT_Sdk_c}/cmake/iotsdk_linux/serializer
                     ${azure_IoT_Sdk_c}/cmake/iotsdk_linux/iothub_client
                     ${azure_IoT_Sdk_c}/cmake/iotsdk_linux/c-utility
                     ${azure_IoT_Sdk_c}/cmake/iotsdk_linux/umqtt)
else()
    include_directories(~/azure-iot-sdk-c/c-utility/inc
                        ~/azure-iot-sdk-c/iothub_client/inc)
    link_directories(~/azure-iot-sdk-c/cmake/iotsdk_linux/serializer
                     ~/azure-iot-sdk-c/cmake/iotsdk_linux/iothub_client
                     ~/azure-iot-sdk-c/cmake/iotsdk_linux/c-utility
                     ~/azure-iot-sdk-c/cmake/iotsdk_linux/umqtt)
endif()

add_executable(app config.h wiring.h certs.h certs.c wiring.c main.c)
target_link_libraries(app mraa
                          serializer
                          iothub_client
                          iothub_client_mqtt_transport
                          umqtt
                          aziotsharedutil
                          ssl
                          crypto
                          curl
                          pthread
                          m
                          ssl
                          crypto)
