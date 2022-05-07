
#include <avr/io.h>
#include <util/delay.h>
#include "LCD4.h"
#include "SPI.h"

int main(void)
{
	lcd_intit();
	SPIS_init();
	
	while (1)
	{
		unsigned char i = 0 ;
		char arr [15];
		
		while (i<15)
		{
			arr[i++]=(char)SPI_getchar();
		}
		//	 unsigned char x = SPI_getchar();
		lcd_goto(1,1);
		lcd_prnt(arr);
		
	}
}

