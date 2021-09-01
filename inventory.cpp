#include "Inventory.hpp"

#define MAXSTACKS 25

Inventory::Inventory()
{
	std::printf("Items:\n");
	for (int i = 0; i < MAXSTACKS; i++)
	{
		std::printf("\tstack[%i]: %i %i\n", i, stacks[i].getType(), stacks[i].getCount());
	}
}

void Inventory::printItems()
{
	std::printf("Items:\n");
	for (int i = 0; i < MAXSTACKS; i++)
	{
		if (stacks[i].getType() != ItemType::empty)
			std::printf("\tstack[%i]: %i %i\n", i, stacks[i].getType(), stacks[i].getCount());
	}
}
int Inventory::getScroll()
{
	return scroll;
}

bool Inventory::canAdd(Item inp)
{
	for (int i = 0; i < MAXSTACKS; i++)
	{
		if (stacks[i].canAdd(inp))
		{
			return true;
		}
	}
	return false;
}
bool Inventory::canRemove(Item inp)
{
	for (int i = 0; i < MAXSTACKS; i++)
	{
		if (stacks[i].canRemove(inp))
		{
			return true;
		}
	}
	return false;
}
void Inventory::addItem(Item inp)
{
	for (int i = 0; i < MAXSTACKS; i++)
	{
		if (stacks[i].canAdd(inp))
		{
			stacks[i].add(inp);
			return;
		}
	}
}
void Inventory::addItem(Item inp, int num)
{
	for (size_t i = 0; i < num; i++)
	{
		addItem(inp);
	}
}
void Inventory::removeItem(Item inp)
{
	if (canRemove(inp))
	{
		for (int i = 0; i < MAXSTACKS; i++)
		{
			if (stacks[i].canRemove(inp))
			{
				stacks[i].removeItem(inp);
				return;
			}
		}
	}
}

bool Inventory::intercectsButton(int x, int y)
{
	if ((x > 1200) && (x < 1244))
	{
		if ((y > 25) && (y < 69))
		{
			return true;
		}
	}
	return false;
}
int Inventory::clickCraft(int x, int y)
{
	//450, 200 + (slotNum*50)

	for (size_t i = 0; i < 5; i++)
	{
		if ((x > 450) && (x < 600))
		{
			if ((y > 200 + (i * 50)) && (y < 250 + (i * 50)))
			{
				return i + 1;
			}
		}
	}

	return 0;
}
void Inventory::craft(int recipe)
{
	switch (recipe)
	{
	case 1:
		if ((canRemove(Item(ItemType::plant)) && canRemove(Item(ItemType::meat))) && canAdd(Item(ItemType::healthPotion)))
		{
			removeItem(Item(ItemType::plant));
			removeItem(Item(ItemType::meat));
			addItem(Item(ItemType::healthPotion));
			notifHandler.addNotification(Notification("Crafted", Item(ItemType::healthPotion)));
			printItems();
		}
		else
		{
			notifHandler.addNotification(Notification("Not Crafted"));
		}

		break;
	default:
		break;
	}
}

void Inventory::drawInventory(RenderWindow * window)
{
	RectangleShape background(Vector2f(100, 50));
	background.setFillColor(Color(0, 0, 0));
	background.setOutlineThickness(2);
	background.setOutlineColor(Color::Cyan);
	window->draw(background);

	Sprite mush = mushroom[0];

	Sprite leatherRect = leatherIcon;
	leatherRect.setScale(.5, .5);

	Sprite meatRect = meatIcon;
	meatRect.setScale(.5, .5);

	Sprite potionhRect = potionhSprite;
	potionhRect.setScale(.5, .5);

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (stacks[(y * 10) + x].getType() == ItemType::plant)
			{
				mush.setPosition(x * 10, y * 10);
				window->draw(mush);
			}
			else if (stacks[(y * 10) + x].getType() == ItemType::leather)
			{
				leatherRect.setPosition(x * 10, y * 10);
				window->draw(leatherRect);
			}
			else if (stacks[(y * 10) + x].getType() == ItemType::meat)
			{
				meatRect.setPosition(x * 10, y * 10);
				window->draw(meatRect);
			}
			else if (stacks[(y * 10) + x].getType() == ItemType::healthPotion)
			{
				potionhRect.setPosition(x * 10, y * 10);
				window->draw(potionhRect);
			}
		}
	}
}
void Inventory::drawCraftSlot(RenderWindow * window, int slotNum)
{
	RectangleShape slotOutline(Vector2f(150, 50));
	slotOutline.setPosition(450, 200 + (slotNum * 50));
	slotOutline.setOutlineThickness(-2);
	slotOutline.setOutlineColor(Color::Green);
	slotOutline.setFillColor(Color::Black);
	window->draw(slotOutline);

	RectangleShape slot1(Vector2f(25, 25));
	slot1.setPosition(450 + 5, 200 + (slotNum * 50) + 12.5);
	slot1.setOutlineColor(Color::White);
	slot1.setOutlineThickness(1);
	slot1.setFillColor(Color::Black);
	window->draw(slot1);

	RectangleShape slot2(Vector2f(25, 25));
	slot2.setPosition(450 + 37.5, 200 + (slotNum * 50) + 12.5);
	slot2.setOutlineColor(Color::White);
	slot2.setOutlineThickness(1);
	slot2.setFillColor(Color::Black);
	window->draw(slot2);

	ConvexShape arrow(7);
	arrow.setPoint(0, Vector2f(0, 5));
	arrow.setPoint(1, Vector2f(25, 5));
	arrow.setPoint(2, Vector2f(25, 0));
	arrow.setPoint(3, Vector2f(40, 20));
	arrow.setPoint(4, Vector2f(25, 40));
	arrow.setPoint(5, Vector2f(25, 35));
	arrow.setPoint(6, Vector2f(0, 35));
	arrow.setPosition(450 + 70, 200 + (slotNum * 50) + 5);
	arrow.setOutlineColor(Color::White);
	arrow.setOutlineThickness(-1);
	arrow.setFillColor(Color::Green);
	window->draw(arrow);

	RectangleShape slot3(Vector2f(25, 25));
	slot3.setPosition(450 + 115, 200 + (slotNum * 50) + 12.5);
	slot3.setOutlineColor(Color::White);
	slot3.setOutlineThickness(1);
	slot3.setFillColor(Color::Black);
	window->draw(slot3);

}
void Inventory::drawCraftSlot(RenderWindow * window, int slotNum, int recipe)
{
	Sprite icon1;
	Sprite icon2;
	Sprite icon3;

	switch (recipe)
	{
	case 1:
		icon1 = mushroom[1];
		icon1.setScale(1.6, 2);
		icon2 = meatIcon;
		icon2.setScale(.75, .75);
		icon3 = potionhSprite;
		icon3.setScale(.75, .75);
		break;
	default:
		return;
		break;
	}

	RectangleShape slotOutline(Vector2f(150, 50));
	slotOutline.setPosition(450, 200 + (slotNum * 50));
	slotOutline.setOutlineThickness(-2);
	slotOutline.setOutlineColor(Color::Green);
	slotOutline.setFillColor(Color::Black);
	//window->draw(slotOutline);
	drawFrame(window, 450, 200 + (slotNum * 50), 150, 50);

	RectangleShape slot1(Vector2f(25, 25));
	slot1.setPosition(450 + 5, 200 + (slotNum * 50) + 12.5);
	slot1.setOutlineColor(Color::White);
	slot1.setOutlineThickness(1);
	slot1.setFillColor(Color::Black);
	window->draw(slot1);
	drawFrame(window, 450 + 5, 200 + (slotNum * 50) + 12.5, 25, 25);
	icon1.setPosition(450 + 5, 200 + (slotNum * 50) + 12.5);
	window->draw(icon1);

	RectangleShape slot2(Vector2f(25, 25));
	slot2.setPosition(450 + 37.5, 200 + (slotNum * 50) + 12.5);
	slot2.setOutlineColor(Color::White);
	slot2.setOutlineThickness(1);
	slot2.setFillColor(Color::Black);
	window->draw(slot2);
	icon2.setPosition(450 + 37.5, 200 + (slotNum * 50) + 12.5);
	window->draw(icon2);

	ConvexShape arrow(7);
	arrow.setPoint(0, Vector2f(0, 5));
	arrow.setPoint(1, Vector2f(25, 5));
	arrow.setPoint(2, Vector2f(25, 0));
	arrow.setPoint(3, Vector2f(40, 20));
	arrow.setPoint(4, Vector2f(25, 40));
	arrow.setPoint(5, Vector2f(25, 35));
	arrow.setPoint(6, Vector2f(0, 35));
	arrow.setPosition(450 + 70, 200 + (slotNum * 50) + 5);
	arrow.setOutlineColor(Color::White);
	arrow.setOutlineThickness(-1);
	arrow.setFillColor(Color::Green);
	window->draw(arrow);

	RectangleShape slot3(Vector2f(25, 25));
	slot3.setPosition(450 + 115, 200 + (slotNum * 50) + 12.5);
	slot3.setOutlineColor(Color::White);
	slot3.setOutlineThickness(1);
	slot3.setFillColor(Color::Black);
	window->draw(slot3);
	icon3.setPosition(450 + 115, 200 + (slotNum * 50) + 12.5);
	window->draw(icon3);

}
void Inventory::drawBackpack(RenderWindow * window)
{
	RectangleShape backpackBG(Vector2f(400, 250));
	//backpackBG.setOutlineThickness(2);
	backpackBG.setOutlineColor(Color::Blue);
	backpackBG.setPosition(200, 200);
	backpackBG.setFillColor(Color::Black);
	window->draw(backpackBG);
	drawFrame(window, 180, 180, 445, 295);

	RectangleShape box(Vector2f(50, 50));
	box.setOutlineThickness(-1);
	box.setOutlineColor(Color::Red);
	box.setFillColor(Color(0, 0, 150));

	Sprite currentSlot;
	int slotX = 1;
	int slotY = 1;

	Sprite mush = mushroom[0];
	mush.setScale(2.25, 2.25);

	Sprite leatherRect = leatherIcon;
	//leatherRect.setScale(1.5625, 1.5625);

	Sprite meatRect = meatIcon;
	//meatRect.setScale(.5, .5);

	Sprite potionhRect = potionhSprite;
	potionhRect.setScale(1, 1);

	Text stackSizeText;
	stackSizeText.setFont(font);
	stackSizeText.setFillColor(Color::White);
	stackSizeText.setOutlineColor(Color::Black);
	stackSizeText.setOutlineThickness(2);

	int times = 0;

	for (size_t i = 0; i < 5; i++)
	{
		for (size_t x = 0; x < 5; x++)
		{
			box.setPosition(200 + (x) * 50, 200 + (i) * 50);
			//window->draw(box);

			times++;

			slotX = 1;
			slotY = 1;
			if (x == 0)
				slotX = 0;
			else if (x == 4)
				slotX = 2;

			if (i == 0)
				slotY = 0;
			else if (i == 5)
				slotY = 2;

			currentSlot = slotSprite[slotY][slotX];
			currentSlot.setScale(1.4, 1.4);
			currentSlot.setPosition(200 + (x) * 50, 200 + (i) * 50);
			window->draw(currentSlot);

			switch (stacks[(i * 5) + x].getType())
			{
			case ItemType::empty:
				break;
			case ItemType::plant:
				mush.setPosition(210 + (x) * 50, 210 + (i) * 50);
				window->draw(mush);

				stackSizeText.setPosition(210 + (x) * 50, 225 + (i) * 50);
				stackSizeText.setString(to_string(stacks[(i * 5) + x].getCount()));
				stackSizeText.setCharacterSize(15);
				window->draw(stackSizeText);

				break;
			case ItemType::leather:
				leatherRect.setPosition(210 + (x) * 50, 210 + (i) * 50);
				window->draw(leatherRect);

				stackSizeText.setPosition(210 + (x) * 50, 225 + (i) * 50);
				stackSizeText.setString(to_string(stacks[(i * 5) + x].getCount()));
				stackSizeText.setCharacterSize(15);
				window->draw(stackSizeText);
				break;
			case ItemType::meat:
				meatRect.setPosition(210 + (x) * 50, 210 + (i) * 50);
				window->draw(meatRect);

				stackSizeText.setPosition(210 + (x) * 50, 225 + (i) * 50);
				stackSizeText.setString(to_string(stacks[(i * 5) + x].getCount()));
				stackSizeText.setCharacterSize(15);
				window->draw(stackSizeText);
				break;
			case ItemType::healthPotion:
				potionhRect.setPosition(210 + (x) * 50, 210 + (i) * 50);
				window->draw(potionhRect);

				stackSizeText.setPosition(210 + (x) * 50, 225 + (i) * 50);
				stackSizeText.setString(to_string(stacks[(i * 5) + x].getCount()));
				stackSizeText.setCharacterSize(15);
				window->draw(stackSizeText);
				break;
			default:
				break;
			}

			std::printf("index: %i\n", (i * 10) + x);
		}
	}



	for (size_t i = 0; i < 5; i++)
	{
		drawCraftSlot(window, i, i + scroll + 1);
	}
}
void Inventory::drawButton(RenderWindow * window)
{
	Sprite icon = craftingIcon;
	Sprite button;

	if (mode == gameMode::inventory)
		button = buttonClicked;
	else
		button = buttonNClicked;

	button.setPosition(1200, 25);
	window->draw(button);

	icon.setPosition(1208, 37);
	window->draw(icon);
}