/*
 * ADC.c
 *
 * Created: 11/7/2018 12:15:11 AM
 * Author : Yameen Abdullah
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
//#include <adc.h>

uint8_t result;

int main(void)
{
    /* Replace with your application code */
    
	TCCR0 |=(1<<WGM00)|(1<<COM01)|(1<<CS00);	 			
	DDRB |= 1<<PINB3;
	
//	TCCR0
	
	ADCSRA |= (1<<ADEN) | (1<<ADPS2) | (1<<ADIE);			
	ADMUX |= (1<<ADLAR) | (1<<REFS0);
	
	
	
	sei();
	
	ADCSRA |= 1<<ADSC;
	
	while (1) 
    {
   	}
}

ISR(ADC_vect)
{
	OCR0 = ADCL;
	ADCSRA |= 1<<ADSC;
}
