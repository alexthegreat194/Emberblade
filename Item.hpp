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