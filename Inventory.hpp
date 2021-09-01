class Inventory
{
private:
	ItemStack stacks[25];
	bool pressed = false;
	int scroll = 0;

public:
	Inventory();

	void printItems();
	int getScroll();

	bool canAdd(Item inp);
	bool canRemove(Item inp);

	void addItem(Item inp);
	void addItem(Item inp, int num);
	void removeItem(Item inp);

	bool intercectsButton(int x, int y);
	int clickCraft(int x, int y);
	void craft(int recipe);

	void drawInventory(RenderWindow* window);
	void drawCraftSlot(RenderWindow* window, int slotNum);
	void drawCraftSlot(RenderWindow* window, int slotNum, int recipe);
	void drawBackpack(RenderWindow* window);
	void drawButton(RenderWindow* window);
};