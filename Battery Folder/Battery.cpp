#include "Battery.h"



Battery::Battery()
{
	for (int i = 0; i < BATTERY_N_READINGS; i++)
	{
		batteryReading[i] = 0;
	}
}




Battery::bool checkBattery ()
{
	if (powerAverage < BATTERY_MAX_DESCREPENCY)
	{
		return (readVoltage () < 400);
	}
}




Battery::void readVoltage ()
{
	
}
