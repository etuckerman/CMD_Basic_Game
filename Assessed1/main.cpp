#include <iostream>
using namespace std;

void payinitialfee(int& balance);
void enteroption(char& option);
void playgame(int& balance);
void showbalance(int balance);
void putinuppercase(char& option);
void processoption(char& option, int& balance);

int main() {									  //removed global variables

	char option;
	int balance;

	payinitialfee(balance);
	enteroption(option);

	while ((option != 'Q') && (balance >= 20))	  //check if user still wants to (and is able to afford to) play
	{
		processoption(option, balance);
		enteroption(option);
	}
	cout << "thanks for playing!"; 				  //thankyou message when user quits
	showbalance(balance);

	return(0);
}

void payinitialfee(int& balance) {
	balance = 100;											   //set initial balance
}

void enteroption(char& option) {
	cout << "\nEnter option(p:play or B:balance or Q:quit)";
	cin >> option;
	putinuppercase(option);
}

void putinuppercase(char& option) {							  //check for incorrect case and fix
	option = toupper(option);

}

void processoption(char& option, int& balance) {			 //decide whether user wants to play game or check balance
	if (option == 'P') {
		playgame(balance);
	}
	else
	{
		if (option == 'B')
			showbalance(balance);
		else

			cout << "\nERROR: invalid command!";			//returns error if incorrect format is typed


	}
}

void playgame(int& balance) {							   //the game function, charges 20 per go
	cout << "playing...";
	cout << "\ncredits - 20";
	balance -= 20;
}

void showbalance(int balance) {							   //shows the users balance
	cout << " The current balance is " << balance;
}