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




bool Battery::checkBattery ()
{
	return (findAverage () < 400);
}




void Battery::readVoltage ()
{
	float batteryOutput = analog.read (pin);

	reading.push (batteryOutput);
	readingsSum += batteryOutput;

	if (readings.size () >= 10)
	{
		readingsSum -= readings.front();
		readings.pop ();
	}
}




float Battery::findAverage ()
{
	if (readings.size () >= 10)
	{
		return (readingsSum / 10);
	}
}
