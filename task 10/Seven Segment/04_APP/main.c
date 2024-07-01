#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SSD_interface.h"
#include <util/delay.h>

int main(void)
{
 
SSD_TYPE FIRST  = { SSD_COMMON_CATHODE , SSD_PORTA , SSD_PORTB , SSD_PIN1 } ;
SSD_TYPE SECOND = { SSD_COMMON_CATHODE , SSD_PORTA , SSD_PORTB , SSD_PIN2 } ;

SSD_voidInitDataPort (FIRST) ;
SSD_voidInitDataPort (SECOND) ;

u8 counter = 0 ;

while(1) {
	
	SSD_voidSendNumber (FIRST , counter % 10 );
	_delay_ms(5);
	SSD_voidSendNumber (SECOND , counter / 10 );
	_delay_ms(5);
	
	if((counter % 100 ) == 99 ) {
		counter = 0 ;
	} else {
		counter ++ ;
	}
	
	_delay_ms(1000)
	
}

     return 0 ;
}