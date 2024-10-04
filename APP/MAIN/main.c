/*
 * 
 *
 * Created: 8/12/2023 3:34:43 PM
 * Author : Esraa Ali
 */ 
#define  F_CPU  16000000U
#include <util/delay.h>
#include "LED.h"
#include "BTN.h"
#include "PORT_Core.h"
#include "IRQH_Core.h"
#include "ADC_Core.h"
#include "LCD_Core.h"
#include "GPT_Core.h"
#include "PWM_Core.h"
#include "Ultrasonic.h"
#include "UART_Core.h"
#include "EEPROM_Core.h"
//#include <math.h>
#include "FXP.h"
#include "LUT.h"

/*void Temp_Func(void)
{
	LED_Toggle(LED_GREEN);
}*/


int main() 
{
	PORT_Init();
	LCD_Init();
	float a =12.45, b = 3.55;

	// Perform fixed-point addition
	uint32_t fixed_sum = fixed_add(a,b);
	
	// Perform fixed-point Substraction
	uint32_t fixed_subt= fixed_sub(a,b);
	
	// Perform fixed-point multiplication
	uint32_t fixed_product = fixed_mult(a,b);
	// Perform fixed-point division
    uint32_t fixed_div = fixed_DIV(a,b);
    LCD_WriteChar(fixed_sum);
	LCD_WriteInteger(fixed_sum);
    LCD_WriteString("/");
	LCD_WriteInteger(fixed_subt);
	LCD_WriteString("/");
	LCD_WriteInteger(fixed_product);
	LCD_WriteString("/");
	//LCD_WriteInteger(100);
	LCD_WriteChar(fixed_div);
	LCD_WriteString("/");
	
	
	
	return 0;
}
/*
int main() {
	PORT_Init();
	LCD_Init();
	draw_sine_wave();
	output_sine_wave();
	return 0;
}*/