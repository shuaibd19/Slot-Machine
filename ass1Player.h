#pragma once
#include <iostream>
#include "Slot_Cosmetics.h"

using namespace std;

class Player
{
public:
	Player();
	~Player();
	//This function automatically sets the default player chips to 2000 when nothing is assigned to it
	void setPlayerChips(int c = 2000);
	int getPlayerChips();
	//Checks whether or not the player can continue playing
	bool doesPlayerHaveChips();
	//Displays players chip count
	void dispChips(int playerChips);
private:
	//Creating an instance of the Slot_Cosmetics class in order to use some of its functions
	Slot_Cosmetics slotCos;
	//Integer to store player's chips
	int chips;
};

Player::Player()
{
}

Player::~Player()
{
}

void Player::setPlayerChips(int c)
{
	chips = c;
}

int Player::getPlayerChips()
{
	return chips;
}

bool Player::doesPlayerHaveChips()
{
	return (chips > 0);
}

void Player::dispChips(int playerChips)
{
	system("CLS");
	slotCos.setColour(GREEN);
	slotCos.tabToMiddle();
	cout << "Player's chips: $" << playerChips << "\n";
}
