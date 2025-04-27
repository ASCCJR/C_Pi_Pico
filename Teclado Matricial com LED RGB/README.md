# Teclado Matricial com LED RGB - Raspberry Pi Pico

## 📌 Visão Geral
Sistema de teclado matricial 4x4 conectado a uma Raspberry Pi Pico, com feedback visual através de um LED RGB. Cada grupo de teclas aciona uma cor diferente no LED.

## 🛠 Componentes Necessários
- Raspberry Pi Pico
- Teclado matricial 4x4
- LED RGB (cátodo comum)
- 3 resistores de 220Ω
- Protoboard e jumpers

## 🔌 Diagrama de Conexões
### Teclado Matricial
```
Linhas (L1-L4) -> GPIO 2-5 (saídas)
Colunas (C1-C4) -> GPIO 6-9 (entradas com pull-down)
```

### LED RGB
```
GPIO 28 (RED_PIN)   -> [220Ω] -> LED Vermelho -> GND
GPIO 26 (GREEN_PIN) -> [220Ω] -> LED Verde   -> GND
GPIO 27 (BLUE_PIN)  -> [220Ω] -> LED Azul    -> GND
```

## ⌨️ Mapeamento do Teclado
|       | C1 | C2 | C3 | C4 |
|-------|----|----|----|----|
| **L1**| 1  | 2  | 3  | A  |
| **L2**| 4  | 5  | 6  | B  |
| **L3**| 7  | 8  | 9  | C  |
| **L4**| *  | 0  | #  | D  |

## 💡 Funcionamento dos LEDs
- **Teclas 1,4,7,*:** Acende LED Vermelho
- **Teclas 2,5,8,0:** Acende LED Verde
- **Teclas 3,6,9,#:** Acende LED Azul
- **Teclas A,B,C,D:** Não acendem LEDs

## ⚙️ Funcionalidades
- Leitura de teclado matricial 4x4
- Feedback visual com LED RGB
- Debounce de teclas incorporado
- Saída serial das teclas pressionadas
