#include "MotorPair.h"



MotorPair::MotorPair()
{
	left = new motor();
	right = new motor();
}


MotorPair::~MotorPair()
{
	delete left, right;
}


void MotorPair::moveForward(float speed, float offset)
{
	left->setSpeed((1 + speed)*offset + speed);
	right->setSpeed(-(1 + speed)*offset + speed);
}