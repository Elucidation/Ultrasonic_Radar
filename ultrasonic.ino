#include <ultrasonic.h>

// Initialize ultrasonic sensors.
Ultrasonic sensor_left(2,3);
Ultrasonic sensor_right(5,6);

void setup() {
  // Initialize serial communication.
  Serial.begin(9600);
  Serial.println("Start");
}

void loop() {
  unsigned int left = (unsigned int)sensor_left.getReading();
  // Wait fo 25 ms, which is roughly how long sound at sea-level takes to travel 8m.
  // 8m being roundtrip time within sensor range, sounds beyond are considered too dispersed since sensors max effective range is 4m.
  delay(25);
  unsigned int right = (unsigned int)sensor_right.getReading();
  Serial.print(left);
  Serial.print(" ");
  Serial.println(right);
  delay(25);
}
