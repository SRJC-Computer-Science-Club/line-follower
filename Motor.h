#pragma once


class Motor
{

public:
	Motor(int set_forward_pin, int set_backward_pin, int set_pwm_pin);

	void coast();
	void setSpeed(float speed);
private:
	float speed;
	int FORWARD_PIN;
	int BACKWARD_PIN;
	int PWM_PIN;


};