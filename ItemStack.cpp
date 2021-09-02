#include "ItemStack.hpp"

//stack sizes
#define DEFAULT 10
#define POTION 5
ItemStack::ItemStack() {
    stackType = ItemType::empty;
}

void ItemStack::printData()
{
    std::printf("StackType: %i, Count: %i\n", stackType, itemCount);
}
bool ItemStack::canAdd(Item inp)
{
    if (stackType == ItemType::empty)
    {
        return true;
    }
    else if (inp.getType() == stackType)
    {
        switch (stackType)
        {
        case ItemType::plant:
            if (itemCount < DEFAULT)
                return true;
            else
                return false;
            break;
        case ItemType::meat:
            if (itemCount < DEFAULT)
                return true;
            else
                return false;
            break;
        case ItemType::leather:
            if (itemCount < DEFAULT)
                return true;
            else
                return false;
            break;
        case ItemType::healthPotion:
            if (itemCount < POTION)
                return true;
            else
                return false;
            break;
        default:
            break;
        }
    }
    else
    {
        return false;
    }
}
void ItemStack::add(Item inp)
{
    if (canAdd(inp))
    {
        if (stackType == ItemType::empty)
        {
            stackType = inp.getType();
            itemCount += 1;
        }
        else
        {
            itemCount += 1;
        }
    }
    else
    {
        std::printf("no\n");
    }
}
bool ItemStack::canRemove(Item inp)
{
    if (inp.getType() != stackType)
        return false;

    if ((stackType != ItemType::empty) && (itemCount > 0))
    {
        return true;
        printData();
    }
    return false;
}
void ItemStack::removeItem(Item inp)
{
    if (canRemove(inp))
    {
        itemCount--;
        if (itemCount < 1)
        {
            stackType = ItemType::empty;
        }
    }
}

ItemType ItemStack::getType()
{
    return stackType;
}
int ItemStack::getCount()
{
    return itemCount;
}