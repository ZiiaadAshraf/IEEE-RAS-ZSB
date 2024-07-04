/*
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  DIO_interface.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  Author : Ziad_Ashraf 
  Layer  : MCAL
  SWC    : DIO  
  
  */

 #include "STD_TYPES.h"
  
  #ifndef DIO_INTERFACE_H_
  #define DIO_INTERFACE_H_
  
  
  typedef enum {
	  DIO_NOK ,
	  DIO_OK 
  }DIO_ErrorState ;
  
  
  #define DIO_PIN_OUTPUT 1
  #define DIO_PIN_INPUT  0
  
  #define DIO_PIN_HIGH 1
  #define DIO_PIN_LOW 0
  
  #define DIO_PORTA 0
  #define DIO_PORTB 1
  #define DIO_PORTC 2
  #define DIO_PORTD 3
  
  #define DIO_PIN1  0
  #define DIO_PIN2  1
  #define DIO_PIN3  2
  #define DIO_PIN4  3
  #define DIO_PIN5  4
  #define DIO_PIN6  5
  #define DIO_PIN7  6
  #define DIO_PIN8  7
  
  
  DIO_ErrorState  DIO_enumSetPinDirection  (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Dierction );
  DIO_ErrorState  DIO_enumSetPinValue      (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value     );
  DIO_ErrorState  DIO_enumGetPinValue      (u8 Copy_u8Port , u8 Copy_u8Pin , u8 * Copy_PtrData    );
  void DIO_voidEnablePullUp                (u8 Copy_u8Port , u8 Copy_u8Pin);
  
  
  
  #endif