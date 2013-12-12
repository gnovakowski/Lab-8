#include "sensors.h"
#include "msp430.h"

/*
 * sensors.c
 *
 *  Created on: Dec 5, 2013
 *      Author: C15Geoffrey.Novakows
 *      Description: This is the implementation file that
 *      contains all methods required to use the sensors
 *      on the robot. In this method, the sensors work in
 *      combination with the MSP430 LEDs so indicate when
 *      the sensors are engaged.
 */

void initSensors() {
	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
	ADC10CTL1 |= ADC10SSEL1 | ADC10SSEL0;                // Select SMCLK
}

unsigned int frontSensor() {
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 = INCH_5;
	ADC10AE0 |= BIT5;
	ADC10CTL0 |= ENC + ADC10SC;
	__bis_SR_register(CPUOFF + GIE);
	return ADC10MEM;
}
unsigned int leftSensor() { 
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 = INCH_3;
	ADC10AE0 |= BIT3;
	ADC10CTL0 |= ENC + ADC10SC;
	__bis_SR_register(CPUOFF + GIE);
	return ADC10MEM;
}
unsigned int rightSensor() {
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 = INCH_4;
	ADC10AE0 |= BIT4;
	ADC10CTL0 |= ENC + ADC10SC;
	__bis_SR_register(CPUOFF + GIE);
	return ADC10MEM;
}

#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void) {
	__bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}
