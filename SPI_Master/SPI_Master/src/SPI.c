#ifndef __SPI_C_
#define __SPI_C_

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 1000000UL

void SPIM_init ()
{
	DDRB |= 0XB0 ; //MOSI, SCLK, SS OUTPUTS..
	SPCR = 0X53; // ENABLED, MSB FIRST ,MASTER,LOW IDL.. LEADING EDGE,
	SPSR = 0x00; // F/128 used..
	
}
void SPIS_init ()
{
	DDRB &= ~(1<<6);
	SPCR = 0x43;
	SPSR = 0x00;

}
void SPI_sendchar (uint8_t data)
{

	SPDR  = data;                   // PUT DATA INTO DATA REGISTER
	while (  (SPSR && (1<<7)) ==0  );	// WAIT TILL TRANSSMISSION IS COMPLETE..
	
}
uint8_t SPI_getchar ()
{
	while ( (SPSR && (1<<7)) ==0 );
	return SPDR ;
}
#endif