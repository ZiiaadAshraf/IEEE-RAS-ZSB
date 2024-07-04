
#include <asf.h>
#include "C:\Users\hp\Documents\Atmel Studio\7.0\GccBoardProject2\GccBoardProject2\BIT_MATH.h"
#include "C:\Users\hp\Documents\Atmel Studio\7.0\GccBoardProject2\GccBoardProject2\STD_TYPES.h"
#include "C:\Users\hp\Documents\Atmel Studio\7.0\GccBoardProject2\GccBoardProject2\SW_interface.h"
#include "C:\Users\hp\Documents\Atmel Studio\7.0\GccBoardProject2\GccBoardProject2\DIO_interface.h"
#include <util/delay.h>

#define IN1 PD1
#define IN2 PD2
#define IN3 PD3
#define IN4 PD4

#define STOP_PIN PA0
#define FORWARD_PIN PA1
#define BACK_PIN PA2
#define LEFT_PIN PA3
#define RIGHT_PIN PA4


void setup () {
	DIO_enumSetPinDirection(DIO_PORTD, IN1, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(DIO_PORTD, IN2, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(DIO_PORTD, IN3, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(DIO_PORTD, IN4, DIO_PIN_OUTPUT);
	
	SW_Type stopSwitch = {DIO_PORTA, STOP_PIN, SW_INT_PULL_UP};
	SW_Type forwardSwitch = {DIO_PORTA, FORWARD_PIN, SW_INT_PULL_UP};
	SW_Type backSwitch = {DIO_PORTA, BACK_PIN, SW_INT_PULL_UP};
	SW_Type leftSwitch = {DIO_PORTA, LEFT_PIN, SW_INT_PULL_UP};
	SW_Type rightSwitch = {DIO_PORTA, RIGHT_PIN, SW_INT_PULL_UP};

	SW_voidInit(stopSwitch);
	SW_voidInit(forwardSwitch);
	SW_voidInit(backSwitch);
	SW_voidInit(leftSwitch);
	SW_voidInit(rightSwitch);
}

void Stop() {
	DIO_enumSetPinValue(DIO_PORTD, IN1, DIO_PIN_LOW);
	DIO_enumSetPinValue(DIO_PORTD, IN2, DIO_PIN_LOW);
	DIO_enumSetPinValue(DIO_PORTD, IN3, DIO_PIN_LOW);
	DIO_enumSetPinValue(DIO_PORTD, IN4, DIO_PIN_LOW);
}

void Forward() {
	DIO_enumSetPinValue(DIO_PORTD, IN1, DIO_PIN_HIGH);
	DIO_enumSetPinValue(DIO_PORTD, IN2, DIO_PIN_LOW);
	DIO_enumSetPinValue(DIO_PORTD, IN3, DIO_PIN_HIGH);
	DIO_enumSetPinValue(DIO_PORTD, IN4, DIO_PIN_LOW);
}

void Back() {
	DIO_enumSetPinValue(DIO_PORTD, IN1, DIO_PIN_LOW);
	DIO_enumSetPinValue(DIO_PORTD, IN2, DIO_PIN_HIGH);
	DIO_enumSetPinValue(DIO_PORTD, IN3, DIO_PIN_LOW);
	DIO_enumSetPinValue(DIO_PORTD, IN4, DIO_PIN_HIGH);
}

void Left() {
	DIO_enumSetPinValue(DIO_PORTD, IN1, DIO_PIN_LOW);
	DIO_enumSetPinValue(DIO_PORTD, IN2, DIO_PIN_HIGH);
	DIO_enumSetPinValue(DIO_PORTD, IN3, DIO_PIN_HIGH);
	DIO_enumSetPinValue(DIO_PORTD, IN4, DIO_PIN_LOW);
}

void Right() {
	DIO_enumSetPinValue(DIO_PORTD, IN1, DIO_PIN_HIGH);
	DIO_enumSetPinValue(DIO_PORTD, IN2, DIO_PIN_LOW);
	DIO_enumSetPinValue(DIO_PORTD, IN3, DIO_PIN_LOW);
	DIO_enumSetPinValue(DIO_PORTD, IN4, DIO_PIN_HIGH);
}

int main (void)
{
	setup();
	
	
	while(1) {
		
		SW_Type stopSwitch = {DIO_PORTA, STOP_PIN, SW_INT_PULL_UP};
		SW_Type forwardSwitch = {DIO_PORTA, FORWARD_PIN, SW_INT_PULL_UP};
		SW_Type backSwitch = {DIO_PORTA, BACK_PIN, SW_INT_PULL_UP};
		SW_Type leftSwitch = {DIO_PORTA, LEFT_PIN, SW_INT_PULL_UP};
		SW_Type rightSwitch = {DIO_PORTA, RIGHT_PIN, SW_INT_PULL_UP};
			
		if (SW_u8GetPressed(stopSwitch) == SW_PRESSED) {
			Stop();
			} else if (SW_u8GetPressed(forwardSwitch) == SW_PRESSED) {
			Forward();
			} else if (SW_u8GetPressed(backSwitch) == SW_PRESSED) {
			Back();
			} else if (SW_u8GetPressed(leftSwitch) == SW_PRESSED) {
			Left();
			} else if (SW_u8GetPressed(rightSwitch) == SW_PRESSED) {
			Right();
		}	
	}

      return 0 ;
	
}
