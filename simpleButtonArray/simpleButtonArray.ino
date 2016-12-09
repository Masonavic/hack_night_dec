
const int buttonPins[] = {2, 3, 4, 5};
const int ledPins[] = {7, 8, 9, 10};

int buttonStates[] = {0, 0, 0, 0};

void setup() {
  for (int i = 0; i < (sizeof(buttonPins)/sizeof(int)); i++){
  pinMode(ledPins[i], OUTPUT);
  pinMode(buttonPins[i], INPUT);
  }


}

void loop() {
  for (int j = 0; j< (sizeof(buttonPins)/sizeof(int)); j++){
    buttonStates[j] = digitalRead(buttonPins[j]);

    //if button is not pressed, HIGH
    //if button is pressed, LOW
   if (buttonStates[j] == LOW) {
      digitalWrite(ledPins[j], HIGH);
    } else {
     digitalWrite(ledPins[j], LOW);
    }
  }


}
