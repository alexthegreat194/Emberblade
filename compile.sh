g++ -c Animal.cpp 
g++ -c BodyBox.cpp 
g++ -c Globals.cpp 
g++ -c Inventory.cpp 
g++ -c Item.cpp 
g++ -c ItemStack.cpp 
g++ -c Notification.cpp 
g++ -c NotificationHandler.cpp
g++ -c WeaponBox.cpp 
g++ -c Emberblade.cpp
g++ -c main.cpp 
g++ main.o -o Emberblade Animal.o BodyBox.o Globals.o Inventory.o Item.o ItemStack.o Notification.o NotificationHandler.o WeaponBox.o Emberblade.o -lsfml-graphics -lsfml-window -lsfml-system