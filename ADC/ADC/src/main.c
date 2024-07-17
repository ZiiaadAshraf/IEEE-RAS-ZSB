
#include "C:\Users\hp\Documents\Atmel Studio\7.0\ADC\ADC\STD_TYPES.h"
#include "C:\Users\hp\Documents\Atmel Studio\7.0\ADC\ADC\DIO_interface.h"
#include "C:\Users\hp\Documents\Atmel Studio\7.0\ADC\ADC\ADC_interface.h"  
#include <util/delay.h>


#define LED_COUNT       8
#define ADC_CHANNEL     ADC_CHANNEL0  // Example ADC channel
#define ADC_MAX_VALUE   
// Define LED pins (example)
u8 LED_Pins[LED_COUNT] = {DIO_PIN1, DIO_PIN2, DIO_PIN3, DIO_PIN4, DIO_PIN5, DIO_PIN6, DIO_PIN7, DIO_PIN8};

// Function to map ADC value to LED count
u8 MapADCtoLEDs(u16 adcValue) {
	// Calculate LED count based on ADC value
	// We divide ADC_MAX_VALUE by LED_COUNT to get the range for each LED
	u8 ledCount = (adcValue * LED_COUNT) / (ADC_MAX_VALUE + 1);  // +1 to ensure the full range is covered

	return ledCount;
}

int main() {
	// Initialize ADC
	ADC_voidInit();

	// Set LED pins as output
	for (u8 i = 0; i < LED_COUNT; i++) {
		DIO_enumSetPinDirection(DIO_PORTC, LED_Pins[i], DIO_PIN_OUTPUT);
	}

	// Main loop
	while (1) {
		u16 adcValue = 0;

		// Read ADC value
		ADC_u8GetResultSync(ADC_CHANNEL, &adcValue);

		// Map ADC value to LED count
		u8 ledCount = MapADCtoLEDs(adcValue);

		// Turn on LEDs based on mapped count
		for (u8 i = 0; i < LED_COUNT; i++) {
			if (i < ledCount) {
				DIO_enumSetPinValue(DIO_PORTC, LED_Pins[i], DIO_PIN_HIGH);  // Turn LED on
				} else {
				DIO_enumSetPinValue(DIO_PORTC, LED_Pins[i], DIO_PIN_LOW);   // Turn LED off
			}
		}

		_delay_ms(100);  // Delay for stability
	}

	return 0;
}