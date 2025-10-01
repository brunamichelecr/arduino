# 🚪 Contador de Fluxo de Pessoas com Arduino

Este projeto implementa um sistema simples de **contagem de pessoas** utilizando um microcontrolador **Arduino** e dois **sensores de luz** (LDRs - Light Dependent Resistor). O objetivo é rastrear a entrada e a saída de indivíduos em uma área e fornecer um *feedback* visual imediato.

## 🛠️ Componentes Necessários

* **Microcontrolador Arduino** (ex: Uno, Nano)
* 2x **Sensores de Luz** (LDRs)
* 2x Resistores (necessários para a montagem do circuito com os LDRs)
* 1x **LED** (para indicação visual)
* 1x Resistor (para o LED)
* Jumpers e Protoboard

## 🧠 Princípio de Funcionamento

O sistema usa dois LDRs posicionados em sequência (por exemplo, na soleira de uma porta) para determinar a **direção do movimento**.

1.  **Sensores em Sequência:** Os dois LDRs monitoram continuamente a luz ambiente.
2.  **Detecção de Passagem:** Quando uma pessoa passa, ela bloqueia a luz que chega a um ou ambos os sensores, fazendo com que o valor de leitura analógica do LDR caia drasticamente.
3.  **Lógica Direcional:**
    * **Entrada:** Se o **LDR 1** for bloqueado **primeiro** e, logo em seguida, o **LDR 2** também for bloqueado, o contador de pessoas é **incrementado (+1)**.
    * **Saída:** Se o **LDR 2** for bloqueado **primeiro** e, logo em seguida, o **LDR 1** também for bloqueado, o contador de pessoas é **decrementado (-1)**.
4.  **Controle Visual:** Um LED (conectado ao Pino 13) é usado como indicador:
    * Ele **acende** se a contagem total de pessoas for **igual ou superior a 1** (indicando que há alguém na área).
    * Ele **apaga** se a contagem for **zero** (indicando que a área está vazia).
5.  **Comunicação Serial:** O sistema envia *logs* para o Monitor Serial do Arduino, informando a contagem atualizada a cada entrada ou saída detectada.

## ⚙️ Configuração dos Pinos

| Componente | Pino do Arduino | Função |
| :--- | :--- | :--- |
| LDR da Entrada 1 | **A0** (Analógica) | Detecta a passagem no ponto inicial. |
| LDR da Entrada 2 | **A1** (Analógica) | Detecta a passagem no ponto final. |
| LED Indicador | **13** (Digital) | Indica se há pessoas na área. |

---

# 🚪 People Flow Counter with Arduino

This project implements a simple **people counting** system using an **Arduino** microcontroller and two **light sensors** (LDRs - Light Dependent Resistor). The goal is to track the entry and exit of individuals in an area and provide immediate visual *feedback*.

## 🛠️ Required Components

* **Arduino Microcontroller** (e.g., Uno, Nano)
* 2x **Light Sensors** (LDRs)
* 2x Resistors (required for the LDR circuit assembly)
* 1x **LED** (for visual indication)
* 1x Resistor (for the LED)
* Jumper Wires and Breadboard

## 🧠 Operating Principle

The system uses two LDRs positioned in sequence (for example, on a doorway's threshold) to determine the **direction of movement**.

1.  **Sequential Sensors:** The two LDRs continuously monitor the ambient light.
2.  **Passage Detection:** When a person passes, they block the light reaching one or both sensors, causing the LDR's analog reading value to drop significantly.
3.  **Directional Logic:**
    * **Entry:** If **LDR 1** is blocked **first** and, immediately after, **LDR 2** is also blocked, the people counter is **incremented (+1)**.
    * **Exit:** If **LDR 2** is blocked **first** and, immediately after, **LDR 1** is also blocked, the people counter is **decremented (-1)**.
4.  **Visual Control:** An LED (connected to Pin 13) is used as an indicator:
    * It **turns on** if the total people count is **one or more** (indicating someone is in the area).
    * It **turns off** if the count is **zero** (indicating the area is empty).
5.  **Serial Communication:** The system sends *logs* to the Arduino Serial Monitor, showing the updated count with each detected entry or exit.

## ⚙️ Pin Configuration

| Component | Arduino Pin | Function |
| :--- | :--- | :--- |
| Entry LDR 1 | **A0** (Analog) | Detects passage at the initial point. |
| Entry LDR 2 | **A1** (Analog) | Detects passage at the final point. |
| Indicator LED | **13** (Digital) | Indicates if people are in the area. |