/*
  * pwmnew.c
 *
 * Created: 11/6/2018 3:31:35 PM
 * Author : Yameen Abdullah
 */ 


#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    
	/* Replace with your application code */
	TCCR0 |= (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS00);
	DDRB |= 1 << PINB3;
	OCR0=0;
	while (1) 
    {
		OCR0++;
		_delay_ms(100);
	}
}

 