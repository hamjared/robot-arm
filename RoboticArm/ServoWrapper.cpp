// 
// 
// 

#include "ServoWrapper.h"

ServoWrapper::ServoWrapper(int pin) : 
	pin{pin}, 
	microSecondsLow{DEFAULT_MICRO_SECONDS_LOW}, 
	microSecondsHigh{DEFAULT_MICRO_SECONDS_HIGH},
	servoMinDegrees{ DEFAULT_SERVO_MIN_DEGREES },
	servoMaxDegrees{DEFAULT_SERVO_MAX_DEGREES}
{
	
}

void ServoWrapper::moveToAbsoluteAngleDegrees(int angleDegrees)
{
	int microSeconds = map(angleDegrees, servoMinDegrees, servoMaxDegrees, microSecondsLow, microSecondsHigh);
	Serial.print("Writing servo to ");
	Serial.print(microSeconds);
	Serial.println();
	servo.write(microSeconds);
}

void ServoWrapper::moveByAngleDegrees(int degrees, int direction)
{
	
}

void ServoWrapper::writeMicroSeconds(int microSeconds)
{
	Serial.print("Writing servo to ");
	Serial.print(microSeconds);
	Serial.println();
	servo.writeMicroseconds(microSeconds);
}

void ServoWrapper::stopMoving()
{
	
}

void ServoWrapper::init()
{
	servo.attach(pin);
	moveToAbsoluteAngleDegrees(0);
}


