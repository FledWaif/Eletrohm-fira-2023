//motors ???////////////////////////////////////////////////////////////////////////////////////////
void setupMotors() {

  motorL.hBridge(10, 11, 8);
  motorL.setEncoderPin(2, 4); //2 e 4
  motorL.setRR(30);
  motorL.setPIDconstants(kp, ki, kd);
  motorL.setPins();
  attachInterrupt(digitalPinToInterrupt(2), interrupt_motor_L, FALLING);
  motorL.stop();

  motorR.hBridge(13, 12, 9);
  motorR.setEncoderPin(3, 5);
  motorR.setRR(30);
  motorR.setPIDconstants(kp, ki, kd);
  motorR.setPins();
  attachInterrupt(digitalPinToInterrupt(3), interrupt_motor_R, FALLING);
  motorR.stop();
}

void interrupt_motor_L() {

  //Serial.println("left motor interrupted");
  motorL.isr();
}

void interrupt_motor_R() {
  //Serial.println("right motor interrupted");
  motorR.isr();
}


void stopMotors(){
  motorR.walk(0);
  motorL.walk(0);
}