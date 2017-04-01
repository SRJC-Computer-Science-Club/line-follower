#include "LineFollower.h"
#include "SensorArray.h"

namespace LFRobot
{
	LineFollower::LineFollower()
	{
		sensorArray = new SensorArray(PIN_SENSORS, N_SENSORS, MICROS_WHITE, MICROS_BLACK, MICROS_TIMEOUT);
	}

	void LineFollower::followLine()
	{

	}

	void LineFollower::testSensorArray()
	{
		while (true)
		{
			Serial.println(sensorArray->getLineOffset());
			delay(100);
		}
	}
}
