/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Jeffrey                                          */
/*    Created:      Thu Jul 02 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

// VEX V5 C++ Project
//COMMENT
#include "vex.h"
#include <algorithm>
using namespace vex;

//#region config_globals
//Configure the motors properly in the robot configuration menu (on the right side menu
//coment testubg 2

vex::motor      back_right_motor(vex::PORT1, vex::gearSetting::ratio18_1, true);
vex::motor      back_left_motor(vex::PORT10, vex::gearSetting::ratio18_1, false);
vex::motor      front_right_motor(vex::PORT11, vex::gearSetting::ratio18_1, true);
vex::motor      indexer(vex::PORT14, vex::gearSetting::ratio6_1, false);
vex::motor      sorter(vex::PORT17, vex::gearSetting::ratio6_1, true);
vex::motor      front_left_motor(vex::PORT20, vex::gearSetting::ratio18_1, false);
vex::controller con(vex::controllerType::primary);
//#endregion config_globals

//Try to interpret this code.
//Then, make an include file and src file for driver control, and reorganize the code there (like how we did over the summer)
int main(void) {
    while(true) {

        //Get the raw sums of appropriate joystick axes
        double front_left = (double)(con.Axis3.position(pct) + con.Axis4.position(pct) + con.Axis1.position(pct));
        double back_left = (double)(con.Axis3.position(pct) - con.Axis4.position(pct) + con.Axis1.position(pct));
        double front_right = (double)(con.Axis3.position(pct) - con.Axis4.position(pct) - con.Axis1.position(pct));
        double back_right = (double)(con.Axis3.position(pct) + con.Axis4.position(pct) - con.Axis1.position(pct));

        //Find the largest raw sum or 100
        double max_raw_value = std::max(front_left,std::max(back_left,std::max(front_right,std::max(back_right,100.0))));

        //Scale down each value if there was one larger than 100, otherwise leave them alone
        //The largest value will be scaled down to 100, and the others will be reduced by the same factor
        front_left = front_left / max_raw_value * 100;
        back_left = back_left / max_raw_value * 100;
        front_right = front_right / max_raw_value * 100;
        back_right = back_right / max_raw_value * 100;

        //Write the scaled sums out to the various motors
        front_left_motor.spin(fwd, front_left, velocityUnits::pct);
        back_left_motor.spin(fwd, back_left, velocityUnits::pct);
        front_right_motor.spin(fwd, front_right, velocityUnits::pct);
        back_right_motor.spin(fwd, back_right, velocityUnits::pct);

        if (con.ButtonR1.pressing()){
          indexer.spin(fwd, 100, pct);
          sorter.spin(fwd, 100, pct);
        }
        else if (con.ButtonR2.pressing()){
          indexer.spin(fwd, 100, pct);
          sorter.spin(fwd, -100, pct);
        }
        else{
          indexer.stop(brake);
          sorter.stop(brake);
        }
    }
}

//@avi no u :))
//ahhhhhhhhhhhhhhhhhhhhhhh