#include <stdio.h>
#include "pico/stdlib.h"

// Definição dos pinos
#define BUTTON_A 3
#define BUTTON_B 28
#define LED_RED 12
#define LED_GREEN 13
#define LED_BLUE 11

int main() {
    stdio_init_all();

    // Configuração dos LEDs como saída
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);

    // Configuração dos botões com pull-up interno
    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A);  // Ativa pull-up
    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_B, GPIO_IN);
    gpio_pull_up(BUTTON_B);  // Ativa pull-up

    while (true) {
        // Lê o estado dos botões (pressionado = LOW)
        bool buttonA_pressed = !gpio_get(BUTTON_A);
        bool buttonB_pressed = !gpio_get(BUTTON_B);

        // Controla o LED Azul (Botão A)
        gpio_put(LED_BLUE, buttonA_pressed);
        
        // Controla o LED Vermelho (Botão B)
        gpio_put(LED_RED, buttonB_pressed);
        
        // Controla o LED Verde (nenhum botão pressionado)
        gpio_put(LED_GREEN, !(buttonA_pressed || buttonB_pressed));

        // Pequeno delay para estabilidade
        sleep_ms(10);
    }
}