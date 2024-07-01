/*
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  LED_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  Author : Ziad Ashraf 
  Layer  : HAL
  SWC    : LED
  
  */
  
  #include "STD_TYPES.h"
  #include "BIT_MATH.h"
  #include "DIO_interface.h"
  #include "LED_interface.h"
  
  void LED_voidInit   ( LED_TYPE LED_Confg ) {
	  DIO_enumSetPinDierction ( LED_Confg.Port , LED_Confg.Pin , DIO_PIN_OUTPUT ) ;
  }
  
  void LED_voidOn     ( LED_TYPE LED_Confg ) {
	  if ( LED_Confg.Active_State == ACTIVE_HIGH ){
		  DIO_enumSetPinValue ( LED_Confg.Port , LED_Confg.Pin , DIO_PIN_HIGH ) ;
	  }
	  else if ( LED_Confg.Active_State == ACTIVE_LOW ) {
		   DIO_enumSetPinValue ( LED_Confg.Port , LED_Confg.Pin , DIO_PIN_LOW ) ;
	  }
	  void LED_voidOff    ( LED_TYPE LED_Confg ) {
		  if ( LED_Confg.Active_State == ACTIVE_HIGH ){
		  DIO_enumSetPinValue ( LED_Confg.Port , LED_Confg.Pin , DIO_PIN_LOW ) ;
	  }
	  else if ( LED_Confg.Active_State == ACTIVE_LOW ) {
		   DIO_enumSetPinValue ( LED_Confg.Port , LED_Confg.Pin , DIO_PIN_HIGH ) ;
	  }
	  void LED_voidToggle ( LED_TYPE LED_Confg ) {
		  DIO_enumTogglePinValue ( LED_Confg.Port , LED_Confg.Pin )
	  }