/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Ramya                                                     */
/*    Created:      Wed Aug 04 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <string>

using namespace vex;
vex::brain    Brain;
vex::competition    Competition;

//Setting up the motors we are going to use

//Make sure to CHANGE THE PORT NUMBER TO THE PORT THAT THE CORRESPONDING MOTOR IS PLUGGED INTO

//Drivetrain
vex::motor  leftDriveMotor = vex::motor( vex:: PORT17);
vex::motor  rightDriveMotor = vex::motor( vex:: PORT13,true);
vex::motor  leftLift = vex::motor( vex:: PORT10, true);
vex::motor  rightLift = vex::motor( vex:: PORT4);
vex::motor ringLiftL = vex::motor( vex:: PORT6,false);
vex::motor ringLiftR = vex::motor( vex:: PORT7,true);

//Setting up the controller

vex::controller Yeetroller = vex::controller();

//functions for simplicity

void moveForward(int deg){
  leftDriveMotor.startRotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
  rightDriveMotor.rotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
}

void turnLeft(int deg){
  rightDriveMotor.rotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
}

void turnRight(int deg){
  leftDriveMotor.rotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
}

void pickUpTower(int deg){
  leftLift.startRotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
  rightLift.rotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
}

void putDownTower(int deg){
  leftLift.startRotateFor(vex::directionType::rev, deg, vex::rotationUnits::deg);
  rightLift.rotateFor(vex::directionType::rev, deg, vex::rotationUnits::deg);
}

void intakeRings(int deg){
  ringLiftL.startRotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
  ringLiftR.rotateFor(vex::directionType::fwd, deg, vex::rotationUnits::deg);
}

void chill(){
  wait(3, vex::timeUnits::sec);
}





//central auton code
void auton() {
  //move lift down
  putDownTower(940);
  chill(); //this is only for testing purposes
  //move forward towards the goal
  moveForward(720);
  chill();
  //pick up goal
  pickUpTower(500);
  chill();
  //turn left a bit towards rings
  turnLeft(360);
  chill();
  //move towards rings
  moveForward(720);
  chill();
  //turn back to original orientation
  turnRight(360);
  chill();
  //move forward while picking up rings
  moveForward(720);
  intakeRings(2160);

  

}


int main() {
  auton();
  vexcodeInit();
  
}
