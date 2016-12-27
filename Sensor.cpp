#include <Sensor.h>

namespace LFRobot
{
	Sensor::Sensor(int inPin)
	{
		pin = inPin;
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
		if (digitalRead(pin) == LOW)
		{
			return true;
		}
	}
}