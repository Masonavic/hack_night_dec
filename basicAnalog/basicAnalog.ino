const int potPin = A0;
const int pwmPin = 9;

int potValue = 0;
int pwmValue = 0;


void setup() {

}

void loop() {
  
  potValue = analogRead(potPin);
  
  pwmValue = map(potValue, 0, 1023, 0, 255);
  
  analogWrite(pwmPin, pwmValue);
  
}
