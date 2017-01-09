#include <iostream>

#include "SensorArray.h"

using namespace std;

namespace LFRobot 
{
	int main()
	{
		Serial.begin(57600);
		SensorArray steven = SensorArray();

		cout << steven.prepSensors
	}
}