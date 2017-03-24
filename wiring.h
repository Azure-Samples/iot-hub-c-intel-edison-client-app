/*
 * IoT Hub sample for Intel Edison board - Microsoft Sample Code - Copyright (c) 2017 - Licensed MIT
 */

#ifndef WIRING_H_
#define WIRING_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mraa.h>

#include "./config.h"

int readMessage(int messageId, char *payload);
void blinkLED();
void setupWiring();

#endif  // WIRING_H_
