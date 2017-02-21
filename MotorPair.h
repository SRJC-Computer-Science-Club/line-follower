#pragma once

#include "motor_class.h"

class MotorPair
{
	motor left, right;
public:
	MotorPair();
	~MotorPair();
	void moveForward(float speed, float offset);
};
