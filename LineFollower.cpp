#include "LineFollower.h"
#include "SensorArray.h"
#include "PIDController.h"


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
		PIDController controller(1.0f, 0.0f, 10.0f);

		controller.start(0);

		while (true)
		{
			float error = sensorArray->getLineOffset();

			float correction = controller.getCorrection(error);

			motors->moveForward(ROBOT_SPEED, correction);
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
