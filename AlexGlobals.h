#pragma once

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
#include <SFML/Network.hpp>

//header Files
#include "AlexClasses.h"

//namespaces
using namespace sf;
using namespace std;

#define PI 3.14159265359

#define MYWINDOW_HEIGHT 720
#define MYWINDOW_WIDTH 1280

#define MAX_SPEED .15
#define WORLD_WIDTH 20000
#define WORLD_HIEGHT 20000

//global variable:
extern bool debug;
extern double worldX;
extern double worldY;
extern double worldZoom;

extern double localX;
extern double localY;

extern int mouseX;
extern int mouseY;

extern float mouseDX;
extern float mouseDY;
extern float mouseRatio;

//texture and sprite variables
extern Texture sheepTexture;
extern Texture grassTexture;
extern Sprite grassSprite;

extern Texture styleSheet;
extern Sprite mushroom[3];

extern Texture leatherSheet;
extern Sprite leatherIcon;

extern Texture meatSheet;
extern Sprite meatIcon;

extern Texture spearSheet;
extern Sprite spearSprite;
extern Sprite spearSpriteStatic;

extern Texture swordSheet;
extern Sprite swordSprite;
extern Sprite swordSpriteStatic;

extern Texture potionhSheet;
extern Sprite potionhSprite;
extern Texture potionaSheet;
extern Sprite potionaSprite;

extern Texture pigTexture;
extern Sprite pigUp[3];
extern Sprite pigRight[3];
extern Sprite pigDown[3];
extern Sprite pigLeft[3];

extern Texture boarTexture;
extern Sprite boarUp[3];
extern Sprite boarRight[3];
extern Sprite boarDown[3];
extern Sprite boarLeft[3];

extern Texture uiTexture;
extern Sprite slotSprite[3][3];
extern Sprite mouseSprite;
extern Sprite buttonNClicked;
extern Sprite buttonClicked;
extern Sprite craftingIcon;
extern Sprite frameTop[3];
extern Sprite frameMiddle[3];
extern Sprite frameBottom[3];

extern Texture playerTexture;
extern Sprite pUp[9];
extern Sprite pLeft[9];
extern Sprite pDown[9];
extern Sprite pRight[9];
extern Sprite playerSprite;
extern int walkingFrames;
extern Clock walkingClock;
extern bool playerIsWalking;

extern Font font;
extern Text fpsText;
extern Text interactText;

extern Inventory playerInv;
extern NotificationHandler notifHandler;
extern gameMode mode;