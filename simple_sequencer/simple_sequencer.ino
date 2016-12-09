const int buttonPins[] = {2, 3, 4, 5};
const int potPins[] = {A0, A1, A2, A3};
const int ledPins[] = {9, 10, 11, 12};
const int tonePin = 8;

int reading;
int prevButtonStates[] = {0, 0, 0, 0};
int potValues[] = {0, 0, 0, 0};
int ledStates[] = {0, 0, 0, 0};
int notes[] = {0, 0, 0, 0};
int bpm = 80;


void setup() {
  for (int i = 0; i < (sizeof(buttonPins)/sizeof(int)); i++){
    pinMode(buttonPins[i], INPUT);
    pinMode(ledPins[i], OUTPUT);
  }

}

void loop() {

  for (int j = 0; j < (sizeof(buttonPins)/sizeof(int)); j++){
    reading = digitalRead(buttonPins[j]);
    if (reading == HIGH && prevButtonStates[j] == LOW){
       if (ledStates[j] == HIGH)
        ledStates[j] = LOW;
       else
        ledStates[j] = HIGH;
    }
       digitalWrite(ledPins[j], ledStates[j]);
       prevButtonStates[j] = reading;
  }

  for (int k = 0; k < (sizeof(potPins)/sizeof(int)); k++){
    potValues[k] = analogRead(potPins[k]);
    notes[k] = map(potValues[k], 0, 1023, 220, 880);
  }

  int noteDuration = 1000 / ((bpm / 60) * 4);

  for (int currentNote; currentNote < (sizeof(notes)/sizeof(int)); currentNote++){

     if (ledStates[currentNote] == HIGH){
      tone(8, notes[currentNote], noteDuration);
      delay(noteDuration * 1.3);
     } else {
      noTone(8);
      delay(noteDuration * 1.3);
     }

    
  }
    

}
