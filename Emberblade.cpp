#include "Emberblade.hpp"
#include "Globals.hpp"
#include <math.h>

int mouseDegrees()
{
	float dx = mouseX - MYWINDOW_WIDTH / 2 + worldX;
	float dy = mouseY - MYWINDOW_HEIGHT / 2 + worldY;

	float rotation = (atan2(dy, dx)) * 180 / PI;
	int result = int(rotation) + 180;

	//std::printf("Mouse Degrees: %i\tdx: %f\tdy: %f", result, float(cos(rotation/(PI/180))), sin(rotation / (PI / 180)));
	return result;
}

float mouseSlope()
{
	float dx = mouseX - MYWINDOW_WIDTH / 2 + worldX;
	float dy = mouseY - MYWINDOW_HEIGHT / 2 + worldY;

	//std::printf("\tSlope: %f\n", (float(dx) / float(dy)));
	return dy / dx;
}

Vector2f mousePoint(float size)
{
	float dx = mouseX - MYWINDOW_WIDTH / 2;
	float dy = mouseY - MYWINDOW_HEIGHT / 2;

	float dh = sqrt((dx * dx) + (dy * dy));
	float ratio = size / dh;
	mouseRatio = ratio;

	Vector2f rVector;
	rVector.x = (dx * ratio);
	rVector.y = (dy * ratio);

	//std::printf("x: %f\ty: %f\n", rVector.x, rVector.y);

	return rVector;
}

Vector2f mousePoint(float size, int angle)