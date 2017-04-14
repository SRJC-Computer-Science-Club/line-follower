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
		SensorArray* sensorArray;
		MotorPair* motors;
	};
}
