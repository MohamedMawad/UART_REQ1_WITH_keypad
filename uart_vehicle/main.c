/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed ELameer
 */
#include"uart.h"
#include"keypad.h"
#include"LCD.h"
#include"Timers.h"


int main(void){
	DDRD&=0xF8; /*pin PD0&PD1&PD2 as input*/
    DDRB=0;
	unit8 num=0;
	LCD_init();
	//timer_init();
	UART_init();
	LCD_displayStrRowCol(0,0,"Speed is: ");

	while(1){
		// UART_sendByte(const unit8 data);

		num=KeyPad_getPressedKey();
		_delay_ms(30);
		if(PINB&(1<<PB2))
		{
			if(PINB&(1<<PB2))
			   num++;
		}
		else if(PINB&(1<<PB1))
		{
			if(PINB&(1<<PD1))
			  num--;
		}
		LCD_gotoRawCol(0,10);
		LCD_IntToStr(num);
		UART_sendByte(num);

 }

}
