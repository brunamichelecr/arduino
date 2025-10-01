# Controle Simples de Bomba por Botão (Arduino)

[EN] Scroll down for the **English Version** 🇬🇧

Este projeto implementa um sistema de controle fundamental onde uma **bomba é ativada apenas enquanto um botão de pressão for mantido pressionado**. É um código essencial, ideal para testes, dosagem manual ou demonstrações básicas de controle de Entrada/Saída (I/O) utilizando a plataforma Arduino.

---

## 🇧🇷 Versão em Português

### ⚙️ Detalhamento do Código

O programa utiliza a estrutura padrão do Arduino: a função `setup()` para configurar o hardware e a função `loop()` para executar a lógica continuamente.

#### 1. Configuração (`void setup()`)

A função `setup` é executada uma vez para configurar os pinos:

| PINO | FUNÇÃO | TIPO | COMPONENTE |
| :---: | :---: | :---: | :---: |
| **D9** | Entrada | `INPUT` | **Botão** de Pressão |
| **D12** | Saída | `OUTPUT` | **Bomba** (acionada via relé/transistor) |

#### 2. Lógica Principal (`void loop()`)

A função `loop` é executada repetidamente e implementa a lógica condicional:

* **`if (digitalRead(9) == HIGH)`**: Verifica se o botão no Pino 9 está pressionado.
    * **Ação:** Se sim, `digitalWrite(12, HIGH)` **liga a bomba** (pino 12).
* **`else`**: Caso contrário (o botão está solto).
    * **Ação:** `digitalWrite(12, LOW)` **desliga a bomba** (pino 12).

### 🔌 Conexão de Hardware

Para reproduzir este projeto, você deve conectar o botão e a bomba (através de um relé ou transistor) aos pinos digitais especificados:

* **Botão (Entrada):** Conectado ao Pino **D9**. Recomenda-se o uso de um resistor **pull-down** para evitar leituras erráticas (flutuação).
* **Bomba (Saída):** O terminal de controle do Relé ou Transistor deve ser conectado ao Pino **D12**.

---

## 🇬🇧 English Version

[PT] Voltar para a **Versão em Português** 🇧🇷

# Simple Button-Controlled Pump (Arduino)

This project implements a basic control system where a **pump is activated only while a momentary push button is held down**. This is a fundamental piece of code, perfect for testing, manual dispensing, or basic I/O (Input/Output) control demonstrations.

### ⚙️ Code Breakdown

The program uses the standard Arduino structure, divided into `setup()` (configuration) and `loop()` (main logic).

#### 1. Configuration (`void setup()`)

The `setup` function runs once to configure the pins:

| PIN | FUNCTION | TYPE | COMPONENT |
| :---: | :---: | :---: | :---: |
| **D9** | Input | `INPUT` | **Push Button** |
| **D12** | Output | `OUTPUT` | **Pump** (Actuated via Relay/Transistor) |

#### 2. Main Logic (`void loop()`)

The `loop` function runs repeatedly and implements the conditional logic:

* **`if (digitalRead(9) == HIGH)`**: Checks if the button on Pin 9 is pressed.
    * **Action:** If yes, `digitalWrite(12, HIGH)` **turns the pump ON** (Pin 12).
* **`else`**: Otherwise (the button is released).
    * **Action:** `digitalWrite(12, LOW)` **turns the pump OFF** (Pin 12).

### 🔌 Hardware Connection

To replicate this project, you must connect the button and the pump (via a relay or transistor) to the specified digital pins:

* **Button (Input):** Connected to Pin **D9**. A **pull-down** resistor is recommended to prevent erratic readings (floating).
* **Pump (Output):** The control terminal of the Relay or Transistor should be connected to Pin **D12**.