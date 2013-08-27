/*
  RadarOrientationControl.h - Library for getting sweeping radar servo back/forth for scanning.
  Created by Sameer Ansari, Aug 26, 2013.
  Released into public domain.
*/
#include "RadarOrientationControl.h"
// Initialize servo and range it will travel.
RadarOrientationControl::RadarOrientationControl(int servo_pin,
                                                 int pos_min,
                                                 int pos_max,
                                                 int pos_step) {
  _servo_pin = servo_pin;
  _pos_min = pos_min;
  _pos_max = pos_max;
  _step = pos_step;

  radar_pos = pos_min;
  radar_dir = 1;
};

void RadarOrientationControl::init() {
  // Set up servo
  servo.attach(_servo_pin);
  // Initialize at minimum position.
  servo.write(_pos_min);
}

// Returns current radar position.
int RadarOrientationControl::getPosition() {
  return radar_pos;
}

// Move servo back and forth along the scan range.
void RadarOrientationControl::update() {
  if (radar_pos <= _pos_min) { radar_dir = 1; }
  else if (radar_pos >= _pos_max) { radar_dir = -1; }
  radar_pos += radar_dir*_step;
  // Serial.println(radar_pos);
  servo.write(radar_pos);
  delay(50);
};
