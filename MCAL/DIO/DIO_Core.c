/*
 * DIO_Core.c
 *
 * Created: 8/19/2023 5:44:42 PM
 *  Author: Esraa Ali
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
#include "DIO_Core.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

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
void DIO_WriteChennel(uint8_t Pin_Num , PIN_VALUE_t Pin_value )
{
	uint8_t Port = 0 , Pin = 0;
	
	Port = Pin_Num / NUMBER_OF_EACH_PORT_PINS ;
	Pin  = Pin_Num % NUMBER_OF_EACH_PORT_PINS ;
	
	switch(Pin_value)
	{
		case PIN_HIGH :
		
		switch(Port)
		{
		case 0:
		SET_BIT(PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) ,Pin );
		break;
		
		case 1:
		SET_BIT(PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) ,Pin );
		break;
		
		case 2:
		SET_BIT(PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) ,Pin );
		break;
		
		case 3:
		SET_BIT(PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) ,Pin );
		break;
		
		default:
		break;
		}
		break;
		
		case PIN_LOW :
				
		switch(Port)
		{
			case 0:
			CLR_BIT(PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) ,Pin );
			break;
			
			case 1:
			CLR_BIT(PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) ,Pin );
			break;
			
			case 2:
			CLR_BIT(PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) ,Pin );
			break;
			
			case 3:
			CLR_BIT(PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) ,Pin );
			break;
			
			default:
			break;
		}
		break;
		
		default:
		break;
	}
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
void DIO_ReadChennel(uint8_t Pin_Num , PIN_VALUE_t * Pin_value )
{
	uint8_t Port = 0 , Pin = 0;
	Port = Pin_Num / NUMBER_OF_EACH_PORT_PINS ;
	Pin  = Pin_Num % NUMBER_OF_EACH_PORT_PINS ;
	
	switch(Port)
	{
	 case 0:
	 *Pin_value = GET_BIT(PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS + GPIO_INPUT_REGISTER_PIN) ,Pin );
	 break;
	 
	 case 1:
	 *Pin_value = GET_BIT(PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS + GPIO_INPUT_REGISTER_PIN) ,Pin );
	 break;
	 
	 case 2:
	 *Pin_value = GET_BIT(PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS + GPIO_INPUT_REGISTER_PIN) ,Pin );
	 break;
	 
	 case 3:
	 *Pin_value = GET_BIT(PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS + GPIO_INPUT_REGISTER_PIN) ,Pin );
	 break;
	 
	 default:
	 break;		
	}
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
void DIO_FlipChennel(uint8_t Pin_Num)
{
	uint8_t Port = 0 , Pin = 0;
	Port = Pin_Num / NUMBER_OF_EACH_PORT_PINS ;
	Pin  = Pin_Num % NUMBER_OF_EACH_PORT_PINS ;
	
	switch(Port)
	{
		case 0:
		 Toggle_BIT(PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) ,Pin );
		break;
		
		case 1:
		Toggle_BIT(PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) ,Pin );
		break;
		
		case 2:
		Toggle_BIT(PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) ,Pin );
		break;
		
		case 3:
		Toggle_BIT(PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) ,Pin );
		break;
		
		default:
		break;
	}	
	
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
void DIO_WritePort(uint8_t Pin_Num , uint8_t Port_value )
{
	uint8_t Port = 0;
	Port = Pin_Num / NUMBER_OF_EACH_PORT_PINS ;
	
	switch(Port)
	{
		case 0:
		PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) = Port_value;
		break;
		
		case 1:
		PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) = Port_value;
		break;
		
		case 2:
		PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) = Port_value;
		break;
		
		case 3:
		PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS + GPIO_OUTPUT_REGISTER_PORT) = Port_value;
		break;
		
		default:
		break;
	}
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
void DIO_ReadPort(uint8_t Pin_Num , uint8_t * Port_value )
{
	uint8_t Port = 0;
	Port = Pin_Num / NUMBER_OF_EACH_PORT_PINS ;
	
	switch(Port)
	{
		case 0:
		*Port_value = PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS + GPIO_INPUT_REGISTER_PIN);
		break;
		
		case 1:
		*Port_value = PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS + GPIO_INPUT_REGISTER_PIN);
		break;
		
		case 2:
		*Port_value = PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS + GPIO_INPUT_REGISTER_PIN);
		break;
		
		case 3:
		*Port_value = PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS + GPIO_INPUT_REGISTER_PIN);
		break;
		
		default:
		break;
	}	
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
