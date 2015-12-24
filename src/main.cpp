#include <iostream>
#include "MenuRenderer/Menu.cpp"
#include "Connector/client.cpp"
#include "Connector/server.cpp"

using namespace std;

int main(int argc, char *argv[])
{
	Menu *menu;

	cout << "Welcome to the App" << endl;
	menu = new Menu();
	menu->AddOption("1 - Server Mode", []() -> void { cout << "Server Mode" << endl; });
	menu->AddOption("2 - Client Mode", []() -> void { cout << "Client Mode" << endl; });
	menu->Render();
}