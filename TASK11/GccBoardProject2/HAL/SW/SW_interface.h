/*
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  SW_interface.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  Author : Ziad_Ashraf 
  Layer  : HAL
  SWC    : SWITCH
  
  */

  #include "BIT_MATH.h"
  #include "STD_TYPES.h"

 #ifndef SW_INTERFACE_H_
 #define SW_INTERFACE_H_

 #define SW_NOT_PRESSED 0
 #define SW_PRESSED 1

 #define SW_INT_PULL_UP 0
 #define SW_EXT_PULL_UP 1
 #define SW_EXT_PULL_DOWN 2
 #define SW_FLOATING 3


 typedef struct 
 {
    u8 Port ;
    u8 Pin ;
    u8 Pull_State ;
 }SW_Type;

 void SW_voidInit (SW_Type SW_Config) ;
 u8 SW_u8GetPressed (SW_Type SW_Config);
 

 #endif