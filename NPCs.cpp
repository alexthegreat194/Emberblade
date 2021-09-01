
//sfml imports
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <Windows.h>

//header Files
#include "AlexClasses.h"
#include "AlexGlobals.h"

//namespaces
using namespace sf;
using namespace std;
//using namespace 

//Animal 
	Animal::Animal(int inpX, int inpY)
	{
		x = inpX;
		y = inpY;
		//printf("Animal: %i :: %i , t: %i\n", x, y, animalType);
		hornsBox = WeaponBox(10);
	}
	Animal::Animal()
	{
		x = 200;
		y = 200;
		hornsBox = WeaponBox(10);
	}

	BodyBox Animal::getBodybox()
	{
		return pigBox;
	}
	void Animal::damageDone(int inpD)
	{
		damage += inpD;
		printf("d: %i md: %i\n", damage, maxDamage);

		//give people things
		if ((damage > maxDamage) && alive)
		{
			if (animalType == 0)
			{
				playerInv.addItem(Item(ItemType::meat));
				notifHandler.addNotification(Notification("Recieved", Item(ItemType::meat)));
			}
			else
			{
				playerInv.addItem(Item(ItemType::leather));
				notifHandler.addNotification(Notification("Recieved", Item(ItemType::leather)));
			}

			alive = false;
		}
		if (damage > 0)
		{
			beingAttacked = true;
		}
	}
	bool Animal::getAlive()
	{
		return alive;
	}

	void Animal::update()
	{
		if (!alive)
			return;
		hornsBox.setPosition(x, y);

		if (beingAttacked)
		{
			int distX = localX - x;
			int distY = localY - y;

			if (animalType == 0)
			{
				if (x < localX)
				{
					x -= 1;
					right = false;
				}
				else if (x > localX)
				{
					x += 1;
					right = true;
				}

				if (y < localY)
				{
					y -= 1;
					up = true;
				}
				else if (y > localY)
				{
					y += 1;
					up = false;
				}
			}
			else
			{
				if (x > localX)
				{
					x -= 1;
					right = false;
				}
				else if (x < localX)
				{
					x += 1;
					right = true;
				}

				if (y > localY)
				{
					y -= 1;
					up = true;
				}
				else if (y < localY)
				{
					y += 1;
					up = false;
				}
			}
		}
		else
		{
			//checks for destinattion
			if (!destinationSelected)
			{
				//gets new coords
				bool find = true;
				while (find)
				{
					randomX = (rand() % 400) - 200 + x;
					randomY = (rand() % 400) - 200 + y;

					find = false;
					if ((randomX < 0) || (randomX > WORLD_WIDTH))
						find = true;
					else if ((randomY < 0) || (randomY > WORLD_HIEGHT))
						find = true;
				}
				destinationSelected = true;
			}
			else
			{
				//moves bruh to coords

				if (walkTimer.getElapsedTime().asMilliseconds() > 10)
				{
					walkTimer.restart();

					if (x > randomX)
					{
						x -= 1;
						right = false;
					}
					else if (x < randomX)
					{
						x += 1;
						right = true;
					}

					if (y > randomY)
					{
						y -= 1;
						up = true;
					}
					else if (y < randomY)
					{
						y += 1;
						up = false;
					}
				}

				//checks if they are equal
				if ((x == randomX) && (y == randomY))
				{
					//cout << "arrived" << endl;
					destinationSelected = false;
				}
			}
		}


		//updates frames
		if (frameTimer.getElapsedTime().asMilliseconds() > 200)
		{
			frames++;
			frameTimer.restart();
		}

		//update bodybox
		pigBox.setPosition(x, y);
	}

	void Animal::draw(RenderWindow * window)
	{
		if (!alive)
			return;

		Sprite toDraw;

		if (animalType == 0)
		{
			if (abs(x - randomX) > abs(y - randomY))
			{
				if (right)
					toDraw = pigRight[frames % 3];
				else
					toDraw = pigLeft[frames % 3];
			}
			else
			{
				if (up)
					toDraw = pigUp[frames % 3];
				else
					toDraw = pigDown[frames % 3];
			}
		}
		else
		{
			if (abs(x - randomX) > abs(y - randomY))
			{
				if (right)
					toDraw = boarRight[frames % 3];
				else
					toDraw = boarLeft[frames % 3];
			}
			else
			{
				if (up)
					toDraw = boarUp[frames % 3];
				else
					toDraw = boarDown[frames % 3];
			}
		}

		toDraw.setPosition(x, y);
		toDraw.setOrigin(32, 32);
		toDraw.setColor(Color(255, 255 - ((float(damage) / float(maxDamage)) * 255), 255 - ((float(damage) / float(maxDamage)) * 255)));
		window->draw(toDraw);

		if (debug)
		{
			pigBox.draw(window);
			hornsBox.draw(window);
		}
	}
