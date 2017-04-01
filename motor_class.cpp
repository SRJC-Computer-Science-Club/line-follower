#include "Motor.h"


Motor::Motor() {
	speed = 0.0f;
	FORWARD_PIN = 0;
	BACKWARD_PIN = 0;
	PWM_PIN = 0;
}

int Motor::map(float x, float in_min, float in_max, int out_min, int out_max)
{
	return int((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}


Motor::Motor(int set_forward_pin, int set_backward_pin, int set_pwm_pin) {
		FORWARD_PIN = set_forward_pin;
		BACKWARD_PIN = set_backward_pin;
		PWM_PIN = set_pwm_pin;

		pinMode(FORWARD_PIN, OUTPUT);
		pinMode(BACKWARD_PIN, OUTPUT);
		pinMode(PWM_PIN, OUTPUT);
}


void Motor::setSpeed(float speed){
	int speedToHardwareVoltage = map(fabs(speed), -1.0f, 1.0f, 0, 255);

	if (speed > 1.0f || speed < -1.0f) {

		Serial.print("The Speed out of range error");
	}

	//int speedToHardwareVoltage = int(map(fabs(speed), 0.0F, 1.0f, 0, 255));

	if (speed == 0.0f) { //coast
		digitalWrite(FORWARD_PIN, LOW);
		digitalWrite(BACKWARD_PIN, LOW);

	}
	else if (speed > 0.0f) {

		digitalWrite(FORWARD_PIN, HIGH);
		digitalWrite(BACKWARD_PIN, LOW);

	}
	else {

		digitalWrite(FORWARD_PIN, LOW);
		digitalWrite(BACKWARD_PIN, HIGH);

	}
	analogWrite(PWM_PIN, speedToHardwareVoltage);

}


void Motor::coast() {
	setSpeed(0);
}

void Motor::halt() {
	setSpeed(0);
}

void Motor::moveForward(int speed, int rotation){
	Motor right, left;

	right.setSpeed(rotation + speed);
	left.setSpeed((-1 * rotation) + speed);
}