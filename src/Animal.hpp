#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "BodyBox.hpp"
#include "WeaponBox.hpp"
using namespace sf;
using namespace std;

class Animal
{
private:
	int x;
	int y;

	int randomX;
	int randomY;
	bool destinationSelected = false;

	sf::Clock walkTimer;

	sf::Clock frameTimer;
	int frames = 0;
	bool up = false;
	bool right = false;
	int animalType = rand() % 2;

	BodyBox pigBox = BodyBox(64, 64);
	int damage = 0;
	int maxDamage = 50 + (50 * animalType);
	bool alive = true;

	bool beingAttacked = false;
	WeaponBox hornsBox;

public:
	Animal(int inpX, int inpY);
	Animal();

	BodyBox getBodybox();
	void damageDone(int inpD);
	bool getAlive();

	void update();

	void draw(RenderWindow* window);
};