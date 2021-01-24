/*
*	File: main_game.cpp
*	Author: H.CHERGUI
*	First verion: 1.0
*	First verion date: 22/01/2021
*	current version: 2.0
*	current version date: 23/01/2021
*/

// System files includes
#include <iostream>
#include <Windows.h>

// User defined files includes
//#include "State_Engine.h"
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

		// Start screen
		if(l_state == E_START){
			l_in_cmd = Input();
			Draw(E_START);

			// Checking if a start is requested
			if (l_in_cmd == GC_START) {
				// Initializing
				Init(GC_TICK_TIME, 0, 3, UP);

				// Setting the state to running
				l_state = E_RUNNING;
			}
		}
		
		// Running state
		else if(l_state == E_RUNNING){
			l_in_cmd = Input();
			l_ud_cmd = Update(l_in_cmd);
			Draw(E_RUNNING);

			// Checking if the game is over
			if (l_ud_cmd == GC_GAME_OVER) {
				// Pausing the game
				l_state = E_RUNNING;
			}

			// Checking if a pause is requested
			else if (l_in_cmd == GC_PAUSE) {
				// Pausing the game
				l_state = E_PAUSE;
			}
			
		}
		
		// Pause state
		else if(l_state == E_PAUSE){
			l_in_cmd = Input();
			Draw(E_PAUSE);

			// Checking whether the game is resumed
			if (l_in_cmd == GC_PAUSE) {
				// Setting the state to running
				l_state = E_RUNNING;
			}

			// Checking if a restart is requested
			else if (l_in_cmd == GC_RESTART) {
				// Return to the main menu
				l_state = E_START;
			}
		}
		
		// Game over state
		else if(l_state == E_GAME_OVER){
			l_in_cmd = Input();
			Draw(E_GAME_OVER);

			// Checking if a restart is requested
			if (l_in_cmd == GC_RESTART) {
				// Return to the main menu
				l_state = E_START;
			}
		}	

		// System delay
		Sleep(g_tick);
	}
	
	return 55;
}

