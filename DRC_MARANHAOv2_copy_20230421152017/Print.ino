void Print(){
    Serial.print("In the second ");
    Serial.print(millis() / 1000);
    Serial.println(" this happend:");
    Serial.print("ultrassonic sensor read: ");
    Serial.println(lateralUltra());
    Serial.println();
    M1000 = M1000 + 1000;
 }


void printLateralDistance(){
  Serial.print("In angle: ");
  Serial.print(servoDistance.read());
  Serial.print(", distance: ");
  Serial.print(lateralUltra());
  Serial.println();
}

void printFrontalDistance(){
  Serial.print("Frontal distance: ");
  Serial.println(frontalUltra());
}
