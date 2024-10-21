#include "IRremote.h"
const int pwm = 3;
const int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); //começa a receber
    pinMode(pwm, OUTPUT); 
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
   
    if (results.value == 0xFF30CF){
    analogWrite(pwm, 255); 
    Serial.println("carro andando");
    }
    
    if (results.value == 0xFF18E7){
    analogWrite(pwm, 0); 
    Serial.println("carro parado");
    }
   
    irrecv.resume(); // Recebe o próximo valor
  }
}