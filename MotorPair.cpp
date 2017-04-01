#include "MotorPair.h"


MotorPair::MotorPair()
	: rightMotor(PIN_MOTOR_RIGHT_FORWARD, PIN_MOTOR_RIGHT_BACKWARD, PIN_MOTOR_RIGHT_PWM), 
	leftMotor(PIN_MOTOR_LEFT_FORWARD, PIN_MOTOR_LEFT_BACKWARD, PIN_MOTOR_LEFT_PWM)
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