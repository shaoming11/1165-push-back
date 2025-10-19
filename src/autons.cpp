#include "vex.h"

/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */

void default_constants()
{
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, 0, 0, 0, 0);
  chassis.set_turn_constants(6, .4, 0.03, 3, 15);
  chassis.set_swing_constants(12, 1, 0, 13, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 100, 5000);
  chassis.set_turn_exit_conditions(0.001, 400, 5000);
  chassis.set_swing_exit_conditions(2.0, 150, 3000);

  LeftTrack.setPosition(0, degrees);
  RearTrack.setPosition(0, degrees);
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

void odom_constants()
{
  default_constants();
  chassis.heading_max_voltage = 10;
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
  chassis.boomerang_lead = .5;
  chassis.drive_min_voltage = 0;
}

/**
 * The expected behavior is to return to the start position.
 */

/*
AUTONS

solo AWP - red & blue
5 ring - red & blue
goal rush - red & blue

win point goal side - red & blue
win point ring side - red & blue
*/
void eight_r()
{
  chassis.set_drive_constants(8, 1.5, 0, 10, 0);
  chassis.set_turn_constants(8, .8, 0.03, 6, 15);

  chassis.drive_settle_error = 0.5;
  chassis.drive_distance(10);
  chassis.drive_settle_error = 1.5;
  armToScorePos = true;
  task::sleep(400);

  chassis.drive_distance(-23);
  armToScorePos = false;
  armToStartPos = true;
  chassis.turn_to_angle(-30);
  task::sleep(250);
  chassis.turn_to_angle(0);
  chassis.drive_timeout = 2000;
  chassis.drive_distance(-20, 0, 4.5, 0, 1.5, 100, 2000, 1.5, 0, 22, 0, 0, 0, 0, 0);

  Clamp.set(1);

  chassis.turn_to_angle(185);
  default_constants();
  // chassis.drive_distance(-5);
  // chassis.drive_distance(5);
  // task::sleep(100);
  chassis.turn_to_angle(165);
  convDir = FORWARD;

  // the 3 rings
  chassis.drive_timeout = 700;
  chassis.drive_distance(20);
  chassis.swing_timeout = 450;
  chassis.right_swing_to_angle(120);
  chassis.drive_distance(15, chassis.get_absolute_heading(), 4);
  task::sleep(500);
  chassis.drive_distance(-4);
  chassis.drive_timeout = 450;
  chassis.turn_to_angle(25);
  chassis.drive_min_voltage = 12;
  armToStartPos = false;
  default_constants();
  chassis.drive_timeout = 600;
  chassis.drive_distance(8);
  armToLoadPos = true;
  chassis.drive_timeout = 800;
  chassis.drive_distance(8);
  doAntiJam = false;
  default_constants();

  // score wallstake
  task::sleep(400);
  chassis.drive_distance(-10);
  armToLoadPos = false;
  // armToScorePos = true;
  chassis.turn_to_angle(120);
  chassis.turn_to_angle(150);
  task::sleep(100);
  convDir = STOP;
  chassis.drive_distance(10);
  // // armToScorePos = false;
  armToScore = true;
  task::sleep(200);
}

void eight_b()
{
  chassis.set_drive_constants(8, 1.5, 0, 10, 0);
  chassis.set_turn_constants(8, .8, 0.03, 6, 15);

  chassis.drive_settle_error = 0.5;
  chassis.drive_distance(10);
  chassis.drive_settle_error = 1.5;
  armToScorePos = true;
  task::sleep(400);

  chassis.drive_distance(-23);
  armToScorePos = false;
  armToStartPos = true;
  chassis.turn_to_angle(30);
  task::sleep(250);
  chassis.turn_to_angle(0);
  chassis.drive_timeout = 2000;
  chassis.drive_distance(-20, 0, 4.5, 0, 1.5, 100, 2000, 1.5, 0, 22, 0, 0, 0, 0, 0);

  Clamp.set(1);

  chassis.turn_to_angle(-185);
  default_constants();
  // chassis.drive_distance(-5);
  // chassis.drive_distance(5);
  // task::sleep(100);
  chassis.turn_to_angle(-165);
  convDir = FORWARD;

  // the 3 rings
  chassis.drive_timeout = 700;
  chassis.drive_distance(20);
  chassis.swing_timeout = 450;
  chassis.left_swing_to_angle(-120);
  chassis.drive_distance(15, chassis.get_absolute_heading(), 4);
  task::sleep(500);
  chassis.drive_distance(-4);
  chassis.drive_timeout = 450;
  chassis.turn_to_angle(-25);
  chassis.drive_min_voltage = 12;
  armToStartPos = false;
  default_constants();
  chassis.drive_timeout = 600;
  chassis.drive_distance(8);
  armToLoadPos = true;
  chassis.drive_timeout = 800;
  chassis.drive_distance(8);
  doAntiJam = false;
  default_constants();

  // score wallstake
  task::sleep(400);
  chassis.drive_distance(-10);
  armToLoadPos = false;
  // armToScorePos = true;
  chassis.turn_to_angle(-120);
  chassis.turn_to_angle(-150);
  task::sleep(100);
  convDir = STOP;
  chassis.drive_distance(15);
  // // armToScorePos = false;
  armToScore = true;
  task::sleep(200);
}

void five_r()
{
  task::sleep(3000);
  chassis.set_drive_constants(8, 1.5, 0, 10, 0);
  chassis.set_turn_constants(8, .8, 0.03, 6, 15);

  chassis.drive_settle_error = 0.5;
  chassis.drive_distance(10);
  chassis.drive_settle_error = 1.5;
  armToScorePos = true;
  task::sleep(400);

  chassis.drive_distance(-23);
  armToScorePos = false;
  armToStartPos = true;
  chassis.turn_to_angle(-30);
  task::sleep(250);
  chassis.turn_to_angle(0);
  chassis.drive_timeout = 2000;
  chassis.drive_distance(-20, 0, 4.5, 0, 1.5, 100, 2000, 1.5, 0, 22, 0, 0, 0, 0, 0);

  Clamp.set(1);

  // task::sleep(50);
  // chassis.turn_timeout = 150;
  // chassis.turn_max_voltage = 2;
  // chassis.turn_to_angle(130);
  chassis.turn_timeout = 200;
  chassis.turn_to_angle(-90);
  default_constants();
  chassis.turn_to_angle(185);
  task::sleep(100);
  chassis.turn_to_angle(165);
  convDir = FORWARD;

  // the 3 rings
  chassis.drive_timeout = 1000;
  chassis.drive_distance(20);
  chassis.swing_timeout = 700;
  chassis.right_swing_to_angle(120);
  chassis.drive_distance(11, chassis.get_absolute_heading(), 4);
  task::sleep(500);
  chassis.turn_to_angle(25);
  // chassis.drive_timeout = 1500;
  chassis.drive_min_voltage = 12;
  chassis.drive_distance(20);
  // convDir = STOP;
  chassis.drive_timeout = 500;
  chassis.drive_distance(20);
  // chassis.drive_distance(27, 2.5);
  default_constants();

  // // chassis.drive_distance(-6);

  // // get corner rings
  doAntiJam = false;
  task::sleep(500);
  chassis.turn_timeout = 500;
  chassis.turn_to_angle(72);
  convDir = FORWARD;
  chassis.drive_timeout = 400;
  chassis.drive_distance(18, chassis.get_absolute_heading(), 12);
  chassis.drive_timeout = 800;
  chassis.drive_distance(20, chassis.get_absolute_heading(), 4);
  // task::sleep(300);

  // get out
  chassis.drive_max_voltage = 4;
  chassis.drive_distance(-10, 72, 8, 6);
  task::sleep(250);
  chassis.turn_to_angle(72);
  default_constants();
  chassis.drive_distance(-55, 72);
  armToLoadPos = true;
  armToStartPos = false;
  // chassis.turn_to_angle(75);
  // task::sleep(300);
}

void five_b()
{
  chassis.set_drive_constants(8, 1.5, 0, 10, 0);
  chassis.set_turn_constants(8, .8, 0.03, 6, 15);

  chassis.drive_settle_error = 0.5;
  chassis.drive_distance(10);
  chassis.drive_settle_error = 1.5;
  armToScorePos = true;
  task::sleep(400);

  chassis.drive_distance(-23);
  armToScorePos = false;
  armToStartPos = true;
  chassis.turn_to_angle(30);
  task::sleep(250);
  chassis.turn_to_angle(0);
  chassis.drive_timeout = 2000;
  chassis.drive_distance(-20, 0, 4.5, 0, 1.5, 100, 2000, 1.5, 0, 22, 0, 0, 0, 0, 0);

  Clamp.set(1);

  // task::sleep(50);
  // chassis.turn_timeout = 150;
  // chassis.turn_max_voltage = 2;
  // chassis.turn_to_angle(130);
  chassis.turn_timeout = 200;
  chassis.turn_to_angle(90);
  default_constants();
  chassis.turn_to_angle(-185);
  task::sleep(100);
  chassis.turn_to_angle(-165);
  convDir = FORWARD;

  // the 3 rings
  chassis.drive_timeout = 1000;
  chassis.drive_distance(16);
  chassis.swing_timeout = 700;
  chassis.left_swing_to_angle(-112);
  chassis.drive_timeout = 1000;
  chassis.drive_distance(14, chassis.get_absolute_heading(), 4);
  task::sleep(500);
  chassis.turn_to_angle(-25);
  // chassis.drive_timeout = 1500;
  chassis.drive_min_voltage = 12;
  chassis.drive_distance(20);
  // // convDir = STOP;
  // chassis.drive_timeout = 500;
  // chassis.drive_distance(23);
  // // chassis.drive_distance(27, 2.5);
  default_constants();

  // diff thing
  task::sleep(500);
  chassis.turn_to_angle(80);
  chassis.drive_distance(30);
  armToLow = true;
  armToStartPos = false;

  // // // get corner rings
  // doAntiJam = false;
  // task::sleep(500);
  // chassis.turn_timeout = 500;
  // chassis.turn_to_angle(-72);
  // convDir = FORWARD;
  // chassis.drive_timeout = 400;
  // chassis.drive_distance(18, chassis.get_absolute_heading(), 12);
  // chassis.drive_timeout = 800;
  // chassis.drive_distance(20, chassis.get_absolute_heading(), 4);
  // // task::sleep(300);

  // // get out
  // chassis.drive_max_voltage = 4;
  // chassis.turn_timeout = 300;
  // chassis.drive_timeout = 500;
  // chassis.drive_distance(-10, -72, 8, 6);
  // task::sleep(250);
  // doAntiJam = true;
  // chassis.turn_to_angle(-72);
  // default_constants();
  // chassis.drive_distance(-63, -72);
  // armToLoadPos = true;
  // armToStartPos = false;
  // // chassis.turn_to_angle(75);
  // // task::sleep(300);
}

void awp_solo_b()
{
  chassis.set_drive_constants(6, 1.5, 0, 10, 0);
  chassis.drive_settle_error = 0.5;
  chassis.drive_distance(10);
  chassis.drive_settle_error = 1.5;
  armToScorePos = true;
  task::sleep(400);
  chassis.turn_to_angle(0);

  chassis.drive_distance(-43, 0, 4.5, 0, 1.5, 100, 2000, 1.5, 0, 22, 0, 0, 0, 0, 0);
  armToScorePos = false;
  armToStartPos = true;
  Clamp.set(1);
  task::sleep(50);

  chassis.turn_to_angle(-120);
  convDir = FORWARD;
  chassis.drive_distance(26);
  task::sleep(300);
  chassis.drive_distance(-20);

  // alliance stack
  chassis.turn_to_angle(35);
  convDir = FORWARD;
  chassis.drive_distance(32);
  chassis.turn_to_angle(60);
  Clamp.set(0);
  chassis.drive_distance(13);

  chassis.turn_to_angle(-60);
  chassis.drive_distance(-20, chassis.get_absolute_heading(), 4.5, 0, 1.5, 100, 2000, 1.5, 0, 22, 0, 0, 0, 0, 0);
  Clamp.set(1);
  chassis.turn_to_angle(60);
  chassis.drive_distance(26);

  chassis.turn_to_angle(-120);
  armToStartPos = false;
  chassis.drive_distance(38);
}

void awp_solo_r()
{
  chassis.set_drive_constants(6, 1.5, 0, 10, 0);
  chassis.drive_settle_error = 0.5;
  chassis.drive_distance(10);
  chassis.drive_settle_error = 1.5;
  armToScorePos = true;
  task::sleep(400);
  chassis.turn_to_angle(0);

  chassis.drive_distance(-43, 0, 4.5, 0, 1.5, 100, 2000, 1.5, 0, 22, 0, 0, 0, 0, 0);
  armToScorePos = false;
  armToStartPos = true;
  Clamp.set(1);
  task::sleep(50);

  chassis.turn_to_angle(120);
  convDir = FORWARD;
  chassis.drive_distance(26);
  task::sleep(300);
  chassis.drive_distance(-20);

  // alliance stack
  chassis.turn_to_angle(-35);
  convDir = FORWARD;
  chassis.drive_distance(32);
  chassis.turn_to_angle(-60);
  Clamp.set(0);
  chassis.drive_distance(13);

  chassis.turn_to_angle(60);
  chassis.drive_distance(-20);
  Clamp.set(1);
  chassis.turn_to_angle(-60);
  chassis.drive_distance(26);

  chassis.turn_to_angle(120);
  chassis.drive_distance(38);
}

void gre_five()
{
  chassis.set_drive_constants(12, 1.5, 0, 10, 0);
  chassis.set_turn_constants(8, .8, 0.03, 6, 15);

  chassis.drive_settle_error = 0.5;
  chassis.drive_distance(10);
  chassis.drive_settle_error = 1.5;
  armToScorePos = true;
  task::sleep(400);

  // mogo
  // chassis.drive_distance(-23);
  // armToScorePos = false;
  // armToStartPos = true;
  // chassis.turn_to_angle(30);
  // task::sleep(250);
  // chassis.turn_to_angle(0);
  // chassis.drive_timeout = 2000;
  // chassis.drive_distance(-20, 0, 4.5, 0, 1.5, 100, 2000, 1.5, 0, 22, 0, 0, 0, 0, 0);
  // task::sleep(50);
  // Clamp.set(1);
  // default_constants();
  // chassis.turn_to_angle(95);
  // task::sleep(200);
  // chassis.turn_to_angle(115);

  // // middle rings
  // chassis.drive_distance(12);

  // chassis.drive_distance(-20, 0, 10, 0, 1.5, 100, 400, 1.5, 0, 22, 0, 0, 0, 0, 0);
  chassis.drive_distance(-40, 0, 5, 0, 1.5, 100, 3000, 1.5, 0, 22, 0, 0, 0, 0, 0);
  armToScore = false;
  armToStartPos = true;
  Clamp.set(1);
  task::sleep(50);
  chassis.turn_to_angle(117);
  chassis.drive_distance(14);

  task::sleep(100);
  chassis.drive_max_voltage = 8;
  chassis.drive_distance(8);
  chassis.turn_timeout = 350;
  chassis.turn_to_angle(130);
  chassis.turn_timeout = 2000;
  task::sleep(100);
  convDir = BACKWARD;

  // middle rings
  chassis.drive_max_voltage = 10;
  chassis.drive_distance(-40);
  convDir = FORWARD;
  task::sleep(250);
  chassis.turn_to_angle(112);
  default_constants();

  // score rings
  chassis.turn_timeout = 600;
  chassis.drive_distance(14);
  chassis.turn_to_angle(210);
  chassis.drive_distance(20);
  chassis.turn_to_angle(255);
  chassis.drive_distance(16);

  // corner
  chassis.turn_to_angle(-50);
  convDir = FORWARD;
  chassis.drive_max_voltage = 6;
  chassis.drive_timeout = 1600;
  chassis.drive_distance(44); // 32
  // chassis.turn_to_angle(-70);
  doAntiJam = false;
  // chassis.drive_timeout = 500;
  // chassis.drive_side_distance(20, 12, 1.5, 0, 20, 0, 1.5, 0, 20, 0);
  // task::sleep(500);
  chassis.drive_max_voltage = 4;
  chassis.drive_distance(-8);
  doAntiJam = true;
  chassis.drive_timeout = 500;
  doAntiJam = false;
  chassis.drive_distance(20);
  doAntiJam = true;
  chassis.drive_distance(-8);
  doAntiJam = false;
  chassis.drive_distance(20);
  doAntiJam = true;
  chassis.drive_distance(-8);
}

void gre_six()
{
  chassis.set_drive_constants(12, 1.5, 0, 10, 0);
  chassis.set_turn_constants(8, .8, 0.03, 6, 15);

  chassis.drive_settle_error = 0.5;
  chassis.drive_distance(10);
  chassis.drive_settle_error = 1.5;
  armToScorePos = true;
  task::sleep(400);

  chassis.drive_distance(-37, 0, 5, 0, 1.5, 100, 3000, 1.5, 0, 22, 0, 0, 0, 0, 0);
  armToScore = false;
  armToStartPos = true;
  Clamp.set(1);
  task::sleep(50);
  chassis.turn_to_angle(117);
  chassis.drive_distance(14, chassis.get_absolute_heading(), 4.5);

  task::sleep(100);
  chassis.drive_max_voltage = 8;
  chassis.drive_distance(8);
  chassis.turn_timeout = 350;
  chassis.turn_to_angle(130);
  chassis.turn_timeout = 2000;
  task::sleep(100);
  convDir = BACKWARD;

  // middle rings
  chassis.drive_max_voltage = 10;
  chassis.drive_distance(-40);
  convDir = FORWARD;
  task::sleep(250);

  chassis.turn_to_angle(112);
  default_constants();

  // score rings
  chassis.turn_timeout = 600;
  chassis.drive_distance(14);
  chassis.turn_to_angle(210);
  chassis.drive_distance(20);
  chassis.turn_to_angle(255);
  chassis.drive_distance(19);

  // corner
  chassis.turn_to_angle(-50);
  convDir = FORWARD;
  chassis.drive_max_voltage = 12;
  chassis.drive_timeout = 1600;
  chassis.drive_distance(40); // 32
  chassis.drive_timeout = 600;
  chassis.drive_side_distance(20, 4.5, 1.5, 0, 20, 0, 1.5, 0, 20, 0);
  // chassis.turn_to_angle(-70);
  doAntiJam = false;
  chassis.drive_timeout = 500;
  // 
  // task::sleep(500);
  chassis.drive_max_voltage = 4;
  chassis.drive_distance(-16);
  chassis.drive_timeout = 750;
  chassis.drive_distance(18);
  chassis.drive_timeout = 750;
  chassis.drive_distance(-16);
  chassis.drive_distance(18);
  chassis.drive_timeout = 750;
  chassis.drive_distance(-16);
  doAntiJam = true;
  chassis.turn_to_angle(160);
  Clamp.set(0);
  chassis.drive_max_voltage = 8;
  armToStartPos = false;
  armToScorePos = true;
  chassis.drive_distance(40);
  armToLow = true;
  armToScorePos = false;
}

void gbe_six() {
  chassis.set_drive_constants(12, 1.5, 0, 10, 0);
  chassis.set_turn_constants(8, .8, 0.03, 6, 15);

  chassis.drive_settle_error = 0.5;
  chassis.drive_distance(10);
  chassis.drive_settle_error = 1.5;
  armToScorePos = true;
  task::sleep(400);

  chassis.drive_distance(-40, 0, 5, 0, 1.5, 100, 3000, 1.5, 0, 22, 0, 0, 0, 0, 0);
  armToScore = false;
  armToStartPos = true;
  Clamp.set(1);
  task::sleep(50);
  chassis.turn_to_angle(-113);
  chassis.drive_distance(14, chassis.get_absolute_heading(), 4.5);

  task::sleep(100);
  chassis.drive_max_voltage = 8;
  chassis.drive_distance(8);
  chassis.turn_timeout = 350;
  chassis.turn_to_angle(-130);
  chassis.turn_timeout = 2000;
  task::sleep(100);
  convDir = BACKWARD;

  // middle rings
  chassis.drive_max_voltage = 10;
  chassis.drive_distance(-40);
  convDir = FORWARD;
  task::sleep(250);

  chassis.turn_to_angle(-112);
  default_constants();

  // score rings
  chassis.turn_timeout = 600;
  chassis.drive_distance(14);
  chassis.turn_to_angle(-210);
  chassis.drive_distance(20);
  chassis.turn_to_angle(-255);
  chassis.drive_distance(19);

  // corner
  chassis.turn_to_angle(50);
  convDir = FORWARD;
  chassis.drive_max_voltage = 12;
  chassis.drive_timeout = 1600;
  chassis.drive_distance(40); // 32
  chassis.drive_timeout = 400;
  chassis.drive_side_distance(20, 4.5, 1.5, 0, 20, 0, 1.5, 0, 20, 0);
  // chassis.turn_to_angle(-70);
  doAntiJam = false;
  chassis.drive_timeout = 500;
  // 
  // task::sleep(500);
  chassis.drive_max_voltage = 4;
  chassis.drive_distance(-16);
  chassis.drive_timeout = 750;
  chassis.drive_distance(18);
  chassis.drive_timeout = 750;
  chassis.drive_distance(-16);
  chassis.drive_distance(18);
  chassis.drive_timeout = 750;
  chassis.drive_distance(-16);
  doAntiJam = true;
  chassis.turn_to_angle(-160);
  Clamp.set(0);
  chassis.drive_max_voltage = 8;
  armToStartPos = false;
  armToScorePos = true;
  chassis.drive_distance(40);
  armToLow = true;
  armToScorePos = false;
}

void gbe_five()
{
  chassis.set_drive_constants(9, 1.5, 0, 22, 0);
  chassis.drive_distance(40);
  chassis.turn_to_angle(45);
  chassis.drive_distance(-25);
  task::sleep(500);
  //chassis.drive_distance(-20);
  Clamp.set(1);
  task::sleep(250);
  convDir = FORWARD;
  task::sleep(500);
  chassis.turn_to_angle(-130);
  chassis.drive_distance(20);
  chassis.turn_to_angle(180);


  chassis.drive_max_voltage = 12;
  chassis.drive_timeout = 1600;
  chassis.drive_distance(40); // 32
  chassis.drive_timeout = 400;
  chassis.drive_side_distance(20, 4.5, 1.5, 0, 20, 0, 1.5, 0, 20, 0);

  doAntiJam = false;
  chassis.drive_timeout = 500;
  // 
  // task::sleep(500);
  chassis.drive_max_voltage = 4;
  chassis.drive_distance(-16);
  chassis.drive_timeout = 750;
  chassis.drive_distance(18);
  chassis.drive_timeout = 750;
  chassis.drive_distance(-16);
  chassis.drive_distance(18);
  chassis.drive_timeout = 750;
  chassis.drive_distance(-16);
}

void grq_four()
{
  chassis.set_drive_constants(8, 1.5, 0, 10, 0);
  chassis.drive_settle_error = 0.5;
  // chassis.drive_distance(10);
  // chassis.drive_settle_error = 1.5;
  // armToScorePos = true;
  // task::sleep(400);

  chassis.drive_distance(-37, 0, 6, 0, 1.5, 100, 1300, 1.2, 0, 21, 0, 0, 0, 0, 0);
  armToScorePos = false;
  armToStartPos = true;
  Clamp.set(1);
  task::sleep(50);
  chassis.turn_to_angle(30);
  convDir = FORWARD;
  chassis.drive_distance(36);
  chassis.drive_distance(-30); // -28`````````````````````````````````````````````````````````````````````````````````````

  chassis.turn_to_angle(120);
  convDir = STOP;

  // middle rings
  chassis.drive_distance(12, chassis.get_absolute_heading(), 4.5);
  task::sleep(100);
  chassis.drive_max_voltage = 8;
  chassis.drive_distance(5);
  chassis.turn_timeout = 350;
  chassis.turn_to_angle(130);
  chassis.turn_timeout = 2000;
  task::sleep(100);
  convDir = BACKWARD;

  chassis.drive_max_voltage = 8;
  chassis.drive_distance(-40);
  convDir = FORWARD;
  task::sleep(250);
  chassis.turn_to_angle(110);

  convDir = FORWARD;
  chassis.drive_min_voltage = 10;
  chassis.drive_distance(10); // 18
  chassis.drive_min_voltage = 0;
  convDir = FORWARD;
  chassis.swing_timeout = 1000;
  chassis.left_swing_to_angle(240);
  convDir = FORWARD;
  chassis.drive_max_voltage = 6;
  chassis.drive_distance(34);
  task::sleep(500);

  chassis.drive_distance(-30);
  chassis.turn_to_angle(110);
  armToLow = true;
  armToStartPos = false;
  task::sleep(500);
}

void gbq_four()
{
  chassis.set_drive_constants(8, 1.5, 0, 10, 0);
  chassis.drive_settle_error = 0.5;
  chassis.drive_distance(10);
  chassis.drive_settle_error = 1.5;
  armToScorePos = true;
  task::sleep(400);

  chassis.drive_distance(-47, 0, 6, 0, 1.5, 100, 1300, 1.2, 0, 21, 0, 0, 0, 0, 0); // -47
  armToScorePos = false;
  armToStartPos = true;
  Clamp.set(1);
  task::sleep(50);
  chassis.turn_to_angle(-30);
  convDir = FORWARD;
  chassis.drive_distance(36);
  chassis.drive_distance(-26);

  chassis.turn_to_angle(-115);
  convDir = STOP;

  // middle rings
  chassis.drive_distance(12);
  task::sleep(100);
  chassis.drive_max_voltage = 8;
  chassis.drive_distance(5);
  chassis.turn_timeout = 350;
  chassis.turn_to_angle(-130);
  chassis.turn_timeout = 2000;
  task::sleep(100);
  convDir = BACKWARD;

  chassis.drive_max_voltage = 8;
  chassis.drive_distance(-40);
  convDir = FORWARD;
  task::sleep(250);
  chassis.turn_to_angle(-110);

  convDir = FORWARD;
  chassis.drive_min_voltage = 10;
  chassis.drive_distance(10); // 18
  chassis.drive_min_voltage = 0;
  convDir = FORWARD;
  chassis.swing_timeout = 1000;
  chassis.right_swing_to_angle(-240);
  convDir = FORWARD;
  chassis.drive_max_voltage = 6;
  chassis.drive_distance(34);

  // corner
  chassis.turn_to_angle(50);
  convDir = FORWARD;
  chassis.drive_max_voltage = 12;
  chassis.drive_timeout = 1600;
  chassis.drive_distance(34); // 32
  chassis.drive_timeout = 400;
  chassis.drive_side_distance(20, 4.5, 1.5, 0, 20, 0, 1.5, 0, 20, 0);
  // chassis.turn_to_angle(-70);
  doAntiJam = false;
  chassis.drive_timeout = 500;
  // 
  // task::sleep(500);
  chassis.drive_max_voltage = 4;
  chassis.drive_distance(-16);
  chassis.drive_timeout = 750;
  chassis.drive_distance(18);
  chassis.drive_timeout = 750;
  chassis.drive_distance(-16);
  chassis.drive_distance(18);
  chassis.drive_timeout = 750;
  chassis.drive_distance(-16);
  doAntiJam = true;
  chassis.turn_to_angle(-160);
  Clamp.set(0);
  chassis.drive_max_voltage = 8;
  armToStartPos = false;
  armToScorePos = true;
  chassis.drive_distance(40);
  armToLow = true;
  armToScorePos = false;
}

void drive_test()
{
  chassis.drive_distance(24, 90);
  task::sleep(1000);
  chassis.drive_distance(-24, 90);
  // chassis.drive_distance(8.4);
  // chassis.drive_distance(-4.2);
  // chassis.drive_distance(-8.4);
}

/**
 * The expected behavior is to return to the start angle, after making a complete turn.
 */

void turn_test()
{
  double S_LEFT = 0.815;
  double S_REAR = -4.759;

  double leftArc = 0;
  double rearArc = 0;

  LeftTrack.resetPosition();  // ADD THIS - reset before turning!
  RearTrack.resetPosition();  // ADD THIS

  // // chassis.turn_to_angle(0);
  chassis.turn_to_angle(90);
  Brain.Screen.clearScreen();
  Brain.Screen.printAt(5, 20, "JAR Template v1.2.0");
  Brain.Screen.printAt(5, 40, "Chassis Heading Reading:");
  Brain.Screen.printAt(5, 60, "%f", chassis.get_absolute_heading());

  Brain.Screen.printAt(5, 80, "Theoretical Left Arc:");
  Brain.Screen.printAt(5, 100, "%f", S_LEFT * chassis.get_absolute_heading() * 2*M_PI / 360); // radius
  Brain.Screen.printAt(5, 120, "Theoretical Rear Arc:");
  Brain.Screen.printAt(5, 140, "%f", S_REAR * chassis.get_absolute_heading() * 2*M_PI / 360); // RearTrack.position(degrees)*2*2*M_PI/360

  leftArc = (LeftTrack.position(degrees) * 2.75 * 2*M_PI / 360);
  rearArc = (RearTrack.position(degrees) * 2.00 * 2*M_PI / 360);

  Brain.Screen.printAt(5, 160, "Actual Left Arc:");
  Brain.Screen.printAt(5, 180, "%f", leftArc);
  Brain.Screen.printAt(5, 200, "Actual Rear Arc:");
  Brain.Screen.printAt(5, 220, "%f", rearArc);
}

/**
 * Should swing in a fun S shape.
 */

void swing_test()
{
  chassis.right_swing_to_angle(-90);
  chassis.right_swing_to_angle(0);
}

/**
 * A little of this, a little of that; it should end roughly where it started.
 */

void full_test()
{
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

/**
 * Doesn't drive the robot, but just prints coordinates to the Brain screen
 * so you can check if they are accurate to life. Push the robot around and
 * see if the coordinates increase like you'd expect.
 */

void odom_test()
{
  chassis.set_coordinates(0, 0, 0);
  while (1)
  {
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5, 20, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(5, 40, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(5, 60, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5, 80, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(5, 100, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

/**
 * Should end in the same place it began, but the second movement
 * will be curved while the first is straight.
 */

void tank_odom_test()
{
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24, 24);
  chassis.drive_to_point(0, 0);
  chassis.turn_to_angle(0);
}

/**
 * Drives in a square while making a full turn in the process. Should
 * end where it started.
 */

void holonomic_odom_test()
{
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_pose(0, 18, 90);
  chassis.holonomic_drive_to_pose(18, 0, 180);
  chassis.holonomic_drive_to_pose(0, 18, 270);
  chassis.holonomic_drive_to_pose(0, 0, 0);
}