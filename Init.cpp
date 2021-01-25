/*
	File: Init.cpp
	Author: H.CHERGUI
	First version: 1.0
	First version date: 22/01/2021
	current version: 2.1
	current version date: 25/01/2021
*/

// System files includes
/*NONE*/

// User defined files includess\biog
#include "Init.h"


/*Global Variables definition*/

// The time of execution
u_int16 g_tick;

// The game window
std::vector<u_int8> l(GC_M);
std::vector<std::vector<u_int8>> g_graph(GC_N, l);

// The game score
u_int16 g_score;

// The game's hi-score
u_int16 g_hi_score = GC_HI_SCORE;

// Pairs of cordinates for snake
std::pair<u_int8, u_int8> g_snake;

// Pairs of cordinates for snake's tail
std::vector<std::pair<u_int8, u_int8>> g_tail(GC_MAX_LENGTH);

// Current length of the tail
u_int16 g_tail_length;

// Pairs of cordinates for fewd
std::pair<u_int8, u_int8> g_fewd;

// Direction of da snaek
u_int8 g_direction;


/*Global Constants*/

// Highest score
u_int16 GC_HI_SCORE = 30;

// Dimensions of the game window
u_int16 GC_N = 25, GC_M = 80;

// Max length of snake
u_int16 GC_MAX_LENGTH = 1000;

// Tick-time
u_int16 GC_TICK_TIME = 200;

// Command codes
u_int8 GC_START		= 'g';
u_int8 GC_RUNNING	= 15 ;
u_int8 GC_PAUSE		= 'p';
u_int8 GC_PAUSE2	= 27 ;
u_int8 GC_RESTART	= 'r';
u_int8 GC_SELF_INTERSECT = 69;
u_int8 GC_WALL_HIT	= 68 ;

// Const messages
const std::string GC_GAME_NAME_S = "HOUSSINE\'S GAME!";
const std::string GC_PAUSE_MSG_S = "PAUSE!";
const std::string GC_START_MSG_S = "press \'g\' to start";
const std::string GC_HI_SCORE_S = "Hi-score: ";


// Definition of the function Init()
void Init(u_int8 p_tick, u_int8 p_init_score, u_int8 p_init_lenght, e_Direction p_direction) {

	// Initializing tick time
	g_tick = p_tick;

	// Initializing score to p_init_score
	g_score = p_init_score;

	// Initializing lenght to p_lenght
	g_tail_length = p_init_lenght;

	// Initializing fewd position
	g_fewd = std::make_pair(rand() % (GC_N - 5) + 2, rand() % (GC_M - 5) + 2);

	// Initializing snake position
	g_snake = std::make_pair(time(0) % (GC_N / 3) + (GC_N / 3), time(0) % (GC_M / 3) + (GC_M / 3));

	// Initializing the snake's tail

	if (p_direction == DOWN) {
		for (int i = 0; i < g_tail_length; i++) {
			g_tail[i] = std::make_pair(g_snake.first - i - 1, g_snake.second);
		}
	}
	else {
		for (int i = 0; i < g_tail_length; i++) {
			g_tail[i] = std::make_pair(g_snake.first + i + 1, g_snake.second);
		}
	}

	// Initializing snake direction
	g_direction = p_direction;
}