#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

HANDLE hCon;
//Create an array Colour of type enum to be used when deciding text colour
enum Colour {
	DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY,
	BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE
};


class Slot_Cosmetics
{
public:
	Slot_Cosmetics();
	~Slot_Cosmetics();
	void setColour(Colour c); //Used to set colour of console text
	void tabToMiddle(); //Used to tab line of text to middle of the console screen
	void dispMenu(); //Outputs the basic homescreen selection menu of the game
	void dispCredits(); //Displays the credits of the game
	void dispDollarBills(); //Displays a matrix of dollar bills
	void dispWarning(); //Displays the beginning warning for the game
};

Slot_Cosmetics::Slot_Cosmetics()
{
}

Slot_Cosmetics::~Slot_Cosmetics()
{
}

void Slot_Cosmetics::setColour(Colour c)
{
	if (hCon == NULL)
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, c);
}

void Slot_Cosmetics::tabToMiddle()
{
	cout << "\t\t\t\t\t";
}

void Slot_Cosmetics::dispMenu()
{
	setColour(BLUE);
	tabToMiddle();
	cout << "1) Play Slots\n";
	tabToMiddle();
	cout << "2) Credits\n";
	tabToMiddle();
	cout << "3) Quit Slot Machine\n";
}

void Slot_Cosmetics::dispCredits()
{
	system("CLS");
	setColour(DARKYELLOW);
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

void Slot_Cosmetics::dispDollarBills()
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

void Slot_Cosmetics::dispWarning()
{
	setColour(GREEN);
	system("CLS");
	tabToMiddle();
	cout << "PLEASE GAMBLE RESPONSIBLY\n";
	Sleep(1000);
	tabToMiddle();
	cout << "Or you can actually go outside and do stuff....\n\n";
	Sleep(1750);
	tabToMiddle();
	cout << "WELCOME TO SHUAIB'S SLOT MACHINE!\n";
}