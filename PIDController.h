#include <Arduino.h>
#include "AveragingQueue.h"


#pragma once

namespace LFRobot {
	class PIDController {
	public:
		PIDController(float P, float I, float D);
		void start(const float inError);
		float getCorrection(float error);
	private:

		float Kp, Ki, Kd;

		long prevTime;

		AveragingQueue<float> pastError = AveragingQueue<float>(5);
		float integralTotal = 0;

		bool firstError = true;
	};
}
