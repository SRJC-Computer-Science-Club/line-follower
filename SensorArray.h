#pragma once

class SensorArray
{
	int N_SENSORS;
public:
	SensorArray();
	SensorArray(int pins[], int nPins);
	~SensorArray();
	double error();
};

