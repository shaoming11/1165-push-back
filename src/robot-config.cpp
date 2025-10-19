#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;
controller Controller(primary);
controller Shao(partner);
//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);

//Add your devices below, and don't forget to do the same in robot-config.h:
motor LF = motor(PORT12, ratio36_1, false);
motor LM = motor(PORT14, ratio18_1, true);
motor LB = motor(PORT16, ratio36_1, true);
motor RF = motor(PORT11, ratio36_1, true);
motor RM = motor(PORT13, ratio36_1, false);
motor RB = motor(PORT15, ratio36_1, false);
motor hIntake = motor(PORT17, ratio36_1, true);
motor hIntake2 = motor(PORT18, ratio36_1, true);
motor_group intake = motor_group(hIntake, hIntake2);

inertial Gyro = inertial(PORT21);
rotation LeftTrack = rotation(PORT19);
rotation RearTrack = rotation(PORT20);
optical ColSort = optical(PORT12);

digital_out Clamp = digital_out(Brain.ThreeWirePort.B);
digital_out Doink = digital_out(Brain.ThreeWirePort.A);
digital_out DoinkR = digital_out(Brain.ThreeWirePort.A);

void vexcodeInit( void ) {
  // nothing to initialize
}