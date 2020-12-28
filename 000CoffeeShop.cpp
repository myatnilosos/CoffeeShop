#include <iostream>
#define PIN 1234
#define ESPRESSO 1
#define CAPPUCCINO 1.5
#define LATTE 1.5

using namespace std;

void show_main_menu();
double deposit_money(double cash);
double customer_balance_adding(double cash);
void coffee_making(int coffee);
bool if_PIN(int pin);
void service_menu();
int cups_adding(int cups);

int main()
{
	int cups = 7, pin = 0;
	double customerBalance = 0, machineBalance = 0;
	double cash = 0; 
	int mainMenuChoice = 0, serviceMenuChoice = 0;
	
  	cout << "Welcome to our CoffeeShop!" << endl << endl;
	  	
	show_main_menu();
	cout << endl;
	cin >> mainMenuChoice; 

	while(true){	
		if (cups == 0){
			if (mainMenuChoice == 1 or mainMenuChoice == 2 or mainMenuChoice == 3 or mainMenuChoice == 4){
				cout << "We are sorry but unfortunately there are no cups left";
			}
		}
		else {
			if (mainMenuChoice == 1){
				customerBalance += customer_balance_adding(cash);
			}
			else if (mainMenuChoice == 2){
				if (customerBalance < ESPRESSO){
					customerBalance += customer_balance_adding(cash);				
				}
				else {
					coffee_making(mainMenuChoice);
				}
			}
			else if (mainMenuChoice == 3){
				if (customerBalance < CAPPUCCINO){
					customerBalance += customer_balance_adding(cash);					
				}
				else {
					coffee_making(mainMenuChoice);
				}		
			}	
			else if (mainMenuChoice == 4){
				if (customerBalance < LATTE){
					customerBalance += customer_balance_adding(cash);					
				}
				else {
					coffee_making(mainMenuChoice);
				}		
			}
		else if (mainMenuChoice == 5){
			cout << "Please input PIN" << endl;
			cout << "    * * * *" << endl;
			cin >> pin;
			if (if_PIN(pin)){
				service_menu();
				cout << endl;
				cin >> serviceMenuChoice;
				if(serviceMenuChoice == 1){
					cups += cups_adding(cups);
				}
				else if (serviceMenuChoice == 2){
					cout << machineBalance << "BYN were given away";
					machineBalance -= machineBalance;
				}
				else if (serviceMenuChoice == 3){
					cout << endl;
				}
			}
			else {
				cout << "The machine is blocked";
				break;
			}
		}
	}
	return 0;
}

void show_main_menu()
{
	cout << "balance, 1, 2, 3, 4, 5" << endl;
}
double deposit_money(double cash)
{
	return 1;
}
double customer_balance_adding(double cash)
{
	return 2;
}
void coffee_making(int coffee)
{
	cout << "Here is your coffee";
}
bool if_PIN()
{
	return true;
}
void service_menu()
{
	cout << "machine balance, cups, 1, 2, 3";
}
int cups_adding(int cups)
{
	return 3;
}

