#pragma once
#include "Motor.h"

class MotorPair
{
public:
	MotorPair();
	void moveForword(float speed, float turning);

private:
	Motor leftMotor;
	Motor rightMotor;
};



