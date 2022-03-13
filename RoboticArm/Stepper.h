// Stepper.h

#ifndef _Stepper_h
#define _Stepper_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Stepper
{
public:
	enum Direction { CW, CCW };

	Stepper(int dir_pin, int step_pin);
	Stepper(int dir_pin, int step_pin, double degrees_per_step);

	void init();
	void update();
	void rotate(int deg, Direction direction);
	void rotate(double deg, Direction direction);

private:
	const double DEGREES_PER_STEP;

	int dir_pin;
	int step_pin;
	int steps_to_perform; // remaining steps to perform. < 1 --> CW, > 1 --> CCW, Follows the right hand rule

	int time_between_steps;
	long last_step_time;

	void step(Direction direction);




};

#endif

