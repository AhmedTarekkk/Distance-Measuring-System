/******************************************************************************
*  File name:		main.c
*  Author:			Oct 15, 2022
*  Author:			Ahmed Tarek
*******************************************************************************/

/*******************************************************************************
*                        		Inclusions                                     *
*******************************************************************************/

#include "HAL/LCD/lcd.h"
#include "avr/io.h"
#include "HAL/ULTRASONIC/ultrasonic.h"

/*******************************************************************************
*           					Main Function                                 *
*******************************************************************************/

int main(void)
{
	SREG |= (1<<7); /* Enable the global interrupt */

	LCD_init(); /* initialize the LCD device */
	LCD_displayStringRowColumn(1, 0, "Distance=");
	LCD_displayStringRowColumn(1, 13, "cm");

	ULTRASONIC_init(); /* initialize the ULTRASONIC device */

	while(1)
	{
		uint16 distance = ULTRASONIC_readDistance(); /* Calculate the distance value */

		LCD_moveCursor(1, 10);
		LCD_intgerToString(distance);

		if(distance < 100)
		{
			LCD_displayCharacter(' ');
		}
	}
}
