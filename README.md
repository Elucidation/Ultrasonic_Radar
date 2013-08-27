Ultrasonic Radar scanning with hobby equipment
---
Having a go at seeing how well an arduino, a servo, and 2 ultrasonic sensors can get at generating maps of the environment.
This is for testing the viability of cheap localization using particle filters on pre-computed maps.
Even without a low-pass filter, the data is usable, here is a partial scan of the kitchen.
![Imgur](http://i.imgur.com/abyPgFH.png)
![Imgur](http://i.imgur.com/yHH4N0P.png)


The setup is pretty straightforward:
2 ultrasonic sensors facing in opposite directions are placed on a breadboard.
The breadboard is placed on a servo, which since it's a cheap one can only turn about 130 degrees, that'll give us 260 degrees of scan with 2 blind spots.
![Imgur](http://i.imgur.com/jbBMUz5.png)

The program is pretty much:
```
loop() {
  left = sensor_left.getReading();
  right = sensor_right.getReading();

  print out position and sensor data
  
  servo_controller.update(); 
}
```

Here's a picture with just one sensor.
![Imgur](http://i.imgur.com/LXJOIuC.png)
![Imgur](http://i.imgur.com/2s2sfuV.png)

Here's the 2 sensor setup.
![Imgur](http://i.imgur.com/MEwrOy5.png)

Housed the motor in a little box with some weights, and found some foam padding to provide a little support for the turning breadboard. I also used some poster putty to hold the board to the servo.
![Imgur](http://i.imgur.com/DR9j3Hr.png)
![Imgur](http://i.imgur.com/d8wNUdt.png)
![Imgur](http://i.imgur.com/ZoXTbn5.png)

Set up the scanner in the kitchen, once this system actually works, the arduino and rf link will be housed in the center of a robot with 8 ultrasound sensors arrayed around it, for now the wires and things are in the way.
![Imgur](http://i.imgur.com/abyPgFH.png)
![Imgur](http://i.imgur.com/T2lwSg6.png)
![Imgur](http://i.imgur.com/yzZiVXr.png)
![Imgur](http://i.imgur.com/PMibB54.png)

A few scans show that there's pretty consistent readings even with varying scan speeds and motor step sizes. I settled on a roughly ~50ms scan step time and increment servo position by one each time, back and forth.
![Imgur](http://i.imgur.com/LA2pInw.png)
![Imgur](http://i.imgur.com/2YI363S.png)

You can kind of see the kitchen forming here, a guess as to why the walls are not getting straight sides, is that the sonar will pick up the first echo as the distance, so for walls angled to the sensor, even if it's center is facing the angled wall at distance X, the closest point of the wall within a small cone radiating out from the sensor is the first to echo back, resulting in that as the reading.

![Imgur](http://i.imgur.com/9ekR5X8.png)
![Imgur](http://i.imgur.com/8SEKVcw.png)
![Imgur](http://i.imgur.com/G6nVygL.png)