
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
#include <Windows.h>

//header Files
#include "AlexClasses.h"

//namespaces
using namespace sf;
using namespace std;

//Weapon Box Methods:

	WeaponBox::WeaponBox(int inpx, int inpy, int inpr)
	{
		x = inpx;
		y = inpy;
		r = inpr;
	}
	WeaponBox::WeaponBox(int inpr)
	{
		x = 0;
		y = 0;
		r = inpr;
	}
	WeaponBox::WeaponBox()
	{
		x = 0;
		y = 0;
		r = 0;
	}

	void WeaponBox::setPosition(int inpx, int inpy)
	{
		x = inpx;
		y = inpy;
	}
	void WeaponBox::setPosition(Vector2f inpV)
	{
		x = inpV.x;
		y = inpV.y;
	}
	void WeaponBox::setRadius(int ir)
	{
		r = ir;
	}
	void WeaponBox::setInUse(bool inp)
	{
		inUse = inp;
	}

	bool WeaponBox::getInUse()
	{
		return inUse;
	}
	Vector2f WeaponBox::getPosition()
	{
		return Vector2f(x, y);
	}
	int WeaponBox::getRadius()
	{
		return r;
	}

	void WeaponBox::draw(RenderWindow* window)
	{
		if (inUse)
		{
			CircleShape circ(r);
			circ.setPosition(x, y);
			circ.setOrigin(r, r);
			circ.setFillColor(Color(200, 0, 0, 100));
			window->draw(circ);
		}
	}


	//Body Box Methods:

	BodyBox::BodyBox(int iw, int ih)
	{
		x = 0;
		y = 0;
		w = iw;
		h = ih;
	}

	void BodyBox::setPosition(int inpx, int inpy)
	{
		x = inpx;
		y = inpy;
	}

	bool BodyBox::isInside(WeaponBox hitbox)
	{
		int dx = abs(hitbox.getPosition().x - x);
		int dy = abs(hitbox.getPosition().y - y);
		bool inX = dx < (w + hitbox.getRadius()) / 2;
		bool inY = dy < (h + hitbox.getRadius()) / 2;

		if ((hitbox.getInUse() == true) && (inX && inY))
		{
			printf("collision, dx: %i dy: %i \n", dx, dy);
			return true;
		}
		else
			return false;
	}

	void BodyBox::draw(RenderWindow* window)
	{
		RectangleShape rect(Vector2f(w, h));
		rect.setPosition(x, y);
		rect.setOrigin(w / 2, h / 2);
		rect.setFillColor(Color(0, 0, 200, 100));
		window->draw(rect);
	}