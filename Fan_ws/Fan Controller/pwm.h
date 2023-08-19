 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.h
 *
 * Description: Header file for the PWM driver
 *
 *******************************************************************************/
#ifndef PWM_H_
#define PWM_H_


#include "std_types.h"

void PWM_Timer0_Start(uint8 duty_cycle_ratio); // Function to generate pwm signal depends on duty cycle ratio

#endif /* PWM_H_ */
