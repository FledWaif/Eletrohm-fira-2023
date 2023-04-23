/*
  this is a c++ code to FIRA maranhão 2023 DRC explorer code
  stated: 1/19/2023,01:00:40
*/

//included librarys/////////////////////////////////////////////////////////////////////////////////
#include <DC_motor_controller.h>
#include <TwoMotors.h>
#include <Servo.h>
#include <Wire.h>
#include <SparkFun_APDS9960.h>

//PINS//////////////////////////////////////////////////////////////////////////////////////////////
#define echo_l 50  //ultrassonic lateral echo pin
#define trig_l 51  //ultrassonic lateral trigger pin
#define echo_f 52  //ultrassonic frontal echo pin
#define trig_f 53  //ultrassonic frontal trigger pin

#define fTch 12  // front touch sensor
/*
#define ledBlueA
#define ledBlueB
#define ledGreenAultra_ino
#define ledGreenB
#define ledRedA
#define ledRedB
#define ledYellowA
*/

DC_motor_controller motorL, motorR;

TwoMotors both(&motorL, &motorR);

Servo servoDistance;
Servo servoColor;
Servo hand;
Servo arm;

SparkFun_APDS9960 apds = SparkFun_APDS9960();

uint16_t ambient = 0;
uint16_t red = 0;
uint16_t green = 0;

#define pin_servoDistance 41  //0 - right ; 90 - frontal
//#define pin_servoColor 33
#define pin_hand 45  //180 (up) - 75 (down)
#define pin_arm 43   //180 (open) - 65 (close)

unsigned long M1000 = 1000;  // variable to millis calculation

const float kp = 3.5;
const float ki = 0.9;
const float kd = 0.15;

float basespeed = 50.0;  //50
float maxspeed = 60.0;
float turnspeed = 80.0;

float rot_per_degree = 1.3 / 90.0;



////////////////////////////////////////////////////////////////////////////////////////////////////
/*void followWall(float left_ratio = 0, float right_ratio = 0, float desired_distance = 10) {
  //float right_distance = lateralUltra();  // pegar o servo 90 graus a direita e atribuir a distancia a essa variável
  //float min_distance = desired_distance - 2, max_distance = desired_distance + 2;

  //goToAngle(servoDistance,90);
  both.together(basespeed);

  // if (frontalUltra() < 4) while(true) stopMotors();
}


void checkFreeWay() {
  if (readMovelDistance(0) < OBSTACLE_RAGE) {
    both.turnDegree(-turnspeed, -90);
  } else both.turnDegree(turnspeed, 90);
  //false = right; true = left;
}
*/
//setup/////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(9600);
  Serial.println("the code started :)");

  //setupColorSensor();
  //setupUltra();
  servoD();
  setupMotors();
  both.setGyreDegreesRatio(0.9, 90);

  //goToAngle(servoDistance, 180);


  //while(true) both.together(50);
 
  while (1) {
    
    //Serial.println(frontalUltra());
    
    getCube();
    both.together(-70,-1.2);
    both.turnDegree(90, 180);
    delay(100);
    both.together(150, 4);
    dropCube();
    while(1);     

  
    arm.write(50);
    both.turnDegree(70, 180);
    both.together(60, 6);  


  }
    
}

//loop//////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
}