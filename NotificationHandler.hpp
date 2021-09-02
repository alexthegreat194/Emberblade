#pragma once 

//sfml imports
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
//other imports
#include <vector>
#include "Notification.hpp"

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