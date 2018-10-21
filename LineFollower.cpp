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
		

		//was ((1.0f, 0.0f, 10.0f)
		PIDController controller(0.8f, 0.0f, 12.0f);

		controller.start(0);

		while (true)
		{
			float error = sensorArray->getLineOffset();

			/*if (error == 2 || error == -2)
			{
				if (error == 2)
				{
					digitalWrite(PIN_MOTOR_RIGHT_FORWARD, LOW);
					digitalWrite(PIN_MOTOR_RIGHT_BACKWARD, HIGH);


					analogWrite(PIN_MOTOR_RIGHT_PWM, 255);

					digitalWrite(PIN_MOTOR_LEFT_FORWARD, HIGH);
					digitalWrite(PIN_MOTOR_LEFT_BACKWARD, HIGH);


				}
			}
			else {*/

				float correction = controller.getCorrection(error);

				motors->moveForward(ROBOT_SPEED, correction);
			}
		//}
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
