Lab-8
=====

A program that can run a robot through the maze using the left and front sensor

In this lab, the purpose was to implement the functionality required to move the robot with the use of the infrared sensors. The robots that we utilize have a set of three infrared (IR) emitter and detector pairs on them and are used to bring in analog voltage values for the ADC. The code that I wrote in this lab is used to interpret these incoming voltages to determine whether the robot is approaching a wall in front or on one of its sides and turn accordingly.

- initializePinOuts()
  * This method initialzies the pins on the robot to be utilized. This is to be called before the robot movement code.

- configureTimer()
  * This method sets the timer for the proper delays with the robot. This is to be called before the robot movement         code.

- moveRobotForward()
  * Because each motor is opposite the other, the code that moves each wheel is spposite the other. This method moves       the robot forward - how far is dependent on how long the delay is set using (__delay_cycles()).

- moveRobotBackward()
  * This method moves the robot backwards - how far is dependent on how long the delay is set using (__delay_cycles()).

- turnRobotLeft()
  * This method turns the robot left. The size of the turn is dependent on how long the delay is.

- turnRobotRight()
  * This method turns the robot right. The size of the turn is dependent on how long the delay is.

- stop()
  * This method stops the robot. The length of the stop is dependent on the chosen delay.

- initSensors()
  * This method enables the interrupt and sets the clock for the robot.

- frontSensor()
  * This method contains the functionality required to enage the sensor at the front of the robot.

- leftSensor()
  * This method contains the functionality required to enage the sensor on the left side of the robot.

- rightSensor()
  * This method contains the functionality required to enage the sensor on the right side of the robot.

An example of how to properly use the above methods can be seen in the file "example.c" in the Lab 8 repository.

