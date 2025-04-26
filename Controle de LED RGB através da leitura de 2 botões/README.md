# Controle de LEDs com Botões - Raspberry Pi Pico

## 📋 Descrição

O código implementa um sistema simples onde:
- O LED azul acende quando o Botão A é pressionado
- O LED vermelho acende quando o Botão B é pressionado
- O LED verde acende quando nenhum botão está pressionado

## 🛠️ Hardware Necessário

- Raspberry Pi Pico
- 3 LEDs (vermelho, verde e azul)
- 2 botões
- Resistores apropriados para os LEDs e botões
- Protoboard e jumpers

## 🔌 Configuração dos Pinos

| Componente | Pino GPIO |
|------------|----------|
| Botão A    | GP3      |
| Botão B    | GP28     |
| LED Vermelho | GP12    |
| LED Verde  | GP13     |
| LED Azul   | GP11     |

## 🚀 Como Usar

1. Conecte os componentes conforme a configuração de pinos acima
2. Carregue o código na Raspberry Pi Pico
3. Pressione os botões para controlar os LEDs:
   - Botão A: acende LED azul
   - Botão B: acende LED vermelho
   - Sem botões pressionados: LED verde aceso

## ⚙️ Funcionamento do Código

- Os LEDs são configurados como saídas digitais
- Os botões são configurados como entradas com resistor pull-up interno
- O programa verifica constantemente o estado dos botões
- A lógica controla os LEDs baseada no estado dos botões
- Um pequeno delay de 10ms é adicionado para estabilidade

## 📝 Notas (1)

- Os botões estão configurados com lógica ativa em LOW (pressionado = LOW)
- Certifique-se de usar resistores apropriados para os LEDs (geralmente 220Ω-330Ω)
- Verifique a polaridade dos LEDs ao conectá-los

### 🔄 **Versão do Código com `if else if else`**:
```c
#include <stdio.h>
#include "pico/stdlib.h"

#define BUTTON_A 3
#define BUTTON_B 28
#define LED_RED 12
#define LED_GREEN 13
#define LED_BLUE 11

int main() {
    stdio_init_all();

    // Configura LEDs como saída
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);

    // Configura botões com pull-up interno
    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A);
    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_B, GPIO_IN);
    gpio_pull_up(BUTTON_B);

    while (true) {
        bool buttonA_pressed = !gpio_get(BUTTON_A); // LOW quando pressionado
        bool buttonB_pressed = !gpio_get(BUTTON_B);

        // Lógica com if-else if-else
        if (buttonA_pressed && buttonB_pressed) {
            // Caso AMBOS os botões estejam pressionados
            gpio_put(LED_BLUE, 1);
            gpio_put(LED_RED, 1);
            gpio_put(LED_GREEN, 0);
        }
        else if (buttonA_pressed) {
            // Apenas Botão A pressionado
            gpio_put(LED_BLUE, 1);
            gpio_put(LED_RED, 0);
            gpio_put(LED_GREEN, 0);
        }
        else if (buttonB_pressed) {
            // Apenas Botão B pressionado
            gpio_put(LED_BLUE, 0);
            gpio_put(LED_RED, 1);
            gpio_put(LED_GREEN, 0);
        }
        else {
            // Nenhum botão pressionado
            gpio_put(LED_BLUE, 0);
            gpio_put(LED_RED, 0);
            gpio_put(LED_GREEN, 1);
        }

        sleep_ms(10); // Delay para evitar bouncing
    }
}
```

### ✔️ **Vantagens dessa abordagem**:
1. **Prioridade clara**: A ordem dos `if else` define qual condição tem precedência (útil se houver conflitos).
2. **Comportamento personalizado**: Você pode adicionar ações específicas quando **ambos os botões** são pressionados (ex.: ligar vermelho e azul juntos).
3. **Legibilidade**: Fica mais fácil entender a lógica de controle.

### ⚠️ **Cuidados**:
- A ordem dos `if else` importa! O código verifica as condições **de cima para baixo**.
- Se inverter `buttonA_pressed` e `buttonB_pressed`, o comportamento pode mudar.

### 🔄 **Exemplo Alternativo** (Se quiser evitar `else if`):
```c
// Usando operadores lógicos para simplificar
gpio_put(LED_BLUE, buttonA_pressed);
gpio_put(LED_RED, buttonB_pressed);
gpio_put(LED_GREEN, !(buttonA_pressed || buttonB_pressed));
```

### ❓ **Quando usar `if else if else`?**
- Se precisar de **ações exclusivas** (ex.: "se o botão A estiver pressionado, ignore o B").
- Se quiser **comportamentos combinados** (ex.: ambos os botões = LED branco).

## 📝 Notas (2)

A escolha entre **pull-up** e **pull-down** depende do circuito e da lógica do programa. No caso do Raspberry Pi Pico (e microcontroladores em geral), **pull-up interno** é mais comum para botões, mas vamos analisar as diferenças:

---

### 🔽 **Pull-Down** (resistor conectando o pino ao GND)
- **Como funciona**:  
  - Botão conectado ao **3.3V** (HIGH quando pressionado).  
  - Resistor (externo ou interno) puxa o pino para **GND** (LOW quando solto).  

- **Vantagens**:  
  - Leitura intuitiva: `1` (HIGH) = pressionado, `0` (LOW) = solto.  
  - Evita flutuação quando o botão está solto.  

- **Desvantagens**:  
  - No Pico, **não há pull-down interno** no hardware (só pull-up).  
  - Exige resistor externo ou ligação física ao GND.  

- **Código**:  
  ```c
  gpio_set_dir(BUTTON_PIN, GPIO_IN);  
  gpio_pull_down(BUTTON_PIN); // Não disponível no Pico! (só pull-up)
  ```

---

### 🔼 **Pull-Up** (resistor conectando o pino a 3.3V)  
- **Como funciona**:  
  - Botão conectado ao **GND** (LOW quando pressionado).  
  - Resistor interno puxa o pino para **3.3V** (HIGH quando solto).  

- **Vantagens**:  
  - **Funciona com o Pico** (tem pull-up interno).  
  - Mais fácil de montar (só precisa conectar o botão ao GND).  

- **Desvantagens**:  
  - Lógica invertida: `0` (LOW) = pressionado, `1` (HIGH) = solto.  

- **Código**:  
  ```c
  gpio_set_dir(BUTTON_PIN, GPIO_IN);  
  gpio_pull_up(BUTTON_PIN); // Ativa pull-up interno
  ```

---

### ⚡ **Qual é mais adequado o projeto?**  
1. **Pull-up (recomendado para o Pico)**:
   - **Use** se:  
     - O botão está conectado entre o GPIO e o **GND**.  
     - Quer evitar componentes externos (já que o Pico tem pull-up interno).  
     - Não se importa com a lógica invertida (`!gpio_get()`).  

   - **Exemplo**:  
     ```c
     bool pressed = !gpio_get(BUTTON_PIN); // LOW = pressionado
     ```

2. **Pull-down (se necessário)**:  
   - **Use** se:  
     - Você **precisa** da lógica direta (HIGH = pressionado).  
     - Pode adicionar um resistor externo (10kΩ entre GPIO e GND).  

   - **Exemplo**:  
     ```c
     bool pressed = gpio_get(BUTTON_PIN); // HIGH = pressionado
     ```

---

### 📌 **Conclusão**:  
- **Para o Pico**, **pull-up interno** é a melhor opção** na maioria dos casos:  
  - Evita componentes extras.  
  - Basta conectar o botão ao GND.  
  - A lógica invertida é resolvida com `!gpio_get()`.  

- **Pull-down** só vale a pena se:  
  - Você **exige** a lógica direta (HIGH = pressionado).  
  - Está disposto a usar um resistor externo.  

---

### 🔄 **Exemplo Prático (Pull-up)**:
```c
// Configuração no Pico (pull-up interno):
gpio_init(BUTTON_PIN);
gpio_set_dir(BUTTON_PIN, GPIO_IN);
gpio_pull_up(BUTTON_PIN); // Ativa resistor interno

// Leitura:
if (!gpio_get(BUTTON_PIN)) { // LOW = pressionado
    printf("Botão pressionado!\n");
}
```

### 🔍 **Quando Usar Cada Um?**

| **Critério**               | **Pull-Up (Interno)** | **Pull-Down (Externo)** |
|----------------------------|-----------------------|-------------------------|
| **Facilidade de Montagem** | ✅ (Só botão + GND)   | ❌ (Precisa de resistor) |
| **Lógica do Código**       | Invertida (`!gpio_get`) | Direta (`gpio_get`)     |
| **Disponibilidade no Pico**| ✅ (Nativo)           | ❌ (Requer hardware)     |
| **Consumo de Energia**     | Baixo                 | Baixo (com resistor 10kΩ) |

---

### 📌 **Resumo Visual**
```
        PULL-UP (Pico)          PULL-DOWN (Externo)
          +3.3V (interno)         GPIO
             |                     |
          GPIO o--> [Botão] -- GND  o--> [Botão] -- +3.3V
             |                     |
           (Lê LOW)           [10kΩ] -- GND
                              (Lê HIGH)
```
