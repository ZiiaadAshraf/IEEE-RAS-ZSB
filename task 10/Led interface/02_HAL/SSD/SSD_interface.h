/*
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  SSD_interface.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  Author : Ziad Ashraf 
  Layer  : HAL
  SWC    : SSD
  
  */
  
  #ifndef SSD_INTERFACE_H_
  #define SSD_INTERFACE_H_
  
  #define SSD_PORTA 0
  #define SSD_PORTB 1
  #define SSD_PORTC 2
  #define SSD_PORTD 3
  
  #define SSD_PIN1  0
  #define SSD_PIN2  1
  #define SSD_PIN3  2
  #define SSD_PIN4  3
  #define SSD_PIN5  4
  #define SSD_PIN6  5
  #define SSD_PIN7  6
  #define SSD_PIN8  7
  
  #define SSD_COMMON_ANODE 1
  #define SSD_COMMON_CATHODE 0
  
  typedef struct {
	  u8 Type ;
	  u8 DataPort ;
	  u8 EnablePort ;
	  u8 EnablePin ;
  }SSD_Type ;
  
  void SSD_voidInitDataPort (SSD_Type Copy_StructConfig) ;
  void SSD_voidEnable (SSD_Type Copy_StructConfig) ;
  void SSD_voidDisable (SSD_Type Copy_StructConfig) ;
  void SSD_voidSendNumber (SSD_Type Copy_StructConfig) ;
  
  #endif
  