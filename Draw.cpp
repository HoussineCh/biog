/*
	File: Draw.cpp
	Author:	H.CHERGUI
	First version: 1.0
	First version date: 22/01/2021
	current version: 2.1
	current version date: 25/01/2021
*/

// System files includes
/*NONE*/

// User defined files includes
#include "Draw.h"


/*Global Variables definition*/
/*NONE*/

/*Global Constants*/
/*NONE*/


// Drawing the content on the screen
void Draw(e_State p_state, uint8_t p_cmd) {
	
	// Clear the screen
	system("cls");

	// Display the start screen
	if (p_state == E_START) {

		// Contructing the sides
		for (u_int8 i = 0; i < GC_N; i++) {
			if (i == 0 || i == 1 || i == GC_N - 2 || i == GC_N - 1) {
				for (u_int8 j = 0; j < GC_M; j++) {
					g_graph[i][j] = '#';
				}
			}
			else {
				g_graph[i][0] = '#';
				g_graph[i][1] = '#';
				for (u_int8 j = 2; j < GC_M - 2; j++) {
					g_graph[i][j] = ' ';
				}
				g_graph[i][GC_M - 2] = '#';
				g_graph[i][GC_M - 1] = '#';
			}
		}

		// Adding the game's name
		for (uint8_t j = GC_M / 2 - 8; j < GC_M / 2 + 8; j++) {
			g_graph[GC_N / 4][j] = GC_GAME_NAME_S[j - (GC_M / 2 - 8)];
		}
		for (uint8_t j = GC_M / 2 - 8; j < GC_M / 2 + 8; j++) {
			g_graph[GC_N / 4+1][j] = GC_GAME_NAME_S[j - (GC_M / 2 - 8)];
		}

		// Adding the 'click to start' message
		for (uint8_t j = GC_M / 2 - 9; j < GC_M / 2 + 9; j++) {
			g_graph[GC_N / 2][j] = GC_START_MSG_S[j - (GC_M / 2 - 9)];
		}

		// Adding the hi-score
		for (uint8_t j = GC_M / 2 - 5; j < GC_M / 2 + 5; j++) {
			g_graph[3*GC_N / 4][j] = GC_HI_SCORE_S[j - (GC_M / 2 - 5) ];
		}
		for (uint8_t j = GC_M / 2 + 5; j < GC_M / 2 + 5 + std::to_string(g_hi_score).length(); j++) {
			g_graph[3*GC_N / 4][j] = std::to_string(g_hi_score)[j - (GC_M / 2 + 5)];
		}

		// Drawing the start screen
		for (u_int8 i = 0; i < GC_N; i++) {
			for (u_int8 j = 0; j < GC_M; j++) {
				std::cout << g_graph[i][j];
			}
			std::cout << std::endl;
		}

	}else
	
	// Run the game
	if (p_state == E_RUNNING) {
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
	if (p_state == E_PAUSE) {
		std::cout << "Score: " << g_score << "\t\t\t\t\t\t\t\t\tHi-Score: " << g_hi_score << std::endl;
		
		for (uint8_t j = GC_M / 2 - 3; j < GC_M / 2 + 3; j++) {
			g_graph[GC_N / 2][j] = GC_PAUSE_MSG_S[j - GC_M / 2 + 3];
		}
		for (u_int8 i = 0; i < GC_N; i++) {
			for (u_int8 j = 0; j < GC_M; j++) {
				std::cout << g_graph[i][j];
			}
			std::cout << std::endl;
		}
	}
	else
		
	// Launch the game-over screen
	if (p_state == E_GAME_OVER) {
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
		std::cout << "(press \'r\' to restart)";
	}

	return;
}
