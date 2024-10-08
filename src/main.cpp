#include <chrono>
#include <ctime>
#include "vex.h"
#include "user-input.h"

// A global instance of competition
vex::competition Competition;
vex::controller Controller = vex::controller{};
vex::brain Brain{};
vex::timer SystemClock{};
constexpr double MillisecondsPerTick{1}; // targeting 20 ticks per second

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void)
{

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void)
{
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  Note: For this project, edits should mostly be focused user-input.cpp.   */
/*  Global variables and constants should be stored there.                   */
/*---------------------------------------------------------------------------*/
void usercontrol(void)
{
  // User control code here, inside the loop
  buttonA::initialize();
  buttonB::initialize();
  buttonX::initialize();
  buttonY::initialize();
  buttonUp::initialize();
  buttonDown::initialize();
  buttonLeft::initialize();
  buttonRight::initialize();
  buttonL1::initialize();
  buttonL2::initialize();
  buttonR1::initialize();
  buttonR2::initialize();
  int timeOfStartOfTickMS{-1};
  while (true)
  {
    timeOfStartOfTickMS = static_cast<int>(SystemClock.time());
    buttonA::onPing();
    buttonB::onPing();
    buttonX::onPing();
    buttonY::onPing();
    buttonUp::onPing();
    buttonDown::onPing();
    buttonLeft::onPing();
    buttonRight::onPing();
    buttonL1::onPing();
    buttonL2::onPing();
    buttonR1::onPing();
    buttonR2::onPing();
    joystickLeft::onPing();
    joystickRight::onPing();
    // Sleep the thread to maintain a consistent 20 tps and conserve battery
    int timeOfEndOfTickMS{static_cast<int>(SystemClock.time())};
    wait(MillisecondsPerTick - (timeOfEndOfTickMS - timeOfStartOfTickMS), vex::msec);
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main()
{
  // Start up System Clock
  SystemClock.reset();
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true)
  {
    wait(100, vex::msec);
  }
}
