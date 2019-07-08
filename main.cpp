#include <iostream>
#include <string>
#include <time.h>
#include "Slot_Cosmetics.h"
#include "Player.h"

using namespace std;
enum MenuChoices
{
	PLAY_SLOTS = 1,
	DISP_CREDITS,
	QUIT
};

int main()
{
	Slot_Cosmetics slot_cosmetics;
	Player player;
	player.setPlayerChips();
	cout << player.getPlayerChips() << endl;
	return 0;
}