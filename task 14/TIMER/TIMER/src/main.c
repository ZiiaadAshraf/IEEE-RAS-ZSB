#include <avr/io.h>
#include <avr/interrupt.h>
#include "C:\Users\hp\Documents\Atmel Studio\7.0\TIMER\TIMER\STD_TYPES.h"
#include "C:\Users\hp\Documents\Atmel Studio\7.0\TIMER\TIMER\BIT_MATH.h"
#include "C:\Users\hp\Documents\Atmel Studio\7.0\TIMER\TIMER\DIO_interface.h"
#include "C:\Users\hp\Documents\Atmel Studio\7.0\TIMER\TIMER\TIMER_interface.h"


int main (void)
{
	DDRB |= (1 << 0); // Set LED as output

	TCCR1B |= (1 << CS10); // Set up timer

	while(1)
	{
		// Check timer value in if statement, true when count matches 1/100 of a second
		if (TCNT1 >= 9999)
		{ //use 29999 above or else led blinking is so fast its not visible
			PORTB ^= (1 << 0); // Toggle the LED

			TCNT1 = 0; // Reset timer value
		}
	}
}