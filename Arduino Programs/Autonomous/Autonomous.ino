int thrustMotorPinLeft = 3;
int thrustMotorPinRight = 4;
int liftMotorPinLeft = 5;
int liftMotorPinRight = 6;

// The value of of lift offset will provide a factor of more power
// to one motor over another. Positive favors right, negative left.
double LIFT_OFFSET = 0.0;
double THRUST_OFFSET = 0.0;

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
  driveStraight(5000, 100);
}

/**
 * Both motors rotate at a given speed.
 * @param duration The time in milliseconds to drive
 * @param speedValue The write value from 0 - 255
 */
void driveStraight(int duration, int speedValue){
  // Set both motors to the same speed
  analogWrite(thrustMotorPinLeft, getAdjustedMotorSpeed(thrustMotorPinLeft, speedValue));
  analogWrite(thrustMotorPinRight, getAdjustedMotorSpeed(thrustMotorPinRight, speedValue));

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

  //While it is still accelerating
  while(currentSpeed < motorSpeed){
    analogWrite(liftMotorPinLeft, getAdjustedMotorSpeed(liftMotorPinLeft, currentSpeed));
    analogWrite(liftMotorPinRight, getAdjustedMotorSpeed(liftMotorPinRight, currentSpeed));
    currentSpeed += 1;
    delay(10);
  }
}

int getAdjustedMotorSpeed(int pinNum, int motorSpeed){
  switch(pinNum){
    case thrustMotorPinLeft:
      return THRUST_OFFSET < 0 ? motorSpeed * THRUST_OFFSET * -1 : motorSpeed;
      break;
      case thrustMotorPinRight:
    return THRUST_OFFSET > 0 ? motorSpeed * THRUST_OFFSET : motorSpeed;
      break;
    case liftMotorPinLeft:
      return LIFT_OFFSET < 0 ? motorSpeed * THRUST_OFFSET * -1 : motorSpeed;
      break;
    case liftMotorPinRight:
      return LIFT_OFFSET > 0 ? motorSpeed * THRUST_OFFSET : motorSpeed;
      break;
  }
}
