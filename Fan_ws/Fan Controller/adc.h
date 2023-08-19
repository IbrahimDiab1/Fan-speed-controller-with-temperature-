 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*
                               Definitions
*/

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   5

/*
                      Functions Prototypes
*/

enum ADC_ReferenceVolatge{
	AREF,AVCC,AREF_Internal=3
};

enum ADC_Prescaler{
	Prescaler_2 =1, Prescaler_4, Prescaler_8, Prescaler_16,
	Prescaler_32 , Prescaler_64 , Prescaler_128
};

typedef struct{
	enum ADC_ReferenceVolatge ref_volt;
	enum ADC_Prescaler prescaler;
}ADC_ConfigType;
/*
 * Function responsible for initialize the ADC driver.
 */

void ADC_init(const ADC_ConfigType * Config_Ptr);
/*
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
