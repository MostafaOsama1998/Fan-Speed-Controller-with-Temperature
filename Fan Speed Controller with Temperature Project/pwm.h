/*
 * pwm.h
 *
 *  Created on: Feb 22, 2024
 *      Author: Mostafa Osama
 */


#ifndef PWM_H_
#define PWM_H_
#include"std_types.h"
void PWM_Timer0_Start(uint8 duty_cycle);
#define Port_OC0   PORTB_ID
#define Pin_OC0   PIN3_ID

#endif
