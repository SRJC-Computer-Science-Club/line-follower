#include "arduino.h"
#include "Math.h"
#include "Motor.h"


Motor::Motor(int set_forward_pin, int set_backward_pin, int set_pwm_pin)
	: FORWARD_PIN(set_forward_pin), BACKWARD_PIN(set_backward_pin), PWM_PIN(set_pwm_pin)
{
	pinMode(FORWARD_PIN, OUTPUT);
	pinMode(BACKWARD_PIN, OUTPUT);
	pinMode(PWM_PIN, OUTPUT);
}



void Motor::coast() {
	digitalWrite(FORWARD_PIN, LOW);
	digitalWrite(BACKWARD_PIN, LOW);
}

void Motor::setSpeed(float speed)
{
	//Clamps speed between -1 and 1
	speed = (speed > 1) ? (1) : (speed);
	speed = (speed < -1) ? (-1) : (speed);

	if (speed == 0)
	{
		coast();
	}
	else if (speed > 0)
	{
		analogWrite(PWM_PIN, 255.0f * speed);

		digitalWrite(FORWARD_PIN, HIGH);
		digitalWrite(BACKWARD_PIN, LOW);

	}else{

		//maps 0 to 1 to a value between 0 and 255
		analogWrite(PWM_PIN, 255.0f * (-speed));

		digitalWrite(FORWARD_PIN, LOW);
		digitalWrite(BACKWARD_PIN, HIGH);
	}
}