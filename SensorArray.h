#pragma once

#include <Arduino.h>
#include "Sensor.h"
#include "Constants.h"
#include "AveragingQueue.h"

using namespace std;

namespace LFRobot
{
	class SensorArray
	{
	public:

		SensorArray(const int pins[], const int nSensors, const long microsWhite[], const long microsBlack[], const long MICROS_TIMEOUT = 10000);
		~SensorArray();
		float getLineOffset();
	

	private:
		void prepSensors();
		void readSensorValues();
		float mapMicrosToValue(int i, long lenTime);
		AveragingQueue<float> lineData = AveragingQueue<float>(VALUES_STORED);

		Sensor** sensors;
		long* sensorValues;

		const int nSensors;

		long* microsWhite;
		long* microsBlack;

		const long MICROS_TIMEOUT;
	};

}
