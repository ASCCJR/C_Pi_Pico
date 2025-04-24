# 🚀 Blink LED com Raspberry Pi Pico

![Raspberry Pi Pico](https://img.shields.io/badge/Board-Raspberry_Pi_Pico-red)
![C/C++](https://img.shields.io/badge/Language-C-blue)
![Pico SDK](https://img.shields.io/badge/Framework-Pico_SDK-green)

## 📌 Visão Geral

Programa simples para piscar um LED usando o Raspberry Pi Pico. O código utiliza o Pico SDK para controlar um GPIO, criando um efeito de blink com intervalo de 500ms.

## 🛠️ Hardware Necessário

- Raspberry Pi Pico
- LED (qualquer cor)
- Resistor 220Ω (ou similar)
- Protoboard e jumpers

## 🔌 Diagrama de Conexão

```
Raspberry Pi Pico
┌─────────────┐
│             │
│ GP15 ───┬─► │
│         │   │
│         │   │
│ GND ────┴─► │
└─────────────┘
       ▲  ▲
       │  │
       │  └─ Resistor 220Ω
       └──── LED (ânodo)
```

## 📋 Código Explicado

```c
#include <stdio.h>
#include "pico/stdlib.h"

#define LED_PIN 15  // GPIO 15 conectado ao LED

int main() {
    // Inicializa o hardware
    stdio_init_all();
    
    // Configura o pino do LED
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Loop principal
    while (true) {
        gpio_put(LED_PIN, 1);  // Liga o LED
        sleep_ms(500);         // Espera 500ms
        
        gpio_put(LED_PIN, 0);  // Desliga o LED
        sleep_ms(500);         // Espera 500ms
    }

    return 0;
}
```
