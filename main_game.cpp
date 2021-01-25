/*
*	File: main_game.cpp
*	Author: H.CHERGUI
*	First version: 1.0
*	First version date: 22/01/2021
*	current version: 2.1
*	current version date: 25/01/2021
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
	u_int8 l_in_cmd;
	u_int8 l_ud_cmd;
	u_int8 l_dr_cmd;
	e_State l_state;

	// Initializing the state to start screen
	l_state = E_START;

	// System loop
	while ( true ) {
		l_in_cmd = 0;

		// Start screen
		if (l_state == E_START) {
			l_in_cmd = Input();
			Draw(E_START, GC_NO_CMD);
			// Checking if a start is requested
			if (l_in_cmd == GC_START) {
				// Initializing
				Init(GC_TICK_TIME, 0, 5, UP);

				// Run the game
				l_state = E_RUNNING;
			}

			// Extra waiting to compensate the reduced cpu load
			Sleep(GC_TICK_TIME);
		}
		
		// Running state
		else if(l_state == E_RUNNING){
			l_in_cmd = Input();
			l_ud_cmd = Update(l_in_cmd);
			Draw(E_RUNNING, GC_NO_CMD);

			// Checking if the game is over
			if (l_ud_cmd == GC_WALL_HIT || l_ud_cmd == GC_SELF_INTERSECT) {
				// Put an end to the game
				l_state = E_GAME_OVER;
			}

			// Checking if a pause is requested
			else if (l_in_cmd == GC_PAUSE || l_in_cmd == GC_PAUSE2) {
				// Pause the game
				l_state = E_PAUSE;
			}			
		}
		
		// Pause state
		else if(l_state == E_PAUSE){
			l_in_cmd = Input();
			Draw(E_PAUSE, GC_NO_CMD);

			// Checking whether the game is resumed
			if (l_in_cmd == GC_PAUSE || l_in_cmd == GC_PAUSE2) {
				// Resume the game
				l_state = E_RUNNING;
			}
			
			// Checking if a restart is requested
			else if (l_in_cmd == GC_RESTART) {
				// Back to main menu
				l_state = E_START;
			}
		}
		
		// Game over state
		else if(l_state == E_GAME_OVER){
			l_in_cmd = Input();
			Draw(E_GAME_OVER, l_ud_cmd);

			// Checking if a restart is requested
			if (l_in_cmd == GC_RESTART) {
				// Back to main menu
				l_state = E_START;
			}
		}	

		// System delay
		Sleep(g_tick);
	}
	
	return 55;
}

