/*
	File: Input.cpp
	Author: H.CHERGUI
	First version: 2.5
	First version date: 25/01/2021
	Current version: 2.5
	Current version date: 25/01/2021
*/

// System files includes
/*NONE*/

// User defined files includes
#include "State_Engine.h"

/*Global Variables definition*/
/*NONE*/

/*Global Constants*/
/*NONE*/

// Definition of the function State_Engine()

e_State State_Engine(e_State p_current_state, u_int8 p_in_cmd, u_int8 p_ud_cmd) {

	// Local variables
	e_State l_current_state = p_current_state;

	// Start screen
	if (p_current_state == e_State::E_START) {
		
		// Initializing
		Init(GC_TICK_TIME, 0, 5, e_Direction::UP);

		// Checking if a start is requested
		if (p_in_cmd == GC_START) {

			// Run the game
			l_current_state = e_State::E_RUNNING;
		}

		// Extra waiting to compensate the reduced cpu load
		Sleep(g_tick);
	}

	// Running state
	else if (p_current_state == e_State::E_RUNNING) {

		// Checking if the game is over
		if (p_ud_cmd == GC_WALL_HIT || p_ud_cmd == GC_SELF_INTERSECT) {
			// Put an end to the game
			l_current_state = e_State::E_GAME_OVER;
		}

		// Checking if a pause is requested
		else if (p_in_cmd == GC_PAUSE || p_in_cmd == GC_PAUSE2) {
			// Pause the game
			l_current_state = e_State::E_PAUSE;
		}
	}

	// Pause state
	else if (p_current_state == e_State::E_PAUSE) {
		
		// Checking whether the game is resumed
		if (p_in_cmd == GC_PAUSE || p_in_cmd == GC_PAUSE2) {
			// Resume the game
			l_current_state = e_State::E_RUNNING;
		}

		// Checking if a restart is requested
		else if (p_in_cmd == GC_RESTART) {
			// Back to main menu
			l_current_state = e_State::E_START;
		}
	}

	// Game over state
	else if (p_current_state == e_State::E_GAME_OVER) {

		// Checking if a restart is requested
		if (p_in_cmd == GC_RESTART) {
			// Back to main menu
			l_current_state = e_State::E_START;
		}

		// Extra waiting to compensate the reduced cpu load
		Sleep(GC_TICK_TIME);
	}

	// Return the updated state
	return l_current_state;
}

