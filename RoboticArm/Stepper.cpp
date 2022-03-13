// 
// 
// 

#include "Stepper.h"

#define DEFAULT_TIME_BETWEEN_STEPS_MILLISECONDS 50

Stepper::Stepper(int dir_pin, int step_pin):
	dir_pin{dir_pin},
	step_pin{step_pin},
	DEGREES_PER_STEP{ 1.8 },
	time_between_steps{DEFAULT_TIME_BETWEEN_STEPS_MILLISECONDS}
{
}

Stepper::Stepper(int dir_pin, int step_pin, double degrees_per_step):
	dir_pin{ dir_pin },
	step_pin{ step_pin },
	DEGREES_PER_STEP{degrees_per_step},
	time_between_steps{ DEFAULT_TIME_BETWEEN_STEPS_MILLISECONDS }
{
}

void Stepper::init()
{
	pinMode(dir_pin, OUTPUT);
	pinMode(step_pin, OUTPUT);

	steps_to_perform = 0;
	last_step_time = 0;
}

void Stepper::update()
{
	if (steps_to_perform == 0) {
		return;
	}

	// check if we have waited long enough since the last step
	if ((millis() - last_step_time) < time_between_steps) {
		return;
	}

	Direction direction = steps_to_perform > 0 ? CW : CCW;
	step(direction);
}

void Stepper::rotate(int deg, Direction direction)
{
	rotate((double)deg, direction);
}

void Stepper::rotate(double deg, Direction direction)
{
	int steps = (int) (deg / DEGREES_PER_STEP);
	steps_to_perform = direction == CW ? steps : -1 * steps;
	update();
}

void Stepper::step(Direction direction)
{
	int dir_output = direction == CW ? HIGH : LOW;
	digitalWrite(dir_pin, dir_output);
	digitalWrite(step_pin, HIGH);
	delayMicroseconds(2);
	digitalWrite(step_pin, LOW);
	if (direction == CW) {
		steps_to_perform--;
	}
	else {
		steps_to_perform++;
	}
	last_step_time = millis();
}





