#include <msp430.h> 
#include "robot.h"
#include "sensors.h"

/*
 * example.c
 *
 * Author: Geoffrey Paul Novakowski
 * Description: Main .c file for controlling a robot with the
 * 				use of a left-hand wall following algorithm
 * 				coupled with the use of infrared sensors on the
 * 				robot.
 *
 */
int main(void) {
	WDTCTL = WDTPW + WDTHOLD;

	initializePinOuts();
	configureTimer();

	initSensors();
	P1DIR |= 0x41;

	while (1) {
		moveRobotForward();
		__delay_cycles(100);

		leftSensor();
		if (ADC10MEM > 0x2FF) {  // follow left wall
			turnRobotRight();
			__delay_cycles(500);
			moveRobotForward();
			__delay_cycles(500);
		}
		if (ADC10MEM < 0x200) {  // turn left around corner
			turnRobotLeft();
			__delay_cycles(5000);
			moveRobotForward();
			__delay_cycles(500);
		}
		frontSensor();
		if (ADC10MEM > 0x1FD) {  // turn right at wall
			stop();
			__delay_cycles(50000);
			turnRobotRight();
			__delay_cycles(90000);
			moveRobotForward();
			__delay_cycles(500);
		}
	}
	return 0;
}
