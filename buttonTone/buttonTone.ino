

const int buttonPin = 2;
const int tonePin = 8;

int buttonState = 0;

void setup() {

  pinMode(buttonPin, INPUT);

}

void loop() {
  
  buttonState = digitalRead(buttonPin);

  //if button is not pressed, HIGH
  //if button is pressed, LOW
  if (buttonState == LOW) {
    tone(tonePin, 440);
  } else {
    noTone(tonePin);
  }

}
