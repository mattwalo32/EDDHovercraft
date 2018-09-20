int thrustMotorPinLeft = 3;
int thrustMotorPinRight = 4;
int liftMotorPinLeft = 5;
int liftMotorPinRight = 6;

// The value of of lift offset will provide a factor of more power
// to one motor over another. Positive favors right, negative left.
final double LIFT_OFFSET = 0.0;
final double THRUST_OFFSET = 0.0;

// First method called for any initialization
void setup() {
  //Set motor pin to be an output
  pinMode(thrustMotorPinLeft, OUTPUT);
  pinMode(thrustMotorPinRight, OUTPUT);
  pinMode(liftMotorPinLeft, OUTPUT);
  pinMode(liftMotorPinRight, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  rampLiftMotors(150);
  driveStraight();
}

/**
 * Both motors rotate at a given speed.
 * @param duration The time in milliseconds to drive
 * @param speedValue The write value from 0 - 255
 */
void driveStraight(int duration, int speedValue){
  // Set both motors to the same speed
  analogWrite(thrustMotorPinLeft, speedValue);
  analogWrite(thrustMotorPinRight, speedValue);

  // While duration has not elasped
  delay(duration);
}

/**
 * Gentley accelerates both lift motors to the given
 * speed value.
 * @param speedValue The speed to ramp the values to
 */
void rampLiftMotors(int motorSpeed){
  int currentSpeed = 0; 
  //Only use left side multipler if value less than 0
  double leftMultiplier = LIFT_OFFSET < 0 ? liftOffset * -1 : 1;
  //Only use right side multipler if value greater than 0
  double rightMultiplier = LIFT_OFFSET > 0 ? liftOffset : 1;

  //While it is still accelerating
  while(currentSpeed < speedValue){
    analogWrite(liftMotorPinLeft, speedValue * leftMultiplier);
    analogWrite(liftMotorPinRight, speedValue * rightMultiplier);
    currentSpeed += 1;
    delay(10);
  }

  int getAdjustedMotorSpeed(int pinNum, int motorSpeed){
    
  }
}
