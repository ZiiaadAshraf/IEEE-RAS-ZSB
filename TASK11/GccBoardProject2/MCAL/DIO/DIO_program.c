/*
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  DIO_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  Author : Ziad_Ashraf 
  Layer  : MCAL
  SWC    : DIO  
  
  */
  
  #include "STD_TYPES.h"
  #include "BIT_MATH.h"
  #include "DIO_interface.h"
  #include "DIO_private.h"
  
  DIO_ErrorState DIO_enumSetPinDirection  (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Dierction )
  {
	DIO_ErrorState LOC_enumState = DIO_OK ;

	  if (Copy_u8Dierction == DIO_PIN_OUTPUT)
	  {
		  switch ( Copy_u8Port){
			 case DIO_PORTA : SET_BIT (DDRA, Copy_u8Pin);break;
			 case DIO_PORTB : SET_BIT (DDRB, Copy_u8Pin);break;
			 case DIO_PORTC : SET_BIT (DDRC, Copy_u8Pin);break;
			 case DIO_PORTD : SET_BIT (DDRD, Copy_u8Pin);break;
		  }
	  } 
	  else if (Copy_u8Dierction == DIO_PIN_INPUT) {
		  switch ( Copy_u8Port){
			 case DIO_PORTA : CLR_BIT (DDRA, Copy_u8Pin);break;
			 case DIO_PORTB : CLR_BIT (DDRB, Copy_u8Pin);break;
			 case DIO_PORTC : CLR_BIT (DDRC, Copy_u8Pin);break;
			 case DIO_PORTD : CLR_BIT (DDRD, Copy_u8Pin);break;
		  }
	  }
	  else {
		LOC_enumState = DIO_NOK ;
	  }
	  return LOC_enumState;
	  
  }
  
  DIO_ErrorState DIO_enumSetPinValue      (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value ) 
	  {
		  DIO_ErrorState LOC_enumState = DIO_OK ;
	  if (Copy_u8Value == DIO_PIN_HIGH)
	  {
		  switch ( Copy_u8Port){
			 case DIO_PORTA : SET_BIT (PORTA, Copy_u8Pin);break;
			 case DIO_PORTB : SET_BIT (PORTB, Copy_u8Pin);break;
			 case DIO_PORTC : SET_BIT (PORTC, Copy_u8Pin);break;
			 case DIO_PORTD : SET_BIT (PORTD, Copy_u8Pin);break;
		  }
	  } 
	  else if (Copy_u8Value == DIO_PIN_LOW) {
		  switch ( Copy_u8Port){
			 case DIO_PORTA : CLR_BIT (PORTA, Copy_u8Pin);break;
			 case DIO_PORTB : CLR_BIT (PORTB, Copy_u8Pin);break;
			 case DIO_PORTC : CLR_BIT (PORTC, Copy_u8Pin);break;
			 case DIO_PORTD : CLR_BIT (PORTD, Copy_u8Pin);break;
		  }
	  }
	  else { LOC_enumState = DIO_NOK ;
	  }
	  return LOC_enumState ;
	  }
	  
  
 DIO_ErrorState  DIO_enumGetPinValue          (u8 Copy_u8Port , u8 Copy_u8Pin ,  u8 * Copy_PtrData   ) {
	  DIO_ErrorState LOC_enumState = DIO_OK ;
	  if (( Copy_u8Port <= DIO_PORTD) && ( Copy_u8Pin <= DIO_PIN8)) {
	  
	  switch ( Copy_u8Port){
			 case DIO_PORTA : * Copy_PtrData = GET_BIT (PINA, Copy_u8Pin);break;
			 case DIO_PORTB : * Copy_PtrData = GET_BIT (PINB, Copy_u8Pin);break;
			 case DIO_PORTC : * Copy_PtrData = GET_BIT (PINC, Copy_u8Pin);break;
			 case DIO_PORTD : * Copy_PtrData = GET_BIT (PIND, Copy_u8Pin);break;
		  }
	  }
	  else {
		  LOC_enumState = DIO_NOK ;
	  }
		  return LOC_enumState ;
	  
  }
  
  DIO_ErrorState DIO_enumTogglePinValue ( u8 Copy_u8Port , u8 Copy_u8Pin) {
	  DIO_ErrorState LOC_enumState = DIO_OK ;
	  
	  if (Copy_u8Pin <=DIO_PIN8)
	  {
		  switch (Copy_u8Port){
			  case DIO_PORTA : TOG_BIT ( PORTA , Copy_u8Pin ) ; break ;
			  case DIO_PORTB : TOG_BIT ( PORTB , Copy_u8Pin ) ; break ;
			  case DIO_PORTC : TOG_BIT ( PORTC , Copy_u8Pin ) ; break ;
			  case DIO_PORTD : TOG_BIT ( PORTD , Copy_u8Pin ) ; break ;
		  }
	  }
	  else {
		  LOC_enumState = DIO_NOK ;
	  }
	  return LOC_enumState ;
  }


  DIO_ErrorState DIO_enumEnablePullUp (u8 Copy_u8Port , u8 Copy_u8Pin) {
	DIO_ErrorState LOC_enumState = DIO_OK ;
        if (( Copy_u8Port <= DIO_PORTD) && ( Copy_u8Pin <= DIO_PIN8)) {
		SET_BIT (Copy_u8Port,Copy_u8Pin) ;
	}
	else { LOC_enumState = DIO_NOK ;}
	return LOC_enumState ;
  }

  void DIO_voidDisablePullUp () {
	SET_BIT (SFIOR,PUD);
  }
