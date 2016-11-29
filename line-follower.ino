const int PIN_LED = 13;

void setup()
{
	pinMode(PIN_LED, OUTPUT);
}

void loop()
{
	digitalWrite(PIN_LED, HIGH);	// Turn on the LED
	delay(500);						// Sleep 500 ms
	digitalWrite(PIN_LED, LOW);		// Turn off the LED
	delay(500);						// Sleep 500 ms
}
