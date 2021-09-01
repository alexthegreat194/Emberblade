#include <BodyBox.hpp>

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