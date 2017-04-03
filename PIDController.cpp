#include "PIDController.h"

namespace LFRobot
{

	PIDController::PIDController(float P, float I, float D)
		: Kp(P), Ki(I), Kd(D)
	{

	}

	void PIDController::start(const float inError) {
		pastError.push(inError);
		prevTime = micros();
		firstError = false;
	}

	float PIDController::getCorrection(float error) {

		if (firstError)
		{
			start(error);
		}

		float pTerm, iTerm, dTerm;

		long currentTime = micros();

		currentTime = micros();
		long deltaTime = currentTime - prevTime;
		integralTotal += error * deltaTime;

		pTerm = Kp * error;
		iTerm = Ki * integralTotal;
		dTerm = Kd * (error - pastError.getAverage()) / deltaTime;

		pastError.push(error);
		prevTime = currentTime;

		return pTerm + iTerm + dTerm;
	}

}