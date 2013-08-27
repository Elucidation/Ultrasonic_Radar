// Define the TRIG and ECHO pins used by the ultrasonic sensor, in my case they were pins 4 and 5.
#define TRIG 4
#define ECHO 5
#define SERVO_PIN 3

#include <Servo.h>
Servo sv;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Set up pins
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(13, OUTPUT);
  
  // Set up servo
  sv.attach(SERVO_PIN);
  sv.write(90);
  delay(1000);
  sv.write(45);
  delay(100);
}


// Uses an ultrasonic sensor to get the measured distance in millimeters
// TRIG and ECHO must be defined, it also blinks the pin 13 LED for pulse duration
int getDistance() {
  unsigned long t, t_start, c;
  
  // Flush sensor LOW for a second
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  
  // Pulse for 10 us
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  // Wait until echo signal is up.
  c = 0;
  while (digitalRead(ECHO) == LOW && c++ < 10000) {}
  
  // Measure echo signal uptime in microseconds. Also blink LED pin 13 during
  c = 0;
  t_start = micros();
  digitalWrite(13, HIGH);
  while(digitalRead(ECHO) == HIGH && c++ < 10000) {}
  digitalWrite(13, LOW);
  
  // Duration in microseconds
  t = micros() - t_start;
  
  // Distance in meters = (duration in seconds) * (speed of sound m/s) / 2
  // Distance in cm = (t * 1e-6) * (340 * 1e2) / 2 = t * 17/1000
  // Distance in millimeters = (t * 1e-6) * (340 * 1e3) / 2 = t * 17/100
  
  // Return distance in mm, sensor is supposedly accurate to 0.3cm = 3mm
  return t * 17 / 100;
}

int pos = 45;
int dir = 1;
void loop() {
  if (pos <= 0) { dir = 1; }
  else if (pos >= 180) { dir = -1; }
  pos = pos + 1 * dir;
  sv.write(pos);
  delay(25);
  
  int dist = getDistance();
  Serial.print(pos);
  Serial.print(" ");
  Serial.println(dist);
  //delay(10);
}
