#include "SensorArray.h"
const int PIN_LED = 13;
using namespace LFRobot;
const int SENSOR_PINS[NUMBER_OF_SENSORS] = { 20, 19, 18, 17, 16, 15, 11, 12 };


void setup()
{
	pinMode(PIN_LED, OUTPUT);
	
	Serial.begin(57600);
}
SensorArray steven = SensorArray(SENSOR_PINS);
void loop()
{

	Serial.println("steven test");
	digitalWrite(PIN_LED, HIGH);	// Turn on the LED
	delay(500);						// Sleep 500 ms

	testSensors();
	
	digitalWrite(13, LOW);
	delay(500);

	
}



void testSensors()
{
	

	steven.prepSensors();
	
	steven.readSensorValues();
	Serial.println(steven.getLineOffset());
}


