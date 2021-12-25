#pragma once

//sfml imports
//other imports

enum ItemType
{
	empty, plant, meat, leather, healthPotion
};

class Item
{
private:
	ItemType blockType;

public:
	Item();
	Item(ItemType iType);

	void setType(ItemType iType);

	ItemType getType();
};