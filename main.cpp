
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

//header Files
#include "AlexClasses.h"
#include "AlexGlobals.h"
#include <thread>

//namespaces
using namespace sf;
using namespace std;

#define PI 3.14159265359

#define MYWINDOW_HEIGHT 720
#define MYWINDOW_WIDTH 1280

#define MAX_SPEED .15
#define WORLD_WIDTH 20000
#define WORLD_HIEGHT 20000

#define PI 3.14159265359

#define MYWINDOW_HEIGHT 720
#define MYWINDOW_WIDTH 1280

#define MAX_SPEED .15
#define WORLD_WIDTH 20000
#define WORLD_HIEGHT 20000

//global variable:
bool debug = false;
double worldX = 0;
double worldY = 0;
double worldZoom = 0;

double localX = 100;
double localY = 100;

int mouseX = 0;
int mouseY = 0;

float mouseDX = 0;
float mouseDY = 0;
float mouseRatio = 0;

//texture and sprite variables
Texture sheepTexture;
Texture grassTexture;
Texture grassBackTexture;
Texture grassFrontTexture;
Sprite grassSprite;
Sprite grassBackSprite;
Sprite grassFrontSprite;

Texture styleSheet;
Sprite mushroom[3];

Texture leatherSheet;
Sprite leatherIcon;

Texture meatSheet;
Sprite meatIcon;

Texture spearSheet;
Sprite spearSprite;
Sprite spearSpriteStatic;

Texture swordSheet;
Sprite swordSprite;
Sprite swordSpriteStatic;

Texture potionhSheet;
Sprite potionhSprite;
Texture potionaSheet;
Sprite potionaSprite;

Texture pigTexture;
Sprite pigUp[3];
Sprite pigRight[3];
Sprite pigDown[3];
Sprite pigLeft[3];

Texture boarTexture;
Sprite boarUp[3];
Sprite boarRight[3];
Sprite boarDown[3];
Sprite boarLeft[3];

Texture uiTexture;
Sprite slotSprite[3][3];
Sprite mouseSprite;
Sprite buttonNClicked;
Sprite buttonClicked;
Sprite craftingIcon;
Sprite frameTop[3];
Sprite frameMiddle[3];
Sprite frameBottom[3];
Sprite healthBarEmpty[3];
Sprite healthBarGreen[3];

Texture playerTexture;
Sprite pUp[9];
Sprite pLeft[9];
Sprite pDown[9];
Sprite pRight[9];
Sprite playerSprite;
int walkingFrames = 0;
Clock walkingClock;
bool playerIsWalking = false;

Font font;
Text fpsText;
Text interactText;

//weopon variables
enum weaponType
{
	spear, sword
};


//player weapon and hitbox varialbes
bool weaponOut = false;
weaponType playerWeapon = weaponType::sword;
int weaponFrame = 100;
Clock weaponClock;
WeaponBox weapon[3];


void drawFrame(RenderWindow *window, int x, int y, int w, int h)
{
	//32 x 32, 96

	double sectionH = h / 3.0;
	double sectionW = w / 3.0;

	for (size_t i = 0; i < 3; i++)
	{
		frameTop[i].setPosition(x + (i * sectionW), y + (0 * sectionH));
		frameTop[i].setScale(sectionW / 32, sectionH / 32);

		frameMiddle[i].setPosition(x + (i * sectionW), y + (1 * sectionH));
		frameMiddle[i].setScale(sectionW / 32, sectionH / 32);

		frameBottom[i].setPosition(x + (i * sectionW), y + (2 * sectionH));
		frameBottom[i].setScale(sectionW / 32, sectionH / 32);
	}

	if (w >= h)
	{
		frameTop[0].setScale(sectionH / 32, sectionH / 32);
		frameTop[1].setScale((w - 2 * sectionH) / 32, sectionH / 32);
		frameTop[1].setPosition(x + sectionH, y);
		frameTop[2].setScale(sectionH / 32, sectionH / 32);

		frameMiddle[0].setScale(sectionH / 32, (h - 2 * sectionH) / 32);
		frameMiddle[0].setPosition(x, y + sectionH);
		frameMiddle[1].setPosition(x + sectionH, y + sectionH);
		frameMiddle[2].setScale(sectionH / 32, (h - 2 * sectionH) / 32);
		frameMiddle[2].setPosition(x + 3*sectionW, y + sectionH);
		frameMiddle[2].setOrigin(frameMiddle[2].getLocalBounds().width, 0);

		frameBottom[0].setScale(sectionH / 32, sectionH / 32);
		frameBottom[1].setScale((w - 2 * sectionH) / 32, sectionH / 32);
		frameBottom[1].setPosition(x + sectionH, y + h - sectionH);
		frameBottom[1].setOrigin(0, 0);
		frameBottom[2].setScale(sectionH / 32, sectionH / 32);
		
		frameMiddle[1].setScale((w - 2 * sectionH) / 32, sectionH / 32);
	}
	else
	{
		frameTop[0].setScale(sectionW / 32, sectionW / 32);
		frameTop[1].setScale((w - 2 * sectionW) / 32, sectionW / 32);
		frameTop[1].setPosition(x + sectionW, y);
		frameTop[2].setScale(sectionW / 32, sectionW / 32);

		frameMiddle[0].setScale(sectionW / 32, (h - 2 * sectionW) / 32);
		frameMiddle[0].setPosition(x, y + sectionW);
		frameMiddle[1].setPosition(x + sectionW, y + sectionW);
		frameMiddle[2].setScale(sectionW / 32, (h - 2 * sectionW) / 32);
		frameMiddle[2].setPosition(x + 3 * sectionW, y + sectionW);
		frameMiddle[2].setOrigin(frameMiddle[2].getLocalBounds().width, 0);

		frameBottom[0].setScale(sectionW / 32, sectionW / 32);
		frameBottom[1].setScale((w - 2 * sectionW) / 32, sectionW / 32);
		frameBottom[1].setPosition(x + sectionW, y + h);
		frameBottom[1].setOrigin(0, sectionH);
		frameBottom[2].setScale(sectionW / 32, sectionW / 32);

		frameMiddle[1].setScale((w - 2 * sectionW) / 32, (h - 2 * sectionW) / 32);
	}
	
	frameTop[2].setOrigin(frameBottom[2].getLocalBounds().width, 0);
	frameTop[2].setPosition(x + w, y);
	frameBottom[0].setOrigin(0, frameBottom[0].getLocalBounds().height);
	frameBottom[0].setPosition(x, y + h);
	frameBottom[2].setOrigin(frameBottom[2].getLocalBounds().width, frameBottom[2].getLocalBounds().height);
	frameBottom[2].setPosition(x + w, y + h);

	//draw thjings

	for (size_t i = 0; i < 3; i++)
	{
		window->draw(frameTop[i]);
		window->draw(frameMiddle[i]);
		window->draw(frameBottom[i]);
	}
}

NotificationHandler notifHandler;

gameMode mode = game;

Inventory playerInv;

class Hotbar
{
public:

	weaponType hotbarWeapon = weaponType::sword;
	Item items[5] = { Item(ItemType::empty), Item(ItemType::empty), Item(ItemType::empty), Item(ItemType::empty) , Item(ItemType::empty) };
	
	void setItem(int index, ItemType type)
	{
		items[index].setType(type);
	}

	void setWeapon(weaponType inpW)
	{
		hotbarWeapon = inpW;
	}

	void drawBar(RenderWindow* window)
	{
		//draw main frame
		drawFrame(window, 200, 620, 400, 100);

		//draw icon boxes
		Text controlText("", font);
		controlText.setOutlineColor(Color::Black);
		controlText.setOutlineThickness(1);
		controlText.setCharacterSize(10);

		Sprite sword = spearSpriteStatic;

		for (size_t i = 0; i < 5; i++)
		{
			drawFrame(window, 200 + (65 * i) + 20, 620 + 15, 60, 60);
		}

		controlText.setPosition(200 + (65 * 0) + 20 + 30, 620 + 15 + 65);
		controlText.setString("1");
		window->draw(controlText);
		controlText.setPosition(200 + (65 * 1) + 20 + 30, 620 + 15 + 65);
		controlText.setString("2");
		window->draw(controlText);
		controlText.setPosition(200 + (65 * 2) + 20 + 30, 620 + 15 + 65);
		controlText.setString("3");
		window->draw(controlText);
		controlText.setPosition(200 + (65 * 3) + 20 + 30, 620 + 15 + 65);
		controlText.setString("4");
		window->draw(controlText);
		controlText.setPosition(200 + (65 * 4) + 20 + 30, 620 + 15 + 65);
		controlText.setString("5");
		window->draw(controlText);
	}
};
Hotbar hotBar;


class DamageNumber
{
	int x, y;
	int damage;
	int visible = 255;

public:
	DamageNumber(int ix, int iy, int idamage)
	{
		x = ix;
		y = iy;
		damage = idamage;
	}

	bool update()
	{
		visible = visible - 5;
		if (visible < 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void draw(RenderWindow* window)
	{
		if (debug)
		{
			CircleShape bruh(10);
			bruh.setFillColor(Color(255, 0, 0, 100));
			bruh.setPosition(x, y);
			bruh.setOrigin(10, 10);
			window->draw(bruh);
		}

		Text dText;
		dText.setFont(font);
		dText.setPosition(x, y);

		dText.setFillColor(Color(255, 255, 255, visible));
		dText.setOutlineColor(Color(0, 0, 0, visible));
		dText.setOutlineThickness(1);

		dText.setString(to_string(damage));
		dText.setCharacterSize(10);
		//std::printf("text: x: %i y: %i v: %i\n", x, y, visible);
		window->draw(dText);
	}
};
vector<DamageNumber> dmVector;

class Plant
{
public:
	int x;
	int y;
	bool collectable = false;

	bool active = true;
	Clock harvestTimer;

	int frames = 0;
	Clock frameTimer;

	Plant(int inpx = 200, int inpy = 200)
	{
		x = inpx;
		y = inpy;
	}

	void harvest()
	{
		if (active && collectable)
		{
			active = false;
			harvestTimer.restart();
			playerInv.addItem(Item(ItemType::plant));
			notifHandler.addNotification(Notification("Recieved", Item(ItemType::plant)));
			playerInv.printItems();
		}
		else if (!active)
		{
			int seconds = harvestTimer.getElapsedTime().asSeconds();
			//std::printf("timer: %i\n", seconds);

			if (seconds >= 3)
			{
				active = true;
				std::printf("replenish");
			}
		}
		else if (active)
		{
			harvestTimer.restart();
		}
	}

	void update()
	{
		int xdistance = abs(x - localX);
		int ydistance = abs(y - localY);

		//std::printf("distX: %i distY: %i\n", xdistance, ydistance);

		if ((xdistance < 60) && (ydistance < 80))
			collectable = true;
		else
			collectable = false;

		if (frameTimer.getElapsedTime().asMilliseconds() > 500)
		{
			frames++;
			frameTimer.restart();
		}

		if (!active)
			if (harvestTimer.getElapsedTime().asSeconds() >= 3)
				active = true;

	}

	void draw(RenderWindow * window)
	{

		//return;

		/*RectangleShape rect(Vector2f(50, 50));
		rect.setPosition(Vector2f(x, y));
		rect.setOrigin(10, 10);
		rect.setFillColor(Color(66, 94, 25));
		if (!active)
			rect.setFillColor(Color(199, 152, 22));
		if (collectable)
		{
			rect.setOutlineThickness(-2);
			rect.setOutlineColor(Color::Cyan);
		}*/

		//window->draw(rect);

		Sprite drawSprite;
		drawSprite.setPosition(x, y);
		drawSprite.setOrigin(3, 3);
		drawSprite.setTexture(styleSheet);
		drawSprite.setTextureRect(mushroom[frames % 3].getTextureRect());
		drawSprite.setScale(4.142, 3.666);
		if (collectable)
			drawSprite.setColor(Color(25, 25, 0));
		if (!active)
			drawSprite.setColor(Color(50, 50, 0));

		window->draw(drawSprite);

		if (collectable && active)
		{
			Text pressE;
			pressE.setString("press E");
			pressE.setFillColor(Color::White);
			pressE.setFont(font);
			pressE.setPosition(x, y);
			pressE.setCharacterSize(8);

			window->draw(pressE);
		}
	}
};

int mouseDegrees()
{
	float dx = mouseX - MYWINDOW_WIDTH / 2 + worldX;
	float dy = mouseY - MYWINDOW_HEIGHT / 2 + worldY;

	float rotation = (atan2(dy, dx)) * 180 / PI;
	int result = int(rotation) + 180;

	//std::printf("Mouse Degrees: %i\tdx: %f\tdy: %f", result, float(cos(rotation/(PI/180))), sin(rotation / (PI / 180)));
	return result;
}

float mouseSlope()
{
	float dx = mouseX - MYWINDOW_WIDTH / 2 + worldX;
	float dy = mouseY - MYWINDOW_HEIGHT / 2 + worldY;

	//std::printf("\tSlope: %f\n", (float(dx) / float(dy)));
	return dy / dx;
}

Vector2f mousePoint(float size)
{
	float dx = mouseX - MYWINDOW_WIDTH / 2;
	float dy = mouseY - MYWINDOW_HEIGHT / 2;

	float dh = sqrt((dx * dx) + (dy * dy));
	float ratio = size / dh;
	mouseRatio = ratio;

	Vector2f rVector;
	rVector.x = (dx * ratio);
	rVector.y = (dy * ratio);

	//std::printf("x: %f\ty: %f\n", rVector.x, rVector.y);

	return rVector;
}

Vector2f mousePoint(float size, int angle)
{
	float dx = cos((angle + 180) * (PI / 180)) * size;
	float dy = sin((angle + 180) * (PI / 180)) * size;

	Vector2f rVector;
	rVector.x = dx;
	rVector.y = dy;

	return rVector;
}

bool isBetween(int testNumber, int num1, int num2)
{
	if ((testNumber >= num1) && (testNumber <= num2))
		return true;
	return false;
}

int imagesLoaded = 0;
void loadTextures()
{
	font.loadFromFile("arial.ttf");
	sheepTexture.loadFromFile("assets\\sheep.png");
	grassTexture.loadFromFile("assets\\grass.jpg");
	grassTexture.loadFromFile("assets\\grassB.png");
	grassTexture.setRepeated(true);
	grassSprite.setTexture(grassTexture);
	grassSprite.setTextureRect(IntRect(0, 0, 20000, 20000));
	imagesLoaded++;

	grassBackTexture.loadFromFile("assets\\grassBack.png");
	grassBackSprite.setTexture(grassBackTexture);
	grassBackSprite.setScale(1.04167, 1.04167);
	imagesLoaded++;

	grassFrontTexture.loadFromFile("assets\\grassFront.png");
	grassFrontSprite.setTexture(grassFrontTexture);
	grassFrontSprite.setScale(1.04167, 1.04167);
	imagesLoaded++;

	//stylesheet sprites
	styleSheet.loadFromFile("assets\\sheet.png");
	for (size_t i = 0; i < 3; i++)
		mushroom[i].setTexture(styleSheet);
	mushroom[0].setTextureRect(IntRect(129, 131, 14, 15));
	mushroom[1].setTextureRect(IntRect(145, 131, 14, 15));
	mushroom[2].setTextureRect(IntRect(161, 131, 14, 15));
	imagesLoaded++;

	leatherSheet.loadFromFile("assets\\leather_icon.png");
	leatherIcon.setTexture(leatherSheet);
	leatherIcon.setTextureRect(IntRect(0, 0, 32, 32));
	imagesLoaded++;

	meatSheet.loadFromFile("assets\\meat_icon.png");
	meatIcon.setTexture(meatSheet);
	meatIcon.setTextureRect(IntRect(0, 0, 32, 32));
	imagesLoaded++;

	spearSheet.loadFromFile("assets\\spear_weapon.png");
	spearSprite.setTexture(spearSheet);
	spearSprite.setTextureRect(IntRect(0, 0, 32, 32));
	spearSpriteStatic = spearSprite;
	imagesLoaded++;

	swordSheet.loadFromFile("assets\\sword_weapon.png");
	swordSprite.setTexture(swordSheet);
	swordSprite.setTextureRect(IntRect(0, 0, 32, 32));
	swordSpriteStatic = swordSprite;
	imagesLoaded++;

	potionaSheet.loadFromFile("assets\\potiona_icon.png");
	potionaSprite.setTexture(potionaSheet);
	potionaSprite.setTextureRect(IntRect(0, 0, 32, 32));
	imagesLoaded++;
	potionhSheet.loadFromFile("assets\\potionh_icon.png");
	potionhSprite.setTexture(potionhSheet);
	potionhSprite.setTextureRect(IntRect(0, 0, 32, 32));
	imagesLoaded++;

	//animal sprites and sheet
	pigTexture.loadFromFile("assets\\pig.png");
	for (size_t i = 0; i < 3; i++)
	{
		pigUp[i].setTexture(pigTexture);
		pigRight[i].setTexture(pigTexture);
		pigDown[i].setTexture(pigTexture);
		pigLeft[i].setTexture(pigTexture);
	}

	for (size_t i = 0; i < 3; i++)
		pigUp[i].setTextureRect(IntRect(i * 64, 0, 64, 64));
	for (size_t i = 0; i < 3; i++)
		pigRight[i].setTextureRect(IntRect(i * 64, 64, 64, 64));
	for (size_t i = 0; i < 3; i++)
		pigDown[i].setTextureRect(IntRect(i * 64, 128, 64, 64));
	for (size_t i = 0; i < 3; i++)
		pigLeft[i].setTextureRect(IntRect(i * 64, 192, 64, 64));
	imagesLoaded++;

	//boar
	boarTexture.loadFromFile("assets\\boar.png");
	for (size_t i = 0; i < 3; i++)
	{
		boarUp[i].setTexture(boarTexture);
		boarRight[i].setTexture(boarTexture);
		boarDown[i].setTexture(boarTexture);
		boarLeft[i].setTexture(boarTexture);
	}

	for (size_t i = 0; i < 3; i++)
		boarUp[i].setTextureRect(IntRect(i * 64, 0, 64, 64));
	for (size_t i = 0; i < 3; i++)
		boarRight[i].setTextureRect(IntRect(i * 64, 64, 64, 64));
	for (size_t i = 0; i < 3; i++)
		boarDown[i].setTextureRect(IntRect(i * 64, 128, 64, 64));
	for (size_t i = 0; i < 3; i++)
		boarLeft[i].setTextureRect(IntRect(i * 64, 192, 64, 64));
	imagesLoaded++;

	//player sheet
	playerTexture.loadFromFile("assets\\gold.png");
	for (size_t i = 0; i < 9; i++)
	{
		pUp[i].setTexture(playerTexture);
		pRight[i].setTexture(playerTexture);
		pDown[i].setTexture(playerTexture);
		pLeft[i].setTexture(playerTexture);
	}
	for (size_t i = 0; i < 9; i++)
		pUp[i].setTextureRect(IntRect(i * 64, 0, 64, 64));
	for (size_t i = 0; i < 9; i++)
		pRight[i].setTextureRect(IntRect(i * 64, 64, 64, 64));
	for (size_t i = 0; i < 9; i++)
		pDown[i].setTextureRect(IntRect(i * 64, 128, 64, 64));
	for (size_t i = 0; i < 9; i++)
		pLeft[i].setTextureRect(IntRect(i * 64, 192, 64, 64));
	imagesLoaded++;

	//ui sprites
	uiTexture.loadFromFile("assets\\ui.png");
	for (size_t y = 0; y < 3; y++)
	{
		slotSprite[y][0].setTexture(uiTexture);
		slotSprite[y][0].setTextureRect(IntRect(316 + 0 * 38, 292 + y * 38, 38, 38));
		slotSprite[y][1].setTexture(uiTexture);
		slotSprite[y][1].setTextureRect(IntRect(316 + 1 * 38, 292 + y * 38, 38, 38));
		slotSprite[y][2].setTexture(uiTexture);
		slotSprite[y][2].setTextureRect(IntRect(316 + 2 * 38, 292 + y * 38, 38, 38));
	}
	mouseSprite.setTexture(uiTexture);
	mouseSprite.setTextureRect(IntRect(200, 108, 16, 16));
	imagesLoaded++;
	buttonClicked.setTexture(uiTexture);
	buttonClicked.setTextureRect(IntRect(802, 481, 44, 44));
	imagesLoaded++;
	buttonNClicked.setTexture(uiTexture);
	buttonNClicked.setTextureRect(IntRect(802, 431, 44, 44));
	imagesLoaded++;
	craftingIcon.setTexture(uiTexture);
	craftingIcon.setTextureRect(IntRect(757, 445, 26, 18));
	imagesLoaded++;

	for (size_t i = 0; i < 3; i++)
	{
		frameTop[i].setTexture(uiTexture);
		frameMiddle[i].setTexture(uiTexture);
		frameBottom[i].setTexture(uiTexture);

		healthBarEmpty[i].setTexture(uiTexture);
		healthBarGreen[i].setTexture(uiTexture);
	}

	for (size_t i = 0; i < 3; i++)
		frameTop[i].setTextureRect(IntRect(16 + (i * 32) + i, 40, 32, 32));
	for (size_t i = 0; i < 3; i++)
		frameMiddle[i].setTextureRect(IntRect(478 + (i * 32) + i, 24, 32, 32));
	for (size_t i = 0; i < 3; i++)
		frameBottom[i].setTextureRect(IntRect(478 + (i * 32) + i, 80, 32, 32));
	imagesLoaded++;

	for (size_t i = 0; i < 3; i++)
		healthBarEmpty[i].setTextureRect(IntRect(259 + (i * 25), 63, 25, 24));
	for (size_t i = 0; i < 3; i++)
		healthBarGreen[i].setTextureRect(IntRect(399 + (i * 7) + i, 72, 7, 14));
	imagesLoaded++;
}
void setText()
{
	//text setting
	fpsText.setFont(font);
	fpsText.setString("Fps:");
	fpsText.setPosition(0, 0);

	interactText.setString("Press \"E\"");
	interactText.setFont(font);
}

void loadingScreen()
{
	//load loading images
	Texture backgroundTexture;
	Sprite backgroundSprite;
	Texture loadingTexture;
	Sprite loadingSprite;

	backgroundTexture.loadFromFile("assets\\loadingPage.png");
	backgroundSprite.setTexture(backgroundTexture);
	loadingTexture.loadFromFile("assets\\potiona_icon.png");
	loadingSprite.setTexture(loadingTexture);

	//loading variables

	int imagesToLoad = 19;
	thread(loadTextures).detach();
	loadingSprite.setScale(0.3645833333333333, 0.462962962962963);
	RectangleShape rect(Vector2f(700, 500));
	rect.setTexture(&backgroundTexture);
	RectangleShape greenBar(Vector2f(1, 25));
	greenBar.setFillColor(Color::Green);
	greenBar.setOutlineThickness(2);
	greenBar.setOutlineColor(Color::Black);

	RenderWindow window(VideoMode(700, 500), "Loading", Style::Titlebar | Style::Close);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		printf("loaded: %i\n", imagesLoaded);
		greenBar.setPosition(100, 425);
		greenBar.setSize(Vector2f(500 * (float(imagesLoaded) / float(imagesToLoad)), greenBar.getSize().y));


		window.clear();
		window.draw(rect);
		window.draw(greenBar);
		window.display();

		if (imagesLoaded / imagesToLoad)
		{
			window.close();
		}
	}

}

int main()
{
	srand(time(NULL));

	loadingScreen();
	setText();

	for (int i = 0; i < 3; i++)
	{
		weapon[i] = WeaponBox(localX, localY, 10);
	}

	RenderWindow window(VideoMode(MYWINDOW_WIDTH, MYWINDOW_HEIGHT), "Moba Monster Hunter", Style::Titlebar | Style::Close);
	window.setFramerateLimit(60);
	window.setMouseCursorVisible(false);

	View view;
	view.setSize(MYWINDOW_WIDTH, MYWINDOW_HEIGHT);
	view.setCenter(MYWINDOW_WIDTH / 2, MYWINDOW_HEIGHT / 2);
	//window.setView(view); 

	View viewHud;
	viewHud.setSize(MYWINDOW_WIDTH, MYWINDOW_HEIGHT);
	viewHud.setCenter(MYWINDOW_WIDTH / 2, MYWINDOW_HEIGHT / 2);
	//window.setView(view);

	RectangleShape world(Vector2f(WORLD_HIEGHT, WORLD_WIDTH));
	world.setFillColor(Color::Green);
	world.setOutlineThickness(-10);
	world.setOutlineColor(Color::Blue);
	world.setTexture(&grassTexture);

	RectangleShape rect = RectangleShape(Vector2f(50, 70));
	rect.setFillColor(Color::Red);
	rect.setOrigin(25, 35.5);

	vector<Animal> animals;
	for (int i = 0; i < 500; i++)
	{
		int x = rand() % WORLD_WIDTH;
		int y = rand() % WORLD_HIEGHT;
		//std::printf("x: %i, y: %i\n", x, y);
		Animal toAdd(x, y);
		animals.push_back(toAdd);
	}

	vector<Plant> plants;
	for (int i = 0; i < 500; i++)
	{
		int x = rand() % WORLD_WIDTH;
		int y = rand() % WORLD_HIEGHT;
		//std::printf("x: %i, y: %i\n", x, y);
		Plant toAdd(x, y);
		plants.push_back(toAdd);
	}

	playerInv.addItem(Item(ItemType::plant), 10);
	playerInv.addItem(Item(ItemType::meat), 10);
	playerInv.addItem(Item(ItemType::leather), 10);
	playerInv.addItem(Item(ItemType::healthPotion), 10);

	Clock updateClock;
	Clock fpsTimer;
	bool debugPressed = false;
	bool tabPressed = false;

	bool switchClick = false;
	Clock clickTimer;

	std::printf("START\n");

	int calcFps = 0;
	RenderTexture grassRenderTexture;
	grassRenderTexture.create(WORLD_WIDTH/4, WORLD_HIEGHT/4);

	grassRenderTexture.clear();
	for (int y = 0; y < (WORLD_HIEGHT / 100)/8; y++)
	{
		for (int x = 0; x < (WORLD_WIDTH / 100)/8; x++)
		{
			if ((abs(x * 100 - localX) <= 3000) && (abs(y * 100 - localY) <= 3000))
			{
				grassBackSprite.setPosition(x * 100, y * 100);
				grassRenderTexture.draw(grassBackSprite);
			}
		}
	}
	grassRenderTexture.display();

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::MouseMoved)
			{
				//cout << "mouseX: " << event.mouseMove.x << endl;
				//cout << "mouseY: " << event.mouseMove.y << endl;
				mouseX = event.mouseMove.x;
				mouseY = event.mouseMove.y;
			}
			if (event.type == Event::MouseButtonReleased)
			{
				switch (mode)
				{
				case game:
					if (playerInv.intercectsButton(mouseX, mouseY))
					{
						mode = gameMode::inventory;
						break;
					}

					if (clickTimer.getElapsedTime().asMilliseconds() > 250)
					{
						clickTimer.restart();

						weaponFrame = 0;
						weaponOut = true;
						weapon[0].setInUse(true);
						weapon[1].setInUse(true);
						weapon[2].setInUse(true);
					}

					break;

				case crafting:
					if (playerInv.intercectsButton(mouseX, mouseY))
					{
						mode = gameMode::inventory;
					}

					break;
				case inventory:
					if (playerInv.intercectsButton(mouseX, mouseY))
					{
						mode = gameMode::game;
					}
					if (playerInv.clickCraft(mouseX, mouseY) != 0)
					{
						playerInv.craft(playerInv.clickCraft(mouseX, mouseY) + playerInv.getScroll());
					}
					break;

				default:
					break;
				}
			}
			if (event.type == Event::MouseWheelScrolled)
			{
				if (event.mouseWheelScroll.delta > 0)
				{
					view.zoom(.9);
					worldZoom++;
					window.setView(view);
					//cout << "zoom" << endl;
				}
				else
				{
					view.zoom(1.1);
					worldZoom--;
					window.setView(view);
					//cout << "zoom" << endl;
				}
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		//camera contols
		int cameraMove = 5;
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			worldX += cameraMove;
			window.setView(view);
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			worldX -= cameraMove;
			window.setView(view);
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			worldY += cameraMove;
			window.setView(view);
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			worldY -= cameraMove;
			window.setView(view);
		}

		if (Keyboard::isKeyPressed(Keyboard::C))
		{
			for (int i = 0; i < abs(worldZoom); i++)
			{
				if (worldZoom > 0)
					view.zoom(1.1);
				else if (worldZoom < 0)
					view.zoom(.9);
			}
			worldZoom = 0;
			worldX = 0;
			worldY = 0;
		}

		view.setCenter(worldX + localX, worldY + localY);
		window.setView(view);

		if (Keyboard::isKeyPressed(Keyboard::Add))
		{
			view.zoom(.9);
			worldZoom--;
			window.setView(view);
			cout << "zoom" << endl;
		}
		if (Keyboard::isKeyPressed(Keyboard::Subtract))
		{
			view.zoom(1.1);
			worldZoom++;
			window.setView(view);
			cout << "zoom" << endl;
		}

		//player controls
		float walkSpeed = 5;
		if (Keyboard::isKeyPressed(Keyboard::LShift))
			walkSpeed = 8;

		playerIsWalking = false;
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			localY -= walkSpeed;
			playerIsWalking = true;
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			localY += walkSpeed;
			playerIsWalking = true;
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			localX += walkSpeed;
			playerIsWalking = true;
		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			localX -= walkSpeed;
			playerIsWalking = true;
		}

		if (Keyboard::isKeyPressed(Keyboard::E))
		{
			for (int i = 0; i < plants.size(); i++)
				plants[i].harvest();
		}

		if (Keyboard::isKeyPressed(Keyboard::Tilde))
		{
			if (!debugPressed)
			{
				debugPressed = true;

				if (debug)
				{
					debug = false;
					window.setMouseCursorVisible(false);
				}
				else
				{
					debug = true;
					window.setMouseCursorVisible(true);
				}
			}
		}
		else
		{
			debugPressed = false;
		}

		if (Keyboard::isKeyPressed(Keyboard::Num1))
		{
			if (!switchClick)
			{
				switchClick = true;

				if (playerWeapon == weaponType::spear)
				{
					playerWeapon = weaponType::sword;
					hotBar.setWeapon(weaponType::spear);
				}
				else
				{
					playerWeapon = weaponType::spear;
					hotBar.setWeapon(weaponType::sword);
				}
			}
		}
		else
		{
			switchClick = false;
		}

		if (Keyboard::isKeyPressed(Keyboard::Tab))
		{
			if (!tabPressed)
			{
				tabPressed = true;

				if (mode == gameMode::game)
					mode = gameMode::inventory;
				else
					mode = gameMode::game;
			}
		}
		else
		{
			tabPressed = false;
		}

		//handle weapon stuff
		if (weaponClock.getElapsedTime().asMilliseconds() > 5)
		{
			weaponClock.restart();
			weaponFrame++;
		}

		if (playerWeapon == weaponType::spear)
		{
			//animation
			if (weaponFrame > 30)
			{
				weapon[0].setPosition(localX, localY);
				weapon[0].setInUse(false);
				weaponOut = false;
			}
			else if (weaponFrame > 15)
			{
				weapon[0].setPosition(localX + mousePoint(50).x - mousePoint((weaponFrame * 2) - 50).x, (localY + mousePoint(50).y - mousePoint((weaponFrame * 2) - 50).y));
			}
			else if (weaponFrame > 0)
			{
				weapon[0].setPosition(localX + mousePoint(weaponFrame * 5).x, (localY + mousePoint(weaponFrame * 5).y));
			}

			//hitboxes
			for (int i = 0; i < animals.size(); i++)
				if (animals[i].getBodybox().isInside(weapon[0]) && animals[i].getAlive())
				{
					std::printf("hit\n");
					animals[i].damageDone(15);
					weapon[0].setInUse(false);
					dmVector.push_back(DamageNumber(weapon[0].getPosition().x, weapon[0].getPosition().y, 15));
				}

			spearSprite.setPosition(weapon[0].getPosition());
			if (weaponOut)
			{
				spearSprite.setOrigin(32, 0);
				spearSprite.setRotation(mouseDegrees() + 225);
			}
			else
			{
				spearSprite.setOrigin(16, 16);
				spearSprite.setRotation(180);
			}
			spearSprite.setScale(1.5, 1.5);
		}
		else if (playerWeapon == weaponType::sword)
		{
			Vector2f v1 = mousePoint(60, mouseDegrees() + weaponFrame * 6 + 300);
			Vector2f v2 = mousePoint(40, mouseDegrees() + weaponFrame * 6 + 300);
			Vector2f v3 = mousePoint(20, mouseDegrees() + weaponFrame * 6 + 300);

			if (weaponFrame > 20)
			{
				weapon[0].setInUse(false);
				weapon[0].setPosition(localX, localY);
				weapon[1].setInUse(false);
				weapon[1].setPosition(localX, localY);
				weapon[2].setInUse(false);
				weapon[2].setPosition(localX, localY);
			}
			else if (weaponFrame > 0)
			{
				weapon[0].setPosition(v1.x + localX, v1.y + localY);
				weapon[1].setPosition(v2.x + localX, v2.y + localY);
				weapon[2].setPosition(v3.x + localX, v3.y + localY);
			}

			for (int i = 0; i < animals.size(); i++)
			{
				if (animals[i].getAlive())
				{
					if (animals[i].getBodybox().isInside(weapon[0]))
					{
						animals[i].damageDone(5);
						weapon[0].setInUse(false);
						dmVector.push_back(DamageNumber(weapon[0].getPosition().x, weapon[0].getPosition().y, 5));
					}
					if (animals[i].getBodybox().isInside(weapon[1]))
					{
						animals[i].damageDone(7);
						weapon[1].setInUse(false);
						dmVector.push_back(DamageNumber(weapon[0].getPosition().x, weapon[0].getPosition().y, 7));
					}
					if (animals[i].getBodybox().isInside(weapon[2]))
					{
						animals[i].damageDone(10);
						weapon[2].setInUse(false);
						dmVector.push_back(DamageNumber(weapon[0].getPosition().x, weapon[0].getPosition().y, 10));
					}
				}
			}

			if ((weapon[0].getInUse() || weapon[1].getInUse()) || weapon[2].getInUse())
			{
				weaponOut = true;
			}
			else
			{
				weaponOut = false;
			}

			swordSprite.setPosition(localX, localY);
			swordSprite.setScale(1.5, 1.5);
			if (weaponOut)
			{
				swordSprite.setOrigin(0, 32);
				swordSprite.setRotation(mouseDegrees() + weaponFrame * 6 + 165);
			}
			else
			{
				swordSprite.setOrigin(16, 16);
				swordSprite.setRotation(180);
			}

		}

		for (int i = 0; i < dmVector.size(); i++)
		{
			if (!dmVector[i].update())
			{
				dmVector.erase(dmVector.begin() + i);
			}
		}

		//update player model
		rect.setPosition(localX, localY);

		if (walkingClock.getElapsedTime().asMilliseconds() > 25)
		{
			walkingFrames++;
			walkingClock.restart();
		}

		//sets walking frames
		if (playerIsWalking)
		{
			if (mouseX < (MYWINDOW_WIDTH / 2 - 150))
				playerSprite = pRight[walkingFrames % 9];
			else if (mouseX > (MYWINDOW_WIDTH / 2 + 150))
				playerSprite = pLeft[walkingFrames % 9];
			else
			{
				if (mouseY < (MYWINDOW_HEIGHT / 2))
					playerSprite = pUp[walkingFrames % 9];
				else
					playerSprite = pDown[walkingFrames % 9];
			}
		}
		else
		{
			playerSprite = pDown[0];
		}


		//playerSprite = pRight[walkingFrames % 9];
		playerSprite.setOrigin(32, 32);
		playerSprite.setPosition(localX, localY);

		//update animals
		for (int i = 0; i < animals.size(); i++)
			animals[i].update();

		//update plants
		for (int i = 0; i < plants.size(); i++)
			plants[i].update();

		//update ui
		fpsText.setPosition(0, 0);
		interactText.setPosition(mouseX, mouseY);
		mouseSprite.setPosition(mouseX, mouseY);

		switch (mode)
		{
		case game:
			break;
		case crafting:
			break;
		case inventory:
			
			break;
		default:
			break;
		}

		//window drawing ~~~~~~~
		window.clear();

		window.setView(view);
		//window.draw(world);

		

		// get the target texture (where the stuff has been drawn)
		const sf::Texture& texture = grassRenderTexture.getTexture();

		// draw it to the window
		sf::Sprite grassBackSpriteToDraw(texture);
		
		for (int y = 0; y < WORLD_HIEGHT / 100; y++)
		{
			for (int x = 0; x < WORLD_WIDTH / 100; x++)
			{
				if ((abs(x * 100 - localX) <= 3000) && (abs(y * 100 - localY) <= 3000))
				{
					grassBackSpriteToDraw.setPosition(x * 100, y * 100);
					x = WORLD_WIDTH / 100;
					y = WORLD_HIEGHT / 100;
				}
			}
		}

		window.draw(grassBackSpriteToDraw);

		for (int i = 0; i < plants.size(); i++)
			plants[i].draw(&window);
		for (int i = 0; i < animals.size(); i++)
			animals[i].draw(&window);

		//draw player
		for (int i = 0; i < 3; i++)
		{
			if(weapon[i].getInUse() && debug)
				weapon[i].draw(&window);
		}

		switch (playerWeapon)
		{
		case spear:
			window.draw(spearSprite);
			break;
		case sword:
			window.draw(swordSprite);
			break;
		default:
			break;
		}

		for (int i = 0; i < dmVector.size(); i++)
			dmVector[i].draw(&window);

		hotBar.drawBar(&window);//pls delete
		window.draw(playerSprite);


		//hud stuff
		window.setView(viewHud);
		window.draw(fpsText);

		notifHandler.draw(&window);
		playerInv.drawInventory(&window);
		hotBar.drawBar(&window);

		if (mode == gameMode::inventory)
		{
			playerInv.drawBackpack(&window);
		}

		playerInv.drawButton(&window);
		window.draw(mouseSprite);

		//testShapes

		window.display();

		calcFps++;
		if (fpsTimer.getElapsedTime().asSeconds() >= 1)
		{
			fpsTimer.restart();
			std::printf("fps: %i\n", calcFps);
			string sendString = "Fps: ";
			sendString += to_string(calcFps);
			fpsText.setString(sendString);
			calcFps = 0;
		}
	}

	return 0;
}