#pragma once

class SensorArray
{
	int N_SENSORS;
	struct sensor {
		int pin;
		int position;
		//Sensor *sensor;
		sensor *next;
	};
	class SensorsArray {
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
	SensorsArray sensors;
public:
	SensorArray();
	//creates sensors and assign positions from -1 to 1, or left to right
	SensorArray(int pins[], int nPins);
	~SensorArray();
	double error();
};

