/*
  RadarOrientationControl.h - Library for getting sweeping radar servo back/forth for scanning.
  Created by Sameer Ansari, Aug 26, 2013.
  Released into public domain.
*/
#ifndef RADAR_ORIENTATION_CONTROL_H
#define RADAR_ORIENTATION_CONTROL_H

#include "Arduino.h"
#include <Servo.h>

class RadarOrientationControl {
public: 
  int radar_pos;
  RadarOrientationControl(int servo_pin,
                          int pos_min,
                          int pos_max,
                          int pos_step);
  void init();
  int getPosition();
  void update();

private:
  int _servo_pin, radar_dir, _pos_min, _pos_max, _step;
  Servo servo;
};

#endif
