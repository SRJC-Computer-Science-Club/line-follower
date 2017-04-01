#include "Motor.h"
#include "MotorPair.h"
#include <math.h>
#include "LineFollower.h"

using namespace LFRobot;

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

/*
Moves both motors, forward, backward, left, right, etc
*/

void testMotorPair() {
	MotorPair bothMotors;
	int DELAY = 500;
	
	//go forward X
	bothMotors.moveForword(1, 0);
	delay(DELAY);
	
	
	
	//go backward  X
	bothMotors.moveForword(-1, 0);
	delay(DELAY);
	
	//forward left X
	bothMotors.moveForword(1, 1);
	delay(DELAY);
	


	// froward right X
	bothMotors.moveForword(1, -1);
	delay(DELAY);
	
	//backward left X
	bothMotors.moveForword(-1, 1);
	delay(DELAY);
	
	
	// backward right X
	bothMotors.moveForword(-1, -1);
	delay(DELAY);
	
	
	//just left ? does not move
	bothMotors.moveForword(0, 2);
	delay(DELAY);
	
	//just right ? does not move
	bothMotors.moveForword(0, -2);
	delay(DELAY);

	
	
	//forward left 100% X
	bothMotors.moveForword(1, 2);
	delay(DELAY);
		
	// forward right 100% X
	bothMotors.moveForword(1, -2);
	delay(DELAY);
	
	//dont move X
	bothMotors.moveForword(0, 0);
	delay(DELAY);
}

void setup()
{
	pinMode(PIN_MOTOR_STBY, OUTPUT);
	digitalWrite(PIN_MOTOR_STBY, HIGH);
	
	//testMotor();
	//testMotorPair();
	Serial.begin(57600);

	LineFollower lineFollower;
	lineFollower.testSensorArray();
}

void loop()
{
	digitalWrite(LED_PIN, HIGH);	// Turn on the LED
	delay(500);						// Sleep 500 ms
	digitalWrite(LED_PIN, LOW);		// Turn off the LED
	delay(500);						// Sleep 500 ms
}


