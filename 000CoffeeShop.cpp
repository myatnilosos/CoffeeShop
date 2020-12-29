#include <iostream>
#define PIN 1234
#define ESPRESSO 1
#define CAPPUCCINO 1.5
#define LATTE 1.5

using namespace std;

void show_main_menu(int customerBalance);
double customer_balance_adding();
void coffee_making(int coffee);
bool if_PIN(int pin);
void service_menu(int machineBalance, int cups);
int cups_adding(int cups);

int main()
{
	int cups = 0, pin = 0;
	double customerBalance = 0, machineBalance = 0;
	double cash = 0; 
	int mainMenuChoice = 0, pinMenuChoice = 0, serviceMenuChoice = 0;
		
  	cout << "Welcome to our CoffeeShop!" << endl << endl;
	  	 

	while(true){
		show_main_menu(customerBalance);
		cout << endl;
		cin >> mainMenuChoice;
		if (cups == 0 and (mainMenuChoice == 1 or mainMenuChoice == 2 or mainMenuChoice == 3 or mainMenuChoice == 4)){
				cout << "We are sorry but unfortunately there are no cups left" << endl;
		}
		else if (cups > 0) {
			if (mainMenuChoice == 1){
				customerBalance += customer_balance_adding();
				machineBalance += customer_balance_adding();
			}
			else if (mainMenuChoice == 2){
				if (customerBalance < ESPRESSO){
					customerBalance += customer_balance_adding();		
					machineBalance += customer_balance_adding();		
				}
				else {
					coffee_making(mainMenuChoice);
					customerBalance -= ESPRESSO;
				}
			}
			else if (mainMenuChoice == 3){
				if (customerBalance < CAPPUCCINO){
					customerBalance += customer_balance_adding();	
					machineBalance += customer_balance_adding();				
				}
				else {
					coffee_making(mainMenuChoice);
					customerBalance -= CAPPUCCINO;
				}		
			}	
			else if (mainMenuChoice == 4){
				if (customerBalance < LATTE){
					customerBalance += customer_balance_adding();	
					machineBalance += customer_balance_adding();				
				}
				else {
					coffee_making(mainMenuChoice);
					customerBalance -= LATTE;
				}		
			}
		}
		else if (mainMenuChoice == 5){
			cout << "1 - PIN input" << endl;
			cout << "2 - Back to Main menu" << endl;
			cin >> pinMenuChoice;
			while (true){
				if (pinMenuChoice == 1){
				cin >> pin;
					if (if_PIN(pin)){
						while (true){
							service_menu(machineBalance, cups);
							cout << endl;
							cin >> serviceMenuChoice;
							if(serviceMenuChoice == 1){
								cups += cups_adding(cups);
								service_menu(machineBalance, cups);
								cout << endl;
								cin >> serviceMenuChoice;
							}
							else if (serviceMenuChoice == 2){
								cout << machineBalance << "BYN were given away";
								machineBalance -= machineBalance;
								service_menu(machineBalance, cups);
								cout << endl;
								cin >> serviceMenuChoice;
							}
							else if (serviceMenuChoice == 3){
								break;
							}
						}
					break;
					}
					else {
						cout << "The machine is blocked";
						return -1;
					}
				}
				else if (pinMenuChoice == 2){
					break;
				} 
				else {
					cout << endl;
				}
			}
		}
		else {
			cout << "Please enter [1...5]" << endl;
		}
	}
	return 0;
}

void show_main_menu(int customerBalance)
{
	cout << "balance, 1, 2, 3, 4, 5" << endl;
}
double customer_balance_adding()
{
	return 2;
}
void coffee_making(int coffee)
{
	cout << "Here is your coffee";
}

bool if_PIN(int pin)
{
	return true;
}
void service_menu(int machineBalance, int cups)
{
	cout << "machine balance, cups, 1, 2, 3";
}
int cups_adding(int cups)
{
	return 3;
}

