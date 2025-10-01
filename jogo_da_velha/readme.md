# 🇧🇷 Jogo da Velha Interativo com Arduino e IA Simples

[EN] Scroll down for the **English Version** 🇬🇧

---

Este projeto implementa um jogo da velha (Tic-Tac-Toe) interativo utilizando um **Arduino Uno**, uma **matriz de LEDs bi-color** para o tabuleiro e **feedback sonoro (Buzzer)** para sinalizar o fim da partida. O jogador compete contra uma **Inteligência Artificial (IA) simples** baseada em lógica de jogadas.

---

## Funcionalidades

* **Oponente de IA:** Lógica de jogo simples que prioriza o centro e os cantos para desafiar o jogador humano.
* **Tabuleiro Dinâmico:** Utiliza uma matriz de LEDs bi-color (Vermelho para Humano, Outra cor para IA) controlada por **multiplexing** para exibir o estado do jogo.
* **Entrada de Dados:** A jogada do humano é detectada através de sensores resistivos/capacitivos simulados (leitura via pinos analógicos A3, A4, A5).
* **Feedback Audiovisual Completo:**
    * O tabuleiro **permanece aceso por 4 segundos** após o final do jogo para mostrar o resultado.
    * **Sinalização Visual (Pinos 11/12):** O LED do vencedor pisca durante a celebração/lamento. Em caso de empate, ambos piscam.
    * **Sinalização Sonora (Buzzer - Pino A0):** Melodias específicas são tocadas para **Vitória** (tom feliz), **Derrota** (tom triste) e **Empate** (tom neutro/alerta).

---

## Montagem do Circuito

O projeto utiliza um sistema de multiplexing, otimizando o número de pinos necessários para controlar a matriz 3x3 (9 posições, 18 LEDs no total).

### Componentes Necessários

* 1 x Placa Arduino Uno R3
* 1 x Matriz de LEDs 3x3 (ou 9 LEDs Bi-color)
* 1 x Buzzer Passivo
* 3 x Sensores Resistivos/Capacitivos (ou botões para simulação da leitura analógica)
* Resistores (necessários para os LEDs e para as filas de leitura dos sensores)
* Jumpers e Protoboard

### Pinagem

A pinagem é crucial para o multiplexing e o controle dos LEDs e sensores:

| Componente/Função | Pinos do Arduino | Tipo |
| :--- | :--- | :--- |
| **Buzzer** | **A0** | `OUTPUT` (Sinal de Áudio) |
| **Sinalização Fim de Jogo** | 11 (IA), 12 (Humano) | `OUTPUT` (LEDs de Status) |
| **Controle das Linhas (Catodo/Ânodo)** | 5, 6, 7 | `OUTPUT` (Multiplexing) |
| **Controle das Colunas (Anodo/Catodo)** | 0, 1, 2, 3, 4, 13 | `OUTPUT` (Cor dos LEDs) |
| **Leitura de Sensores (Colunas)** | 8, 9, 10 | `OUTPUT` (Controle do Sensor) |
| **Leitura de Sensores (Filas)** | A3, A4, A5 | `INPUT` (Leitura Analógica) |

---

## Como Rodar o Código

1. **Montagem:** Monte o circuito conforme a pinagem detalhada acima, prestando atenção à lógica de multiplexing da matriz de LEDs. Conecte o **Buzzer** ao pino **A0** e GND.
2. **Upload:** Copie e cole o código Arduino (`.ino`) na IDE do Arduino.
3. **Compilação:** Conecte sua placa Arduino e faça o upload do código.
4. **Jogar:** O jogo começará imediatamente. O jogador Humano (marcador 'R', geralmente Vermelho) joga primeiro.

---

## Lógica de Jogada e Sinais

| Condição | Variável | Sinal Visual (LEDs 11/12) | Sinal Sonoro (Buzzer A0) |
| :--- | :--- | :--- | :--- |
| **Humano Vence** | `resultado == 1` | LED 12 pisca | Melodia Feliz (Ascendente) |
| **IA Vence** | `resultado == 2` | LED 11 pisca | Melodia Triste (Descendente) |
| **Empate** | `resultado == 3` | LEDs 11 e 12 piscam juntos | Toque de Alerta (Repetido) |
| **Erro (Toque Inválido)** | N/A | Nenhum sinal visual ou sonoro | Silêncio |

---

## Contribuições

Sinta-se à vontade para abrir issues ou enviar Pull Requests! Ideias de melhoria:
* Implementar uma IA mais robusta (algoritmo Minimax).
* Adicionar um display LCD/OLED para mensagens de turno e placar.

---

## Sobre Mim

Gestora e bacharel em Tecnologia da Informação, Engenheira de Computação e líder da equipe Skywalkers em batalhas de robôs. Apaixonada por soluções em IoT, automação e robótica.

## Contato

- GitHub: [@brunamichelecr](https://github.com/brunamichelecr)
- LinkedIn: [brunamcr](https://www.linkedin.com/in/brunamcr)

---
---
---

# 🇬🇧 Interactive Tic-Tac-Toe with Arduino and Simple AI

[PT] Voltar para a **Versão em Português** 🇧🇷

---

This project implements an interactive **Tic-Tac-Toe** game using an **Arduino Uno**, a **bi-color LED matrix** for the board, and **sound feedback (Buzzer)** to signal the end of the match. The player competes against a **Simple Artificial Intelligence (AI)** based on logical moves.

---

## Features

* **AI Opponent:** Simple game logic that prioritizes the center and corners to challenge the human player.
* **Dynamic Board:** Utilizes a bi-color LED matrix (Red for Human, Other color for AI) controlled by **multiplexing** to display the game state.
* **Input Detection:** The human's move is detected through simulated resistive/capacitive sensors (read via analog pins A3, A4, A5).
* **Complete Audiovisual Feedback:**
    * The board **remains lit for 4 seconds** after the game ends to show the result.
    * **Visual Signaling (Pins 11/12):** The winner's LED blinks during the celebration/lament. In case of a draw, both blink.
    * **Sound Signaling (Buzzer - Pin A0):** Specific melodies are played for **Victory** (happy tone), **Defeat** (sad tone), and **Draw** (neutral/alert tone).

---

## Circuit Assembly

The project uses a **multiplexing system**, optimizing the number of pins required to control the 3x3 matrix (9 positions, 18 LEDs in total).

### Required Components

* 1 x Arduino Uno R3 Board
* 1 x 3x3 LED Matrix (or 9 Bi-color LEDs)
* 1 x Passive Buzzer
* 3 x Resistive/Capacitive Sensors (or buttons to simulate analog reading)
* Resistors (required for the LEDs and for the sensor reading rows)
* Jumpers and Breadboard

### Pinout

The pinout is crucial for multiplexing and controlling the LEDs and sensors:

| Component/Function | Arduino Pins | Type |
| :--- | :--- | :--- |
| **Buzzer** | **A0** | `OUTPUT` (Audio Signal) |
| **Game End Signaling** | 11 (AI), 12 (Human) | `OUTPUT` (Status LEDs) |
| **Row Control (Cathode/Anode)** | 5, 6, 7 | `OUTPUT` (Multiplexing) |
| **Column Control (Anode/Cathode)** | 0, 1, 2, 3, 4, 13 | `OUTPUT` (LED Color) |
| **Sensor Read (Columns)** | 8, 9, 10 | `OUTPUT` (Sensor Control) |
| **Sensor Read (Rows)** | A3, A4, A5 | `INPUT` (Analog Reading) |

---

## How to Run the Code

1. **Assembly:** Assemble the circuit according to the pinout detailed above, paying attention to the LED matrix multiplexing logic. Connect the **Buzzer** to pin **A0** and GND.
2. **Upload:** Copy and paste the Arduino code (`.ino`) into the Arduino IDE.
3. **Compilation:** Connect your Arduino board and upload the code.
4. **Play:** The game will start immediately. The Human player (marker 'R', usually Red) plays first.

---

## Game Logic and Signals

| Condition | Variable | Visual Signal (LEDs 11/12) | Sound Signal (Buzzer A0) |
| :--- | :--- | :--- | :--- |
| **Human Wins** | `resultado == 1` | LED 12 blinks | Happy Melody (Ascending) |
| **AI Wins** | `resultado == 2` | LED 11 blinks | Sad Melody (Descending) |
| **Draw** | `resultado == 3` | LEDs 11 and 12 blink together | Alert Tone (Repeated) |
| **Error (Invalid Touch)** | N/A | No visual or sound signal | Silence |

---

## Contributions

Feel free to open issues or send Pull Requests! Ideas for improvement:
* Implement a more robust AI (Minimax algorithm).
* Add an LCD/OLED display for turn messages and scoreboard.

---

## About Me

Manager and bachelor's in Information Technology, Computer Engineer, and leader of the Skywalkers team in robot battles. Passionate about IoT solutions, automation, and robotics.

## Contact

- GitHub: [@brunamichelecr](https://github.com/brunamichelecr)
- LinkedIn: [brunamcr](https://www.linkedin.com/in/brunamcr)