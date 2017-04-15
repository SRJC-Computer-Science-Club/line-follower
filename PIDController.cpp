#include "PIDController.h"

namespace LFRobot
{

	PIDController::PIDController(float P, float I, float D)
		: Kp(P), Ki(I), Kd(D)
	{

	}

	void PIDController::start(const float inError) {
		pastError.push(inError);
		firstError = false;
	}

	float PIDController::getCorrection(float error, float deltaTime) {

		if (firstError)
		{
			start(error);
		}

		float pTerm, iTerm, dTerm;

		integralTotal += error * deltaTime;

		pTerm = Kp * error;
		iTerm = Ki * integralTotal;
		dTerm = Kd * (error - pastError.getAverage()) / deltaTime;

		pastError.push(error);

		return pTerm + iTerm + dTerm;
	}

}