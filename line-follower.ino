#include "Motor.h"
#include "MotorPair.h"
#include <math.h>
#include "LineFollower.h"
#include "AveragingQueue.h"

/*
This is needed in order to use some stuff from the STL.
DON'T ASK WHY
*/
namespace std {
	void __throw_bad_alloc()
	{
		Serial.println("Unable to allocate memory");
	}

	void __throw_length_error(char const*e)
	{
		Serial.print("Length Error :");
		Serial.println(e);
	}
}

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
Moves both motors.
forward, backward, turn right, turn left, backward left, backward right, pivot right, pivot left, stop.
*/
void testMotorPair() {
	MotorPair bothMotors;
	int DELAY = 500;
	
	//go forward X
	bothMotors.moveForward(1, 0);
	delay(DELAY);
	//go backward  X
	bothMotors.moveForward(-1, 0);
	delay(DELAY);
	


	//forward right X
	bothMotors.moveForward(1, 1);
	delay(DELAY);
	// froward left X
	bothMotors.moveForward(1, -1);
	delay(DELAY);
	

	//backward left X
	bothMotors.moveForward(-1, 1);
	delay(DELAY);
	// backward right X
	bothMotors.moveForward(-1, -1);
	delay(DELAY);

	
	
	//pivot right
	bothMotors.moveForward(1, 2);
	delay(DELAY);
	//pivot left
	bothMotors.moveForward(1, -2);
	delay(DELAY);
	
	//stop
	bothMotors.moveForward(0, 0);
	delay(DELAY);
}

/*
Continuously prints the line center position over serial.
*/
void testSensorArray()
{
	SensorArray sensorArray(PIN_SENSORS, N_SENSORS, MICROS_WHITE, MICROS_BLACK, 1000);

	while (true)
	{
		float lineCenter = sensorArray.getLineOffset();
		Serial.println(lineCenter);
		delay(100);
	}
}

/*
Expected Serial Output
0
3
8
28
5
10
41
*/
void testAveragingQueue()
{
	AveragingQueue<int> intQueue(5);

	Serial.println(intQueue.getAverage());

	for (int i = 1; i <= 5; i++)
	{
		intQueue.push(i);
	}
	Serial.println(intQueue.getAverage());

	for (int i = 10; i <= 12; i++)
	{
		intQueue.push(i);
	}
	Serial.println(intQueue.getAverage());

	intQueue.push(102);
	Serial.println(intQueue.getAverage());

	Serial.println(intQueue.pop());
	Serial.println(intQueue.pop());

	Serial.println(intQueue.getAverage());
}

void setup()
{
	Serial.begin(57600);
	pinMode(PIN_MOTOR_STBY, OUTPUT);
	digitalWrite(PIN_MOTOR_STBY, HIGH);
	
	//testMotor();
	//testMotorPair();
//	testSensorArray();

	
	LineFollower lineFollower;
	lineFollower.followLine();
	

	//testAveragingQueue();
}

void loop()
{
	digitalWrite(LED_PIN, HIGH);	// Turn on the LED
	delay(500);						// Sleep 500 ms
	digitalWrite(LED_PIN, LOW);		// Turn off the LED
	delay(500);						// Sleep 500 ms
}


