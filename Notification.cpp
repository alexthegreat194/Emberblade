Notification::Notification(string inpMessage)
{
    message = inpMessage;
    notifItem = Item(ItemType::empty);
}
Notification::Notification(string inpMessage, Item inpItem)
{
    message = inpMessage;
    notifItem = inpItem.getType();
}

Item Notification::getItem()
{
    return notifItem;
}
string Notification::getMessage()
{
    return message;
}
bool Notification::getShow()
{
    if (showTimer.getElapsedTime().asSeconds() > 2)
        return false;
    else
        return true;
}