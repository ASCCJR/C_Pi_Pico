# LED RGB com Botões - Raspberry Pi Pico

## 📌 Visão Geral
Controle de um LED RGB utilizando dois botões na Raspberry Pi Pico. Cada combinação de botões pressionados aciona uma cor diferente no LED.

## 📋 Funcionalidades
- Controle de um LED RGB com dois botões
- 4 modos de cores diferentes:
  - **Verde**: Nenhum botão pressionado
  - **Azul**: Apenas Botão A pressionado
  - **Vermelho**: Apenas Botão B pressionado
  - **Magenta**: Ambos botões pressionados

## 🛠 Componentes Necessários
- Raspberry Pi Pico
- 1 LED RGB (cátodo comum)
- 2 botões
- 3 resistores de 220Ω (para os canais R, G e B)
- Protoboard e jumpers

## 🔌 Diagrama de Conexões
```
Pico GP12 (LED_RED) ----[220Ω]----| R |--+
Pico GP13 (LED_GREEN) --[220Ω]----| G |--+-- LED RGB
Pico GP11 (LED_BLUE) ---[220Ω]----| B |--+
                                          |
                                         GND

Pico GP3 (BUTTON_A) ----+----| BTN A |---- GND
Pico GP28 (BUTTON_B) ---+----| BTN B |---- GND
```

## ⚙️ Configuração
1. Conecte os componentes conforme o diagrama acima
2. Carregue o código na Pico
3. Pressione os botões para testar as combinações de cores

## 📚 Código Principal
O código utiliza:
- Pull-up interno para os botões
- Lógica condicional para controlar as cores
- Anti-bouncing com delay de 10ms