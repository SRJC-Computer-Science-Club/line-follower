#include "LineFollower.h"
#include "SensorArray.h"

namespace LFRobot
{
	LineFollower::LineFollower()
	{
		sensorArray = new SensorArray(PIN_SENSORS, N_SENSORS, MICROS_WHITE, MICROS_BLACK, MICROS_TIMEOUT);
		motors = new MotorPair();
	}

	LineFollower::~LineFollower()
	{
		delete sensorArray;
		delete motors;
	}

	void LineFollower::followLine()
	{
		while (true)
		{
			float error = sensorArray->getLineOffset();

			motors->moveForward(.7f, 1.2f*error);
		}
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
