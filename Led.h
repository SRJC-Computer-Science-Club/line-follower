#pragma once

class Led
{
public:
	
	Led();

	Led( int RED_PIN, int GREEN_PIN, int BLUE_PIN );

	// red, green, blue in range [0,255]
	void setRGB( int red, int green, int blue );

	// red, green, blue in range [0,1]
	void setRGB( float red, float green, float blue );

	// hue, sat, val in range [0,1]
	void setHSV( float hue, float sat, float val );

private:
	const int RED_PIN;
	const int GREEN_PIN;
	const int BLUE_PIN;
};



