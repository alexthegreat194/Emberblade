#pragma once

//sfml imports
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;

int mouseDegrees();
float mouseSlope();
Vector2f mousePoint(float size);
Vector2f mousePoint(float size, int angle);

enum gameMode
{
	game, crafting, inventory
};

void drawFrame(RenderWindow* window, int x, int y, int w, int h);