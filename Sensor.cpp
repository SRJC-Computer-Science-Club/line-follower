#include "Sensor.h"
#include "Arduino.h"
namespace LFRobot
{
	Sensor::Sensor(int inPin, float inPosition)
		: pin(inPin), position(inPosition)
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
		return digitalRead(pin) == LOW; 
		
	}

	float Sensor::getPosition()
	{
		return position;
	}
}