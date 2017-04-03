#include "PIDController.h"

namespace LFRobot
{

	PIDController::PIDController(float P, float I, float D)
		: pConstant(P), iConstant(I), dConstant(D)
	{
		prevError = micros();
	}

	void PIDController::start(const float inError, const long inTime) {
		cachePreviousError(inError, inTime);
		firstError = false;
	}

	void PIDController::setPID(float& P, float& I, float& D, float currentErr, long dTime) {
		P = pConstant * currentErr;
		I = iConstant * integralTotal;
		D = (dConstant * (currentErr - prevError)) / dTime;
	}

	void PIDController::cachePreviousError(const float inError, const long inTime) {
		prevError = inError;
		prevTime = inTime;
	}

	float PIDController::getCorrection(float currentError) {
		float proportionalTerm;
		float derivativeTerm;
		float integralTerm;
		long currentTime;
		long deltaTime;

		if (firstError) {
			start(currentError, currentTime);
		}

		currentTime = micros();
		deltaTime = currentTime - prevTime;
		integralTotal += currentError * deltaTime;

		setPID(proportionalTerm, derivativeTerm, integralTerm, currentError, deltaTime);
		cachePreviousError(currentError, currentTime);
		return proportionalTerm + derivativeTerm + integralTerm;
	}

}