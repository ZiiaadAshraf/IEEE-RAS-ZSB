

#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LED_interface.h"
#include <util/delay.h>
int main(void)
{

   LED_TYPE RED = {LED_PORTA,LED_PIN1,ACTIVE_HIGH};
   LED_TYPE YELLOW = {LED_PORTA,LED_PIN2,ACTIVE_HIGH};
   LED_TYPE GREEN = {LED_PORTA,LED_PIN3,ACTIVE_HIGH};

   LED_voidInit(RED);
   LED_voidInit(YELLOW);
   LED_voidInit(GREEN);


    while(1) {
        LED_voidOn(RED);
        LED_voidOff(YELLOW);
        LED_voidOff(GREEN);
       _delay_ms(15000);

       
        LED_voidOff(RED);
        LED_voidOn(YELLOW);
        LED_voidOff(GREEN);
       _delay_ms(5000);


        LED_voidOff(RED);
        LED_voidOff(YELLOW);
        LED_voidOn(GREEN);
       _delay_ms(10000);

        }
         return 0;
    }




