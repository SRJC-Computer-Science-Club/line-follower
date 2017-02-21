#pragma once
// Austin Meyer
// Project - line_follower
// Date Created 2/4/2017
// Last Opened 2/20/2017

const int PIN_NUMBER = 15;
const int BATTERY_N_READINGS = 10;
const int BATTERY_MAX_DESCREPENCY = 5;

class Battery
{
	private:
		int pin;
		double powerAverage;
		double lastReading;
		double internalCounter;
	public:
		Battery ();
		bool checkBattery ();
		double findAverage ();
		void readVoltage ();
};

