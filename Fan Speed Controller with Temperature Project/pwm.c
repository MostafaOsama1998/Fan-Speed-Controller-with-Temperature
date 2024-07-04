/*
 * PWM.c
 *
 *  Created on: Feb 22, 2024
 *      Author: Mostafa Osama
 */
#include"common_macros.h"
#include"pwm.h"
#include"avr/io.h"
#include"gpio.h"
void PWM_Timer0_Start(uint8 duty_cycle)
{
	SET_BIT(TCCR0,WGM00);/*choose the PWM mode*/
	SET_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,CS01);/*choose the prescalr to 8*/
	SET_BIT(TCCR0,COM01);/*enable non-inverting mode*/
	TCNT0=0;/*initialize the timer start from  zero*/
	OCR0= (((uint32)(255*duty_cycle))/100);/*calculate speed */
	GPIO_setupPinDirection(Port_OC0, Pin_OC0, PIN_OUTPUT);/*set the OC0 pin output*/

}

