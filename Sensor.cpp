#include <Sensor.h>

namespace LFRobot
{
	Sensor::Sensor(int inPin)
		: pin(inPin) // pin is given the value of the argument
	{
		pinMode(pin, INPUT);

	}

	void Sensor::setMode(SensorMode mode)
	{
		if (mode == OUT)
		{
			pinMode(pin, OUTPUT);
			digitalWrite(pin, HIGH);
		}
		if (mode == IN)
		{
			pinMode(pin, INPUT);
		}
	}

	bool Sensor::isLow()
	{
		// returns false if not LOW
		return digitalRead(pin) == LOW;

	}
}