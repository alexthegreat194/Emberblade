#pragma once 
//sfml imports
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;
//other imports

class WeaponBox
{
private:
	int x;
	int y;
	int r;
	bool inUse = false;

public:
	WeaponBox(int inpx, int inpy, int inpr);
	WeaponBox(int inpr);
	WeaponBox();

	void setPosition(int inpx, int inpy);
	void setPosition(Vector2f inpV);
	void setRadius(int ir);
	void setInUse(bool inp);

	bool getInUse();
	Vector2f getPosition();
	int getRadius();

	void draw(RenderWindow* window);
};