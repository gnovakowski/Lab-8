/*
 * sensors.h
 *
 *  Created on: Dec 5, 2013
 *      Author: C15Geoffrey.Novakows
 *      Description: Header file displaying all methods required
 *      to utilize the sensors with robot movement.
 */

#ifndef _sensors_h
#define _sensors_h
#include <msp430.h>

void initSensors();

unsigned int frontSensor();

unsigned int leftSensor();

unsigned int rightSensor();

#endif
