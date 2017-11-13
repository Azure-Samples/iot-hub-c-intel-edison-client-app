#!/bin/sh
#Copyright (c) Microsoft. All rights reserved.
#Licensed under the MIT license. See LICENSE file in the project root for full license information.

mkdir ~/azure-iot-sdk-c
unzip azure-iot-sdk-c-release-2017-11-03.zip -d ~
sed -i 's/--jobs=$CORES/--jobs=2/g' ~/azure-iot-sdk-c/build_all/linux/build.sh
chmod 755 ~/azure-iot-sdk-c/build_all/linux/build.sh
sudo ~/azure-iot-sdk-c/build_all/linux/build.sh  --no-amqp --no-http --no_uploadtoblob
