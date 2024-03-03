/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Dial                                                      */
/*    Created:      2/3/2024, 6:47:28 PM                                      */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h"
#include "imagestore.h"
using namespace vex;

triport  threeWirePort(PORT22);

// Brain should be defined by default
brain Brain;
 


// START V5 MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END V5 MACROS


// Robot configuration code.
motor WingsMotorA = motor(PORT1, ratio18_1, true); // Left 
motor WingsMotorB = motor(PORT10, ratio18_1, false);  // Right & Previously PORT02
motor_group Wings = motor_group(WingsMotorA, WingsMotorB);

motor Cata = motor(PORT2, ratio18_1, false); // Previously PORT11

// Variable Names to be Fixed.
motor LDrive1 = motor(PORT3, ratio36_1, true); // Previously Port14, is Reversed
motor LDrive2 = motor(PORT4, ratio36_1, false); // Previously Port15, is not Reversed
motor RDrive1 = motor(PORT5, ratio36_1, true); // Previously PORT16, is Reversed
motor RDrive2 = motor(PORT6, ratio36_1, false); // Previously PORT17, is not Reversed
// Variable Names to be Fixed.

motor_group LeftDriveSmart = motor_group(LDrive1, RDrive1); // Variable Names to be Fixed.
motor_group RightDriveSmart = motor_group(LDrive2, RDrive2); // Variable Names to be Fixed.
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 70, mm, 1);

motor IntakeMotorA = motor(PORT7, ratio18_1, false); // Depreciate in Future.
motor IntakeMotorB = motor(PORT19, ratio18_1, true); // Depreciate in Future.
motor_group Intake = motor_group(IntakeMotorA, IntakeMotorB);

controller Controller1 = controller(primary);
motor Blocker = motor(PORT21, ratio18_1, true); // Depreciated 

pneumatics PistonA = pneumatics(Brain.ThreeWirePort.A);
pneumatics PistonB = pneumatics(Brain.ThreeWirePort.B);



// Helper to make playing sounds from the V5 in VEXcode easier and
// keeps the code cleaner by making it clear what is happening.
void playVexcodeSound(const char *soundName) {
  printf("VEXPlaySound:%s\n", soundName);
  wait(5, msec);
}



// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool DrivetrainLNeedsToBeStopped_Controller1 = true;
bool DrivetrainRNeedsToBeStopped_Controller1 = true;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    if(RemoteControlCodeEnabled) {
      
      // calculate the drivetrain motor velocities from the controller joystick axies
      // left = Axis3 + Axis1
      // right = Axis3 - Axis1
      int drivetrainLeftSideSpeed = Controller1.Axis3.position() + Controller1.Axis1.position();
      int drivetrainRightSideSpeed = Controller1.Axis3.position() - Controller1.Axis1.position();
      
      // check if the value is inside of the deadband range
      if (drivetrainLeftSideSpeed < 5 && drivetrainLeftSideSpeed > -5) {
        // check if the left motor has already been stopped
        if (DrivetrainLNeedsToBeStopped_Controller1) {
          // stop the left drive motor
          LeftDriveSmart.stop();
          // tell the code that the left motor has been stopped
          DrivetrainLNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the left motor nexttime the input is in the deadband range
        DrivetrainLNeedsToBeStopped_Controller1 = true;
      }
      // check if the value is inside of the deadband range
      if (drivetrainRightSideSpeed < 5 && drivetrainRightSideSpeed > -5) {
        // check if the right motor has already been stopped
        if (DrivetrainRNeedsToBeStopped_Controller1) {
          // stop the right drive motor
          RightDriveSmart.stop();
          // tell the code that the right motor has been stopped
          DrivetrainRNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the right motor next time the input is in the deadband range
        DrivetrainRNeedsToBeStopped_Controller1 = true;
      }
      
      // only tell the left drive motor to spin if the values are not in the deadband range
      if (DrivetrainLNeedsToBeStopped_Controller1) {
        LeftDriveSmart.setVelocity(drivetrainLeftSideSpeed, percent);
        LeftDriveSmart.spin(forward);
      }
      // only tell the right drive motor to spin if the values are not in the deadband range
      if (DrivetrainRNeedsToBeStopped_Controller1) {
        RightDriveSmart.setVelocity(drivetrainRightSideSpeed, percent);
        RightDriveSmart.spin(forward);
      }
    }
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}

task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);

#pragma endregion VEXcode Generated Robot Configuration

// Include the V5 Library
#include "vex.h"

// Allows for easier use of the VEX Library
using namespace vex;

competition Competition;

// User defined function
void myblockfunction_Set_Wings_extendWings(bool myblockfunction_Set_Wings_extendWings__extendWings);
// User defined function
void myblockfunction_Toggle_Wings();
// User defined function
void myblockfunction_Intake_Mode_Mode_of_Operation(double myblockfunction_Intake_Mode_Mode_of_Operation__Mode);
// User defined function
void myblockfunction_Catapult_enable(bool myblockfunction_Catapult_enable__enable);
// User defined function
void myblockfunction_Toggle_Catapult();
// User defined function
void myblockfunction_Controller_Screen_DisplayMetric(double myblockfunction_Controller_Screen_DisplayMetric__DisplayMetric);
// User defined function
void myblockfunction_Toggle_Blocker();
// User defined function
void myblockfunction_Autonomous();
// User defined function
void myblockfunction_AutoCode();
// User defined function
void myblockfunction_AutoRecode();
// User defined function
void myblockfunction_Color_Cycle_N(double myblockfunction_Color_Cycle_N__N);
// User defined function
void myblockfunction_Screen();
// User defined function
void myblockfunction_AutoDecodeAndRun();

int Brain_precision = 0, Console_precision = 0, Controller1_precision = 0;

float myVariable, n, i, catapultSpeedSetting, AutoTime, AutoIterator1, AutoIterator20, AutoRecievingInput, AutoKey, AutoDecodeKey, BlockerDeployed;

bool areWingsDeployed, isCatapultEnabled, isBlockerDeployed;

float a[2];
float AutoCode[20][20];

// User defined function
void myblockfunction_Set_Wings_extendWings(bool myblockfunction_Set_Wings_extendWings__extendWings) {
  if (myblockfunction_Set_Wings_extendWings__extendWings) {
    Wings.spin(forward);
  }
  else {
    Wings.spin(reverse);
  }
}

// User defined function
void myblockfunction_Toggle_Wings() {
  if (areWingsDeployed) {
    areWingsDeployed = false;
    myblockfunction_Set_Wings_extendWings(false);
  }
  else {
    areWingsDeployed = false;
    myblockfunction_Set_Wings_extendWings(true);
  }
}

// User defined function
void myblockfunction_Intake_Mode_Mode_of_Operation(double myblockfunction_Intake_Mode_Mode_of_Operation__Mode) {
  // Operational Mode: 1 Forward, 0 Stop, -1  Reverse
  if (myblockfunction_Intake_Mode_Mode_of_Operation__Mode == 1.0) {
    Intake.spin(forward);
  } else if (myblockfunction_Intake_Mode_Mode_of_Operation__Mode == 0.0) {
    Intake.stop();
  } else if (myblockfunction_Intake_Mode_Mode_of_Operation__Mode == -1.0) {
    Intake.spin(reverse);
  } else {
  }
}

// User defined function
void myblockfunction_Catapult_enable(bool myblockfunction_Catapult_enable__enable) {
  if (myblockfunction_Catapult_enable__enable) {
    Cata.spin(forward);
  }
  else {
    Cata.stop();
  }
}

// User defined function
void myblockfunction_Toggle_Catapult() {
  if (isCatapultEnabled) {
    isCatapultEnabled = false;
    Cata.stop();
  }
  else {
    isCatapultEnabled = true;
    Cata.spin(forward);
  }
}

// Used to find the format string for printing numbers with the
// desired number of decimal places
const char* printToController1_numberFormat() {
  // look at the current precision setting to find the format string
  switch(Controller1_precision){
    case 0:  return "%.0f"; // 0 decimal places (1)
    case 1:  return "%.1f"; // 1 decimal place  (0.1)
    case 2:  return "%.2f"; // 2 decimal places (0.01)
    case 3:  return "%.3f"; // 3 decimal places (0.001)
    default: return "%f"; // use the print system default for everthing else
  }
}

// User defined function
void myblockfunction_Controller_Screen_DisplayMetric(double myblockfunction_Controller_Screen_DisplayMetric__DisplayMetric) {
  Controller1.Screen.clearScreen();
  if (myblockfunction_Controller_Screen_DisplayMetric__DisplayMetric == 0.0) {
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print("Catapult V% : ");
    Controller1.Screen.setCursor(1, 15);
    Controller1.Screen.print(printToController1_numberFormat(), static_cast<float>(catapultSpeedSetting));
    Controller1.Screen.setCursor(2, 1);
    Controller1.Screen.print("Catapult *F : ");
    Controller1.Screen.setCursor(2, 14);
    Controller1.Screen.print(printToController1_numberFormat(), static_cast<float>(Cata.temperature(percent)));
  } else if (myblockfunction_Controller_Screen_DisplayMetric__DisplayMetric == 1.0) {
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print("DriveTrain Temper:");
    Controller1.Screen.setCursor(2, 10);
    Controller1.Screen.print(printToController1_numberFormat(), static_cast<float>(Drivetrain.temperature(percent)));
    Controller1.Screen.setCursor(3, 10);
    Controller1.Screen.print("Fahrenheit");
  } else if (myblockfunction_Controller_Screen_DisplayMetric__DisplayMetric == 2.0) {
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print("Blocker temperature");
    Controller1.Screen.setCursor(2, 10);
    Controller1.Screen.print(printToController1_numberFormat(), static_cast<float>(Blocker.temperature(temperatureUnits::fahrenheit)));
    Controller1.Screen.setCursor(3, 10);
    Controller1.Screen.print("Fahrenheit");
  } else {
  }
}

// User defined function
void myblockfunction_Toggle_Blocker() {
  if (isBlockerDeployed) {
    isBlockerDeployed = false;
    Blocker.spinFor(forward, 180.0, degrees, false);
    Blocker.setBrake(coast);
  }
  else {
    isBlockerDeployed = true;
    Blocker.spinFor(reverse, 180.0, degrees, false);
    Blocker.setBrake(hold);
  }
}

void onevent_Controller1ButtonX_pressed_0() {
  myblockfunction_Toggle_Blocker();
}
void onevent_Controller1ButtonX_released_0() {
  myblockfunction_Toggle_Blocker();
}
// User defined function
void myblockfunction_Autonomous() {
  // Used to call Autonomous code. Use this block to update.
  Controller1.Screen.clearScreen();
  Brain.Screen.setCursor(2, 1);
  Controller1.rumble("....");
  Controller1.Screen.print("AUTO");
  // DO NOT REMOVE CODE ABOVE THIS COMMENT
  Drivetrain.setDriveVelocity(75.0, percent);
  Drivetrain.driveFor(reverse, 40.0, inches, true);
}

// Used to find the format string for printing numbers with the
// desired number of decimal places
const char* printToBrain_numberFormat() {
  // look at the current precision setting to find the format string
  switch(Brain_precision){
    case 0:  return "%.0f"; // 0 decimal places (1)
    case 1:  return "%.1f"; // 1 decimal place  (0.1)
    case 2:  return "%.2f"; // 2 decimal places (0.01)
    case 3:  return "%.3f"; // 3 decimal places (0.001)
    default: return "%f"; // use the print system default for everthing else
  }
}

// Used to find the format string for printing numbers with the
// desired number of decimal places
const char* printToConsole_numberFormat() {
  // look at the current precision setting to find the format string
  switch(Console_precision){
    case 0:  return "%.0f"; // 0 decimal places (1)
    case 1:  return "%.1f"; // 1 decimal place  (0.1)
    case 2:  return "%.2f"; // 2 decimal places (0.01)
    case 3:  return "%.3f"; // 3 decimal places (0.001)
    default: return "%f"; // use the print system default for everthing else
  }
}

// User defined function

int mathRandomInt(float a, float b) {
  if (a > b) {
    // Swap a and b to ensure a is smaller.
    float c = a;
    a = b;
    b = c;
  }
  int tmpA = static_cast<int>(a);
  int tmpB = static_cast<int>(b);
  int r = tmpA + rand() / (RAND_MAX / (tmpB - tmpA + 1));
  return r;
}

// User defined function
void myblockfunction_Color_Cycle_N(double myblockfunction_Color_Cycle_N__N) {
  if (myblockfunction_Color_Cycle_N__N == 1.0) {
    Brain.Screen.setPenColor(red);
  } else if (myblockfunction_Color_Cycle_N__N == 2.0) {
    Brain.Screen.setPenColor(orange);
  } else if (myblockfunction_Color_Cycle_N__N == 3.0) {
    Brain.Screen.setPenColor(yellow);
  } else if (myblockfunction_Color_Cycle_N__N == 4.0) {
    Brain.Screen.setPenColor(green);
  } else if (myblockfunction_Color_Cycle_N__N == 5.0) {
    Brain.Screen.setPenColor(blue);
  } else if (myblockfunction_Color_Cycle_N__N == 6.0) {
    Brain.Screen.setPenColor(purple);
  } else {
    myblockfunction_Color_Cycle_N(static_cast<float>(mathRandomInt(1.0, 6.0)));
  }
}

// User defined function
void myblockfunction_Screen() {
  repeat(5) {
    myblockfunction_Color_Cycle_N(n);
    Brain.Screen.setFont(mono60);
    Brain.Screen.print("YIPPEE");
    Brain.Screen.setCursor(n, fmod(n,21.0 - 6.0));
    n = n + 1.0;
    n = fmod(n,6.0);
    wait(5, msec);
  }
}



// "when Controller1 ButtonUp pressed" hat block
void onevent_Controller1ButtonUp_pressed_0() {
  Controller1.Screen.setCursor(1, 1);
  catapultSpeedSetting = catapultSpeedSetting + 10.0;
  Cata.setVelocity(catapultSpeedSetting, percent);
  Controller1.rumble("-.-.");
  Controller1.Screen.clearScreen();
  Controller1.Screen.print("Catapult");
  Controller1.Screen.newLine();
  Controller1.Screen.print(printToController1_numberFormat(), static_cast<float>(catapultSpeedSetting));
  Controller1.Screen.print("Percent Velocity");
  Controller1.Screen.newLine();
}

// "when Controller1 ButtonL1 pressed" hat block
void onevent_Controller1ButtonL1_pressed_0() {
  AutoRecievingInput = 1.0;
  myblockfunction_Catapult_enable(true);
}

// "when Controller1 ButtonR1 pressed" hat block
void onevent_Controller1ButtonR1_pressed_0() {
  AutoRecievingInput = 3.0;
  myblockfunction_Intake_Mode_Mode_of_Operation(1.0);
}

// "when started" hat block
int whenStarted1() {
  catapultSpeedSetting = 60.0;
  Wings.setVelocity(75.0, percent);
  Wings.setStopping(hold);
  Intake.setVelocity(100.0, percent);
  Intake.setStopping(brake);
  Cata.setVelocity(catapultSpeedSetting, percent);
  Cata.setStopping(coast);
  Drivetrain.setDriveVelocity(100.0, percent);
  Drivetrain.setTurnVelocity(100.0, percent);
  Blocker.setBrake(hold);
  Blocker.setVelocity(50.0, percent);
  return 0;
}

// "when Controller1 ButtonL1 released" hat block
void onevent_Controller1ButtonL1_released_0() {
  AutoRecievingInput = 11.0;
  myblockfunction_Catapult_enable(false);
}

// "when Controller1 ButtonR1 released" hat block
void onevent_Controller1ButtonR1_released_0() {
  AutoRecievingInput = 33.0;
  myblockfunction_Intake_Mode_Mode_of_Operation(0.0);
}

// "when Controller1 ButtonL2 pressed" hat block
void onevent_Controller1ButtonL2_pressed_0() {
  AutoRecievingInput = 2.0;
  myblockfunction_Set_Wings_extendWings(true);
}

// "when Controller1 ButtonR2 pressed" hat block
void onevent_Controller1ButtonR2_pressed_0() {
  AutoRecievingInput = 4.0;
  myblockfunction_Intake_Mode_Mode_of_Operation(-1.0);
}

// "when Controller1 ButtonDown pressed" hat block
void onevent_Controller1ButtonDown_pressed_0() {
  Controller1.Screen.setCursor(1, 1);
  catapultSpeedSetting = catapultSpeedSetting + -10.0;
  Cata.setVelocity(catapultSpeedSetting, percent);
  Controller1.rumble("-.-.");
  Controller1.Screen.clearScreen();
  Controller1.Screen.print("Catapult");
  Controller1.Screen.newLine();
  Controller1.Screen.print(printToController1_numberFormat(), static_cast<float>(catapultSpeedSetting));
  Controller1.Screen.print("Percent Velocity");
  Controller1.Screen.newLine();
}

// "when Controller1 ButtonL2 released" hat block
void onevent_Controller1ButtonL2_released_0() {
  AutoRecievingInput = 22.0;
  myblockfunction_Set_Wings_extendWings(false);
}

// "when Controller1 ButtonR2 released" hat block
void onevent_Controller1ButtonR2_released_0() {
  AutoRecievingInput = 44.0;
  myblockfunction_Intake_Mode_Mode_of_Operation(0.0);
}

// "when Controller1 ButtonLeft pressed" hat block
void onevent_Controller1ButtonLeft_pressed_0() {
  myblockfunction_Autonomous();
}

// "when driver control" hat block
int ondriver_drivercontrol_0() {
  while (true) {
    // Stops Motors
    Wings.stop();
    wait(5.0, seconds);
  wait(5, msec);
  }
  return 0;
}

void displayYippeeImages(int number) {
  switch (number)
  {
  case 1:
    Brain.Screen.drawImageFromBuffer(yippee_map_one, 0, 0, sizeof(yippee_map_one));
    break;
  case 2:
    Brain.Screen.drawImageFromBuffer(yippee_map_two, 0, 0, sizeof(yippee_map_two));
    break;
    case 3:
    Brain.Screen.drawImageFromBuffer(yippee_map_three, 0, 0, sizeof(yippee_map_three));
    break;
    case 4:
    Brain.Screen.drawImageFromBuffer(yippee_map_four, 0, 0, sizeof(yippee_map_four));
    break;
  default:
    break;
  }
}
// "when driver control" hat block
int ondriver_drivercontrol_1() {
  Brain.Screen.setFillColor(white);
  Brain.Screen.setPenColor(black);
  Brain.Screen.drawRectangle(0,0, 480, 272);
  // Brain.Screen.print(Brain.Screen.drawImageFromBuffer(yippee_map, 0, 0, sizeof(yippee_map)));
  // return 0;
  int imageNumber = 1;
  while (true) {
    // Interfaces with Brain LCD
    //myblockfunction_Screen();
    displayYippeeImages(imageNumber);
    imageNumber = imageNumber + 1;
    imageNumber = (imageNumber % 4) + 1;
    wait(2.0, seconds);
    Brain.Screen.clearScreen();
  wait(5, msec);
  }
  return 0;
}

// "when driver control" hat block
int ondriver_drivercontrol_2() {
  i = 0.0;
  while (true) {
    // Interfaces with Controller LCD
    myblockfunction_Controller_Screen_DisplayMetric(i);
    wait(3.0, seconds);
    i = i + 1.0;
    i = fmod(i,3.0);
  wait(5, msec);
  }
  return 0;
}

// "when autonomous" hat block
int onauton_autonomous_0() {
  myblockfunction_Autonomous();
  return 0;
}

void VEXcode_driver_task() {
  // Start the driver control tasks....
  vex::task drive0(ondriver_drivercontrol_0);
vex::task drive1(ondriver_drivercontrol_1);
vex::task drive2(ondriver_drivercontrol_2);
  while(Competition.isDriverControl() && Competition.isEnabled()) {this_thread::sleep_for(10);}
  drive0.stop();
drive1.stop();
drive2.stop();
  return;
}

void VEXcode_auton_task() {
  // Start the auton control tasks....
  vex::task auto0(onauton_autonomous_0);
  while(Competition.isAutonomous() && Competition.isEnabled()) {this_thread::sleep_for(10);}
  auto0.stop();
  return;
}



int main() {
  vex::competition::bStopTasksBetweenModes = false;
  PistonA.open();    
  PistonB.open();
  Competition.autonomous(VEXcode_auton_task);
  Competition.drivercontrol(VEXcode_driver_task);

  // initialize the random number system
  srand(Brain.Timer.system());

  // register event handlers
  Controller1.ButtonUp.pressed(onevent_Controller1ButtonUp_pressed_0);
  Controller1.ButtonL1.pressed(onevent_Controller1ButtonL1_pressed_0);
  Controller1.ButtonR1.pressed(onevent_Controller1ButtonR1_pressed_0);
  Controller1.ButtonL1.released(onevent_Controller1ButtonL1_released_0);
  Controller1.ButtonR1.released(onevent_Controller1ButtonR1_released_0);
  Controller1.ButtonL2.pressed(onevent_Controller1ButtonL2_pressed_0);
  Controller1.ButtonR2.pressed(onevent_Controller1ButtonR2_pressed_0);
  Controller1.ButtonDown.pressed(onevent_Controller1ButtonDown_pressed_0);
  Controller1.ButtonL2.released(onevent_Controller1ButtonL2_released_0);
  Controller1.ButtonR2.released(onevent_Controller1ButtonR2_released_0);
  Controller1.ButtonLeft.pressed(onevent_Controller1ButtonLeft_pressed_0);
  Controller1.ButtonX.pressed(onevent_Controller1ButtonX_pressed_0);
  Controller1.ButtonX.released(onevent_Controller1ButtonX_released_0);


  wait(15, msec);
  // post event registration

  // set default print color to black
  printf("\033[30m");

  // wait for rotation sensor to fully initialize
  wait(30, msec);

  whenStarted1();
}