#pragma once

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

		private:
			int pin;
			float position;
	};
}