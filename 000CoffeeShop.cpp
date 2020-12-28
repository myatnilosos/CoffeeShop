#include <iostream>

using namespace std;

void show_main_menu();
double deposit_money(double cash);

int main()
{
	int cups = 7;
	double customerBalance = 0, machineBalance = 0;
	double cash = 0; 
	int mainMenuChoice = 0;
	
  	cout << "Welcome to our CoffeeShop!" << endl << endl;
	  	
	show_main_menu();
	cin << mainMenuChoice; 
	
	if (cups == 0){
		if (mainMenuChoice == 1 or mainMenuChoice == 2 or mainMenuChoice == 3 or mainMenuChoice == 4){
			cout << "We are sorry but unfortunately there are no cups left"
		}
	}
	else {
		if (mainMenuChoice == 1){
			cash = deposit_money(cash);
			customerBalance += cash;
		}
		else if (mainMenuChoice == 2){
			if ()
		}
	}

	  
	return 0;
}

void show_main_menu()
{
	cout << "balance, 1, 2, 3, 4, 5"
}
double deposit_money(double cash)
{
	return 1;
}
