// Define the TRIG and ECHO pins used by the ultrasonic sensor, in my case they were pins 4 and 5.
#define TRIG 4
#define ECHO 5

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Set up pins
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(13, OUTPUT);
}


// Uses an ultrasonic sensor to get the measured distance in millimeters
// TRIG and ECHO must be defined, it also blinks the pin 13 LED for pulse duration
unsigned long getDistance() {
  unsigned long t, t_start;
  
  // Flush sensor LOW for a second
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  
  // Pulse for 10 us
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  // Wait until echo signal is up.
  while (digitalRead(ECHO) == LOW) {}
  
  // Measure echo signal uptime in microseconds. Also blink LED pin 13 during
  t_start = micros();
  digitalWrite(13, HIGH);
  while(digitalRead(ECHO) == HIGH) {}
  digitalWrite(13, LOW);
  
  // Duration in microseconds
  t = micros() - t_start;
  
  // Distance in meters = (duration in seconds) * (speed of sound m/s) / 2
  // Distance in cm = (t * 1e-6) * (340 * 1e2) / 2 = t * 17/1000
  // Distance in millimeters = (t * 1e-6) * (340 * 1e3) / 2 = t * 17/100
  
  // Return distance in mm, sensor is supposedly accurate to 0.3cm = 3mm
  return t * 17 / 100;
}

unsigned long prev = 0;
void loop() {
  // Take an ultrasonic reading every second. Results in mm
  unsigned long dist = getDistance();
  
  // Low-pass filter it
  dist = constrain(dist, 0, 4000);
  signed long diff = (signed long)dist - (signed long)prev;
  dist = (unsigned long)(prev + diff * 3 / 10);
  prev = dist;
  
  Serial.println(dist);
  delay(10);
}
