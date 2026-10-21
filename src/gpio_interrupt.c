#include <pico/stdlib.h>
#include <pico/sync.h>
#include <stdio.h>

#define IN_PIN 16
#define OUT_PIN 28

int toggle = 1;
void irq_callback(uint gpio, uint32_t event_mask)
{
    for (volatile int i = 0; i < 100000000; i++){
    __nop();
  }
    if (gpio != IN_PIN) return;
    toggle = !toggle;
    if (event_mask & GPIO_IRQ_EDGE_RISE) {
        gpio_put(OUT_PIN, true);
    } else if (event_mask & GPIO_IRQ_EDGE_FALL) {
        gpio_put(OUT_PIN, false);
    }
}

int main(void)
{
    stdio_init_all();

    gpio_init(IN_PIN);
    gpio_set_dir(IN_PIN, GPIO_IN);

    gpio_init(OUT_PIN);
    gpio_set_dir(OUT_PIN, GPIO_OUT);
    gpio_put(OUT_PIN, toggle);

    gpio_set_irq_enabled_with_callback(IN_PIN, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL , true, irq_callback);
    while(1) __wfi();
    return 0;
}
