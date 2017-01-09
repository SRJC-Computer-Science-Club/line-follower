#include <vector>
#include "SensorArray.h"

using namespace std;

namespace LFRobot
{
	SensorArray::SensorArray()
	{
		vector<Sensor*> sensors;



		for (int i = 0; i < NUMBER_OF_SENSORS; i++)
		{
			sensors.push_back(new Sensor(i));
		}
	}


	void SensorArray::prepSensors()
	{
		int X = 3;
		for (int i = 0; i < X; i++)
		{
		cout << "testing" << endl;
		}

	}

}