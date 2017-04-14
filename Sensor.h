#pragma once
#include <Arduino.h>
namespace LFRobot
{
	enum SensorMode {IN, OUT};

	class Sensor
	{
		public:
			Sensor(int inPin, float inPosition);

			void setMode(SensorMode mode);
			bool isLow();
			float getPosition();
			bool isRead();
			void setRead(const bool read);

		private:
			int pin;
			float position;
			bool read;
	};
}