 /******************************************************************************
 *
 * Module: Fan Controller System
 *
 * File Name: main.c
 *
 * Description: main file of the project
 *
 *******************************************************************************/


#include "gpio.h"
#include "pwm.h"
#include "lm35_sensor.h"
#include "lcd.h"
#include "dc_motor.h"
#include "adc.h"

void main(void){


	ADC_ConfigType adc_Config={AREF_Internal,Prescaler_8};
	uint8 temp;

 ////////////////////////////////// Functions Initialization


	LCD_init();
	ADC_init(& adc_Config);
	DcMotor_Init();
	LCD_displayString("Fan is ");
	LCD_displayStringRowColumn(1,0,"Temp =  c");

	while(1){

		temp= LM35_getTemperature();

//If the temperature is less than 30C turn off the fan.
//Displaying the real time temp on lcd
		if (temp<30){
			LCD_moveCursor(0,7);
			LCD_displayString("off");
			LCD_moveCursor(1,6);
			LCD_displayString(" ");
			if(temp<10)
			LCD_displayString(" ");
			LCD_intgerToString(temp);
			 DcMotor_Rotate(CW,0);
		}
//If the temperature is greater than or equal 30C turn on the fan with 25% of its maximum speed.
//Displaying the real time temp on lcd
		else if((temp>=30)&&(temp<60)){
			LCD_moveCursor(0,7);
			LCD_displayString("on ");
			LCD_moveCursor(1,6);
			LCD_displayString(" ");
			LCD_intgerToString(temp);
			 DcMotor_Rotate(CW , 25);
		}
//If the temperature is greater than or equal 60C turn on the fan with 50% of its maximum speed.
//Displaying the real time temp on lcd
		else if((temp>=60)&&(temp<90)){
			LCD_moveCursor(0,7);
			LCD_displayString("on ");
			LCD_moveCursor(1,6);
			LCD_displayString(" ");
			LCD_intgerToString(temp);
			 DcMotor_Rotate(CW ,50 );
				}
//If the temperature is greater than or equal 90C turn on the fan with 75% of its maximum speed.
//Displaying the real time temp on lcd
		else if((temp>=90)&&(temp<120)){
			LCD_moveCursor(0,7);
			LCD_displayString("on ");
			LCD_moveCursor(1,6);
			if(temp<100)
			LCD_displayString(" ");
			LCD_intgerToString(temp);
			 DcMotor_Rotate(CW ,75);
				}
//If the temperature is greater than or equal 120C turn on the fan with 100% of its maximum speed.
//Displaying the real time temp on lcd
		else if(temp>=120){
			LCD_moveCursor(0,7);
			LCD_displayString("off");
			LCD_moveCursor(1,6);
			LCD_intgerToString(temp);

			 DcMotor_Rotate(CW ,100);
				}

	}

}
