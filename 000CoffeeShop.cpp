#include <iostream>

using namespace std;

void show_main_menu();

int main()
{
  	cout << "Welcome to our CoffeeShop!" << endl << endl;
	  	
	show_main_menu();
	  
	  
	return 0;
}

void show_main_menu ()
{
	cout << "What do you want to do?" << endl;
	cout << "1 - to drink coffee" << endl; 
	cout << "2 - to service" << endl;
}
