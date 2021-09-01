#pragma once

//standard imports
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <math.h>  
#include <stdio.h>

//sfml imports
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

//namespaces
using namespace sf;
using namespace std;

//calculations:
int mouseDegrees();
float mouseSlope();
Vector2f mousePoint(float size);
Vector2f mousePoint(float size, int angle);

enum gameMode
{
	game, crafting, inventory
};

void drawFrame(RenderWindow* window, int x, int y, int w, int h);

//inventory
enum ItemType
{
	empty, plant, meat, leather, healthPotion
};
