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
{
	float dx = cos((angle + 180) * (PI / 180)) * size;
	float dy = sin((angle + 180) * (PI / 180)) * size;

	Vector2f rVector;
	rVector.x = dx;
	rVector.y = dy;

	return rVector;
}

void drawFrame(RenderWindow *window, int x, int y, int w, int h)
{
	//32 x 32, 96

	double sectionH = h / 3.0;
	double sectionW = w / 3.0;

	for (size_t i = 0; i < 3; i++)
	{
		frameTop[i].setPosition(x + (i * sectionW), y + (0 * sectionH));
		frameTop[i].setScale(sectionW / 32, sectionH / 32);

		frameMiddle[i].setPosition(x + (i * sectionW), y + (1 * sectionH));
		frameMiddle[i].setScale(sectionW / 32, sectionH / 32);

		frameBottom[i].setPosition(x + (i * sectionW), y + (2 * sectionH));
		frameBottom[i].setScale(sectionW / 32, sectionH / 32);
	}

	if (w >= h)
	{
		frameTop[0].setScale(sectionH / 32, sectionH / 32);
		frameTop[1].setScale((w - 2 * sectionH) / 32, sectionH / 32);
		frameTop[1].setPosition(x + sectionH, y);
		frameTop[2].setScale(sectionH / 32, sectionH / 32);

		frameMiddle[0].setScale(sectionH / 32, (h - 2 * sectionH) / 32);
		frameMiddle[0].setPosition(x, y + sectionH);
		frameMiddle[1].setPosition(x + sectionH, y + sectionH);
		frameMiddle[2].setScale(sectionH / 32, (h - 2 * sectionH) / 32);
		frameMiddle[2].setPosition(x + 3*sectionW, y + sectionH);
		frameMiddle[2].setOrigin(frameMiddle[2].getLocalBounds().width, 0);

		frameBottom[0].setScale(sectionH / 32, sectionH / 32);
		frameBottom[1].setScale((w - 2 * sectionH) / 32, sectionH / 32);
		frameBottom[1].setPosition(x + sectionH, y + h - sectionH);
		frameBottom[1].setOrigin(0, 0);
		frameBottom[2].setScale(sectionH / 32, sectionH / 32);
		
		frameMiddle[1].setScale((w - 2 * sectionH) / 32, sectionH / 32);
	}
	else
	{
		frameTop[0].setScale(sectionW / 32, sectionW / 32);
		frameTop[1].setScale((w - 2 * sectionW) / 32, sectionW / 32);
		frameTop[1].setPosition(x + sectionW, y);
		frameTop[2].setScale(sectionW / 32, sectionW / 32);

		frameMiddle[0].setScale(sectionW / 32, (h - 2 * sectionW) / 32);
		frameMiddle[0].setPosition(x, y + sectionW);
		frameMiddle[1].setPosition(x + sectionW, y + sectionW);
		frameMiddle[2].setScale(sectionW / 32, (h - 2 * sectionW) / 32);
		frameMiddle[2].setPosition(x + 3 * sectionW, y + sectionW);
		frameMiddle[2].setOrigin(frameMiddle[2].getLocalBounds().width, 0);

		frameBottom[0].setScale(sectionW / 32, sectionW / 32);
		frameBottom[1].setScale((w - 2 * sectionW) / 32, sectionW / 32);
		frameBottom[1].setPosition(x + sectionW, y + h);
		frameBottom[1].setOrigin(0, sectionH);
		frameBottom[2].setScale(sectionW / 32, sectionW / 32);

		frameMiddle[1].setScale((w - 2 * sectionW) / 32, (h - 2 * sectionW) / 32);
	}
	
	frameTop[2].setOrigin(frameBottom[2].getLocalBounds().width, 0);
	frameTop[2].setPosition(x + w, y);
	frameBottom[0].setOrigin(0, frameBottom[0].getLocalBounds().height);
	frameBottom[0].setPosition(x, y + h);
	frameBottom[2].setOrigin(frameBottom[2].getLocalBounds().width, frameBottom[2].getLocalBounds().height);
	frameBottom[2].setPosition(x + w, y + h);

	//draw thjings

	for (size_t i = 0; i < 3; i++)
	{
		window->draw(frameTop[i]);
		window->draw(frameMiddle[i]);
		window->draw(frameBottom[i]);
	}
}