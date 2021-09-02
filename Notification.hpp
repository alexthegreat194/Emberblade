#pragma once

//sfml imports
#include <SFML/System.hpp>
//other imports
#include <string>
#include "Item.hpp"

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