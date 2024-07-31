/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    USART_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Ziad_Ashraf
 *  Layer  : MCAL
 *  SWC    : USART
 *
 */
 
/*File Gard*/
#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_
#include "C:\Users\hp\Documents\Atmel Studio\7.0\GccBoardProject4\GccBoardProject4\STD_TYPES.h"
void USART_voidInit (void);

u8   USART_u8SendData (u8 Copy_u8Data);
 
u8   USART_u8RecevieData (u8 * Copy_u8ReceviedData) ;

u8   USART_u8SendStringSynch (const u8 * Copy_pchString);
u8   USART_u8SendStringAsynch (const u8 * Copy_pchString , void (* NotificationFunc)(void)) ;

u8   USART_u8ReceiveBufferSynch (u8 * Copy_pchString , u32 Copy_uint32BufferSize) ;
u8   USART_u8ReceiveBufferAsynch (u8 * Copy_pchString , u32 Copy_uint32BufferSize , void (* NotificationFunc)(void)) ;

#endif