#ifndef __SPI_H_
#define __SPI_H_

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 1000000UL

void SPIM_init ();

void SPIS_init ();

void SPI_sendchar (uint8_t);

uint8_t SPI_getchar ();

#endif