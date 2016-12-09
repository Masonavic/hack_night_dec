
const int buttonPin = 2;
const int potPin = A0;
const int tonePin = 8;

int buttonState = 0;
int potValue = 0;
int toneValue = 0;

void setup() {

  pinMode(buttonPin, INPUT);

}

void loop() {
  
  buttonState = digitalRead(buttonPin);

  //if button is not pressed, HIGH
  //if button is pressed, LOW
  if (buttonState == LOW) {
    potValue = analogRead(potPin);
    toneValue = map(potValue, 0, 1023, 220, 880);
    tone(tonePin, toneValue);
  } else {
    noTone(tonePin);
  }

}
