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
		motor();
		void halt();
		void coast();
		void setSpeed(float speed);
		void moveForward(int speed, int rotation);	

		//gets in a value between -1, 1
		//sets the speed to that value.
		//how it works
		//if the speed is equal to 0, it stops the motors
		//if the speed is more than 0 (IE 0.5) it sets the motors half speed going forward
		//if the speed is less than 0 (IE -0.2) it set the motors going slow going backward

		motor(int set_forward_pin, int set_backward_pin, int set_pwm_pin);

		int map(float x, float in_min, float in_max, int out_min, int out_max);

};


#endif
