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
 * L1 - Intake in
 * L2 - Intake out
 * R1 - 
 * R2 - 
 * Up - 
 * Down - Toggle hook
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
---------------Hardware Definitions--------------------
*/
// Motors
// - Drive Train
// - - Port Side
vex::motor frontLeftDriveTrainMotor{vex::PORT4, STARBOARD};
vex::motor backLeftDriveTrainMotor{vex::PORT3, STARBOARD};
vex::motor_group leftDriveTrainMotorGroup{frontLeftDriveTrainMotor, backLeftDriveTrainMotor};
// - - Starboard Side
vex::motor frontRightDriveTrainMotor{vex::PORT2, PORT};
vex::motor backRightDriveTrainMotor{vex::PORT1, PORT};
vex::motor_group rightDriveTrainMotorGroup{frontRightDriveTrainMotor, backRightDriveTrainMotor};
// - Intake
vex::motor intake(vex::PORT10, STARBOARD);

// Pneumatics
// - Clamp
vex::pneumatics clamp(vex::TRIPORTA);

/*
---------------Variables-----------------------
*/
double driveSpeedPercentDefault = 100;
double driveSpeedPercentAlternate = 50;
bool useDefaultSpeed = true;
side forwardSide = FORWARD;

double intakeSpeed = 50;
bool intakeOn = false;
vex::directionType intakeDirection = vex::forward;
/*
---------------Button Definitions-------------
*/

namespace buttonA
{
  static vex::controller::button BUTTON_OBJECT{Controller.ButtonA};
  void onPress()
  {
    switch (forwardSide)
    {
      case FORWARD:
        forwardSide = AFT;
      case AFT:
        forwardSide = FORWARD;
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
    useDefaultSpeed = !useDefaultSpeed;
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
  static bool isClampOn = false;
  void onPress()
  {
    isClampOn = !isClampOn;
    clamp.set(isClampOn);
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
    if (intakeOn && intakeDirection == vex::forward)
    {
      intakeOn = false;
      intake.stop();
    }
    else
    {
      intakeOn = true;
      intakeDirection = vex::forward;
      intake.spin(intakeDirection, intakeSpeed, vex::velocityUnits::pct);
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
    if (intakeOn && intakeDirection == vex::reverse)
    {
      intakeOn = false;
      intake.stop();
    }
    else
    {
      intakeOn = true;
      intakeDirection = vex::reverse;
      intake.spin(intakeDirection, intakeSpeed, vex::velocityUnits::pct);
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
    double driveSpeedPercent = yAxis.position() / 100.0;
    if (useDefaultSpeed) driveSpeedPercent *= driveSpeedPercentDefault;
    else driveSpeedPercent *= driveSpeedPercentAlternate;
    
    if (forwardSide == FORWARD) 
    {
      rightDriveTrainMotorGroup.spin(vex::directionType::fwd, driveSpeedPercent, vex::velocityUnits::pct);
    }
    if (forwardSide == AFT) 
    {
      leftDriveTrainMotorGroup.spin(vex::directionType::rev, driveSpeedPercent, vex::velocityUnits::pct);
    }
  }
}

namespace joystickLeft
{
  static vex::controller::axis xAxis{Controller.Axis4};
  static vex::controller::axis yAxis{Controller.Axis3};
  void onPing()
  {
    double driveSpeedPercent = yAxis.position() / 100.0;
    if (useDefaultSpeed) driveSpeedPercent *= driveSpeedPercentDefault;
    else driveSpeedPercent *= driveSpeedPercentAlternate;
    
    if (forwardSide == FORWARD) 
    {
      leftDriveTrainMotorGroup.spin(vex::directionType::fwd, driveSpeedPercent, vex::velocityUnits::pct);
    }
    if (forwardSide == AFT) 
    {
      rightDriveTrainMotorGroup.spin(vex::directionType::rev, driveSpeedPercent, vex::velocityUnits::pct);
    }
  }
}
