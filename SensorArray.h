#pragma once
#include <vector>
#include "Sensor.h"

using namespace std;

namespace LFRobot
{
	const int NUMBER_OF_SENSORS = 8;
	class SensorArray
	{
	public:

		SensorArray();
		void prepSensors();


	private:
		int pins[NUMBER_OF_SENSORS];
		vector<Sensor*> sensors = vector<Sensor*>();

	};

}
