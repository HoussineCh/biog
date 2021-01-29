/*
*	File: main_game.cpp
*	Author: H.CHERGUI
*	First version: 1.0
*	First version date: 22/01/2021
*	current version: 2.6
*	current version date: 29/01/2021
*/

// System files includes
/*NONE*/

// User defined files includes
#include "Init.h"
#include "Input.h"
#include "Update.h"
#include "Draw.h"

int main_game() {
	
	// Local variables
	u_int8 l_in_cmd = 0;
	s_Game_info l_game_info = {e_State::E_START, 0};

	// System loop
	while (true) {
		
		// Getting the input
		l_in_cmd = Input();

		// Updating the current step
		l_game_info = Update(l_game_info, l_in_cmd);

		// Drawing the window
		Draw(l_game_info);

		// System delay
		Sleep(g_tick);
	}
	

	return 55;
}