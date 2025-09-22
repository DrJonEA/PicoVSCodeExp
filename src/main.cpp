/**
 * Flash status LED from within FreeRTOS Kernel
 * Jon Durrant - 2025
 */

#include "pico/stdlib.h"

extern "C"{
#include "pico/status_led.h"
}
#include <cstdio>
#include <FreeRTOS.h>
#include <task.h>



#define DELAY_SHORT 200 // in microseconds

#define TASK_PRIORITY      ( tskIDLE_PRIORITY + 1UL )


void main_task(void* params){
	bool on;

 	printf("Main task started\n");

 	for (;;){
 		 status_led_set_state(on);
 		 on = !on;
 		vTaskDelay(DELAY_SHORT);
 	}
}




int main() {


	//Initialise IO as we are using printf for debug
	stdio_init_all();
	bool rc = status_led_init();
	hard_assert(rc);
	sleep_ms(2000);
	printf("Start\n");

	TaskHandle_t task;

   xTaskCreate(main_task, "MainThread", 2048, NULL, TASK_PRIORITY, &task);

  /* Start the tasks and timer running. */
	vTaskStartScheduler();

	for (;;){

	}
}
