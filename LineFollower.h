#pragma once

#include "Constants.h"
#include "SensorArray.h"

namespace LFRobot
{
	class LineFollower
	{
	public:
		LineFollower();

		void followLine();

		void testSensorArray();
	private:
		SensorArray* sensorArray;
	};
}
