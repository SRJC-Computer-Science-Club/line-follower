#include <vector>
#include "SensorArray.h"


using namespace std;

namespace LFRobot
{
	SensorArray::SensorArray(int pins[])
	{
		vector<Sensor> sensors = vector<Sensor>();

		sensors.push_back(Sensor(0));



		for (int i = 0; i < NUMBER_OF_SENSORS; i++)
		{
			sensors.push_back(Sensor(pins[i]));
		}
	}


	void SensorArray::prepSensors()
	{

	//	Sensor sensorArray[8] = { Sensor(pins[0]), Sensor(pins[1]), Sens };


		for (int i = 0; i < NUMBER_OF_SENSORS; i++)
		{
			sensors[i]-> setMode(OUT);
		}
	}


	void SensorArray::readSensorValues()
	{
		long startTime, endTime, lengthOfTime; 
		int tempSensorValues[NUMBER_OF_SENSORS] = { 0 };
		int numSensorsFinished = 0;

		startTime = micros();
		for (int i = 0; i < NUMBER_OF_SENSORS; i++)
		{
			sensors[i]->setMode(IN);
		}
		while(numSensorsFinished < 8)
		{
			numSensorsFinished = 0;

			for (int sensorNum = 0; sensorNum < NUMBER_OF_SENSORS; sensorNum++)
			{

				if (tempSensorValues[sensorNum] == 0)// if array element is empty.
				{

					if (sensors[sensorNum]->isLow) // if low, record time.
					{

						endTime = micros();
						lengthOfTime = endTime - startTime;

						tempSensorValues[sensorNum] = lengthOfTime;

						numSensorsFinished++;/// is this faster or slower(?)
					}
				}
				else
				{
					numSensorsFinished++; //counting how many sensors are done.
				}
			}


		}
		for (int i = 0; i < 8; i++)
		{
			sensorValues[i] = tempSensorValues[i];
			Serial.print(sensorValues[i] + " ");
		}
	}



	//void test()
	//{
	//	for (int i = 0; i < 8; i++)
	//	{
	//		sensorValues[i]
	//			Serial.print(sensorValues[i])
	//	}
	//
	//}

}