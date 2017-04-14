#pragma once
<<<<<<< HEAD

#include "motor_class.h"

class MotorPair
{
	motor *left, *right;
public:
	MotorPair();
	~MotorPair();
	void moveForward(float speed, float offset);
};

=======
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



	
>>>>>>> refs/remotes/origin/dev
