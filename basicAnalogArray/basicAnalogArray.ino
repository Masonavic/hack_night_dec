const int potPins[] = {A0, A1, A2};
const int pwmPins[] = {9, 10, 11};

int potValues[] = {0, 0, 0};
int pwmValues[] = {0, 0, 0};


void setup() {

}

void loop() {
  for (int i = 0; i < (sizeof(potPins)/sizeof(int)); i++){
    potValues[i] = analogRead(potPins[i]);
  
    pwmValues[i] = map(potValues[i], 0, 1023, 0, 255);
  
    analogWrite(pwmPins[i], pwmValues[i]);
  }

  
}
