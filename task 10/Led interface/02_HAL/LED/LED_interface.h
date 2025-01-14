/*
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  LED_interface.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  Author : Ziad Ashraf 
  Layer  : HAL
  SWC    : LED
  
  */
  
  #ifndef LED_INTERFACE_H_
  #define LED_INTERFACE_H_
  
  #define LED_PORTA 0
  #define LED_PORTB 1
  #define LED_PORTC 2
  #define LED_PORTD 3
  
  #define LED_PIN1  0
  #define LED_PIN2  1
  #define LED_PIN3  2
  #define LED_PIN4  3
  #define LED_PIN5  4
  #define LED_PIN6  5
  #define LED_PIN7  6
  #define LED_PIN8  7
  
  #define ACTIVE_HIGH 1
  #define ACTIVE_LOW  0
  
  typedef struct {
	  u8 Port ;
	  u8 Pin ;
	  u8 Active_State ;
  }LED_TYPE ;
  
  
  void LED_voidInit   ( LED_TYPE LED_Confg ) ;
  void LED_voidOn     ( LED_TYPE LED_Confg ) ;
  void LED_voidOff    ( LED_TYPE LED_Confg ) ;
  void LED_voidToggle ( LED_TYPE LED_Confg ) ;