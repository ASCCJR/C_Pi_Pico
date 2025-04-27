#include <stdio.h>
#include "pico/stdlib.h"

// Define os pinos GPIO para as linhas e para as colunas do teclado matricial
#define L1 2
#define L2 3
#define L3 4
#define L4 5
#define C1 6
#define C2 7
#define C3 8
#define C4 9

// Definindo os pinos para os LEDs
#define RED_PIN 28   // LED Vermelho
#define GREEN_PIN 26 // LED Verde
#define BLUE_PIN 27  // LED Azul

// Mapeamento das teclas
char teclas[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

// Inicializando os pinos de GPIO para o teclado
void init_teclado() {
    // Definição das linhas como saídas
    gpio_init(L1);
    gpio_set_dir(L1, GPIO_OUT);
    gpio_put(L1, 0);

    gpio_init(L2);
    gpio_set_dir(L2, GPIO_OUT);
    gpio_put(L2, 0);

    gpio_init(L3);
    gpio_set_dir(L3, GPIO_OUT);
    gpio_put(L3, 0);

    gpio_init(L4);
    gpio_set_dir(L4, GPIO_OUT);
    gpio_put(L4, 0);

    // Definição das colunas como entradas com resistores de pull-down
    gpio_init(C1);
    gpio_set_dir(C1, GPIO_IN);
    gpio_pull_down(C1);

    gpio_init(C2);
    gpio_set_dir(C2, GPIO_IN);
    gpio_pull_down(C2);

    gpio_init(C3);
    gpio_set_dir(C3, GPIO_IN);
    gpio_pull_down(C3);

    gpio_init(C4);
    gpio_set_dir(C4, GPIO_IN);
    gpio_pull_down(C4);
}

// Varredura do teclado e retorno da tecla pressionada
char leitura_teclado() {
    for (int row = 0; row < 4; row++) {
  // Coloca a linha atual em nível alto
     gpio_put(L1 + row, 1);

    for (int col = 0; col < 4; col++) {
      if (gpio_get(C1 + col)) {
   // Espera um tempo para estabilização da tecla pressionada
      sleep_ms(50);

     while (gpio_get(C1 + col)); // Espera até a tecla ser liberada
            gpio_put(L1 + row, 0); // Reseta a linha atual

 return teclas[row][col];
            }
        }

        // Coloca a linha atual novamente para nível baixo
        gpio_put(L1 + row, 0);
    }

    return 0; // Nenhuma tecla pressionada
}

int main() {
 stdio_init_all();
    
    // Inicializa os LEDs
    gpio_init(RED_PIN);
    gpio_init(GREEN_PIN);
    gpio_init(BLUE_PIN);
    
    // Define os pinos dos LEDs como saída
    gpio_set_dir(RED_PIN, GPIO_OUT);
    gpio_set_dir(GREEN_PIN, GPIO_OUT);
    gpio_set_dir(BLUE_PIN, GPIO_OUT);
    
    // Inicializa o teclado
    init_teclado();

    printf("Pressione uma tecla!\n");

    while (1) {
        char key = leitura_teclado();
        
        // Limpa os LEDs antes de verificar uma nova tecla
        gpio_put(RED_PIN, 0);
        gpio_put(GREEN_PIN, 0);
        gpio_put(BLUE_PIN, 0);

        if (key) {
            printf("Tecla pressionada: %c\n", key);
            
   // Controla os LEDs de acordo com a tecla pressionada
   switch (key) {
            case '1':case '4': case '7':case '*':
            gpio_put(RED_PIN, 1);   // Acende o LED Vermelho
             break;
            case '2':case '5':case '8': case '0':
            gpio_put(GREEN_PIN, 1); // Acende o LED Verde    
            break;     
            case '3':case '6': case '9': case '#':
            gpio_put(BLUE_PIN, 1);  // Acende o LED Azul    
            break;    
            case 'A': case 'B': case 'C': case 'D': // Nenhum LED deve acender
            break;
            }               
           
            }
        sleep_ms(100);
    }

    return 0;
}