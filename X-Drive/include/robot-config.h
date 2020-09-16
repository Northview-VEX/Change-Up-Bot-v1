using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor back_right_motor;
extern motor back_left_motor;
extern motor front_right_motor;
extern motor indexer;
extern motor sorter;
extern motor front_left_motor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );