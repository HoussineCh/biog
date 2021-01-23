/*
	File: main_game.cpp
	Author: H.CHERGUI
	First verion: 1.0
	First verion date: 22/01/2021
	current verion: 1.0
	current verion date: 22/01/2021
*/

// System files includes
#include <iostream>
#include <Windows.h>

// User defined files includes
#include "Init.h"
#include "Input.h"
#include "Update.h"
#include "Draw.h"

int main_game() {
	// Local variables
	u_int8 l_cmd=0;

	labl_Start:
	// Initializing
	Init(GC_TICK_TIME, 0, 3, UP);

	// System loop
	while ( l_cmd != GC_GAME_OVER) {
		system("cls");
		l_cmd = Input();
		l_cmd = Update(l_cmd);
		l_cmd = Draw(l_cmd);
		Sleep(g_tick);		
	}

	/*temporary code*/

	std::cout << "\n(press \'r\' for a restart)";
	while (1) {	
		Sleep(200);
		l_cmd = Input();
		if (l_cmd == 'r')
			goto labl_Start;
	}
	return 55;
}

