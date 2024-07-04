/*
 * DC_moto.h
 *
 *  Created on: Feb 22, 2024
 *      Author: Mostafa Osama
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "std_types.h"

#define DCMOTOR_ENAPLE1_PORT PORTB_ID
#define DCMOTOR_ENAPLE2_PORT PORTB_ID

#define DCMOTOR_ENAPLE1_PIN PIN0_ID
#define DCMOTOR_ENAPLE2_PIN PIN1_ID

/*
 * this enum to set the status of the motor
 * */
typedef enum
{
	OFF,CW,A_CW
}DcMotor_State;

void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state, uint8 speed);
#endif /* DC_MOTOR_H_ */
