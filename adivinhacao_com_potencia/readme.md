# Adivinhe o Número (Potências de 2) - Jogo Eletrônico com Arduino

[EN] Scroll down for the **English Version** 🇬🇧

## Visão Geral do Projeto

Este projeto transforma um clássico truque de mágica matemática em um dispositivo interativo e didático, usando o **Arduino**. O objetivo é demonstrar de forma lúdica o funcionamento do **Sistema Binário** e a decomposição de números em **Potências de Base 2**.

O dispositivo utiliza 5 pares de botões/LEDs, permitindo que um jogador escolha um número secreto no intervalo de **1 a 31**, enquanto o adivinho revela o número instantaneamente.

---

## Regras e Mecânica do Jogo

O jogo é implementado em uma placa dupla-face (MDF), separando as entradas das saídas para garantir a surpresa:

1.  **Lado do Jogador (Entrada):** O jogador pressiona os botões correspondentes às tabelas onde seu número secreto aparece.
2.  **Lado do Adivinho (Saída):** Cada um dos 5 **LEDs** está rotulado com uma **Potência de 2** ($1, 2, 4, 8, 16$).
3.  **A Revelação:** O adivinho apenas **soma os valores** das Potências de 2 que estão com seus LEDs acesos. A soma resultante é o número secreto.

---

## A Mágica Matemática: Potências de 2

A lógica reside no **Sistema Binário** (Base 2). Todo número de 1 a 31 possui uma **representação única** como a soma das potências $1, 2, 4, 8$ e $16$.

* Ao pressionar os botões, o jogador está, na verdade, informando qual é a representação binária do seu número secreto.
* **Exemplo:** Se o número secreto for **25**, ele é representado por $16 + 8 + 1$. Apenas os LEDs desses valores acenderão.

---

## Montagem Prática (Hardware)

* **Estrutura:** Placa de MDF ou acrílico para separar o ambiente de entrada (botões) do ambiente de saída (LEDs).
* **Componentes Chave:** Arduino Uno/Nano, 5 Botões Tácteis, 5 LEDs e 5 Resistores de proteção.
* **Fiação:** Cada botão é conectado a um pino de entrada (ex.: 12, 10, 8, 6, 4) e seu LED correspondente a um pino de saída (ex.: 13, 11, 9, 7, 5).

---

## Software (Código Arduino)

O código utiliza a técnica de **Detecção de Borda (Edge Detection)** e variáveis de estado (`bool buttonStates[]` e `bool ledStates[]`) para implementar a lógica de **alternância (toggle)**.

* Isso garante que o LED acenda ou apague com um **único clique**, e não apenas enquanto o botão é mantido pressionado.
* A ação de ligar/desligar o LED só é executada no instante exato da transição de "solto" para "pressionado".
* O código completo pode ser encontrado no arquivo **`adivinhe_o_numero.ino`**.

***

# Guess the Number (Powers of 2) - Electronic Game with Arduino

[PT] Voltar para a **Versão em Português** 🇧🇷

## Project Overview

This project transforms a classic mathematical magic trick into an interactive and educational device using the **Arduino**. Its goal is to playfully demonstrate how the **Binary System** and the decomposition of numbers into **Powers of 2** work.

The device uses 5 pairs of buttons/LEDs, allowing one player to choose a secret number in the range of **1 to 31**, while the guesser can reveal the number instantly.

---

## Game Rules and Mechanics

The game is implemented on a double-sided board (MDF), separating the inputs from the outputs to ensure the surprise:

1.  **Player Side (Input):** The player presses the buttons corresponding to the tables where their secret number appears.
2.  **Guesser Side (Output):** Each of the 5 **LEDs** is labeled with a **Power of 2** ($1, 2, 4, 8, 16$).
3.  **The Reveal:** The guesser simply **adds up the values** of the Powers of 2 that have their LEDs lit. The resulting sum is the secret number.

---

## The Mathematical Magic: Powers of 2

The logic behind the trick lies in the **Binary System** (Base 2). Every whole number from 1 to 31 can be formed by a **unique combination** of the powers $1, 2, 4, 8$, and $16$.

* By pressing the buttons, the player is essentially inputting the binary representation of their secret number.
* **Example:** If the secret number is **25**, it is represented by $16 + 8 + 1$. Only the LEDs corresponding to those values will light up.

---

## Practical Assembly (Hardware)

* **Structure:** An MDF or acrylic board is used to separate the input area (buttons) from the output area (LEDs).
* **Key Components:** Arduino Uno/Nano, 5 Tactile Buttons, 5 LEDs, and 5 protective Resistors.
* **Wiring:** Each button on the player's side is connected to an input pin (e.g., 12, 10, 8, 6, 4) and its corresponding LED to an output pin (e.g., 13, 11, 9, 7, 5).

---

## Software (Arduino Code)

The code uses **Edge Detection** and state variables (`bool buttonStates[]` and `bool ledStates[]`) to implement the **toggle logic**.

* This ensures the LED turns on or off with a **single click**, rather than only when the button is held down.
* The action of toggling the LED is executed only at the exact moment of transition from "released" to "pressed."
* The complete code can be found in the file **`adivinhe_o_numero.ino`**.