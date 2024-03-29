/*******************************************************************************
 * Copyright (c) 2014 IBM Corp.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * and Eclipse Distribution License v1.0 which accompany this distribution.
 *
 * The Eclipse Public License is available at
 *    http://www.eclipse.org/legal/epl-v10.html
 * and the Eclipse Distribution License is available at
 *   http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * Contributors:
 *    Ian Craggs - initial implementation
 *******************************************************************************/

#if !defined(K64F_H)
#define K64F_H

C12832 lcd(D11, D13, D12, D7, D10);
PwmOut r(D5);
PwmOut g(D9);
PwmOut b(D8);
DigitalOut led1(LED1); DigitalOut led2(LED2); DigitalOut led3(LED3);
MMA7660 MMA(D14, D15);
LM75B sensor(D14,D15);
PHOTOCONT PHC(D14, D15);

DigitalIn Up(A2); DigitalIn Down(A3); DigitalIn Left(A4); DigitalIn Right(A5); DigitalIn Click(D4);
//AnalogIn ain1 (A0); AnalogIn ain2 (A1);
//Define the loudness sensor on analog port (A0)
AnalogIn loudness(A0);

//Define light sensor on analog port(A1)
AnalogIn light_sensor(A1);

// Define motion sensor on Digital port (D3)
InterruptIn motion(D3);

#define LED2_OFF 0
#define LED2_ON 1

#define DEFAULT_TYPE_NAME "iotsample-mbed-c027"

#include "lpc_phy.h"
// need a wrapper since K64F and LPC1768 wont have the same name for mii read methods
static uint32_t linkStatus(void)
{
    return (lpc_mii_read_data() & 1);
}

#endif