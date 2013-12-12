/*
 * robot.h
 *
 *  Created on: Nov 20, 2013
 *      Author: C15Geoffrey.Novakows
 */

#ifndef _robot_h
#define _robot_h
#include <msp430.h>

#endif

void initializePinOuts();

void configureTimer();

void moveRobotForward();

void moveRobotBackward();

void turnRobotLeft();

void turnRobotRight();

void stop();
