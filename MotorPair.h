#pragma once

#include "Motor.h"
#include "Constants.h"

class MotorPair
{
public:
	MotorPair();
	void moveForward(float speed, float turning);

private:
	Motor leftMotor;
	Motor rightMotor;
};



	
