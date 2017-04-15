#include "LineFollower.h"
#include "SensorArray.h"
#include "PIDController.h"


namespace LFRobot
{
	LineFollower::LineFollower()
	{
		sensorArray = new SensorArray(PIN_SENSORS, N_SENSORS, MICROS_WHITE, MICROS_BLACK, MICROS_TIMEOUT);
		motors = new MotorPair();
		prevTime = micros();
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
			float deltaTime = getDeltaTime();

			float error = sensorArray->getLineOffset();

			// turning = |error|
			float turning = error >= 0 ? error : -error;
			
			if (turning >= ACCELERATION_POINT)
			{
				turning -= ACCELERATION_POINT;
				turning /= ACCELERATION_POINT - 1;
			}
			else
			{
				turning /= ACCELERATION_POINT;
			}

			speed += ACCELERATION * turning * deltaTime / 1000;
			
			// Clamp speed between SPEED_MIN and SPEED_MAX
			speed = speed < SPEED_MIN ? SPEED_MIN : speed;
			speed = speed > SPEED_MAX ? SPEED_MAX : speed;

			float correction = controller.getCorrection(error, 1);

			motors->moveForward(speed, correction);
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

	float LineFollower::getDeltaTime()
	{
		long currentTime = micros();
		float deltaTime = (currentTime - prevTime) / 1000.0f;
		prevTime = currentTime;

		//Converts us to ms and returns deltaTime
		return deltaTime;
	}
}
