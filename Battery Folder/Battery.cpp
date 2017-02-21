#include "Battery.h"



Battery::Battery()
{
	averageCounter = 0;
	powerAverage = 0;

	for (int i = 0; i < BATTERY_N_READINGS; i++)
	{
		batteryReading[i] = 0;
	}
}




Battery::bool checkBattery ()
{
	if (lastReading < BATTERY_MAX_DESCREPENCY)
	{
		return (readVoltage () < 400);
	}
}




Battery::void readVoltage ()
{
	lastReading = analog.read (pin);
}




Battery::double findAverage ()
{
	powerAverage += lastReading;
	internalCounter++;

	if (internalCounter == 9)
	{
		double averageHolder = powerAverage;
		powerAverage = 0;
		internalCounter = 0;

		return averageHolder;
	}
}
