const int ledPins[] = {13, 11, 9, 7, 5};
const int buttonPins[] = {12, 10, 8, 6, 4};

bool ledStates[] = {false, false, false, false, false};
bool buttonStates[] = {false, false, false, false, false};

void setup() {
    for(int i = 0; i < 5; i++) {
        pinMode(ledPins[i], OUTPUT);
    }
    
    for(int i = 0; i < 5; i++) {
        pinMode(buttonPins[i], INPUT);
    }
}

void loop() {
    // Verificar o estado de cada botão e alternar o LED correspondente
    for(int i = 0; i < 5; i++) {
        bool currentButtonState = digitalRead(buttonPins[i]);
        
        // Verificar se o botão foi pressionado (mudança de estado de LOW para HIGH)
        if (currentButtonState == HIGH && buttonStates[i] == LOW) {
            ledStates[i] = !ledStates[i]; // Alternar o estado do LED
            digitalWrite(ledPins[i], ledStates[i] ? HIGH : LOW); // Atualizar o LED
        }
        
        // Atualizar o estado anterior do botão
        buttonStates[i] = currentButtonState;
    }
}
