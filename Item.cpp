Item::Item()
{
	blockType = ItemType::empty;
}
Item::Item(ItemType iType)
{
	blockType = iType;
}
void Item::setType(ItemType iType)
{
	blockType = iType;
}
ItemType Item::getType()
{
	return blockType;
}