int testingPin = 9;
int motorSpeed = 200;

void setup() {
  pinMode(testingPin, OUTPUT);
}

void loop() {
  int i = 0;
  while(true){
    i++;
  if(i % 3 == 0){
    digitalWrite(testingPin, LOW);
  }else{
    digitalWrite(testingPin, HIGH);
  }
  delay(5);
  }
} 
