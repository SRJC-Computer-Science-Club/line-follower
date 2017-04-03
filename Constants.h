#pragma once

const int PIN_LED = 13;
const int N_SENSORS = 8;

//										{ 0,   1,   2,   3,   4,   5,   6,   7  }
const int PIN_SENSORS[N_SENSORS] =		{ 20,  19,  18,  17,  16,  15,  11,  12 };
const long MICROS_WHITE[N_SENSORS] =	{ 280, 200, 170, 160, 160, 170, 200, 250 };
const long MICROS_BLACK[N_SENSORS] =	{ 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000 };
const long MICROS_TIMEOUT = 3000;
//motor pins left
const int PIN_MOTOR_LEFT_FORWARD = 5;
const int PIN_MOTOR_LEFT_BACKWARD = 6;
const int PIN_MOTOR_LEFT_PWM = 4;
//motor pins right
const int PIN_MOTOR_RIGHT_FORWARD = 8;
const int PIN_MOTOR_RIGHT_BACKWARD = 9;
const int PIN_MOTOR_RIGHT_PWM = 10;
//
const float ROBOT_SPEED = 1;
const int VALUES_STORED = 5;
const float MIN_LINE_VALUE = 0.05;