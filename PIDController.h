#include <Arduino.h>
#include "AveragingQueue.h"


#pragma once

namespace LFRobot {
	class PIDController {
	public:
		PIDController(float P, float I, float D);
		void start(const float inError);
		float getCorrection(float error, float deltaTime);
	private:

		float Kp, Ki, Kd;

		AveragingQueue<float> pastError = AveragingQueue<float>(3);
		float integralTotal = 0;

		bool firstError = true;
	};
}
