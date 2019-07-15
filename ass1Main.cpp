#include <iostream>
#include "Slot_Cosmetics.h"
#include "Player.h"
#include "Slot_Machine.h"

using namespace std;

int main()
{
	bool playerHasQuit = false;
	//Creating objects of the various classes needed to run the program
	Player player;
	Slot_Machine slot_machine;
	Slot_Cosmetics slot_cosmetics;
	//The setPlayerChips() function has a default of 2000 hence no assigning of any initial value
	player.setPlayerChips();
	//This condition of the loop ensures that the game exits either when the player decides to quit
	//or their chip count is completely depleted to 0
	while (!playerHasQuit && player.doesPlayerHaveChips())
	{
		player.dispChips(player.getPlayerChips());
		slot_cosmetics.dispMenu();
		int userInput = slot_machine.getUserInp();
		switch (userInput)
		{
		case 1:
			slot_cosmetics.dispWarning();
			slot_cosmetics.dispDollarBills();
			player.setPlayerChips(slot_machine.slotGame(player.getPlayerChips()));
			break;
		case 2:
			slot_cosmetics.dispCredits();
			break;
		case 3:
			playerHasQuit = true;
			break;
		default:
			slot_cosmetics.dispInvalidChoice();
			Sleep(1000);
		}
	}
	return 0;
}
