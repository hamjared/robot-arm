// 
// 
// 

#include "RobotArmApi.h"
#include <WebServer.h>
#include "ServoWrapper.h"

extern WebServer server;
extern ServoWrapper servo;
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
