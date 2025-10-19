#include "vex.h"
#include "robot-config.h"

ConveyorDirection_e convDir = STOP;
int convVelocity            = 0;
int armTimeout              = 0;
int jamTimeout              = 0;
bool doColorSort            = false;
bool doAntiJam              = false;
bool armToLoadPos           = false;
bool armToStartPos          = false;
bool armToScorePos          = false;
bool armToScore             = false;
bool armToLow               = false;
bool armToScoreTwo          = false;
bool armToScoreThree          = false;

// 210 for blue
// 20 for red
const int SORT_COLOUR = 20;



int debugLoop(void *params) {
  uint32_t now = Brain.Timer.time(msec);

  while(1){
    task::sleep(20);
  }

  return 0;
}

int conveyorLoop() {
  uint32_t now = Brain.Timer.time(msec);
  int jamcount = 0;
  ColSort.setLight(ledState::on);
  while (true) {
    if (convDir == ConveyorDirection_e::FORWARD) 
    {
      if (ColSort.hue() > SORT_COLOUR - 20 && ColSort.hue() < SORT_COLOUR + 20 && doColorSort && ColSort.isNearObject()){ //  && 
        jamcount = 0;
        task::sleep(125);
        hIntake.spin(directionType::rev, 12, volt);
        task::sleep(300);
        hIntake.spin(fwd, 12, volt);
      }
      //red or not detected
      else if (fabs(hIntake.torque())>=1.0 && fabs(hIntake.velocity(rpm)) <= 1 && doAntiJam){
        jamcount++;
        task::sleep(10);
        if (jamcount>10){
          hIntake.spin(directionType::rev, 12, volt);
          task::sleep(100);
          hIntake.spin(fwd, 12, volt);
          
        }
      } 
      else { // change if (1) to else
        jamcount = 0;
        hIntake.spin(fwd, 12, volt);
      }
    } 
    else if (convDir == BACKWARD) 
    {
      hIntake.spin(directionType::rev, 12, volt);
    } 
    else 
    {
      hIntake.spin(fwd, 0, volt);
    }

    task::sleep(1);
  }

  return 0;
}

int armLoop() {
  uint32_t now = Brain.Timer.time(msec);

  while (true) {
    // Arm control removed

    task::sleep(1);
  }

  return 0;
}