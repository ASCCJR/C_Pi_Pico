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

## 📝 Notas

- Os botões estão configurados com lógica ativa em LOW (pressionado = LOW)
- Certifique-se de usar resistores apropriados para os LEDs (geralmente 220Ω-330Ω)
- Verifique a polaridade dos LEDs ao conectá-los
