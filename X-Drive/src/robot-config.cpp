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

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}