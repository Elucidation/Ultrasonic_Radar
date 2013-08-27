#include <ultrasonic.h>
#include <RadarOrientationControl.h>
#include <Servo.h>

Ultrasonic sensor_left(2,3);
Ultrasonic sensor_right(5,6);

// Initialize servo.
RadarOrientationControl radar_control(9, 20, 155, 5);

void setup() {
  // Initialize serial communication.
  Serial.begin(9600);
  
  // Initialize ultrasonic sensors.
  sensor_left.init();
  sensor_right.init();
  Serial.println(" Ultrasonic sensors initialized.");
  
  // Init servos
  radar_control.init();
  Serial.println(" Radar Orientation Servo initialized.");
  
  Serial.println(" Start");
  Serial.println(" Position : Left_Sensor_Reading Right_Sensor_Reading");
  Serial.println(" ---------------------------------------------------");
}

void loop() {
  unsigned int left = (unsigned int)sensor_left.getReading();
  // Wait fo 25 ms, which is roughly how long sound at sea-level takes to travel 8m.
  // 8m being roundtrip time within sensor range, sounds beyond are considered too dispersed since sensors max effective range is 4m.
  delay(25);
  unsigned int right = (unsigned int)sensor_right.getReading();
  
  // Print information.
  Serial.print(radar_control.getPosition());
  Serial.print(" : ");
  Serial.print(left);
  Serial.print(" ");
  Serial.println(right);
  delay(25);
  
  // Update radar position.
  radar_control.update();
  delay(500);
}
