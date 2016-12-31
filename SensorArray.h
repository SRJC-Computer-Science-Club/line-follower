#pragma once

#include "Sensor.h"


namespace LFRobot
{

	class SensorArray
	{
	public:

		SensorArray(int pins[]);
		void prepSensors();


	private:
		int pins[];

	};

}
