/*
	File: Init.cpp
	Author: H.CHERGUI
	First verion: 1.0
	First verion date: 22/01/2021
	current verion: 1.0
	current verion date: 22/01/2021
*/

// System files includes
/*NONE*/

// User defined files includess\biog
#include "Init.h"


/*Global Variables definition*/

// the time of execution
u_int16 g_tick;

// the game window
std::vector<u_int8> l(GC_M);
std::vector<std::vector<u_int8>> g_graph(GC_N, l);

// the game score
u_int16 g_score;

// the game's hi-score
u_int16 g_hi_score = 0;

// pairs of cordinates for snake
std::pair<u_int8, u_int8> g_snake;

// pairs of cordinates for snake's tail
std::vector<std::pair<u_int8, u_int8>> g_tail(GC_MAX_LENGTH);

// current length of the tail
u_int16 g_tail_length;

// pairs of cordinates for fewd
std::pair<u_int8, u_int8> g_fewd;

// direction of da snaek
u_int8 g_direction;


/*Global Constants*/

// Highest score
u_int16 GC_HI_SCORE = 30;

// dimensions of the game window
u_int16 GC_N = 27, GC_M = 100;

// max length of snake
u_int16 GC_MAX_LENGTH = 1000;

// tick-time
u_int16 GC_TICK_TIME = 100;

// command codes
u_int16 GC_GAME_OVER = 101;


// Definition of the function Init()
void Init(u_int8 p_tick, u_int8 p_init_score, u_int8 p_lenght, e_direction p_direction) {

	// Initializing tick time
	g_tick = p_tick;

	// Initializing score to p_init_score
	g_score = 0;

	// Initializing hi-score to GC_HI_SCORE
	if (g_hi_score < GC_HI_SCORE)
		g_hi_score = GC_HI_SCORE;
	
	// Initializing lenght to p_lenght
	g_tail_length = p_lenght;

	// Initializing fewd position
	g_fewd = std::make_pair(rand() % (GC_N - 5) + 2, rand() % (GC_M - 5) + 2);

	// Initializing snake position
	g_snake = std::make_pair(time(0) % (GC_N / 3) + (GC_N / 3), time(0) % (GC_M / 3) + (GC_M / 3));

	// Initializing the snake's tail
	for (int i = 0; i < g_tail_length; i++) {
		g_tail[i] = std::make_pair(g_snake.first + i+1, g_snake.second);
	}

	// Initializing snake direction
	g_direction = p_direction;
}