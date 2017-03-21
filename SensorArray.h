#pragma once

#include <Arduino.h>
#include "Sensor.h"

using namespace std;

namespace LFRobot
{
	const int NUMBER_OF_SENSORS = 8;
	class SensorArray
	{
	public:

		SensorArray(const int pins[]);
		~SensorArray();
		void prepSensors();
		void readSensorValues();
		float getLineOffset();
		void testingSensors(int values[]);
	

	private:
		Sensor* sensorArray[8];
		int pins[NUMBER_OF_SENSORS];
		int sensorValues[NUMBER_OF_SENSORS];

	};

}
