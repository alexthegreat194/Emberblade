#include "WeaponBox.hpp"
#include <SFML/Graphics.hpp>
using namespace sf;

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