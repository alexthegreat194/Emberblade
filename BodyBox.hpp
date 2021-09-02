#pragma once

//sfml imports
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

//other imports
#include "WeaponBox.hpp"

class BodyBox
{
private:
	int x;
	int y;
	int w;
	int h;

public:
	BodyBox(int iw, int ih);
	void setPosition(int inpx, int inpy);
	bool isInside(WeaponBox hitbox);
	void draw(RenderWindow* window);
};