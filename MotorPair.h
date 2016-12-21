#pragma once

#include "motor_class.h"

class MotorPair
{
	motor *left, *right;
public:
	MotorPair() {
		left = new motor();
		right = new motor();

	}
	~MotorPair();
	void moveForward(float speed, float offset) {
		left->setSpeed((1 + speed)*offset + speed);
		right->setSpeed(-(1 + speed)*offset + speed);

	}
};

