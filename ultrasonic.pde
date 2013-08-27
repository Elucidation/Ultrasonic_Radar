import processing.serial.*;

int xspacing = 8;   // How far apart should each horizontal location be spaced
int w;              // Width of entire wave
int maxwaves = 4;   // total # of waves to add together

float[] yvalues;                           // Using an array to store height values for the wave (not entirely necessary)

Serial port;

void setup() {
  size(640, 360);
  frameRate(30);
  colorMode(RGB, 255, 255, 255, 100);
  w = width + 16;
  yvalues = new float[w/xspacing];
  // Set all height values to zero
  for (int i = 0; i < yvalues.length; i++) {
    yvalues[i] = 0;
  }

  // Set up serial port
  println(Serial.list());
  if (Serial.list().length > 0) {
    port = new Serial(this, Serial.list()[0], 9600);
    port.bufferUntil('\n');
  } 
  else {
    port = null;
  }
}

void draw() {
  background(0);
  renderWave();
}

void serialEvent(Serial port) {
  String s = port.readStringUntil('\n');
  if (s != null) {
    float measured_val = float(trim(s));
    measured_val = map(measured_val, 0, 1000, 0, height);

    // Shift array down one
    for (int i = 0; i < yvalues.length-1; i++) {
      yvalues[i] = yvalues[i+1];
    }

    // Set next measured value
    yvalues[yvalues.length-1] = measured_val;
  }
}

void renderWave() {
  // A simple way to draw the wave with an ellipse at each location
  noStroke();
  fill(255, 50);
  ellipseMode(CENTER);
  for (int x = 0; x < yvalues.length; x++) {
    ellipse(x*xspacing, height-yvalues[x], 8, 8);
  }
}

