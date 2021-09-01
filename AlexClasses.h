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




class Inventory
{
private:
	ItemStack stacks[25];
	bool pressed = false;
	int scroll = 0;

public:
	Inventory();

	void printItems();
	int getScroll();

	bool canAdd(Item inp);
	bool canRemove(Item inp);

	void addItem(Item inp);
	void addItem(Item inp, int num);
	void removeItem(Item inp);

	bool intercectsButton(int x, int y);
	int clickCraft(int x, int y);
	void craft(int recipe);

	void drawInventory(RenderWindow* window);
	void drawCraftSlot(RenderWindow* window, int slotNum);
	void drawCraftSlot(RenderWindow* window, int slotNum, int recipe);
	void drawBackpack(RenderWindow* window);
	void drawButton(RenderWindow* window);
};


//Notifications
class Notification
{
	string message;
	Item notifItem;
	Clock showTimer;

public:

	Notification(string inpMessage);
	Notification(string inpMessage, Item inpItem);

	Item getItem();
	string getMessage();
	bool getShow();
};

class NotificationHandler
{
private:
	vector<Notification> notifications;
	int mCount = 0;

public:

	void addNotification(Notification inpNotif);
	void update();
	void draw(RenderWindow* window);
};

//Hitboxes
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

//Npcs
class Animal
{
private:
	int x;
	int y;

	int randomX;
	int randomY;
	bool destinationSelected = false;

	Clock walkTimer;

	Clock frameTimer;
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