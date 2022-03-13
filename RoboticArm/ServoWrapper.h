// ServoWrapper.h

#ifndef _ServoWrapper_h
#define _ServoWrapper_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#include <ESP32_Servo.h>

#define DEFAULT_MICRO_SECONDS_LOW 1000
#define DEFAULT_MICRO_SECONDS_HIGH 2000
#define DEFAULT_SERVO_MIN_DEGREES -45
#define DEFAULT_SERVO_MAX_DEGREES 45


class ServoWrapper{
private:
	Servo servo;
	int pin;
	int microSecondsLow;
	int microSecondsHigh;
	int servoMinDegrees;
	int servoMaxDegrees;

 public:
	 ServoWrapper(int pin);
	 void moveToAbsoluteAngleDegrees(int angleDegrees);
	 void moveByAngleDegrees(int degrees, int direction);
	 void writeMicroSeconds(int microSeconds);
	 void stopMoving();
	 void init();
};


#endif

