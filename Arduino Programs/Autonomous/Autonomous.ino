int thrustMotorPinLeft = 3;
int thrustMotorPinRight = 5;
int liftMotorPinLeft = 6;
int liftMotorPinRight = 9;

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
  turn(0.5, 200, 2000);
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

/**
 * Turns the hovercraft.
 * @param sharpness: A value between -1 and 1 determining the sharpness of the turn. -1 is left, 1 is right
 * @param motorSpeed: The max speed at which the motor shall run
 * @param duration: The duration of the turn in milliseconds
 */
void turn(double sharpness, int motorSpeed, int duration){
  // Calculate motor speeds based on turn sharpness and motorSpeed
  int leftMotorSpeed = sharpness >= 0 ? motorSpeed : (1 + sharpness)  * motorSpeed;
  int rightMotorSpeed = sharpness <= 0 ? motorSpeed : (1 - sharpness) * motorSpeed;

  // Set motor values
  analogWrite(thrustMotorPinLeft, getAdjustedMotorSpeed(thrustMotorPinLeft, leftMotorSpeed));
  analogWrite(thrustMotorPinRight, getAdjustedMotorSpeed(thrustMotorPinRight, rightMotorSpeed));

  // Wait for this step to be over
  delay(duration);
}

/**
 * Returns the motor speed after adjusting it by the appropriate factor to balance it.
 * @param pinNum The pin number of the motor to adjust
 * @param motorSpeed The unadjusted motor speed
 */
int getAdjustedMotorSpeed(int pinNum, int motorSpeed){
    if(pinNum == thrustMotorPinLeft)
      return THRUST_OFFSET < 0 ? motorSpeed * THRUST_OFFSET * -1 : motorSpeed;
    else if(pinNum == thrustMotorPinRight)
      return THRUST_OFFSET > 0 ? motorSpeed * THRUST_OFFSET : motorSpeed;
    else if(pinNum == liftMotorPinLeft)
      return LIFT_OFFSET < 0 ? motorSpeed * THRUST_OFFSET * -1 : motorSpeed;
    else if(pinNum == liftMotorPinRight)
      return LIFT_OFFSET > 0 ? motorSpeed * THRUST_OFFSET : motorSpeed;
    else
      return motorSpeed;
}
