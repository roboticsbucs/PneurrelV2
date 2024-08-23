
#include <chrono>
#include "vex.h"
#include "main.h"
using namespace std::chrono;
/*
These are a collection of presets you can use to set up
the various user input devices.
A note: It is *critical* that you set the value for the BUTTON_OBJECT.
The code will compile but it will have undefined behavoir (meaning it will act randomly),
which is a pretty awful thing to debug


also: the compiler is set up to give a warning whenever a function is unused.
given the nature of this as a template class, these function are and will remain unused,
so it is okay that the compiler gives a warning about it.
*/
/*
-----------------Examples-----------------------------
*/
// the most basic button template
namespace emptyButtonTemplate
{
    static vex::controller::button BUTTON_OBJECT{};
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
// continually acts while the respective button is pressed
namespace whilePressedButtonTemplate
{
    static vex::controller::button BUTTON_OBJECT{};
    static bool buttonIsPressed{false};
    static void onPress()
    {
        buttonIsPressed = true;
        // you can add more code here, just make sure that the bool being set is preserved
    }
    static void onRelease()
    {
        buttonIsPressed = false;
        // you can add more code here, just make sure that the bool being set is preserved
    }
    static void onPing()
    {
        if (!buttonIsPressed)
        {
            return;
        }
        // toggled action here
    }
    static void initialize()
    {
        BUTTON_OBJECT.pressed(onPress);
        BUTTON_OBJECT.released(onRelease);
    }

}
// acts once after a constant delay
// please do not use vex::waitUntil, because we only have one thread to work with
namespace actAfterDelayButtonTemplate
{
    static vex::controller::button BUTTON_OBJECT{};
    static bool latch{false};
    static milliseconds timeOfLastPressMS{};
    const static milliseconds actionDelayMS{100};
    void onPress()
    {
        if (!latch)
        {
            // we use steady clock over system clock because reading the system time
            // is very expensive and we only need relative time
            timeOfLastPressMS = duration_cast<milliseconds>(steady_clock::now().time_since_epoch());
        }
        latch = true;
    }
    void onRelease()
    { // you could also open the latch here for potentially better ux
    }
    void onPing()
    {
        if (!latch)
        {
            return;
        }
        milliseconds currentTime{duration_cast<milliseconds>(steady_clock::now().time_since_epoch())};
        if (currentTime < timeOfLastPressMS + actionDelayMS)
        {
            return;
        }
        latch = false;
        // do something
    }
    void initialize()
    {
        BUTTON_OBJECT.pressed(onPress);
        BUTTON_OBJECT.released(onRelease);
    }
}
namespace emptyJoystickTemplate
{
    static vex::controller::axis xAxis{};
    static vex::controller::axis yAxis{};
    void onPing()
    {
    }
}

/*
--------------End of examples------------------
*/