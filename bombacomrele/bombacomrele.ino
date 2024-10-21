#define pinoRele 8 // Define o pino 8 como "pinoRele"
 
void setup() {
Serial.begin(9600); // Declara o BaundRate em 9600
pinMode(pinoRele, OUTPUT); // Declara o pinoRele como Saída
}
 
void loop() {
Serial.println("Irrigando a planta ..."); // Imprime a frase no monitor serial
digitalWrite(pinoRele, HIGH); // Altera o estado do pinoRele para nível Alto
delay (5000);
Serial.println("Planta Irrigada ..."); // Imprime a frase no monitor serial
digitalWrite(pinoRele, LOW); // Altera o estado do pinoRele para nível Baixo
delay (1000); // Estabelece o tempo de 1s para reinicializar a leitura
}