#include "SensorArray.h"
const int PIN_LED = 13;

using namespace LFRobot;
void rgbLED(int inValue);
int pins[8] = {20,19,18,17,16,15,11,12};
const int BLUE_LED_PIN = 21;
void setup()
{
	pinMode(PIN_LED, OUTPUT);
	
}

void loop()
{
	//int offSet;
	int sensorValues[8];
	SensorArray sensorArray(pins);


	sensorArray.prepSensors();
	sensorArray.readSensorValues();
	//offSet = sensorArray.getLineOffset();
	sensorArray.testingSensors(sensorValues);





}





void rgbLED(int inValue)
{

	analogWrite(BLUE_LED_PIN, inValue);

}


