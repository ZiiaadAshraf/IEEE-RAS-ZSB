/*
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  DIO_interface.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  Author : Ziad Ashraf 
  Layer  : MCAL
  SWC    : DIO  
  
  */
  
  #ifndef DIO_INTERFACE_H_
  #define DIO_INTERFACE_H_
  
  
  typedef enum {
	  DIO_NOK ,
	  DIO_OK 
  }DIO_ErrorState ;
  
  
  #define DIO_PIN_OUTPUT 1
  #define DIO_PIN_INPUT  0
  
  #define DIO_PIN HIGH 1
  #define DIO_PIN  LOW 0
  
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
  
  
  void DIO_voidSetPinDirection  (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Dierction );
  void DIO_voidSetPinValue      (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value     );
  u8   DIO_GetPinValue          (u8 Copy_u8Port , u8 Copy_u8Pin                       );
  
  
  
  #endif