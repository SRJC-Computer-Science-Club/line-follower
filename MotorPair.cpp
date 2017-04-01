#include "MotorPair.h"


MotorPair::MotorPair()
	: leftMotor(8, 9, 10), rightMotor(5, 6, 4)
{

}

void MotorPair::moveForword(float speed, float turning)
{
	turning = turning > 2 ? 2 : turning;
	turning = turning < -2 ? -2 : turning;

	if (turning >= 0)
	{
		//Turn right!
		leftMotor.setSpeed(speed);
		rightMotor.setSpeed(speed * (1 - turning));
	}
	else
	{
		//Turn left!
		leftMotor.setSpeed(speed * (1 + turning));
		rightMotor.setSpeed(speed);
	}
}