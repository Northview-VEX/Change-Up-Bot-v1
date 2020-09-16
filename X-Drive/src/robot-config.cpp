#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor back_right_motor = motor(PORT1, ratio18_1, false);
motor back_left_motor = motor(PORT10, ratio18_1, true);
motor front_right_motor = motor(PORT11, ratio18_1, true);
motor indexer = motor(PORT14, ratio6_1, true);
motor sorter = motor(PORT17, ratio6_1, false);
motor front_left_motor = motor(PORT20, ratio18_1, true);
controller Controller1 = controller(primary);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool Controller1LeftShoulderControlMotorsStopped = true;
bool Controller1RightShoulderControlMotorsStopped = true;
bool Controller1UpDownButtonsControlMotorsStopped = true;
bool Controller1XBButtonsControlMotorsStopped = true;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_callback_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    if(RemoteControlCodeEnabled) {
      // check the ButtonL1/ButtonL2 status to control front_left_motor
      if (Controller1.ButtonL1.pressing()) {
        front_left_motor.spin(forward);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonL2.pressing()) {
        front_left_motor.spin(reverse);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (!Controller1LeftShoulderControlMotorsStopped) {
        front_left_motor.stop();
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1LeftShoulderControlMotorsStopped = true;
      }
      // check the ButtonR1/ButtonR2 status to control front_right_motor
      if (Controller1.ButtonR1.pressing()) {
        front_right_motor.spin(reverse);
        Controller1RightShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonR2.pressing()) {
        front_right_motor.spin(forward);
        Controller1RightShoulderControlMotorsStopped = false;
      } else if (!Controller1RightShoulderControlMotorsStopped) {
        front_right_motor.stop();
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1RightShoulderControlMotorsStopped = true;
      }
      // check the Up/Down Buttons status to control sorter
      if (Controller1.ButtonUp.pressing()) {
        sorter.spin(forward);
        Controller1UpDownButtonsControlMotorsStopped = false;
      } else if (Controller1.ButtonDown.pressing()) {
        sorter.spin(reverse);
        Controller1UpDownButtonsControlMotorsStopped = false;
      } else if (!Controller1UpDownButtonsControlMotorsStopped){
        sorter.stop();
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1UpDownButtonsControlMotorsStopped = true;
      }
      // check the X/B buttons status to control indexer
      if (Controller1.ButtonX.pressing()) {
        indexer.spin(forward);
        Controller1XBButtonsControlMotorsStopped = false;
      } else if (Controller1.ButtonB.pressing()) {
        indexer.spin(reverse);
        Controller1XBButtonsControlMotorsStopped = false;
      } else if (!Controller1XBButtonsControlMotorsStopped){
        indexer.stop();
        Controller1XBButtonsControlMotorsStopped = true;
      }
    }
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  task rc_auto_loop_task_Controller1(rc_auto_loop_callback_Controller1);
}