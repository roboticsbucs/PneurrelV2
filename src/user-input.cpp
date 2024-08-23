#include <chrono>
#include "vex.h"
#include "main.h"
using namespace std::chrono;
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
! Even if the method is empty, DO NOT DELETE the method, this will cause the system to break

A note: Because the entirety of this program is serial, or single-threaded, it is paramount to
not let a single button process sit idle, ie using vex's wait method. If you want to have a
program that does something after a certain amount of time or for a certain amount of time,
use a condition using the time in onPing() to avoid this.
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
enum speedMode
{
  FULL_SPEED,
  SLOW_SPEED
};
double getSpeedPercent(speedMode mode)
{
  switch (mode)
  {
  case FULL_SPEED:
    return 1.0;
  case SLOW_SPEED:
    return .5;
  default:
    break;
  }
}
/*
---------------Constants------------------------
*/
// Motors
// - Drive Train
// - - Port Side
vex::motor frontLeftDriveTrainMotor{vex::PORT12, PORT};
vex::motor backLeftDriveTrainMotor{vex::PORT10, PORT};
vex::motor_group leftDriveTrainMotorGroup{frontLeftDriveTrainMotor, backLeftDriveTrainMotor};
// - - Starboard Side
vex::motor frontRightDriveTrainMotor{vex::PORT12, STARBOARD};
vex::motor backRightDriveTrainMotor{vex::PORT10, STARBOARD};
vex::motor_group rightDriveTrainMotorGroup{frontRightDriveTrainMotor, backRightDriveTrainMotor};

/*
---------------Variables-----------------------
*/
speedMode driveSpeedMode{FULL_SPEED};
double driveSpeedPercent = getSpeedPercent(driveSpeedMode);
side frontSide{FORWARD};
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
    if (driveSpeedMode == FULL_SPEED)
    {
      driveSpeedMode = SLOW_SPEED;
    }
    else
    {
      driveSpeedMode = FULL_SPEED;
    }
    driveSpeedPercent = getSpeedPercent(driveSpeedMode);
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
  static vex::controller::button BUTTON_OBJECT{Controller.ButtonDown};
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

namespace buttonR2
{
  static vex::controller::button BUTTON_OBJECT{Controller.ButtonR2};
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

namespace joystickRight
{
  static vex::controller::axis xAxis{Controller.Axis1};
  static vex::controller::axis yAxis{Controller.Axis2};
  void onPing()
  {
    if (frontSide == FORWARD)
    {
      rightDriveTrainMotorGroup.spin(vex::directionType::fwd, driveSpeedPercent * yAxis.position(), vex::velocityUnits::pct);
    }
    else
    {
      leftDriveTrainMotorGroup.spin(vex::directionType::rev, driveSpeedPercent * yAxis.position(), vex::velocityUnits::pct);
    }
  }
}

namespace joystickLeft
{
  static vex::controller::axis xAxis{Controller.Axis3};
  static vex::controller::axis yAxis{Controller.Axis4};
  void onPing()
  {
    if (frontSide == FORWARD)
    {
      leftDriveTrainMotorGroup.spin(vex::directionType::fwd, driveSpeedPercent * yAxis.position(), vex::velocityUnits::pct);
    }
    else
    {
      rightDriveTrainMotorGroup.spin(vex::directionType::rev, driveSpeedPercent * yAxis.position(), vex::velocityUnits::pct);
    }
  }
}
