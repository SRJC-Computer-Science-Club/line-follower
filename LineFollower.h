#pragma once

#include "Constants.h"
#include "SensorArray.h"
#include "MotorPair.h"

namespace LFRobot
{
	class LineFollower
	{
	public:
		LineFollower();
		~LineFollower();

		void followLine();

		void testSensorArray();
	private:
		//Returns the time in ms since the last time getDeltaTime() or the constructor was called.
		float getDeltaTime();

		//The time in us when getDeltaTime() or the constructor was last called.
		long prevTime;

		SensorArray* sensorArray;
		MotorPair* motors;

		float speed = SPEED_MIN;
	};
}
