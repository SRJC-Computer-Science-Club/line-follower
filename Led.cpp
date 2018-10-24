#include "Led.h"
#include <assert.h>

#define MIN_VALUE 0
#define MAX_VALUE 255


Led::Led() :
	RED_PIN{ 0 },
	GREEN_PIN{ 0 },
	BLUE_PIN{ 0 }
{}



Led::Led( int RED_PIN, int GREEN_PIN, int BLUE_PIN ) :
	RED_PIN{ RED_PIN },
	GREEN_PIN{ GREEN_PIN },
	BLUE_PIN{ BLUE_PIN }
{
	pinMode( RED_PIN, OUTPUT );
	pinMode( GREEN_PIN, OUTPUT );
	pinMode( BLUE_PIN, OUTPUT );
}



void Led::setRGB( int red, int green, int blue )
{
	assert( red >= MIN_VALUE && red <= MAX_VALUE );
	assert( green >= MIN_VALUE && green <= MAX_VALUE );
	assert( blue >= MIN_VALUE && blue <= MAX_VALUE );

	analogWrite( RED_PIN, red );
	analogWrite( GREEN_PIN, green );
	analogWrite( BLUE_PIN, blue );
}



void Led::setRGB( float red, float green, float blue )
{
	setRGB( int( red * MAX_VALUE ), int( green * MAX_VALUE ), int( blue * MAX_VALUE ) );
}



void Led::setHSV( float hue, float sat, float val )
{
	float chroma = sat * val;
	int h = int( hue * 6 );
	float x = chroma * ( 1 - abs( h % 2 - 1 ) );

	float r = 0.0f, g = 0.0f, b = 0.0f;

	switch( h )
	{
	case 0:
		r = chroma;
		g = x;
		break;
	case 1:
		r = x;
		g = chroma;
		break;
	case 2:
		g = chroma;
		b = x;
		break;
	case 3:
		g = x;
		b = chroma;
		break;
	case 4:
		r = x;
		b = chroma;
		break;
	case 5:
		r = chroma;
		b = x;
		break;

	default: assert( false ); break;
	}

	float m = val - chroma;
	setRGB( r + m, g + m, b + m );
}
