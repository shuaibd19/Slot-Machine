#pragma once
#include <iostream>

using namespace std;

class Player
{
public:
	int chips; //Integer to store player's chips
	Player();
	~Player();
	void setPlayerChips(int c = 2000);
	int getPlayerChips();
	bool doesPlayerHaveChips(); //Checks whether or not the player can continue playing
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