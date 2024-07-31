#include "C:\Users\hp\Documents\Atmel Studio\7.0\GccBoardProject4\GccBoardProject4\USART_interface.h"
#include "C:\Users\hp\Documents\Atmel Studio\7.0\GccBoardProject4\GccBoardProject4\CLCD_interface.h"
#ifndef F_CPU
#define F_CPU 8000000UL 
#endif
#include <util/delay.h>
#include <avr/io.h>

int main(void) {
	// Initialize USART and LCD
	USART_voidInit();
	CLCD_voidInit();
	CLCD_voidClearScreen(); // Clear the LCD screen

	u8 receivedData;

	while (1) {
		if (USART_u8RecevieData(&receivedData) == 0) { // Check if data received successfully
			CLCD_voidSendData(receivedData); // Display received data on LCD
			USART_u8SendData(receivedData); // Echo back the received data
		}
	}

	return 0; // This line will never be reached
}
