/*
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< KPAD_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  Author : Ziad_Ashraf 
  Layer  : HAL
  SWC    : KPAD
  
  */

#include <util/delay.h>

#include "C:\Users\hp\Documents\Atmel Studio\7.0\GccBoardProject3\GccBoardProject3\STD_TYPES.h"
#include "C:\Users\hp\Documents\Atmel Studio\7.0\GccBoardProject3\GccBoardProject3\BIT_MATH.h"
#include "C:\Users\hp\Documents\Atmel Studio\7.0\GccBoardProject3\GccBoardProject3\DIO_interface.h"
#include "C:\Users\hp\Documents\Atmel Studio\7.0\GccBoardProject3\GccBoardProject3\KPAD_config.h"
#include "C:\Users\hp\Documents\Atmel Studio\7.0\GccBoardProject3\GccBoardProject3\KPAD_interface.h"
#include "C:\Users\hp\Documents\Atmel Studio\7.0\GccBoardProject3\GccBoardProject3\KPAD_private.h"

u8 KPAD_u8Buttons [4][4] = { { '7' , '8' , '9' , '/' } ,
{ '4' , '5' , '6' , '*' } ,
{ '1' , '2' , '3' , '-' } ,
{ '?' , '0' , '=' , '+' }
} ;



void KPAD_voidInit(){
	DIO_enumEnablePullUp (KPAD_PORT , KPAD_ROW0);
	DIO_enumEnablePullUp (KPAD_PORT , KPAD_ROW1);
	DIO_enumEnablePullUp (KPAD_PORT , KPAD_ROW2);
	DIO_enumEnablePullUp (KPAD_PORT , KPAD_ROW3);
	
	DIO_enumSetPinDirection(KPAD_PORT , KPAD_COL0 , DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(KPAD_PORT , KPAD_COL1 , DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(KPAD_PORT , KPAD_COL2 , DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(KPAD_PORT , KPAD_COL3 , DIO_PIN_OUTPUT);
	
	DIO_enumSetPinValue(KPAD_PORT , KPAD_COL0 , DIO_PIN_HIGH);
	DIO_enumSetPinValue(KPAD_PORT , KPAD_COL1 , DIO_PIN_HIGH);
	DIO_enumSetPinValue(KPAD_PORT , KPAD_COL2 , DIO_PIN_HIGH);
	DIO_enumSetPinValue(KPAD_PORT , KPAD_COL3 , DIO_PIN_HIGH);
	
	
}

u8 KPAD_u8GetPressed(){
	u8 LOC_u8GetPressed ;
	u8 LOC_u8ReturnData = NOT_PRESSED;
	u8 LOC_u8Row ;
	u8 LOC_u8Col ;
	
	for (LOC_u8Col = 0 + KPAD_COL_INIT ; LOC_u8Col < KPAD_COL_END +1 ; LOC_u8Col ++) {
		DIO_enumSetPinValue(KPAD_PORT , LOC_u8Col , DIO_PIN_LOW);
		for (LOC_u8Row = 0 + KPAD_ROW_INIT ; LOC_u8Row < KPAD_ROW_END +1 ; LOC_u8Row ++) {
			DIO_enumGetPinValue(KPAD_PORT , LOC_u8Row , &LOC_u8GetPressed);
			if (LOC_u8GetPressed ==0)
			{
				_delay_ms(50);
				DIO_enumGetPinValue(KPAD_PORT , LOC_u8Row , &LOC_u8GetPressed);
				if (LOC_u8GetPressed ==0){
					LOC_u8ReturnData = KPAD_u8Buttons[LOC_u8Row - KPAD_ROW_INIT][LOC_u8Col - KPAD_COL_INIT];
				}
				DIO_enumGetPinValue(KPAD_PORT , LOC_u8Row , &LOC_u8GetPressed);
				while(DIO_PIN_LOW == LOC_u8GetPressed){
					DIO_enumGetPinValue(KPAD_PORT , LOC_u8Row , &LOC_u8GetPressed);
				}
				break;
	
			}
			
		}
		DIO_enumSetPinValue(KPAD_PORT , LOC_u8Col , DIO_PIN_HIGH);
	}
	
	return LOC_u8ReturnData ;
}