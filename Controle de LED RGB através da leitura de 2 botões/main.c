#include <stdio.h>
#include "pico/stdlib.h"

// Definição dos pinos
#define BUTTON_A 3
#define BUTTON_B 28
#define LED_RED 12    // Pino do LED RGB (canal vermelho)
#define LED_GREEN 13  // Pino do LED RGB (canal verde)
#define LED_BLUE 11   // Pino do LED RGB (canal azul)

int main() {
    stdio_init_all();

    // Configuração dos canais RGB como saída
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);

    // Configuração dos botões com pull-up interno
    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A);
    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_B, GPIO_IN);
    gpio_pull_up(BUTTON_B);

    while (true) {
        bool buttonA_pressed = !gpio_get(BUTTON_A); // LOW = pressionado
        bool buttonB_pressed = !gpio_get(BUTTON_B);

        // Lógica do LED RGB:
        if (buttonA_pressed && buttonB_pressed) {
            // AMBOS pressionados: Magenta (Vermelho + Azul)
            gpio_put(LED_RED, 1);
            gpio_put(LED_GREEN, 0);
            gpio_put(LED_BLUE, 1);
        } 
        else if (buttonA_pressed) {
            // Apenas Botão A: Azul
            gpio_put(LED_RED, 0);
            gpio_put(LED_GREEN, 0);
            gpio_put(LED_BLUE, 1);
        } 
        else if (buttonB_pressed) {
            // Apenas Botão B: Vermelho
            gpio_put(LED_RED, 1);
            gpio_put(LED_GREEN, 0);
            gpio_put(LED_BLUE, 0);
        } 
        else {
            // Nenhum botão: Verde
            gpio_put(LED_RED, 0);
            gpio_put(LED_GREEN, 1);
            gpio_put(LED_BLUE, 0);
        }

        sleep_ms(10); // Anti-bouncing
    }
}