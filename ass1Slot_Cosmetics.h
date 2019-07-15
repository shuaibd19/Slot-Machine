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
	//Used to set colour of console text
	void setColour(Colour c);
	//Used to tab line of text to middle of the console screen
	void tabToMiddle();
	//Outputs the basic homescreen selection menu of the game
	void dispMenu(); 
	//Displays the credits of the game
	void dispCredits(); 
	//Displays a 5x11 matrix of dollar bills
	void dispDollarBills();
	//Displays the beginning warning for the game
	void dispWarning();
	//Displays red text indicating wrong choice
	void dispInvalidChoice();
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
	Sleep(750);
	cout << "*******************************************\n";
	tabToMiddle();
	Sleep(750);
	cout << "Lead Developer: Shuaib Dorani\n";
	tabToMiddle();
	Sleep(750);
	cout << "Lead Designer: Shuaib Dorani\n";
	Sleep(750);
	tabToMiddle();
	cout << "Tester: Shuaib Dorani\n";
	Sleep(750);
	tabToMiddle();
	cout << "MEDIA DESIGN SCHOOL\n";
	Sleep(750);
	tabToMiddle();
	cout << "TORRENS UNIVERISTY\n";
	Sleep(750);
	tabToMiddle();
	cout << "*******************************************\n";
	Sleep(750);
	tabToMiddle();
	cout << "\n\n";
}

void Slot_Cosmetics::dispDollarBills()
{
	for (int i = 0; i < 5; ++i)
	{
		tabToMiddle();
		for (int j = 0; j < 11; ++j)
		{
			Sleep(25);
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

void Slot_Cosmetics::dispInvalidChoice()
{
	tabToMiddle();
	setColour(RED);
	cout << "Invalid choice! Please try again.\n\n";
}
