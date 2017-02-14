#pragma once
// Austin Meyer
// Project - line_follower
// Date Created 2/4/2017
// Last Opened 2/4/2017

const int PIN_NUMBER = 15;
const int BATTERY_N_READINGS = 10;
const int BATTERY_MAX_DESCREPENCY = 5;

class Battery
{
	private:
		int pin;
		int batteryReadings[BATTER_N_READINGS];
		int powerAverage;
	public:
		Battery ();
		bool checkBattery ();
		void readVoltage ();
};

