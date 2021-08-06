/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       pranavakella                                              */
/*    Created:      Friday June 11 2021                                       */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----


//Before running this code, make sure the ports for the motors are identical to the ports mentioned in the code
//To move the left motor, move the left stick, while to move the right motor, move the right stick

//POGPOGPOGPOGPOGPOGPOGPOGPOGPOGPOGPOGPOGPOGPOGPOGPOGPOGPOGPOGPOGPOGPOGPOGPOG
//lol hi iuahsufhwep bipuab ieu brwafupbfe iub iue-wafbuew ap9f  iobewaoiubfahubv ijobd jdbfiweBFEWPIFBPAWIEFUUOIAEBWFPIUbdfakj bdskjb jkasbcbwaeubfibwaeiubfpjabdf jdskbf jkabdfkjbasdjkfbs







#include "vex.h"
#include <string>

using namespace vex;
vex::brain    Brain;
vex::competition    Competition;

//Setting up the motors we are going to use

//Make sure to CHANGE THE PORT NUMBER TO THE PORT THAT THE CORRESPONDING MOTOR IS PLUGGED INTO
vex::motor  leftDriveMotor = vex::motor( vex:: PORT17, true);
vex::motor  rightDriveMotor = vex::motor( vex:: PORT13);
vex::motor  leftLift = vex::motor( vex:: PORT10, true);
vex::motor  rightLift = vex::motor( vex:: PORT4);
vex::motor ringLift = vex::motor( vex:: PORT6, false);
vex::motor ringLift2 = vex::motor( vex:: PORT7, true);



bool aPressed = false;

//Setting up the controller

vex::controller Yeetroller = vex::controller();

//Created functions:

void printMotorValue(int num, int num1) {
  Yeetroller.Screen.clearScreen();
  Yeetroller.Screen.setCursor(1,1);
  Yeetroller.Screen.print(num);
  Yeetroller.Screen.setCursor(1, 15);
  Yeetroller.Screen.print(num1);
}

void printText(const char text){
  Yeetroller.Screen.clearScreen();
  Yeetroller.Screen.setCursor(1, 1);
  Yeetroller.Screen.print(text);
}




//Stuff like calibrating sensors, positioning lift, etc.
void setup (void) {


}

//The code for the autonomous period (when we get around to doing that)
void auton (void) {


}

//User control period (and general)
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  


  
  
  // infinite loop for the controller binds
  while (1) {
    //measuring values
    double velocityValue = leftDriveMotor.velocity(velocityUnits::pct);
    int leftTrainPower = Yeetroller.Axis3.position();
    int rightTrainPower = Yeetroller.Axis2.position();

    if (Yeetroller.ButtonB.pressing()){
      aPressed = false;
      Yeetroller.Screen.clearScreen();
      Yeetroller.Screen.setCursor(1, 1);
      Yeetroller.Screen.print("Reverse Mode: OFF");
    }
    
    if (Yeetroller.ButtonA.pressing()){
      aPressed = true;
      Yeetroller.Screen.clearScreen();
      Yeetroller.Screen.setCursor(1, 1);
      Yeetroller.Screen.print("Reverse Mode: ON");
    }
    
    
    // printMotorValue(leftTrainPower, rightTrainPower);

    
    if (aPressed == true){
      leftTrainPower = leftTrainPower*-1;
      rightTrainPower = rightTrainPower*-1;
    }


    //DRIVETRAIN CODE


    leftDriveMotor.spin(vex::directionType::rev, leftTrainPower, vex::velocityUnits::pct);

    rightDriveMotor.spin(vex::directionType::rev, rightTrainPower, vex::velocityUnits::pct);

    //LIFT CODE

    if (Yeetroller.ButtonR1.pressing() ) {
      leftLift.spin(vex::directionType::fwd, 40, vex::velocityUnits::pct);
      rightLift.spin(vex::directionType::fwd, 40, vex::velocityUnits::pct);
    }
    else if (Yeetroller.ButtonR2.pressing()){
      leftLift.spin(vex::directionType::rev, 40, vex::velocityUnits::pct);
      rightLift.spin(vex::directionType::rev, 40, vex::velocityUnits::pct);
    }
    else {
      leftLift.stop(vex::brakeType::brake);
      rightLift.stop(vex::brakeType::brake);

    }



    //INTAKE CODE

    if (Yeetroller.ButtonL1.pressing() ) {
      ringLift.spin(vex::directionType::fwd, 80, vex::velocityUnits::pct);
      ringLift2.spin(vex::directionType::fwd, 80, vex::velocityUnits::pct);
    }
    else if (Yeetroller.ButtonL2.pressing()){
      ringLift.spin(vex::directionType::rev, 80, vex::velocityUnits::pct);
      ringLift2.spin(vex::directionType::rev, 80, vex::velocityUnits::pct);
    }
    else {
      ringLift.stop(vex::brakeType::brake);
      ringLift2.stop(vex::brakeType::brake);
    }


    vex::task::sleep(20); //Apparently prevents wasted resources yeah idk the tutorial had it so I kept it

  }
  
}