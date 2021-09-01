class ItemStack
{
private:

	ItemType stackType;
	int itemCount = 0;

public:

	ItemStack();

	void printData();
	bool canAdd(Item inp);
	void add(Item inp);
	bool canRemove(Item inp);
	void removeItem(Item inp);

	ItemType getType();
	int getCount();
};