#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "G:\Ziad\ras tasks\embedded ras\TASK11\GccBoardProject2\LIB\STD_TYPES.h"
#include "G:\Ziad\ras tasks\embedded ras\TASK11\GccBoardProject2\LIB\BIT_MATH.h"
#include "C:\Users\hp\Documents\Atmel Studio\7.0\GccBoardProject3\GccBoardProject3\DIO_interface.h"
#include "C:\Users\hp\Documents\Atmel Studio\7.0\GccBoardProject3\GccBoardProject3\CLCD_config.h"
#include "C:\Users\hp\Documents\Atmel Studio\7.0\GccBoardProject3\GccBoardProject3\CLCD_interface.h"
#include "C:\Users\hp\Documents\Atmel Studio\7.0\GccBoardProject3\GccBoardProject3\KPAD_config.h"
#include "C:\Users\hp\Documents\Atmel Studio\7.0\GccBoardProject3\GccBoardProject3\KPAD_interface.h"

void Calculator_Init(void);
u8 Get_Keypad_Input(void);
void Perform_Operation(u8 operation, u8 operand1, u8 operand2);
void Reset_Calculator(void);

int main(void)
{
	Calculator_Init();
	
	u8 operand1 = 0;
	u8 operand2 = 0;
	u8 operation = 0;
	u8 result = 0;
	u8 key;
	u8 Result_Displayed = 0; 

	while (1)
	{
		key = Get_Keypad_Input();
		
		if (key != NOT_PRESSED)
		{
			if (key >= '0' && key <= '9')
			{
				if (Result_Displayed)
				{
					CLCD_voidClearScreen();
					operand1 = 0;
					operand2 = 0;
					operation = 0;
					Result_Displayed = 0;
				}
				
				if (operation == 0)
				{
					operand1 = operand1 * 10 + (key - '0');
					CLCD_voidSendData(key);
				}
				else
				{
					operand2 = operand2 * 10 + (key - '0');
					CLCD_voidSendData(key);
				}
			}
			else if (key == '+' || key == '-' || key == '*' || key == '/')
			{
				operation = key;
				CLCD_voidSendData(key);
			}
			else if (key == '=')
			{
				Perform_Operation(operation, operand1, operand2);
				operand1 = 0;
				operand2 = 0;
				operation = 0;
				Result_Displayed = 1; 
			}
			else if (key == '?') 
			{
				Reset_Calculator();
				operand1 = 0;
				operand2 = 0;
				operation = 0;
				Result_Displayed = 0;
			}
		}
	}
}

void Calculator_Init(void)
{
	CLCD_voidInit();
	KPAD_voidInit();
}

u8 Get_Keypad_Input(void)
{
	return KPAD_u8GetPressed();
}

void Perform_Operation(u8 operation, u8 operand1, u8 operand2)
{
	u8 result;
	
	switch (operation)
	{
		case '+':
		result = operand1 + operand2;
		break;
		case '-':
		result = operand1 - operand2;
		break;
		case '*':
		result = operand1 * operand2;
		break;
		case '/':
		if (operand2 != 0)
		{
			result = operand1 / operand2;
		}
		else
		{
			CLCD_voidSendString((const u8 *)"Err");
			return;
		}
		break;
		default:
		return;
	}
	
	CLCD_voidClearScreen();
	if(result < 10) {
		CLCD_voidSendData(result + '0');
		} else {
		CLCD_voidSendData(result / 10 + '0');
		CLCD_voidSendData(result % 10 + '0');
	}
}

void Reset_Calculator(void)
{
	CLCD_voidClearScreen();
}