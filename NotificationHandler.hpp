class NotificationHandler
{
private:
	vector<Notification> notifications;
	int mCount = 0;

public:

	void addNotification(Notification inpNotif);
	void update();
	void draw(RenderWindow* window);
};