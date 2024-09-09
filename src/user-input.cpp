#include <chrono>
#include <iostream>
#include "vex.h"
#include "main.h"
/*
------------------------------------------------------------------
BUTTON DEFINITIONS ! READ ME !
------------------------------------------------------------------
Each button has a respective namespace which has four methods:
- initialize()
- onPress()
- onRelease()
- onPing()
initialize():
Is called at the start of usercontrol to allow proper control flow.
This should be called exactly once.
onPress():
Is called once and only once on the event that the namespace's respective button is pressed
onRelease():
Is called once and only once on the event that the namespace's respective button is pressed
onPing()
Is called once and only once every tick.
A tick is every iteration of the main gameplay loop that is found in usercontrol()
This is useful for when you want some operation to happen while the button is pressed,
or have a button toggle an operation.
All Variables that impact only one button must be stored within the button's namespace
! Even if the method is empty, DO NOT DELETE the method, this will cause the system to break.

A note to advanced readers: every use of the method vex::controller::button::pressed spins up a new thread,
so try to make your methon fail-safe to collisions
*/
/*
 *
 * BUTTON DOCS:
 *
 * Left Joystick - left tank drive
 * Right Joystick - right tank drive
 *
 * L1 -
 * L2 -
 * R1 -
 * R2 -
 * Up -
 * Down -
 * Left -
 * Right -
 * A - Change front of robot
 * B -
 * X - Change Drive Speed Mode
 * Y -
 *
 */
/*
---------------Enums---------------------------
*/
enum side
{
  PORT,
  STARBOARD,
  FORWARD,
  AFT
};
/*
---------------Constants------------------------
*/
// Motors
// - Drive Train
// - - Port Side
vex::motor frontLeftDriveTrainMotor{vex::PORT12, STARBOARD};
vex::motor backLeftDriveTrainMotor{vex::PORT10, STARBOARD};
vex::motor_group leftDriveTrainMotorGroup{frontLeftDriveTrainMotor, backLeftDriveTrainMotor};
// - - Starboard Side
vex::motor frontRightDriveTrainMotor{vex::PORT1, PORT};
vex::motor backRightDriveTrainMotor{vex::PORT2, PORT};
vex::motor_group rightDriveTrainMotorGroup{frontRightDriveTrainMotor, backRightDriveTrainMotor};
// - Lift
vex::motor leftLift{vex::PORT6, STARBOARD};
vex::motor rightLift{vex::PORT7, PORT};
vex::motor_group lift{leftLift, rightLift};
// - Puncher
vex::motor puncher{vex::PORT8, PORT};
constexpr double liftSpeedPct{60};

/*
---------------Variables-----------------------
*/
double driveSpeedPercent = 80;
/*
---------------Button Definitions-------------
*/

namespace buttonA
{
  static vex::controller::button BUTTON_OBJECT{Controller.ButtonA};
  void onPress()
  {
  }
  void onRelease()
  {
  }
  void onPing()
  {
  }
  void initialize()
  {
    BUTTON_OBJECT.pressed(onPress);
    BUTTON_OBJECT.released(onRelease);
  }
}

namespace buttonB
{
  static vex::controller::button BUTTON_OBJECT{Controller.ButtonB};
  void onPress()
  {
  }
  void onRelease()
  {
  }
  void onPing()
  {
  }
  void initialize()
  {
    BUTTON_OBJECT.pressed(onPress);
    BUTTON_OBJECT.released(onRelease);
  }
}

namespace buttonX
{
  static vex::controller::button BUTTON_OBJECT{Controller.ButtonX};
  void onPress()
  {
  }
  void onRelease()
  {
  }
  void onPing()
  {
  }
  void initialize()
  {
    BUTTON_OBJECT.pressed(onPress);
    BUTTON_OBJECT.released(onRelease);
  }
}

namespace buttonY
{
  static vex::controller::button BUTTON_OBJECT{Controller.ButtonY};
  void onPress()
  {
  }
  void onRelease()
  {
  }
  void onPing()
  {
  }
  void initialize()
  {
    BUTTON_OBJECT.pressed(onPress);
    BUTTON_OBJECT.released(onRelease);
  }
}

namespace buttonUp
{
  static vex::controller::button BUTTON_OBJECT{Controller.ButtonUp};
  void onPress()
  {
  }
  void onRelease()
  {
  }
  void onPing()
  {
  }
  void initialize()
  {
    BUTTON_OBJECT.pressed(onPress);
    BUTTON_OBJECT.released(onRelease);
  }
}

namespace buttonDown
{
  static vex::pneumatics wing(vex::triport(vex::PORT22).A);
  static vex::controller::button BUTTON_OBJECT{Controller.ButtonDown};
  static bool isWingOut{false};
  void onPress()
  {
    isWingOut = !isWingOut;
    wing.set(isWingOut);
  }
  void onRelease()
  {
  }
  void onPing()
  {
  }
  void initialize()
  {
    BUTTON_OBJECT.pressed(onPress);
    BUTTON_OBJECT.released(onRelease);
  }
}

namespace buttonLeft
{
  static vex::controller::button BUTTON_OBJECT{Controller.ButtonLeft};
  void onPress()
  {
  }
  void onRelease()
  {
  }
  void onPing()
  {
  }
  void initialize()
  {
    BUTTON_OBJECT.pressed(onPress);
    BUTTON_OBJECT.released(onRelease);
  }
}

namespace buttonRight
{
  static vex::controller::button BUTTON_OBJECT{Controller.ButtonRight};
  void onPress()
  {
  }
  void onRelease()
  {
  }
  void onPing()
  {
  }
  void initialize()
  {
    BUTTON_OBJECT.pressed(onPress);
    BUTTON_OBJECT.released(onRelease);
  }
}

namespace buttonL1
{
  static vex::controller::button BUTTON_OBJECT{Controller.ButtonL1};
  static bool isPuncherOn{false};
  void onPress()
  {
    isPuncherOn = !isPuncherOn;
    if (isPuncherOn)
    {
      
    }
  }
  void onRelease()
  {
  }
  void onPing()
  {
  }
  void initialize()
  {
    BUTTON_OBJECT.pressed(onPress);
    BUTTON_OBJECT.released(onRelease);
  }
}

namespace buttonL2
{
  static vex::controller::button BUTTON_OBJECT{Controller.ButtonL2};
  void onPress()
  {
  }
  void onRelease()
  {
  }
  void onPing()
  {
  }
  void initialize()
  {
    BUTTON_OBJECT.pressed(onPress);
    BUTTON_OBJECT.released(onRelease);
  }
}

namespace buttonR1
{
  static vex::controller::button BUTTON_OBJECT{Controller.ButtonR1};
  void onPress()
  {
    lift.spin(vex::directionType::fwd, liftSpeedPct, vex::velocityUnits::pct);
  }
  void onRelease()
  {
    lift.stop();
  }
  void onPing()
  {
  }
  void initialize()
  {
    BUTTON_OBJECT.pressed(onPress);
    BUTTON_OBJECT.released(onRelease);
  }
}

namespace buttonR2
{
  static vex::controller::button BUTTON_OBJECT{Controller.ButtonR2};
  void onPress()
  {
    lift.spin(vex::directionType::rev, liftSpeedPct, vex::velocityUnits::pct);
  }
  void onRelease()
  {
    lift.stop();
  }
  void onPing()
  {
  }
  void initialize()
  {
    BUTTON_OBJECT.pressed(onPress);
    BUTTON_OBJECT.released(onRelease);
  }
}

namespace joystickRight
{
  static vex::controller::axis xAxis{Controller.Axis1};
  static vex::controller::axis yAxis{Controller.Axis2};
  void onPing()
  {
    rightDriveTrainMotorGroup.spin(vex::directionType::fwd, driveSpeedPercent * yAxis.position(), vex::velocityUnits::pct);
  }
}

namespace joystickLeft
{
  static vex::controller::axis xAxis{Controller.Axis4};
  static vex::controller::axis yAxis{Controller.Axis3};
  void onPing()
  {
    // std::cout << "foo";
    // Controller.Screen.clearLine();
    // Controller.Screen.print(yAxis.position());
    leftDriveTrainMotorGroup.spin(vex::directionType::fwd, driveSpeedPercent * yAxis.position(), vex::velocityUnits::pct);
  }
}
