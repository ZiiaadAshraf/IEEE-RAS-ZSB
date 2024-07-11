/*
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  CLCD_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  Author : Ziad_Ashraf 
  Layer  : HAL
  SWC    : CLCD
  
  */


#define F_CPU 8000000UL
#include <util/delay.h>

#include "C:\Users\hp\Documents\Atmel Studio\7.0\GccBoardProject3\GccBoardProject3\STD_TYPES.h"
#include "C:\Users\hp\Documents\Atmel Studio\7.0\GccBoardProject3\GccBoardProject3\BIT_MATH.h"
#include "C:\Users\hp\Documents\Atmel Studio\7.0\GccBoardProject3\GccBoardProject3\DIO_interface.h"
#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"


void CLCD_voidSendData(u8 Copy_u8Data) {
	#if CLCD_MODE == 8 
	DIO_enumSetPortValue (CLCD_DATA_PORT , Copy_u8Data);
	DIO_enumSetPinValue(CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_HIGH);
	DIO_enumSetPinValue(CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_LOW);
	CLCD_voidSendFallingEdge();
	
	#elif CLCD_MODE == 4 
	
	
	#endif
	_delay_ms(1);
}
void CLCD_voidSendString (const u8 * Copy_u8ptr ){
	u8 LOC_counter = 0 ;
	while (Copy_u8ptr [LOC_counter] == '\0') {
		CLCD_voidSendData(Copy_u8ptr[LOC_counter]);
		LOC_counter++;
	}
}

void CLCD_voidSendCommand(u8 Copy_u8Command) {
	#if CLCD_MODE == 8
	DIO_enumSetPortValue (CLCD_DATA_PORT , Copy_u8Command);
	DIO_enumSetPinValue(CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_LOW);
	DIO_enumSetPinValue(CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_LOW);
	CLCD_voidSendFallingEdge();
	
	#elif CLCD_MODE == 4
	
	
	#endif
	_delay_ms(1);
}

static void CLCD_voidSendFallingEdge() {
	DIO_enumSetPinValue(CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_enumSetPinValue(CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_LOW);
	_delay_ms(1);
}

void CLCD_voidInit (void) {
	#if CLCD_MODE == 8 
	_delay_ms(50);
	DIO_enumSetPortDirection(CLCD_DATA_PORT , DIO_PORT_OUTPUT );
	DIO_enumSetPinDirection(CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_OUTPUT);
	
	CLCD_voidSendCommand(lcd_Home);
	_delay_ms(1);
	CLCD_voidSendCommand(EIGHT_BITS);
	_delay_ms(1);
	CLCD_voidSendCommand(lcd_DisplayOn_CursorOff);
	_delay_ms(1);
	CLCD_voidClearScreen();
	CLCD_voidSendCommand(lcd_EntryMode);
	_delay_ms(1);
	
	#elif CLCD_MODE == 4
	
	#endif
}

CLCD_voidClearScreen(){
	CLCD_voidSendCommand(lcd_Clear);
	_delay_ms(5);
	}