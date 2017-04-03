
#pragma once

namespace LFRobot {
	class PIDController {
	public:
		PIDController(float P, float I, float D);
		void start(const float inError, const long inTime);
		void cachePreviousError(const float inError, const long inTime);
		void setPID(float& P, float& I, float& D, float currentErr, long dTime);
		float getCorrection(float error);
	private:
		long prevTime;
		float prevError;
		float iConstant;
		float dConstant;
		float pConstant;
		bool firstError = true;
		float integralTotal = 0;
	};
}
