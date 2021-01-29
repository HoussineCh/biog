#ifndef GLOBAL_VARIABLES
#define GLOBAL_VARIABLES

// System files includes
#include <vector>
#include <string>

// User defined files includes
#include "Global_Constants.h"
#include "Snake.h"


/*Globale Variables declaration*/

// The time of execution
extern u_int16 g_tick;

// The game's window
extern std::vector<std::vector<u_int8>> g_graph;

// The game's score
extern u_int16 g_score;

// The game's hi-score
extern u_int16 g_hi_score;

// Da snake!
extern Snake g_snake;

// Pairs of cordinates for fewd
extern std::pair<u_int8, u_int8> g_fewd;

#endif // !GLOBAL_VARIABLES
