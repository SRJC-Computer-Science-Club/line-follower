#include "SensorArray.h"

#ifndef _SENSOR_ARRAY_h
#define _SENSOR_ARRAY_h
#endif

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class SensorsArray {
	struct sensor {
		int pin;
		int position;
		//Sensor *sensor;
		sensor *next;
	};
	sensor *head, *tail;
public:
	SensorsArray() {
		head = tail = nullptr;
	}

	~SensorsArray() {
		sensor *curr = head;
		while (curr != nullptr) {
			sensor *destory = curr;
			curr = destory->next;
			delete destory;
		}
	}

	//inserts a new node at the tail vs the head
	void insert(int pinValue, float posValue) {
		sensor *instance = new sensor();
		instance->pin = pinValue;
		instance->position = posValue;
		tail->next = instance;

		tail = instance;
	}

	//starting at 0 as the first node. Iterates starting at the head
	sensor* at(int indexValue) {
		sensor *node = head;
		while (indexValue > 0) {
			node = node->next;
			indexValue -= 1;
		}

		return node;
	}
};

SensorArray::SensorArray()
{
	sensors = SensorsArray();
}

SensorArray::SensorArray(int pins[], int nPins)
{
	N_SENSORS = nPins;
	for (int pin = 0; pin < N_SENSORS; pin++)
	{
		pinMode(pin, INPUT);
		float pos = 2 / N_SENSORS * pin;
		sensors.insert(pin, pos);
	}
}


SensorArray::~SensorArray()
{
	sensors.~SensorsArray();
}


double SensorArray::error()
{
	float sum1 = 0, sum2 = 0;
	for (int sensor = 0; sensor < N_SENSORS; sensor++)
	{
		//sum1 += sensors.at(sensor)->position * sensors.at(sensor)->sensor.value();
		//sum2 += sensors.at(sensor)->sensor.value();
	}

	return sum1 / sum2;
}
