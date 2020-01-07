#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

#define F_CPU 8000000UL		/* 8 MHz internal generator */
#define Port_H		PORTA
#define Direct_H	DDRA
#define Pin_H		PINA
#define Port_L		PORTC
#define Direct_L	DDRC
#define Pin_L		PINC
#define Display_P	PORTD
#define Display_D	DDRD
#define Port_E		PORTE
#define Direct_E	DDRE
#define Pin_E		PINE

#define key_UP		(PINB | (1 << 2))
#define key_DN		(PINB | (1 << 3))
#define key_SEARCH	(PINB | (1 << 0))
#define key_TEST	(PINB | (1 << 1))

/* Pins declaration for IC connector port */
#define BIT_L0		1
#define BIT_L1		2
#define BIT_L2		4
#define BIT_L3		8
#define BIT_L4		16
#define BIT_L5		32
#define BIT_L6		64
#define BIT_L7		128
#define BIT_L8		1	/* Port E bit 0 */
#define BIT_L9		0	/* Connected to GND */

#define BIT_H0		1
#define BIT_H1		2
#define BIT_H2		4
#define BIT_H3		8
#define BIT_H4		16
#define BIT_H5		32
#define BIT_H6		64
#define BIT_H7		128
#define BIT_H8		4	/* Port E bit 2 */
#define BIT_H9		2	/* Port E bit 1 */
