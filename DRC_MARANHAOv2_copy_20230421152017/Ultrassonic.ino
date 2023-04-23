//Ultrassonic sensor////////////////////////////////////////////////////////////////////////////////


void setupUltra() {
  pinMode(echo_l, INPUT);
  pinMode(trig_l, OUTPUT);
  pinMode(echo_f, INPUT);
  pinMode(trig_f,OUTPUT);
}

float lateralUltra() {
  digitalWrite(trig_l, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_l, LOW);
  return float(pulseIn(echo_l, HIGH) * 0.01723);
}

float readMovelDistance(int angle){
  goToAngle(servoDistance, angle);
  return lateralUltra();    
}


float frontalUltra() {  // start ultrassonic sensor, shorts it only allows to read until 255
  //uint8_t

  digitalWrite(trig_f, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_f, LOW);

  return float(pulseIn(echo_f, HIGH) * 0.01723);  // Im using "*0.01723" just becouse i want more precision,
                                                  // ya the 23 part makes a huge diference

  // this return is here just to avoid problems, so it works well without it
}  // end ultrassonic sensor



