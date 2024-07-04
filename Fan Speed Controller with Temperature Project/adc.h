 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Mostafa Osama
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/*#define ADC_PORT_ID PORTA_ID*/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   5
#define INTERRUPT_ENABLE FULSE



typedef enum
{
	ADC_CHANNENEL0,ADC_CHANNENEL1,ADC_CHANNENEL2,ADC_CHANNENEL3,ADC_CHANNENEL4
	,ADC_CHANNENEL5,ADC_CHANNENEL6,ADC_CHANNENEL7
}ADC_Channel;

typedef enum
{
	F_CPU_2=1,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;

typedef enum
{
	ADC_AREF,ADC_VCC,ADC_RESERVED,ADC_INTAREF
}ADC_ReferenceVolatge;

typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType *ADC_type);
#if(INTERRUPT_ENABLE==TRUE)
void ADC_readChannel(ADC_Channel channel_num);
extern uint16 ADC_Read;

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
#else
uint16 ADC_readChannel(ADC_Channel channel_num);
#endif

#endif /* ADC_H_ */
