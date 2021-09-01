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