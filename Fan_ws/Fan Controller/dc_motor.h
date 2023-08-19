 /******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: dc_motor.h
 *
 * Description: Header file for the DC Motor driver
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

#define TWO_MOTORS_MODE    0 // if we connect 2 motors to LM016L driver

#define DC_MOTOR_IN1_PORT_ID PORTB_ID
#define DC_MOTOR_IN1_PIN_NUM PIN1_ID

#define DC_MOTOR_IN2_PORT_ID PORTB_ID
#define DC_MOTOR_IN2_PIN_NUM PIN2_ID

#if(TWO_MOTORS_MODE)

#define DC_MOTOR_IN3_PORT_ID
#define DC_MOTOR_IN3_PIN_NUM

#define DC_MOTOR_IN4_PORT_ID
#define DC_MOTOR_IN4_PIN_NUM

#endif

typedef enum{
CW , A_CW,STOP
}DcMotor_State;

/*The Function responsible for setup the direction for the two motor pins through the GPIO driver.*/
void DcMotor_Init(void);

/* The function responsible for rotate the DC Motor CW/ or A-CW or stop the motor
* based on the state input state value
* The speed parameter between 0 to 100 percent of motor
*/
void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* DC_MOTOR_H_ */
