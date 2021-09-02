#pragma once
#include "Globals.hpp"

#define PI 3.14159265359

#define MYWINDOW_HEIGHT 720
#define MYWINDOW_WIDTH 1280

#define MAX_SPEED .15
#define WORLD_WIDTH 20000
#define WORLD_HIEGHT 20000

//global variable:
bool debug;
double worldX;
double worldY;
double worldZoom;

double localX;
double localY;

int mouseX;
int mouseY;

float mouseDX;
float mouseDY;
float mouseRatio;

//texture and sprite variables
Texture sheepTexture;
Texture grassTexture;
Sprite grassSprite;

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

Texture playerTexture;
Sprite pUp[9];
Sprite pLeft[9];
Sprite pDown[9];
Sprite pRight[9];
Sprite playerSprite;
int walkingFrames;
Clock walkingClock;
bool playerIsWalking;

Font font;
Text fpsText;
Text interactText;

Inventory playerInv;
NotificationHandler notifHandler;
gameMode mode;