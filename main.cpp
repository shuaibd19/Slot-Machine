#include <iostream>
#include <string>
#include <time.h>
#include <Windows.h>
#include <stdlib.h>

using namespace std;

HANDLE hCon;
//Create an array Colour of type enum to be used when deciding text colour
enum Colour {
	DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY,
	BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE
};

void setColour(Colour c); //Used to set colour of console text
void tabToMiddle(); //Used to tab line of text to middle of the console screen
void dispMenu(); //Outputs the basic homescreen selection menu of the game
void dispCredits(); //Displays the credits of the game
void dispChips(int playerChips); //Displays players chip count
void slotMachine(int userInp, int playerChips); //Function for the slot machine game in switch logic
int getUserInp(); //Get the users input
bool isBetValid(int playerChips, int bet); //Checks the validity of a players bet
int placeBet(int playerChips, int bet); //Removes the bet amount from player's chips
bool doesPlayerHaveChips(int playerChips); //Checks whether or not the player can continue playing
int rewardPlayer();
void dollarBills();
void playGame(int playersChips);

int main()
{
	const int PLAYER_INITIAL_CHIPS = 2000;
	int playerChips = PLAYER_INITIAL_CHIPS;
	int choice = -1;
	while (1)
	{
		dispChips(playerChips);
		dispMenu();
		choice = getUserInp();
		slotMachine(choice, playerChips);
	}
	return 0;
}

void setColour(Colour c)
{
	if (hCon == NULL)
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, c);
}

void tabToMiddle()
{
	cout << "\t\t\t\t\t";
}

void dispMenu()
{
	setColour(BLUE);
	tabToMiddle();
	cout << "1) Play Slots\n";
	tabToMiddle();
	cout << "2) Credits\n";
	tabToMiddle();
	cout << "3) Quit Slot Machine\n";
}

void dispCredits()
{
	system("CLS");
	setColour(DARKYELLOW);
	tabToMiddle();
	cout << "\n\n\n\n";
	tabToMiddle();
	cout << "*******************************************\n";
	tabToMiddle();
	cout << "Lead Developer: Shuaib Dorani\n";
	tabToMiddle();
	cout << "Lead Designer: Shuaib Dorani\n";
	tabToMiddle();
	cout << "Tester: Shuaib Dorani\n";
	tabToMiddle();
	cout << "MEDIA DESIGN SCHOOL\n";
	tabToMiddle();
	cout << "TORRENS UNIVERISTY\n";
	tabToMiddle();
	cout << "*******************************************\n";
	tabToMiddle();
	cout << "\n\n\n\n";
}

void dispChips(int playerChips)
{
	setColour(GREEN);
	tabToMiddle();
	cout << "Player's chips: $" << playerChips << "\n";
}

int getUserInp()
{
	int userInp = -1;
	setColour(GREEN);
	tabToMiddle();
	cout << "Please select from the above options: ";
	cin >> userInp;
	cout << "\n";
	return userInp;
}

void slotMachine(int userInp, int playerChips)
{
	switch (userInp)
	{
	case 1:
	{
		setColour(GREEN);
		playGame(playerChips);
	}
	break;
	case 2:
	{
		dispCredits();
	}
	break;
	case 3:
	{
		exit(0);
	}
	break;
	default:
		setColour(PINK);
		tabToMiddle();
		cout << "Pick Again\n\n";
	}
}

void playGame(int playersChips)
{
	/*srand(time(0));*/
	int chips = playersChips;
	int bet = -1;
	int min = 2;
	int max = 7;
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	system("CLS");
	tabToMiddle();
	cout << "PLEASE GAMBLE RESPONSIBLY\n";
	Sleep(1000);
	tabToMiddle();
	cout << "Or you can actually go outside and do stuff....\n\n";
	Sleep(1750);
	tabToMiddle();
	cout << "WELCOME TO SHUAIB'S SLOT MACHINE!\n";
	dollarBills();
	tabToMiddle();
	setColour(GREEN);
	cout << "Please place your bet amount: $";
	cin >> bet;
	cout << "\n";
	while (isBetValid(playersChips, bet) == false)
	{
		tabToMiddle();
		setColour(RED);
		cout << "Invalid Amount!\n\n";
		setColour(GREEN);
		tabToMiddle();
		cout << "Please place your bet amount: $";
		cin >> bet;
		cout << "\n";
	}
	int update = placeBet(chips, bet);
	tabToMiddle();
	cout << "Your current chip  amount is: " << update << endl;

}

bool isBetValid(int playerChips, int bet)
{
	return (bet > 0 && bet <= playerChips);
}

int placeBet(int playerChips, int bet)
{
	int updateChips = 0;
	updateChips = playerChips - bet;
	return updateChips;
}

bool doesPlayerHaveChips(int playerChips)
{
	return (playerChips > 0);
}

void dollarBills()
{
	for (int i = 0; i < 5; ++i)
	{
		tabToMiddle();
		for (int j = 0; j < 11; ++j)
		{
			setColour(GRAY);
			cout << "[";
			setColour(GREEN);
			cout << "$";
			setColour(GRAY);
			cout << "]";
		}
		cout << "\n";
	}
	cout << "\n";
}