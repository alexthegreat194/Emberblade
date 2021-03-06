#include "NotificationHandler.hpp"
#include "Globals.hpp"

void NotificationHandler::addNotification(Notification inpNotif)
{
    notifications.push_back(inpNotif);
}

void NotificationHandler::update()
{
    for (int i = 0; i < notifications.size(); i++)
    {
        if (!notifications[i].getShow())
        {
            notifications.erase(notifications.begin() + i);
        }
    }
}

void NotificationHandler::draw(RenderWindow * window)
{
    update();

    RectangleShape rect(Vector2f(125, 30));
    rect.setFillColor(Color::Black);
    rect.setOutlineColor(Color::Magenta);
    rect.setOutlineThickness(2);

    Sprite nSprite;
    nSprite.setScale(1, 1);

    Text nText;
    nText.setFont(font);
    nText.setCharacterSize(15);

    for (int i = 0; i < notifications.size(); i++)
    {
        //select icon
        switch (notifications[i].getItem().getType())
        {
        case ItemType::plant:
            nSprite = mushroom[0];
            nSprite.setScale(2, 2);
            break;
        case ItemType::meat:
            nSprite = meatIcon;
            nSprite.setScale(1, 1);
            break;
        case ItemType::leather:
            nSprite = leatherIcon;
            nSprite.setScale(1, 1);
            break;
        case ItemType::empty:
            nSprite = Sprite();
            nSprite.setScale(1, 1);
            break;
        default:
            break;
        }

        nText.setString(notifications[i].getMessage());
        nText.setOrigin(nText.getLocalBounds().width + 5, nText.getCharacterSize() + 5);

        rect.setPosition(MYWINDOW_WIDTH * .75, MYWINDOW_HEIGHT * .5 + (i * 40));
        window->draw(rect);
        drawFrame(window, MYWINDOW_WIDTH * .75 - 2, MYWINDOW_HEIGHT * .5 + (i * 40) - 2, 129, 34);

        nSprite.setPosition(MYWINDOW_WIDTH * .75, MYWINDOW_HEIGHT * .5 + (i * 40));
        window->draw(nSprite);
        nText.setPosition(MYWINDOW_WIDTH * .75 + 115, MYWINDOW_HEIGHT * .5 + (i * 40) + 25);
        window->draw(nText);
    }
}