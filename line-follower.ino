#include "Motor.h"
#include <math.h>
int LED_PIN = 13;

int PIN_MOTOR_STBY = 7;

/*
The bot should pivot in place according to the sine function.
clockwise, anti-clockwise, clockwise, anti-clockwise, stop.
*/
void testMotor()
{
	Motor rightMotor(5, 6, 4);
	Motor leftMotor(8, 9, 10);

	for (float i = 0; i < 12.57; i += 0.01)
	{
		rightMotor.setSpeed(sin(i));
		leftMotor.setSpeed(-sin(i));
		delay(10);
	}
	
}

void setup()
{
	pinMode(PIN_MOTOR_STBY, OUTPUT);
	digitalWrite(PIN_MOTOR_STBY, HIGH);
	
	testMotor();
	
	pinMode(LED_PIN, OUTPUT);
}

void loop()
{
	digitalWrite(LED_PIN, HIGH);	// Turn on the LED
	delay(500);						// Sleep 500 ms
	digitalWrite(LED_PIN, LOW);		// Turn off the LED
	delay(500);						// Sleep 500 ms
}


