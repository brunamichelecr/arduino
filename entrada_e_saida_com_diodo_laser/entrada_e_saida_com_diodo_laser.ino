const int ldrEntrada1 = A0; // Pino analógico para o LDR da entrada 1
const int ldrEntrada2 = A1; // Pino analógico para o LDR da entrada 2
const int ledPin = 13;      // Pino digital para o LED

int valorLdr1 = 0;
int valorLdr2 = 0;
int pessoas = 0;

void setup() {
  pinMode(ldrEntrada1, INPUT);
  pinMode(ldrEntrada2, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  valorLdr1 = analogRead(ldrEntrada1);
  valorLdr2 = analogRead(ldrEntrada2);

  // Ajuste os valores de limiar conforme necessário
  if (valorLdr1 < 500) { // Luz diminuiu no LDR da entrada 1
    delay(1000); // Pequeno atraso para evitar leituras falsas
    valorLdr2 = analogRead(ldrEntrada2);
    if (valorLdr2 < 500) { // Luz diminuiu no LDR da entrada 2
      pessoas++;
      Serial.println("Pessoa entrou. Total: " + String(pessoas));
    }
  } else if (valorLdr2 < 500) { // Luz diminuiu no LDR da entrada 2
    delay(1000); // Pequeno atraso para evitar leituras falsas
    valorLdr1 = analogRead(ldrEntrada1);
    if (valorLdr1 < 500) { // Luz diminuiu no LDR da entrada 1
      pessoas--;
      Serial.println("Pessoa saiu. Total: " + String(pessoas));
    }
  }

  // Controle do LED
  if (pessoas >= 1) {
    digitalWrite(ledPin, HIGH); // Acende o LED
  } else {
    digitalWrite(ledPin, LOW); // Apaga o LED
  }

  delay(1000); // Pequeno atraso para evitar leituras muito rápidas
}
