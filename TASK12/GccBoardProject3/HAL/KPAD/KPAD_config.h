/*
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< KPAD_config.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  Author : Ziad_Ashraf 
  Layer  : HAL
  SWC    : KPAD
  
  */


#ifndef KPAD_CONFIG_H_
#define KPAD_CONFIG_H_
#define KPAD_ROW_INIT   DIO_PIN1
#define KPAD_ROW_END   DIO_PIN4

#define KPAD_COL_INIT   DIO_PIN5
#define KPAD_COL_END    DIO_PIN8

extern u8 KPAD_u8Buttons[4][4];
#define KPAD_PORT   DIO_PORTC

#define KPAD_ROW0   DIO_PIN1
#define KPAD_ROW1   DIO_PIN2
#define KPAD_ROW2   DIO_PIN3
#define KPAD_ROW3   DIO_PIN4

#define KPAD_COL0   DIO_PIN5
#define KPAD_COL1   DIO_PIN6
#define KPAD_COL2   DIO_PIN7
#define KPAD_COL3   DIO_PIN8


#endif /* KPAD_CONFIG_H_ */