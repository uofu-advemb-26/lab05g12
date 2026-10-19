#include <FreeRTOS.h>
#include <pico/stdlib.h>
#include <stdio.h>
#include <task.h>
#include <pico/sync.h>

#define OUT_PIN 5
#define DELAY_MS 50

void main_task(__unused void *params) {
  int toggle = 0;
  while (1) {
    toggle = !toggle;
    for (int i = 0; i < 100000; i++){
    __nop();
  }
    gpio_put(OUT_PIN, toggle);
    vTaskDelay(pdMS_TO_TICKS(DELAY_MS));
  }
}

int main(void) {
  stdio_init_all();
  gpio_init(OUT_PIN);
  gpio_set_dir(OUT_PIN, GPIO_OUT);
  const char *rtos_name = "FreeRTOS";
  TaskHandle_t task;
  xTaskCreate(main_task, "MainThread", configMINIMAL_STACK_SIZE, NULL,
              tskIDLE_PRIORITY + 1UL, &task);
  vTaskStartScheduler();
  return 0;
}
