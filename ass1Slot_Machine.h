#pragma once
#include <iostream>
#include "Player.h"
#include <time.h>
#include <Windows.h>

using namespace std;

class Slot_Machine
{
public:
	Slot_Machine();
	~Slot_Machine();
	//Checks the validity of a players bet
	bool isBetValid(int playerChips, int bet);
	/*Removes the bet amount from player's chips and returns the remaining amount*/
	int placeBet(int playerChips, int bet);
	/*Checks the outcome of the slot machine and calculates the player rewards returning the players balance*/
	int rewardCalculator(int playerChips, int bet, int slot1, int slot2, int slot3);
	/*The function that is used for the actual slot machine game and generates 3 random slots and returns
	players balance*/
	int slotGame(int playerChips);
	//Get the users input
	int getUserInp();
private:
	Slot_Cosmetics slotCos;
};

Slot_Machine::Slot_Machine()
{
}

Slot_Machine::~Slot_Machine()
{
}

bool Slot_Machine::isBetValid(int playerChips, int bet)
{
	return (bet > 0 && bet <= playerChips);
}

int Slot_Machine::placeBet(int playerChips, int bet)
{
	int updateChips = playerChips - bet;
	return updateChips;
}

int Slot_Machine::rewardCalculator(int playerChips, int bet, int slot1, int slot2, int slot3)
{
	//Check if the player gets 3x '7'
	if (slot1 == 7 && slot2 == 7 && slot3 == 7)
	{
		//Calculate their reward: In this case the bet is multiplied by 10 and added back to the playerChips
		bet *= 10;
		playerChips += bet;
		slotCos.tabToMiddle();
		slotCos.setColour(GREEN);
		cout << "OMG!!! YOU JUST GOT THREE 7's!\n";
		slotCos.tabToMiddle();
		cout << "Congratulations you've just won $" << bet << "!!!\n";
		slotCos.tabToMiddle();
		cout << "You now have $" << playerChips << "\n\n";
		return playerChips;
	}
	//Check if the player gets a three slots all being the same
	else if (slot1 == slot2 && slot2 == slot3)
	{
		bet *= 5;
		playerChips += bet;
		slotCos.tabToMiddle();
		slotCos.setColour(GREEN);
		cout << "OMG!!! YOU JUST GOT THREE OF A KIND\n";
		slotCos.tabToMiddle();
		cout << "Congratulations you've just won $" << bet << "!!\n";
		slotCos.tabToMiddle();
		cout << "You now have $" << playerChips << "\n\n";
		return playerChips;
	}
	//Check if the player gets atleast 2 slots the same
	else if (slot1 == slot2 || slot1 == slot3 || slot2 == slot3)
	{
		bet *= 3;
		playerChips += bet;
		slotCos.tabToMiddle();
		slotCos.setColour(GREEN);
		cout << "OMG!!! YOU JUST GOT TWO OF A KIND\n";
		slotCos.tabToMiddle();
		cout << "Congratulations you've just won $" << bet << "!\n";
		slotCos.tabToMiddle();
		cout << "You now have $" << playerChips << "\n\n";
		return playerChips;
	}
	//If there are no slots that are the same the player loses their bet amount
	else
	{
		slotCos.tabToMiddle();
		slotCos.setColour(RED);
		cout << "Well that's unfortunate...\n";
		slotCos.tabToMiddle();
		cout << "You've just lost $" << bet << "!\n";
		slotCos.tabToMiddle();
		cout << "You now have $" << playerChips << "\n\n";
		return playerChips;
	}
}

int Slot_Machine::slotGame(int playerChips)
{
	int bet = 0;
	slotCos.tabToMiddle();
	slotCos.setColour(GREEN);
	cout << "Your chip balance: $" << playerChips <<"\n";
	slotCos.tabToMiddle();
	cout << "Please place your bet: $";
	cin >> bet;
	cout << "\n";
	//This while loop informs the player whether or not their placed bet is valid
	while (!isBetValid(playerChips, bet))
	{
		system("CLS");
		slotCos.tabToMiddle();
		cout << "Your chip balance: $" << playerChips << "\n\n";
		slotCos.tabToMiddle();
		slotCos.setColour(RED);
		cout << "Invalid amount! Please try again.\n\n";
		slotCos.setColour(GREEN);
		slotCos.tabToMiddle();
		cout << "Please place your bet: $";
		cin >> bet;
		cout << "\n";
	}
	//After checking the validity of the player's bet, the game removes the betted amount from
	//the players bank 
	playerChips = placeBet(playerChips, bet);
	//These next lines of code generate 3 slot numbers ranging between 2 and 7
	srand((unsigned int)time(NULL));
	int slot1 = (rand() % 7) + 2;
	int slot2 = (rand() % 7) + 2;
	int slot3 = (rand() % 7) + 2;
	slotCos.tabToMiddle();
	slotCos.setColour(BLUE);
	//Adding suspense to the slot machine by adding pauses to the terminals output
	cout << "Your 3 Numbers are: ";
	Sleep(750);
	cout << slot1 << " ";
	Sleep(750);
	cout << slot2 << " ";
	Sleep(750);
	cout << slot3 << "\n\n";
	playerChips = rewardCalculator(playerChips, bet, slot1, slot2, slot3);
	Sleep(6000);
	return playerChips;
}

int Slot_Machine::getUserInp()
{
	int userInp = -1;
	slotCos.setColour(GREEN);
	slotCos.tabToMiddle();
	cout << "Please select from the above options: ";
	cin >> userInp;
	cout << "\n";
	return userInp;
}
