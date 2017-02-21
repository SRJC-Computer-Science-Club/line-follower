#include "MotorPair.h"



MotorPair::MotorPair()
{
	left = motor();
	right = motor();
}


MotorPair::~MotorPair()
{
}


void MotorPair::moveForward(float speed, float offset)
{
	left->setSpeed((1 + speed)*offset + speed);
	right->setSpeed(-(1 + speed)*offset + speed);
}
