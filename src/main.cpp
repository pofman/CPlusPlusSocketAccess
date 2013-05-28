#include <iostream>
#include "MenuRenderer/Menu.cpp"
using namespace std;

int main()
{
	Menu *menu;

	cout << "Welcome to the App" << endl;
	menu = new Menu();
	menu->AddOption(1);
	menu->AddOption(2);
	menu->Render();
}