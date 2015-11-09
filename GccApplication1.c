/*
 * GccApplication1.c
 *
 * Created: 2015-11-05 08:49:12
 *  Author: Administrator
 */ 
#define F_CPU 16000000UL
#include<util/delay.h>

#include <avr/io.h>

int main(void)
{
	DDRA = 0xFF;
	DDRB = 0x00;
	PORTB = 0x01;
    
	
	while(1)
    {
		if(PINB & 0x01)
		{
			PORTA = 0x00;
		}
		else
		{
			//Zapalanie kolejnych diod
			for(int i=0;i<8;i++)
			{
				_delay_ms(200);
				PORTA = 1 << i;	
			}
			
			//Rozjasnianie i przyciemnianie
			for(int t=0; t<1000; t++)
			{
				PORTA = 0x00;
				_delay_us(t);
				PORTA = 0xFF;
				_delay_us(1000-t);
			}
			
			//Proba polaczenia weza i rozjasniania
			for(int i=0;i<8;i++)
			{
				_delay_ms(200);
				int pin = 1 << i;
				
				for(int t=0; t<1000; t++)
				{
					PORTA = 0x00;
					_delay_us(t);
					PORTA = pin;
					_delay_us(1000-t);
				}
			}
			
			
			
		}
		
		
		
        
    }
}