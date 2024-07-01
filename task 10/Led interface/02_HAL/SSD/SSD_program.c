/*
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  Seven_Segment_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  Author : Ziad Ashraf 
  Layer  : HAL
  SWC    : SSD
  
  */
  
  #include "STD_TYPES.h"
  #include "BIT_MATH.h"
  #include "DIO_interface.h"
  #include "SSD_interface.h"
  #include "SSD_config.h"
  #include "SSD_private.h"
  
  static u8 Local_u8SSDNumbers [10] = SSD_NUMBER_ARR ;
  
  void SSD_voidInitDataPort (SSD_Type Copy_StructConfig) {
	  DIO_enumSetPortDirection ( Copy_StructConfig.DataPort , 0xFF )
  }
  void SSD_voidEnable (SSD_Type Copy_StructConfig) {
	  if (Copy_StructConfig.Type == SSD_COMMON_ANODE ) {
		  DIO_enumSetPinDirection ( Copy_StructConfig.EnablePort , Copy_StructConfig.EnablePin , DIO_PIN_OUTPUT )
		  DIO_enumSetPinValue     ( Copy_StructConfig.EnablePort , Copy_StructConfig.EnablePin , DIO_PIN_HIGH	)
	  }
	  else if ( Copy_StructConfig.Type == SSD_COMMON_CATHODE) {
		  DIO_enumSetPinDirection ( Copy_StructConfig.EnablePort , Copy_StructConfig.EnablePin , DIO_PIN_OUTPUT )
		  DIO_enumSetPinValue     ( Copy_StructConfig.EnablePort , Copy_StructConfig.EnablePin , DIO_PIN_LOW	)
	  }
  }
  
  void SSD_voidDisable (SSD_Type Copy_StructConfig) {
	  if (Copy_StructConfig.Type == SSD_COMMON_ANODE ) {
		  DIO_enumSetPinDirection ( Copy_StructConfig.EnablePort , Copy_StructConfig.EnablePin , DIO_PIN_OUTPUT )
		  DIO_enumSetPinValue     ( Copy_StructConfig.EnablePort , Copy_StructConfig.EnablePin , DIO_PIN_LOW	)
	  }
	  else if ( Copy_StructConfig.Type == SSD_COMMON_CATHODE) {
		  DIO_enumSetPinDirection ( Copy_StructConfig.EnablePort , Copy_StructConfig.EnablePin , DIO_PIN_OUTPUT )
		  DIO_enumSetPinValue     ( Copy_StructConfig.EnablePort , Copy_StructConfig.EnablePin , DIO_PIN_HIGH	)
	  }
  }
  
  void SSD_voidSendNumber (SSD_Type Copy_StructConfig , Copy_u8Number) {
	  if ( Copy_StructConfig.Type == SSD_COMMON_CATHODE){
	  DIO_enumSetPortValue ( Copy_StructConfig.DataPort , Local_u8SSDNumbers [Copy_u8Number] )
	  }
	  else if ( Copy_StructConfig.Type == SSD_COMMON_ANODE){
	  DIO_enumSetPortValue ( Copy_StructConfig.DataPort , ~( Local_u8SSDNumbers [Copy_u8Number] ) )
	  }
  }