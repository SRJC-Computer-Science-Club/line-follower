#include "SensorArray.h"

#ifndef _SENSOR_ARRAY_h
#define _SENSOR_ARRAY_h
#endif

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif


SensorArray::SensorArray()
{
}

SensorArray::SensorArray(int pins[], int nPins)
{
}


SensorArray::~SensorArray()
{
}


double SensorArray::error()
{
	return 0;
}
