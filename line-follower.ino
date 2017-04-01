
#include "LineFollower.h"

using namespace LFRobot;


void setup()
{
	pinMode(PIN_LED, OUTPUT);
	pinMode(PIN_LED, HIGH);
	delay(200);
	pinMode(PIN_LED, LOW);
	delay(200);
	pinMode(PIN_LED, HIGH);
	delay(200);
	
	Serial.begin(57600);

	LineFollower lineFollower;
	lineFollower.testSensorArray();
}

void loop()
{

	
}
