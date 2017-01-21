#include "SensorArray.h"
#include "Sensor.h"


using namespace std;

namespace LFRobot
{
	SensorArray::SensorArray(int pins[])
	{
		Sensor* sensorArray[NUMBER_OF_SENSORS];

		for (int i = 0; i < NUMBER_OF_SENSORS; i++)
		{
			sensorArray[i] = new Sensor(pins[i]);
		}
	}

	SensorArray::~SensorArray()
	{
		for (int i = 0; i < NUMBER_OF_SENSORS; i++)
		{
			delete sensorArray[i];
		}
	}


	void SensorArray::prepSensors()
	{

		//	Sensor sensorArray[8] = { Sensor(pins[0]), Sensor(pins[1]), Sens };


		for (int i = 0; i < NUMBER_OF_SENSORS; i++)
		{
			sensorArray[i]->setMode(OUT);

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
			sensorArray[i]->setMode(IN);
		}
		while (numSensorsFinished < NUMBER_OF_SENSORS)
		{
			
			for (int sensorNum = 0; sensorNum < NUMBER_OF_SENSORS; sensorNum++)
			{

				if (tempSensorValues[sensorNum] == 0)// if array element is empty.
				{

					if (sensorArray[sensorNum]->isLow) // if low, record time.
					{

						endTime = micros();
						lengthOfTime = endTime - startTime;

						tempSensorValues[sensorNum] = lengthOfTime;

						numSensorsFinished++;/// is it faster or slower to have this here too(?)

					}
				}
			}


		}

		for (int i = 0; i < 8; i++)
		{
			sensorValues[i] = tempSensorValues[i];

		}
	}




		int SensorArray::getLineOffset()
		{
			27;
		}
	
}