#include "SensorArray.h"
#include "Sensor.h"


using namespace std;

namespace LFRobot
{
	SensorArray::SensorArray(const int pins[])
	{
		Sensor* sensorArray[NUMBER_OF_SENSORS];

		for (int i = 0; i < NUMBER_OF_SENSORS; i++)
		{
			sensorArray[i] = new Sensor(pins[i], -1 + 2*i / (NUMBER_OF_SENSORS - 1));
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
		
	
		for (int i = 0; i < NUMBER_OF_SENSORS; i++)
		{
			
		pinMode(pins[i], OUTPUT);
		digitalWrite(pins[i], HIGH);
		//	sensorArray[1]->setMode(OUT);
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
			pinMode(pins[i], INPUT);
		//	sensorArray[i]->setMode(IN);
		}
		
		while (numSensorsFinished < NUMBER_OF_SENSORS)
		{
			
			for (int sensorNum = 0; sensorNum < NUMBER_OF_SENSORS; sensorNum++)
			{

				if (tempSensorValues[sensorNum] == 0)// if array element is empty.
				{
					
					if (digitalRead(sensorNum) == LOW) // if low, record time. 
					{
					
						endTime = micros();
						lengthOfTime = endTime - startTime;

						tempSensorValues[sensorNum] = lengthOfTime;

						numSensorsFinished++;
						Serial.println(numSensorsFinished);
					}
				}
			}
			

		}
digitalWrite(13, LOW);
		for (int i = 0; i < NUMBER_OF_SENSORS; i++)
		{
			sensorValues[i] = tempSensorValues[i];

		}
	}




		int SensorArray::getLineOffset()
		{
			float positionRefectanceSum = 0.0;
			float reflectanceSum = 0.0;

			for (int i = 0; i < NUMBER_OF_SENSORS; i++)
			{
			positionRefectanceSum += sensorArray[i]->getPosition() * sensorValues[i];  //          }
			//	positionRefectanceSum += -1 + 2 * i / (NUMBER_OF_SENSORS - 1) * sensorValues[i];  //   } was trying to not use the sensor objects
			
				reflectanceSum += sensorValues[i];
			}

			float L = positionRefectanceSum / reflectanceSum;
			return L;
		}
	
}