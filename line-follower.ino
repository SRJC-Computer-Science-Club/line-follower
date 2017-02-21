#include "motor_class.h"

int LED_PIN = 13;

void setup()
{
	motor test (5,6,2);
    test.setSpeed(0.5);

	pinMode(LED_PIN, OUTPUT);
}

void loop()
{
	digitalWrite(LED_PIN, HIGH);	// Turn on the LED
	delay(500);						// Sleep 500 ms
	digitalWrite(LED_PIN, LOW);		// Turn off the LED
	delay(500);						// Sleep 500 ms
}
