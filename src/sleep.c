#include <pico/stdlib.h>
#include <stdio.h>
#include <pico/sync.h>

#define OUT_PIN 5
#define DELAY_MS 50

int main(void) {
  int toggle = 0;
  stdio_init_all();
  gpio_init(OUT_PIN);
  gpio_set_dir(OUT_PIN, GPIO_OUT);
  gpio_put(OUT_PIN, toggle);

  while (true) {
    toggle = !toggle;
    for (int i = 0; i < 100000; i++){
    __nop();
  }
    gpio_put(OUT_PIN, toggle);
    sleep_ms(DELAY_MS);
  }
}
