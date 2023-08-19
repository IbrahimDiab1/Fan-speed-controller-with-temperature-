/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: dc_motor.c
 *
 * Description: Source file for the DC Motor driver
 *
 *******************************************************************************/

#include "std_types.h"
#include "dc_motor.h"
#include "gpio.h"
#include "pwm.h"

/*The Function responsible for setup the direction for the two motor pins through the GPIO driver.*/
void DcMotor_Init(void) {

GPIO_setupPinDirection(DC_MOTOR_IN1_PORT_ID,DC_MOTOR_IN1_PIN_NUM,PIN_OUTPUT);
GPIO_setupPinDirection(DC_MOTOR_IN2_PORT_ID,DC_MOTOR_IN2_PIN_NUM,PIN_OUTPUT);

/*Stop at the DC-Motor at the beginning through the GPIO driver.*/

GPIO_writePin(DC_MOTOR_IN1_PORT_ID,DC_MOTOR_IN1_PIN_NUM,0);
GPIO_writePin(DC_MOTOR_IN2_PORT_ID,DC_MOTOR_IN2_PIN_NUM,0);

#if(TWO_MOTORS_MODE)

GPIO_setupPinDirection(DC_MOTOR_IN3_PORT_ID,DC_MOTOR_IN3_PIN_NUM,PIN_OUTPUT);
GPIO_setupPinDirection(DC_MOTOR_IN4_PORT_ID,DC_MOTOR_IN4_PIN_NUM,PIN_OUTPUT);

GPIO_writePin(DC_MOTOR_IN3_PORT_ID,DC_MOTOR_IN3_PIN_NUM,0);
GPIO_writePin(DC_MOTOR_IN4_PORT_ID,DC_MOTOR_IN4_PIN_NUM,0);

#endif
}

/* The function responsible for rotate the DC Motor CW/ or A-CW or stop the motor
* based on the state input state value
* The speed parameter between 0 to 100 percent of motor
*/

void DcMotor_Rotate(DcMotor_State state, uint8 speed) {

PWM_Timer0_Start(speed);
if (state) {
switch (state){
case CW:
GPIO_writePin(DC_MOTOR_IN1_PORT_ID,DC_MOTOR_IN1_PIN_NUM,0);
GPIO_writePin(DC_MOTOR_IN2_PORT_ID,DC_MOTOR_IN2_PIN_NUM,1);
#if(TWO_MOTORS_MODE)
GPIO_writePin(DC_MOTOR_IN3_PORT_ID,DC_MOTOR_IN3_PIN_NUM,0);
GPIO_writePin(DC_MOTOR_IN4_PORT_ID,DC_MOTOR_IN4_PIN_NUM,1);
#endif
break;

case A_CW:
GPIO_writePin(DC_MOTOR_IN1_PORT_ID,DC_MOTOR_IN1_PIN_NUM,1);
GPIO_writePin(DC_MOTOR_IN2_PORT_ID,DC_MOTOR_IN2_PIN_NUM,0);
#if(TWO_MOTORS_MODE)
GPIO_writePin(DC_MOTOR_IN3_PORT_ID,DC_MOTOR_IN3_PIN_NUM,1);
GPIO_writePin(DC_MOTOR_IN4_PORT_ID,DC_MOTOR_IN4_PIN_NUM,0);
#endif
break;
case STOP:
	GPIO_writePin(DC_MOTOR_IN1_PORT_ID,DC_MOTOR_IN1_PIN_NUM,0);
	GPIO_writePin(DC_MOTOR_IN2_PORT_ID,DC_MOTOR_IN2_PIN_NUM,0);
	#if(TWO_MOTORS_MODE)
	GPIO_writePin(DC_MOTOR_IN3_PORT_ID,DC_MOTOR_IN3_PIN_NUM,0);
	GPIO_writePin(DC_MOTOR_IN4_PORT_ID,DC_MOTOR_IN4_PIN_NUM,0);
	#endif
}}}

