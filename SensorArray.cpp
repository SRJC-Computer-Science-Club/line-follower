#include "SensorArray.h"
#include "Sensor.h"
#include <vector>
#include <Arduino.h>
#include <math.h>


using namespace std;

namespace LFRobot
{
	SensorArray::SensorArray(const int pins[], const int nSensors, const long microsWhite[], const long microsBlack[], const long MICROS_TIMEOUT)
		: nSensors(nSensors), MICROS_TIMEOUT(MICROS_TIMEOUT)
	{
		sensors = new Sensor*[nSensors];
		sensorValues = new long[nSensors];
		this->microsWhite = new long[nSensors];
		this->microsBlack = new long[nSensors];

		for (int i = 0; i < nSensors; i++)
		{
			sensors[i] = new Sensor(pins[i], 2.0f*i / (nSensors - 1.0f) - 1.0f);
			Serial.println(sensors[i]->getPosition());
			sensorValues[i] = 0.0f;
			this->microsWhite[i] = microsWhite[i];
			this->microsBlack[i] = microsBlack[i];
		}
	}

	SensorArray::~SensorArray()
	{
		for (int i = 0; i < nSensors; i++)
		{
			delete sensors[i];
		}

		delete[] sensors;
		delete[] sensorValues;
		delete[] microsWhite;
		delete[] microsBlack;
	}


	void SensorArray::prepSensors()
	{
		for (int i = 0; i < nSensors; i++)
		{
			sensors[i]->setMode(OUT);
		}

		delayMicroseconds(10);
	}


	void SensorArray::readSensorValues()
	{
		prepSensors();

		long startTime;
		int numSensorsFinished = 0;

		startTime = micros();
		for (int i = 0; i < nSensors; i++)
		{
			sensors[i]->setMode(IN);
			sensors[i]->setRead(false);
		}
		
		while (numSensorsFinished < nSensors)
		{

			for (int i = 0; i < nSensors; i++)
			{

				if (!sensors[i]->isRead())
				{
					long endTime = micros();

					if (sensors[i]->isLow() || endTime - startTime > MICROS_TIMEOUT) // if low, record time.
					{
						long lengthOfTime = endTime - startTime;

						sensorValues[i] = MICROS_TIMEOUT * (lengthOfTime - microsWhite[i]) / (MICROS_TIMEOUT - microsWhite[i]);

						numSensorsFinished++;
						sensors[i]->setRead(true);
					}
				}
			}
		}
	}

	float SensorArray::mapMicrosToValue(int i, long lenTime)
	{
		if (lenTime <= microsWhite[i])
		{
			return 0.0f;
		}
		else if (lenTime >= microsBlack[i])
		{
			return 1.0f;
		}
		else
		{
			return (float)(lenTime - microsWhite[i]) / (float)(microsBlack[i] - microsWhite[i]);
		}
	}


	float SensorArray::getLineOffset()
	{
		readSensorValues();

		float lineCenter = 0;
		long totalSensorValue = 0;
		
		for (int i = 0; i < nSensors; i++)
		{
			lineCenter += sensors[i]->getPosition() * sensorValues[i];
			totalSensorValue += sensorValues[i];
		}

		lineCenter /= totalSensorValue;
		if (totalSensorValue == 0)
		{
			lineCenter = 0;
		}



		float lineThickness = float(totalSensorValue) / MICROS_TIMEOUT / nSensors;

		if(lineThickness <= MIN_LINE_VALUE || lineThickness >= .6f)
		{
			if (lineData.getAverage() > 0)
			{
				lineCenter = 2;
			}
			else
			{
				lineCenter = -2;
			}
		}
		else {
			lineData.push(lineCenter * lineThickness);
		}

		return lineCenter;
	}
}