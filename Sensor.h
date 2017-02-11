#pragma once
#include <Arduino.h>
namespace LFRobot
{
	enum SensorMode {IN, OUT};

	class Sensor
	{
		public:
			
			Sensor(int inPin);

			void setMode(SensorMode mode);
			bool isLow();

		private:

			int pin;

	};
}