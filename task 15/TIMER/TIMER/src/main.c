#include <avr/io.h>
#include <avr/interrupt.h>
#include <util\delay.h>
#include "C:\Users\hp\Documents\Atmel Studio\7.0\TIMER\TIMER\STD_TYPES.h"
#include "C:\Users\hp\Documents\Atmel Studio\7.0\TIMER\TIMER\BIT_MATH.h"
#include "C:\Users\hp\Documents\Atmel Studio\7.0\TIMER\TIMER\DIO_interface.h"
#include "C:\Users\hp\Documents\Atmel Studio\7.0\TIMER\TIMER\TIMER_interface.h"
#include "C:\Users\hp\Documents\Atmel Studio\7.0\TIMER\TIMER\ADC_interface.h"


#define LED_PORT DIO_PORTD
#define LED_PIN  DIO_PIN6

void setup() {
	DIO_enumSetPinDirection(LED_PORT, LED_PIN, DIO_PIN_OUTPUT);
	ADC_voidInit();
	TIMER1_voidInit();


	ADC_u8StartConversionAsynch(ADC_CHANNEL0, NULL, NULL); 
}

void loop() {
	u16 adcResult = 0;
	u16 pwmValue;

	ADC_u8GetResultSync(ADC_CHANNEL0, &adcResult);

	// Map ADC result to PWM duty cycle
	pwmValue = (u16)(((u32)adcResult * 1023) / 1024 ); 

	
	TIMER1_voidSetCTCA(pwmValue);

}

int main(void) {
	setup();
	while(1) {
		loop();
	}
	return 0;
}