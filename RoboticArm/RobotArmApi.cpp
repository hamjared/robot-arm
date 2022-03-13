// 
// 
// 

#include "RobotArmApi.h"
#include <WebServer.h>
#include "ServoWrapper.h"
#include "Stepper.h"


extern WebServer server;
extern ServoWrapper servo;
extern Stepper stepper;

void getStatus()
{
	Serial.println("status called");
	server.send(200, "text/plain", "OK");
	
}


void setServo1Angle() {
	Serial.println("setServoangle called");
	int angle = server.arg(0).toInt();
	servo.moveToAbsoluteAngleDegrees(angle);
	server.send(200, "text/plain", "OK");

}

void rotateStepper()
{
	Serial.println("rotate stepper called");
	int angle = server.arg(0).toDouble();
	stepper.rotate(angle, Stepper::Direction::CCW);
	server.send(200, "text/plain", "OK");
}

void getAllAxes()
{
	
}
