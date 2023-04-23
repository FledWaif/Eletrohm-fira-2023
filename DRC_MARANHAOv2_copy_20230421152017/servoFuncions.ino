void servoD() {
  servoDistance.attach(pin_servoDistance);
  arm.attach(pin_arm);
  hand.attach(pin_hand);
  //servoColor.attach(pin_servoColor);
  //goToAngle(servoDistance, 0);
  //goToAngle(arm, 180);
 // goToAngle(hand, 65);
}

void goToAngle(Servo s, int angle) {
  int current_angle = s.read();
  if (current_angle <= angle) {
    for (current_angle; current_angle < angle; current_angle++) {
      s.write(current_angle);
      delay(30);
    }
  } else {
    for (current_angle; current_angle >= angle; current_angle--) {
      s.write(current_angle);
      delay(30);
    }
  }
  delay(300);
}

void armAway() {
  lockArms();
  arm.write(135);  // 0 (super front), 180 (super back)
  hand.write(90);  // 180 (super open) 0 (super close)
  unlockArms();
}

void lockArms() {
  arm.attach(pin_arm);
  hand.attach(pin_hand);
  //servoDistance.attach(pin_servoDistance);
}

void unlockArms() {
  delay(1000);
  arm.detach();
  hand.detach();
  //servoDistance.detach();
}

void getCube() {
  lockArms();
  goToAngle(arm, 65);
  both.together(150, 4);
  both.together(70,1.7);
  goToAngle(arm, 115);
  unlockArms();
}

void dropCube() {
  lockArms();
  goToAngle(arm,65);
  delay(200);
  both.together(-150,-6.3);

  unlockArms();
}