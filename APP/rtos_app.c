/*
 * rtos_app.c
 *
 * Created: 8/11/2020 6:20:18 PM
 *  Author: safifi
 */ 


#include "std_macros.h"

#include "FreeRTOS.h"
#include "task.h"

#include "LCD.h"
void task1(){
	lcd_init();
	uint8_t count =  0;
	while (1)
	{
		lcd_write_command(1);
		lcd_write_num(count++);
		vTaskDelay(500);
	}
}
void task2(){
	SETBIT(DDRD,2);
	while (1)
	{
		TOGBIT(PORTD,2);
		_delay_ms(500);
	}	
}
int main(void)
{
	xTaskCreate(task1, "lcd", 80, NULL, 1, NULL);
	xTaskCreate(task2, "led", 80, NULL, 1, NULL);
	vTaskStartScheduler();
}