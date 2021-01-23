#ifndef GLOBAL_VARIABLES
#define GLOBAL_VARIABLES

// System files includes
#include <vector>
#include <string>

// User defined files includes
#include "Global_Constants.h"


/*Globale Variables declaration*/

// the time of execution
extern u_int16 g_tick;

// the game's window
extern std::vector<std::vector<u_int8>> g_graph;

// the game's score
extern u_int16 g_score;

// the game's hi-score
extern u_int16 g_hi_score;

// pairs of cordinates for snake
extern std::pair<u_int8, u_int8> g_snake;

// pairs of cordinates for snake's tail
extern std::vector<std::pair<u_int8, u_int8>> g_tail;

// current length of the tail
extern u_int16 g_tail_length;

// direction of da snaek
extern u_int8 g_direction;

// pairs of cordinates for fewd
extern std::pair<u_int8, u_int8> g_fewd;

#endif // !GLOBAL_VARIABLES
