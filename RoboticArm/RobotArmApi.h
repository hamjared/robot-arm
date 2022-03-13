// RobotArmApi.h

#ifndef _ROBOTARMAPI_h
#define _ROBOTARMAPI_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif



void getStatus();
void setServo1Angle();

#endif

