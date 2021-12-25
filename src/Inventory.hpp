#pragma once

//sfml imports
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;

//other import
#include "Item.hpp"
#include "ItemStack.hpp"

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

	void drawInventory(sf::RenderWindow* window);
	void drawCraftSlot(sf::RenderWindow* window, int slotNum);
	void drawCraftSlot(sf::RenderWindow* window, int slotNum, int recipe);
	void drawBackpack(sf::RenderWindow* window);
	void drawButton(sf::RenderWindow* window);
};