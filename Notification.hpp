class Notification
{
	string message;
	Item notifItem;
	Clock showTimer;

public:

	Notification(string inpMessage);
	Notification(string inpMessage, Item inpItem);

	Item getItem();
	string getMessage();
	bool getShow();
};