/*
	File: Draw.cpp
	Author:	H.CHERGUI
	First verion: 1.0
	First verion date: 22/01/2021
	current verion: 1.0
	current verion date: 22/01/2021
*/

// System files includes
/*NONE*/

// User defined files includes
#include "Draw.h"


/*Global Variables definition*/
/*NONE*/

/*Global Constants*/
/*NONE*/


// Definition of the function Draw()
void Draw(e_State p_cmd) {

	// Display the start screen
	if (p_cmd == GC_START) {
		// ...
	}else
	
	// Run the game
	if (p_cmd == GC_RUNNING) {
		system("cls");
		std::cout << "Score: " << g_score << "\t\t\t\t\t\t\t\t\tHi-Score: " << g_hi_score << std::endl;
		for (u_int8 i = 0; i < GC_N; i++) {
			for (u_int8 j = 0; j < GC_M; j++) {
				std::cout << g_graph[i][j];
			}
			std::cout << std::endl;
		}
	}
	else
	
	// Pause the game
	if (p_cmd == GC_PAUSE) {
		// ...
	}
	else
		
	// Launch the game-over screen
	if (p_cmd == GC_GAME_OVER) {
		system("cls");
		std::cout << "\n-------------------------------------------------------------------------------\n";
		std::cout << "---------------------------------  GAME OVER  ---------------------------------\n";
		std::cout << "-------------------------------------------------------------------------------\n\n";
		std::cout << ((g_score > GC_HI_SCORE) ? ("New hi-score: " + std::to_string(g_score) + " !") : "Score: " + std::to_string(g_score)) << std::endl;

		if (p_cmd == GC_WALL_HIT) {
			std::cout << "\n\"wall was hit!!\"\n\n";
		}
		else if (p_cmd == GC_SELF_INTERSECT) {
			std::cout << "\n\"ate your self!!\"\n\n";
		}
		else {
			std::cout << "\n[>>ERR::UNKOWN_REASON]\n\n";
		}
	}

	return;
}
