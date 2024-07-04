/*
 * fan_controller.c
 *
 *  Created on: Feb 22, 2024
 *      Author: Mostafa Osama
 */
#include"lcd.h"
#include"lm35_sensor.h"
#include"DC_motor.h"
#include "adc.h"
DcMotor_State state = OFF;
int main()
{

	uint8 temp;
	ADC_ConfigType setup = {ADC_INTAREF,F_CPU_8};
	DcMotor_Init();
	LCD_init();
	ADC_init(&setup);
	LCD_displayString("FAN is    ");
	LCD_moveCursor(1,0);
	LCD_displayString("Temp =      C");
	temp=LM35_getTemperature();
	while(1)
	{
		if(temp<30)
		{
			DcMotor_Rotate(OFF, 0);
			LCD_moveCursor(0,8);
			LCD_displayString("OFF");
			temp=LM35_getTemperature();
			LCD_moveCursor(1,8);
			LCD_intgerToString(temp);
		}
		else if(temp<60&&temp>=30)
		{
			LCD_moveCursor(0,8);
			LCD_displayString("ON ");
			DcMotor_Rotate(CW, 25);
			temp=LM35_getTemperature();
			LCD_moveCursor(1,8);
			LCD_intgerToString(temp);
		}
		else if(temp<90 && temp>=60)
		{
			LCD_moveCursor(0,8);
			LCD_displayString("ON ");
			DcMotor_Rotate(CW, 50);
			temp=LM35_getTemperature();
			LCD_moveCursor(1,8);
			LCD_intgerToString(temp);

		}
		else if(temp<120 && temp>=90)
		{
			LCD_moveCursor(0,8);
			LCD_displayString("ON ");
			DcMotor_Rotate(CW, 75);
			temp=LM35_getTemperature();
			LCD_moveCursor(1,8);
			LCD_intgerToString(temp);
		}
		else if(temp>=120)
		{
			LCD_moveCursor(0,8);
			LCD_displayString("ON ");
			DcMotor_Rotate(CW, 100);
			temp=LM35_getTemperature();
			LCD_moveCursor(1,8);
			LCD_intgerToString(temp);
		}
		if(temp<100)
		{
			LCD_displayString(" ");
		}
	}
}
