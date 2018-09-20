int testingPin = 3;
int motorSpeed = 255;

void setup() {
  pinMode(testingPin, OUTPUT);
}

void loop() {
  analogWrite(testingPin, motorSpeed);
}
