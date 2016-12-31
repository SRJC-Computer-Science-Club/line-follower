#pragma once

class SensorsArray;

class SensorArray
{
	int N_SENSORS;
	SensorsArray sensors;
public:
	SensorArray();
	//creates sensors and assign positions from -1 to 1, or left to right
	SensorArray(int pins[], int nPins);
	~SensorArray();
	double error();
};

