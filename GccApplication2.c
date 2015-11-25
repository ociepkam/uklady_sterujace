/*
 * GccApplication2.c
 *
 * Created: 2015-11-19 08:50:03
 *  Author: Administrator
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <AVR/interrupt.h>

int licznik = 0;

ISR(INT0_vect)
{
	licznik++;
	PORTA = (PORTA & 0x01) | ((licznik<<1) & 0xFE);

}

int main(void)
{
	DDRA = 0xFF;
	DDRD = 0;
	PORTD |= (1<<PD2);
	
	MCUCR |= (1<<ISC01);
	GICR |= (1<<INT0);
	sei();
	
	
    while(1)
    {
		  PORTA ^= 0x01;
		  _delay_ms(500);
		
    }
}
