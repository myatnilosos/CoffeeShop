#include <iostream>
#include "windows.h"
#define PIN 1234
#define ESPRESSO 1
#define CAPPUCCINO 1.5
#define LATTE 1.5

using namespace std;

void showMainMenu(int customerBalance);
double customerBalanceAdding();
void coffeeMaking(string coffee);
bool IsPIN(int pin);
void serviceMenu(double machineBalance, int cups);
int cupsAdding(int cups);

int main()
{
	int cups = 1, pin = 0;
	double customerBalance = 5, machineBalance = 0;
	double cash = 0;
	int mainMenuChoice = 0, pinMenuChoice = 0, serviceMenuChoice = 0;
	string coffee = "";

	cout << "Welcome to our CoffeeShop!" << endl << endl;


	while (true) {
		showMainMenu(customerBalance);
		cout << endl;
		cin >> mainMenuChoice;
		if (cups == 0 and (mainMenuChoice == 1 or mainMenuChoice == 2 or mainMenuChoice == 3 or mainMenuChoice == 4)) {
			cout << "We are sorry but unfortunately there are no cups left" << endl;
		}
		else if (cups > 0) {
			if (mainMenuChoice == 1) {
				customerBalance += customerBalanceAdding();
				machineBalance += customerBalance;
			}
			else if (mainMenuChoice == 2) {
				if (customerBalance < ESPRESSO) {
					customerBalance += customerBalanceAdding();
					machineBalance += customerBalance;
					cups--;
				}
				else {
					coffee = "Espresso";
					coffeeMaking(coffee);
					customerBalance -= ESPRESSO;
					cups--;
				}
			}
			else if (mainMenuChoice == 3) {
				if (customerBalance < CAPPUCCINO) {
					customerBalance += customerBalanceAdding();
					machineBalance += customerBalance;
				}
				else {
					coffee = "Cappuccino";
					coffeeMaking(coffee);
					customerBalance -= CAPPUCCINO;
					cups--;
				}
			}
			else if (mainMenuChoice == 4) {
				if (customerBalance < LATTE) {
					customerBalance += customerBalanceAdding();
					machineBalance += customerBalance;
				}
				else {
					coffee = "Latte";
					coffeeMaking(coffee);
					customerBalance -= LATTE;
					cups--;
				}
			}
		}
		else if (mainMenuChoice == 5 && cups != -1) {
			cout << "1 - PIN input" << endl;
			cout << "2 - Back to Main menu" << endl;
			cin >> pinMenuChoice;
			while (true) {
				if (pinMenuChoice == 1) {
					if (IsPIN(pin)) {
						while (true) {
							serviceMenu(machineBalance, cups);
							cout << endl;
							cin >> serviceMenuChoice;
							if (serviceMenuChoice == 1) {
								cups += cupsAdding(cups);
								cout << endl;
							}
							else if (serviceMenuChoice == 2) {
								cout << machineBalance << "BYN were given away";
								machineBalance -= machineBalance;
								cout << endl;
							}
							else if (serviceMenuChoice == 3) {
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
				else if (pinMenuChoice == 2) {
					break;
				}
				else {
					cout << endl;
				}
			}
		}
		else
		{
			cout << "Please enter [1...5]" << endl;
		}
	}
	return 0;
}

void showMainMenu(int customerBalance)
{
	cout << "Balance: " << customerBalance << endl;
	cout << "1 - Deposit money" << endl << "2 - Espresso - 1 BYN" << endl << "3 - Cappuccino - 1.5 BYN" << endl << "4 - Latte - 1.5 BYN"<< endl <<  "5 - Service menu";
}

double customerBalanceAdding()
{
	double balance = 0.0;
	int userChoise = 0;

	cout << "Please deposit coins. Pay attention that the coffee machine doesn’t give change" << endl;
	cout << "1 - 10 coins" << endl << "2 - 20 coins" << endl << "3 - 50 coins" << endl << "4 - 1 BYN" << endl << "5 - 2 BYN" << endl;

	while (userChoise == 0)
	{
		cout << "Choose: ";
		cin >> userChoise;

		if (userChoise == 1)
		{
			balance += 0.10;
			break;
		}
		else if (userChoise == 2)
		{
			balance += 0.20;
			break;
		}
		else if (userChoise == 3)
		{
			balance += 0.50;
			break;
		}
		else if (userChoise == 4)
		{
			balance += 1.00;
			break;
		}
		else if (userChoise == 5)
		{
			balance += 2.00;
			break;
		}
		else
		{
			cout << "Incorrect input";
		}
	}

	return balance;
}

void coffeeMaking(string coffee)
{
	int count = 0;
	cout << "Wait your coffee, please" << endl << endl;
	for (count; count < 30; ++count) {
		cout << "#";
		Sleep(130);
	}
	cout << endl << endl;
	cout << "Here is your "<< coffee << endl << endl;
}

bool IsPIN(int pin)
{
	int i = 0;

	while (i < 3)
	{
		cin >> pin;

		if (pin == PIN)
		{
			return true;
		}

		cout << "PIN is wrong. Please input PIN" << endl;
		i++;
	}

	return false;
}

void serviceMenu(double machineBalance, int cups)
{
	cout << "Machine balance - " << machineBalance << endl << "Cups - " << cups << endl << "1 - Add cups" << endl << "2 - Withdrawal of proceeds" << endl << "3 - Back to Main Menu";
}

int cupsAdding(int cups)
{
	int cup = 0;
	cout << "How many cups are you adding?" << endl;
	cin >> cup;
	return cup;
}