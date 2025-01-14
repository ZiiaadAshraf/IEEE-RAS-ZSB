/*
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  BIT_MATH.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  Author : Ziad_Ashraf 
  Layer : LIB 
  
  */
  
  #ifndef BIT_MATH_H_
  #define BIT_MATH_H_

  #define SET_BIT(reg, bit)     reg |= (1 << bit)
  #define CLR_BIT(reg, bit)     reg &= (~(1 << bit))
  #define TOG_BIT(reg, bit)     reg ^= (1 << bit)
  #define GET_BIT(reg, bit)     ((reg & (1 << bit)) >> bit)

  #endif