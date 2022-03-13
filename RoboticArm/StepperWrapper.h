// StepperWrapper.h

#ifndef _StepperWrapper_h
#define _StepperWrapper_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class StepperWrapper
{
private:
	double gear_ratio;
 protected:


 public:
	void init();
};


#endif

