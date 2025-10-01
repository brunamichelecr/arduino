// GAME STATE AND CONTROL VARIABLES (Retained)

// These variables likely represent the sensor readings or input for each cell
// p1 to p9 correspond to the 9 cells of the tic-tac-toe board.
int fila1, fila2, fila3, p1; 
int p2;
int p3;
int p4;
int p5;
int p6;
int p7;
int p8;
int p9;

// Variables representing the board state for the Human player (R/Red)
// rX = 1 means the Human has a piece in cell X.
int r1; // Human (R/Red)
int r2;
int r3;
int r4;
int r5;
int r6;
int r7;
int r8;
int r9;

// Variables representing the board state for the Computer player (A/Blue or Green)
// aX = 1 means the Computer has a piece in cell X.
int a1; // Computer (A/Blue or Green)
int a2;
int a3;
int a4;
int a5;
int a6;
int a7;
int a8;
int a9;

// Counter variable used for display multiplexing loop control
int cuenta;

// Game turn: 0 = Human (R), 1 = Computer (A). Starts with Human.
int turno = 0; 

// NEW: Buzzer Pin and Note Definitions
const int BUZZER_PIN = A0;

// Common Frequencies in Hz for musical notes
#define NOTE_C4  262
#define NOTE_E4  330
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_G5  784


// ------------------------------------
// GAME OVER AND TIE CHECK FUNCTION
// Returns: 0 = Game Continues, 1 = Human Won, 2 = Computer Won, 3 = Tie
// ------------------------------------
int verificaFimJogo() {
    // 1. Check for Human (R) Victories
    if ((r1 && r2 && r3) || (r4 && r5 && r6) || (r7 && r8 && r9) || // Rows
        (r1 && r4 && r7) || (r2 && r5 && r8) || (r3 && r6 && r9) || // Columns
        (r1 && r5 && r9) || (r3 && r5 && r7)) { // Diagonals
        return 1; // Human Won
    }

    // 2. Check for Computer (A) Victories
    if ((a1 && a2 && a3) || (a4 && a5 && a6) || (a7 && a8 && a9) || // Rows
        (a1 && a4 && a7) || (a2 && a5 && a8) || (a3 && a6 && a9) || // Columns
        (a1 && a5 && a9) || (a3 && a5 && a7)) { // Diagonals
        return 2; // Computer Won
    }

    // 3. Check for Tie (All spaces occupied)
    if ((r1 || a1) && (r2 || a2) && (r3 || a3) &&
        (r4 || a4) && (r5 || a5) && (r6 || a6) &&
        (r7 || a7) && (r8 || a8) && (r9 || a9)) {
        return 3; // Tie
    }

    // 4. Game Continues
    return 0;
}

// ------------------------------------
// COMPUTER MOVE FUNCTION (Simple AI)
// The AI logic here is just a simple priority-based selection: Center > Corners > Sides.
// There is no explicit win/block logic.
// ------------------------------------
void jogadaComputador() {
    // Try the Center (p5)
    if (!r5 && !a5) { a5 = 1; return; }

    // Try the Corners (p1, p3, p7, p9)
    if (!r1 && !a1) { a1 = 1; return; }
    if (!r3 && !a3) { a3 = 1; return; }
    if (!r7 && !a7) { a7 = 1; return; }
    if (!r9 && !a9) { a9 = 1; return; }

    // Try the Sides (p2, p4, p6, p8)
    if (!r2 && !a2) { a2 = 1; return; }
    if (!r4 && !a4) { a4 = 1; return; }
    if (!r6 && !a6) { a6 = 1; return; }
    if (!r8 && !a8) { a8 = 1; return; }
}

// ------------------------------------
// NEW: Melody for Human Win (Happy Tone)
// ------------------------------------
void playWinTone() {
    int tempo = 120; // Note duration (tempo)
    tone(BUZZER_PIN, NOTE_C4, tempo); delay(tempo);
    tone(BUZZER_PIN, NOTE_E4, tempo); delay(tempo);
    tone(BUZZER_PIN, NOTE_G4, tempo); delay(tempo);
    tone(BUZZER_PIN, NOTE_C5, tempo * 2); delay(tempo * 2);
    noTone(BUZZER_PIN);
}

// ------------------------------------
// NEW: Melody for Computer Win (Sad/Slow Tone)
// ------------------------------------
void playLoseTone() {
    int tempo = 200; // Longer note duration
    tone(BUZZER_PIN, NOTE_G4, tempo); delay(tempo);
    tone(BUZZER_PIN, NOTE_E4, tempo); delay(tempo);
    tone(BUZZER_PIN, NOTE_C4, tempo * 2); delay(tempo * 2);
    noTone(BUZZER_PIN);
}

// ------------------------------------
// NEW: Melody for Tie (Alternating/Alert Tone)
// ------------------------------------
void playTieTone() {
    int tempo = 150;
    tone(BUZZER_PIN, NOTE_C4, tempo); delay(tempo); noTone(BUZZER_PIN); delay(tempo/2);
    tone(BUZZER_PIN, NOTE_C4, tempo); delay(tempo); noTone(BUZZER_PIN); delay(tempo/2);
    tone(BUZZER_PIN, NOTE_C4, tempo); delay(tempo); noTone(BUZZER_PIN);
}

// ------------------------------------
// SETUP FUNCTION
// Initializes pins and game state.
// ------------------------------------
void setup()
{
    // Configure all pins from 0 to 13 as OUTPUT. (Common practice for LED matrix control)
    for(int i = 0; i <= 13; i++) {
        pinMode(i, OUTPUT);
    }
    // Configure the Buzzer pin
    pinMode(BUZZER_PIN, OUTPUT);
    
    // Initialize the game state (all cells empty)
    r1 = 0; r2 = 0; r3 = 0; r4 = 0; r5 = 0; r6 = 0; r7 = 0; r8 = 0; r9 = 0;
    a1 = 0; a2 = 0; a3 = 0; a4 = 0; a5 = 0; a6 = 0; a7 = 0; a8 = 0; a9 = 0;
    cuenta = 0; // Reset display counter
    turno = 0;  // Start with Human turn
}


// ------------------------------------
// MAIN LOOP
// Handles display multiplexing, game flow, and input reading.
// ------------------------------------
void loop()
{
    // LEDs 11 and 12 are turned OFF during active play. They are used for the end-game state.
    digitalWrite(11, LOW);  
    digitalWrite(12, LOW);

    // 1. DISPLAY (MULTIPLEXING)
    marca2:; // Label for the multiplexing loop (goto target)
    cuenta = cuenta + 1;
    
    // Row 1 (Pin 7 - Common Cathode/Anode control for the row)
    digitalWrite(7, LOW); // Activate Row 1 (assuming active LOW/or specific matrix wiring)
    // Check Human (r) and Computer (a) pieces for cells 1, 2, 3 and turn on the corresponding column pins
    if(r1 == 1){ digitalWrite(13, HIGH); } // Cell 1 - R
    if(r2 == 1){ digitalWrite(1, HIGH); }  // Cell 2 - R
    if(r3 == 1){ digitalWrite(0, HIGH); }  // Cell 3 - R
    if(a1 == 1){ digitalWrite(2, HIGH); }  // Cell 1 - A
    if(a2 == 1){ digitalWrite(3, HIGH); }  // Cell 2 - A
    if(a3 == 1){ digitalWrite(4, HIGH); }  // Cell 3 - A
    delay(10); // Display time for Row 1
    digitalWrite(7, HIGH); // Deactivate Row 1
    // Turn off all column pins to prevent ghosting
    digitalWrite(13, LOW); digitalWrite(1, LOW); digitalWrite(0, LOW);
    digitalWrite(2, LOW); digitalWrite(3, LOW); digitalWrite(4, LOW);

    // Row 2 (Pin 6)
    digitalWrite(6, LOW); // Activate Row 2
    if(r4 == 1){ digitalWrite(13, HIGH); } // Cell 4 - R
    if(r5 == 1){ digitalWrite(1, HIGH); }  // Cell 5 - R
    if(r6 == 1){ digitalWrite(0, HIGH); }  // Cell 6 - R
    if(a4 == 1){ digitalWrite(2, HIGH); }  // Cell 4 - A
    if(a5 == 1){ digitalWrite(3, HIGH); }  // Cell 5 - A
    if(a6 == 1){ digitalWrite(4, HIGH); }  // Cell 6 - A
    delay(10); // Display time for Row 2
    digitalWrite(6, HIGH); // Deactivate Row 2
    // Turn off all column pins
    digitalWrite(13, LOW); digitalWrite(1, LOW); digitalWrite(0, LOW);
    digitalWrite(2, LOW); digitalWrite(3, LOW); digitalWrite(4, LOW);

    // Row 3 (Pin 5)
    digitalWrite(5, LOW); // Activate Row 3
    if(r7 == 1){ digitalWrite(13, HIGH); } // Cell 7 - R
    if(r8 == 1){ digitalWrite(1, HIGH); }  // Cell 8 - R
    if(r9 == 1){ digitalWrite(0, HIGH); }  // Cell 9 - R
    if(a7 == 1){ digitalWrite(2, HIGH); }  // Cell 7 - A
    if(a8 == 1){ digitalWrite(3, HIGH); }  // Cell 8 - A
    if(a9 == 1){ digitalWrite(4, HIGH); }  // Cell 9 - A
    delay(10); // Display time for Row 3
    digitalWrite(5, HIGH); // Deactivate Row 3
    // Turn off all column pins
    digitalWrite(13, LOW); digitalWrite(1, LOW); digitalWrite(0, LOW);
    digitalWrite(2, LOW); digitalWrite(3, LOW); digitalWrite(4, LOW);

    // Control for the multiplexing loop repetition
    if(cuenta < 20) // Loop 20 times for consistent brightness/flicker-free display
    {
        goto marca2;
    }
    else
    {
        cuenta = 0; // Reset counter for the next round
    }
    
    // 2. CHECK FOR GAME END
    int resultado = verificaFimJogo();
    if (resultado != 0) {
        
        // --- PLAY RESULT TONE BEFORE ENTERING THE END-GAME BLINK LOOP ---
        if (resultado == 1) {   
            playWinTone(); // Human Win
        } else if (resultado == 2) {
            playLoseTone(); // Computer Win
        } else {
            playTieTone(); // Tie
        }
        
        // --- END-GAME MODE: BLINK LED AND KEEP BOARD LIT FOR 4 SECONDS ---
        unsigned long startTime = millis();
        
        while (millis() - startTime < 4000) { // Loop for 4 seconds
            
            // Blink Logic (Blinks every 500ms)
            // 'blink_state' is true for the first 250ms, false for the next 250ms
            bool blink_state = (millis() % 500) < 250; 
            
            if (resultado == 1) { // Human Won (Blink Pin 12)
                digitalWrite(12, blink_state ? HIGH : LOW); 
                digitalWrite(11, LOW); 
            } else if (resultado == 2) { // Computer Won (Blink Pin 11)
                digitalWrite(11, blink_state ? HIGH : LOW); 
                digitalWrite(12, LOW);
            } else { // Tie (Blink both Pin 11 and 12)
                digitalWrite(11, blink_state ? HIGH : LOW); 
                digitalWrite(12, blink_state ? HIGH : LOW);
            }
            
            // --- Repeat Multiplexing to keep the board fully lit ---

            // Row 1 (Pin 7)
            digitalWrite(7, LOW); 
            if(r1 == 1){ digitalWrite(13, HIGH); } if(r2 == 1){ digitalWrite(1, HIGH); } if(r3 == 1){ digitalWrite(0, HIGH); }
            if(a1 == 1){ digitalWrite(2, HIGH); } if(a2 == 1){ digitalWrite(3, HIGH); } if(a3 == 1){ digitalWrite(4, HIGH); }
            delay(10);
            digitalWrite(7, HIGH);
            digitalWrite(13, LOW); digitalWrite(1, LOW); digitalWrite(0, LOW);
            digitalWrite(2, LOW); digitalWrite(3, LOW); digitalWrite(4, LOW);

            // Row 2 (Pin 6)
            digitalWrite(6, LOW);
            if(r4 == 1){ digitalWrite(13, HIGH); } if(r5 == 1){ digitalWrite(1, HIGH); } if(r6 == 1){ digitalWrite(0, HIGH); }
            if(a4 == 1){ digitalWrite(2, HIGH); } if(a5 == 1){ digitalWrite(3, HIGH); } if(a6 == 1){ digitalWrite(4, HIGH); }
            delay(10);
            digitalWrite(6, HIGH);
            digitalWrite(13, LOW); digitalWrite(1, LOW); digitalWrite(0, LOW);
            digitalWrite(2, LOW); digitalWrite(3, LOW); digitalWrite(4, LOW);

            // Row 3 (Pin 5)
            digitalWrite(5, LOW);
            if(r7 == 1){ digitalWrite(13, HIGH); } if(r8 == 1){ digitalWrite(1, HIGH); } if(r9 == 1){ digitalWrite(0, HIGH); }
            if(a7 == 1){ digitalWrite(2, HIGH); } if(a8 == 1){ digitalWrite(3, HIGH); } if(a9 == 1){ digitalWrite(4, HIGH); }
            delay(10);
            digitalWrite(5, HIGH);
            digitalWrite(13, LOW); digitalWrite(1, LOW); digitalWrite(0, LOW);
            digitalWrite(2, LOW); digitalWrite(3, LOW); digitalWrite(4, LOW);
        }
        
        // Turn off the result indicator LEDs
        digitalWrite(11, LOW);  
        digitalWrite(12, LOW);

        // RESET THE GAME STATE
        r1 = 0; r2 = 0; r3 = 0; r4 = 0; r5 = 0; r6 = 0; r7 = 0; r8 = 0; r9 = 0;
        a1 = 0; a2 = 0; a3 = 0; a4 = 0; a5 = 0; a6 = 0; a7 = 0; a8 = 0; a9 = 0;
        turno = 0; // Reset turn to Human
        
        return; // Exit loop and restart the game cycle
    }
    
    // 3. Computer Turn (AI)
    if(turno == 1) {
        jogadaComputador(); // Make the AI move
        delay(500); // Pause for half a second to show the move
        turno = 0;  // Switch turn back to Human
        return; // Exit loop iteration early
    }
    
    // 4. Human Turn (Input Reading)
    marca1:; // Label for the Human input loop (goto target)
    // --- Sensor reading code (p1 to p9) - Retained, assuming a specific matrix/sensor setup ---
    
    // Read Column 1 (controlled by Digital Pin 10)
    digitalWrite(10,HIGH); 
    fila1 = analogRead(A5); fila2 = analogRead(A4); fila3 = analogRead(A3);
    if (fila1 > 500) { p1 = 1; } else { p1 = 0; } // Cell 1
    if (fila2 > 500) { p4 = 1; } else { p4 = 0; } // Cell 4
    if (fila3 > 500) { p7 = 1; } else { p7 = 0; } // Cell 7
    digitalWrite(10, LOW);
    
    // Read Column 2 (controlled by Digital Pin 9)
    digitalWrite(9, HIGH);
    fila1 = analogRead(A5); fila2 = analogRead(A4); fila3 = analogRead(A3);
    if (fila1 > 500) { p2 = 1; } else { p2 = 0; } // Cell 2
    if (fila2 > 500) { p5 = 1; } else { p5 = 0; } // Cell 5
    if (fila3 > 500) { p8 = 1; } else { p8 = 0; } // Cell 8
    digitalWrite(9, LOW);
    
    // Read Column 3 (controlled by Digital Pin 8)
    digitalWrite(8, HIGH);
    fila1 = analogRead(A5); fila2 = analogRead(A4); fila3 = analogRead(A3);
    if (fila1 > 500) { p3 = 1; } else { p3 = 0; } // Cell 3
    if (fila2 > 500) { p6 = 1; } else { p6 = 0; } // Cell 6
    if (fila3 > 500) { p9 = 1; } else { p9 = 0; } // Cell 9
    digitalWrite(8, LOW);
    
    // 5. INVALID INPUT CHECK (Multi-touch)
    // If more than one sensor registered a press, clear the input and wait.
    if(p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9 > 1)
    {
        p1 = 0; p2 = 0; p3 = 0; p4 = 0; p5 = 0; p6 = 0; p7 = 0; p8 = 0; p9 = 0;
        delay(500); // Debounce/wait
        goto marca1; // Go back to re-read input
    }
    
    // 6. PROCESS HUMAN MOVE (If a single touch is detected)
    if(p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9 == 1)
    {
        bool jogada_valida = false;
        
        // Mark the move if the spot is currently empty (!rX and !aX)
        if(p1 == 1 && !r1 && !a1) { r1 = 1; jogada_valida = true; }
        else if(p2 == 1 && !r2 && !a2) { r2 = 1; jogada_valida = true; }
        else if(p3 == 1 && !r3 && !a3) { r3 = 1; jogada_valida = true; }
        else if(p4 == 1 && !r4 && !a4) { r4 = 1; jogada_valida = true; }
        else if(p5 == 1 && !r5 && !a5) { r5 = 1; jogada_valida = true; }
        else if(p6 == 1 && !r6 && !a6) { r6 = 1; jogada_valida = true; }
        else if(p7 == 1 && !r7 && !a7) { r7 = 1; jogada_valida = true; }
        else if(p8 == 1 && !r8 && !a8) { r8 = 1; jogada_valida = true; }
        else if(p9 == 1 && !r9 && !a9) { r9 = 1; jogada_valida = true; }
        
        // If the move was valid, switch the turn to the computer
        if(jogada_valida) {
            turno = 1;
        } else {
            // If the player touched an occupied spot (invalid move), pause and re-read input
            delay(500); 
            goto marca1;
        }
    }
}