// motor_class.h
//notes http://bildr.org/2012/04/tb6612fng-arduino/
//map function https://www.arduino.cc/en/Reference/Map
//motor driver used https://www.pololu.com/product/713
//long map(long, long, long, long, long);
//ex val = map(val, 0, 1023, 0, 255);
#ifndef _MOTOR_CLASS_h
#define _MOTOR_CLASS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

int map(float x, float in_min, float in_max, float out_min, float out_max)
{
return ceil((min(x,1) - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

class motor
{

private:
	float speed;
	int FORWARD_PIN; 
	int BACKWARD_PIN;
	int PWM_PIN; 
public:
	class speedRangeOutOfBounds {};
	motor()
	{
		speed = 0.0f;
		FORWARD_PIN  = 0;
		BACKWARD_PIN = 0;
		PWM_PIN      = 0;
	}

	~motor() {
	}

	motor(int set_forward_pin, int set_backward_pin, int set_pwm_pin) {
		FORWARD_PIN = set_forward_pin;
		BACKWARD_PIN = set_backward_pin;
		PWM_PIN = set_pwm_pin;

		pinMode(FORWARD_PIN,  OUTPUT);
		pinMode(BACKWARD_PIN, OUTPUT);
		pinMode(PWM_PIN,      OUTPUT);

	}

	//gets in a value between -1, 1
	//sets the speed to that value.
	//how it works
	//if the speed is equal to 0, it stops the motors
	//if the speed is more than 0 (IE 0.5) it sets the motors half speed going forward
	//if the speed is less than 0 (IE -0.2) it set the motors going slow going backward

	void setSpeed(float speed) {

		try {
			int speedToHardwareVoltage = int(map(abs(speed), 0.0F, 1.0f, 0, 255));
			if (speed < 1.0f) {
				throw speedRangeOutOfBounds();
			}
			else if (speed > -1.0f) {
				throw speedRangeOutOfBounds();
			}

			int speedToHardwareVoltage = int(map(abs(speed), 0.0F, 1.0f, 0, 255));

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
		catch (speedRangeOutOfBounds e) {
			Serial.print("The Speed out of range error");

		}

	}

	
	void coast(){
		setSpeed(0);
	}

	void halt() {
		setSpeed(0);
	}

	void moveForward(int speed, int rotation) {
		motor right, left;

		right.setSpeed(       rotation  + speed);
		left .setSpeed( (-1 * rotation) + speed);
	}
};


#endif