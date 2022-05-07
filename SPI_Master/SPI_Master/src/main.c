#include <avr/io.h>
#include <util/delay.h>
#include "LCD4.h"
#include "SPI.h"


int main(void)
{
	SPIM_init();
   _delay_ms(5);
    while (1) 
    {
	 char str [15] = {"SPI Initialized"};
	//   char str [8] = "12345678";
	   PORTB &= ~(1<<4);
	   _delay_us(2);
		 for (unsigned char i = 0 ; i < 15 ; i ++)
		 {
			 
			SPI_sendchar(str[i]);
			_delay_us(100);
		 }
		  PORTB |= (1<<4);
		  _delay_us(1000);
		/* 	SPI_sendchar('0');s
		 	_delay_ms(1);
		 	SPI_sendchar('1');
		 	_delay_ms(1);*/
    }
}
