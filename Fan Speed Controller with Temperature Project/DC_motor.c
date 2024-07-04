/*
 * DC_motor.c
 *
 *  Created on: Feb 22, 2024
 *      Author: Mostafa Osama
 */
#include "DC_motor.h"
#include "gpio.h"
#include "common_macros.h"
#include "pwm.h"

/*
 * this function to initialize the motor pins and port
 * */
void DcMotor_Init(void)
{
	GPIO_setupPinDirection(DCMOTOR_ENAPLE1_PORT,DCMOTOR_ENAPLE1_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(DCMOTOR_ENAPLE2_PORT,DCMOTOR_ENAPLE2_PIN, PIN_OUTPUT);
	GPIO_writePin(DCMOTOR_ENAPLE1_PORT,DCMOTOR_ENAPLE1_PIN,LOGIC_LOW);
	GPIO_writePin(DCMOTOR_ENAPLE2_PORT,DCMOTOR_ENAPLE2_PIN,LOGIC_LOW);
}

/*
 * this function to set the direction of the motor rotation
 * and the speed that the motor will rotate with
 *  */
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	switch (state)/*setting the direction of the rotation*/
	{
	case OFF:
		GPIO_writePin(DCMOTOR_ENAPLE1_PORT,DCMOTOR_ENAPLE1_PIN,LOGIC_LOW);
		GPIO_writePin(DCMOTOR_ENAPLE2_PORT,DCMOTOR_ENAPLE2_PIN,LOGIC_LOW);
		break;
	case CW:
		GPIO_writePin(DCMOTOR_ENAPLE1_PORT,DCMOTOR_ENAPLE1_PIN,LOGIC_HIGH);
		GPIO_writePin(DCMOTOR_ENAPLE2_PORT,DCMOTOR_ENAPLE2_PIN,LOGIC_LOW);
		break;
	case A_CW:
		GPIO_writePin(DCMOTOR_ENAPLE1_PORT,DCMOTOR_ENAPLE1_PIN,LOGIC_LOW);
		GPIO_writePin(DCMOTOR_ENAPLE2_PORT,DCMOTOR_ENAPLE2_PIN,LOGIC_HIGH);
		break;
	}
	PWM_Timer0_Start(speed);/*this function gives the PWM the duty cycle*/
}

