/*
 * KeyPad.c
 *
 * Created:  10:02:11 PM
 *  Author:Esraa Ali
 */ 
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "KEYPAD_Core.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define F_CPU   16000000
#include <util/delay.h>
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
const static uint8_t KEYPAD_VALUES[4][4] ={ {'1' , '2' , '3' , '/'} ,
{'4' , '5' , '6' , '*'} ,
{'7' , '8' , '9' , '-'} ,
{'c' , '0' , '=' , '+'} };
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/



STD_RETURN KeyPad_Init(void)
{
	STD_RETURN return_val = NOK;
	
	DIO_WriteChennel(KEYPAD_ROW_0, PIN_HIGH);
	DIO_WriteChennel(KEYPAD_ROW_1, PIN_HIGH);
	DIO_WriteChennel(KEYPAD_ROW_2, PIN_HIGH);
	DIO_WriteChennel(KEYPAD_ROW_3, PIN_HIGH);

	return_val = OK;
	return return_val ;
}



/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
uint8_t KeyPad_GetValue(void)
{
	uint8_t Col_Loc = 0;
	uint8_t Row_Loc = 0;
	uint8_t Button_Value = 0;
	
	uint8_t Temp;
	
	for(Row_Loc=12 ; Row_Loc<=15 ; Row_Loc++)
	{
		DIO_WriteChennel(Row_Loc, PIN_LOW);
		
		for(Col_Loc = 26 ; Col_Loc <= 29 ; Col_Loc++)
		{
			DIO_ReadChennel(Col_Loc , &Temp);
			
			if(Temp == KEYPAD_PRESSED)
			{
				Button_Value =KEYPAD_VALUES[Row_Loc - ROW_INIT][Col_Loc - COL_INIT];
				
				
				while(Temp == KEYPAD_PRESSED)
				{
					DIO_ReadChennel(Col_Loc , &Temp);
				}
				
				_delay_ms(10);
				
			}
			
			else
			{
				
			}
		}
		
		DIO_WriteChennel(Row_Loc, PIN_HIGH);
	}
	
	return Button_Value ;
	
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/


