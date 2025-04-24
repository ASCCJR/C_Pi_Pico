#include <stdio.h>
#include "pico/stdlib.h"

#define LED_PIN 15  // Definindo o pino para o LED (15 por exemplo)

int main() {
  
    gpio_init(LED_PIN);  // Inicializa o pino do LED
    gpio_set_dir(LED_PIN, GPIO_OUT);  // Configura o pino como saída

    while (true) {
        gpio_put(LED_PIN, 1);  // Acende o LED
        sleep_ms(500);  // Aguarda 500 ms

        gpio_put(LED_PIN, 0);  // Apaga o LED
        sleep_ms(500);  // Aguarda 500 ms
    }

    return 0;
}