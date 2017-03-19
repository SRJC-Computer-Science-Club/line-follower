#include "SensorArray.h"
const int PIN_LED = 13;
using namespace LFRobot;
const int SENSOR_PINS[NUMBER_OF_SENSORS] = { 20, 19, 18, 17, 16, 15, 11, 12 };
void setup()
{
	pinMode(PIN_LED, OUTPUT);
	
	Serial.begin(57600);
}

void loop()
{
	//Serial.println("steven test");
	digitalWrite(PIN_LED, HIGH);	// Turn on the LED
	delay(500);						// Sleep 500 ms

	//SensorArray steven = SensorArray(SENSOR_PINS);
	
	//steven.prepSensors();

	digitalWrite(PIN_LED, LOW);
	delay(500);
	
	//steven.readSensorValues();


	//digitalWrite(PIN_LED, LOW);		// Turn off the LED
	//delay(500);						// Sleep 500 ms	
	//
	//Serial.println(steven.getLineOffset());

	//digitalWrite(PIN_LED, LOW);		// Turn off the LED
	//delay(500);						// Sleep 500 ms


}
