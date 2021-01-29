/*
*	File: main_game.cpp
*	Author: H.CHERGUI
*	First version: 1.0
*	First version date: 22/01/2021
*	current version: 2.5
*	current version date: 25/01/2021
*/

// System files includes
/*NONE*/

// User defined files includes
#include "State_Engine.h"
#include "Init.h"
#include "Input.h"
#include "Update.h"
#include "Draw.h"

int main_game() {
	
	// Local variables
	u_int8 l_in_cmd = 0;
	u_int8 l_ud_cmd = 0;
	e_State l_state = e_State::E_START;

	// System loop
	for (; true; l_in_cmd = 0) {
		
		// Getting the input
		l_in_cmd = Input();

		// Determining the current state
		l_state = State_Engine(l_state, l_in_cmd, l_ud_cmd);

		// Updating the internal values
		l_ud_cmd = Update(l_state, (e_Direction)l_in_cmd);

		// Drawing the window
		Draw(l_state, l_ud_cmd);

		// System delay
		Sleep(g_tick);
	}
	
	return 55;
}