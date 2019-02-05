/*z Created: 11/6/2018 9:30:39 AM
 * Author : Yameen Abdullah
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
    DDRD &= ~(1<<PIND7);		//D7 as input(button)
	DDRB |= 1<<PINB3;			//B3 as output(led)
	PORTD |= 1<<PIND7;
	
	int pressed=0;
	int released=0;
	int p=0,r=0;
	

	while (1) 
    {
		if(bit_is_clear(PIND,7))
			{
				p++;
				if(p>100)
				{
					if(pressed==0)
					{
						PORTB ^= 1<<PORTB3;
						pressed=1;	
					}
					p=0;
				}
			}
		else
			{
				r++;
				if(r>100)
				{
					pressed=0;
					r=0;	
				}
					
			}
			
	}
}

