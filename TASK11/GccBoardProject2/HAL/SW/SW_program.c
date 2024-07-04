/*
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  SW_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  Author : Ziad_Ashraf 
  Layer  : HAL
  SWC    : SWITCH
  
  */

  #include "BIT_MATH.h"
  #include "STD_TYPES.h"

  #include "DIO_interface.h"
  #include "SW_interface.h"
  

  void SW_voidInit (SW_Type SW_Config) {
    DIO_enumSetPinDirection (SW_Config.Port , SW_Config.Pin , DIO_PIN_INPUT ) ;
    if (SW_Config.Pull_State == SW_INT_PULL_UP) {
        DIO_enumSetPinValue (SW_Config.Port , SW_Config.Pin , DIO_PIN_HIGH) ;
    }
  }

  u8 SW_u8GetPressed(SW_Type SW_Config) {
	  u8 pin_state = SW_NOT_PRESSED;
	  u8 result = SW_NOT_PRESSED;
	  DIO_ErrorState dio_state;

	  dio_state = DIO_enumGetPinValue(SW_Config.Port,SW_Config.Pin, SW_Config.Pull_State);

	  if (dio_state == DIO_OK) {
		  if (SW_Config.Pull_State == SW_INT_PULL_UP ||SW_Config.Pull_State == SW_EXT_PULL_UP) {
			  result = (pin_state == 0) ? SW_PRESSED : SW_NOT_PRESSED;
			  } else if (SW_Config.Pull_State == SW_EXT_PULL_DOWN || SW_Config.Pull_State == SW_FLOATING) {
			  result = (pin_state == 1) ? SW_PRESSED : SW_NOT_PRESSED;
		  }
	  }

	  return result;
  }
