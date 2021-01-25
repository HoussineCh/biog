/*
	File: Update.cpp
	Author: H.CHERGUI
	First version: 1.0
	First version date: 22/01/2021
	current verson: 2.0
	current version date: 24/01/2021
*/

// System files includes
/*NONE*/

// User defined files includes
#include "Update.h"

/*Global Variables definition*/
/*NONE*/

/*Global Constants*/
/*NONE*/


// Definition of the function Update()
u_int8 Update(e_State p_state, u_int8 p_cmd) {

	if (p_state == E_RUNNING) {
		// updating the direction with its speed
		g_tick = GC_TICK_TIME;
		switch (p_cmd) {
		case UP:
			if (g_direction == LEFT || g_direction == RIGHT) {
				g_direction = UP;
			}
			else if (g_direction == p_cmd) {
				g_tick = GC_TICK_TIME / 10;
			}
			break;
		case DOWN:
			if (g_direction == LEFT || g_direction == RIGHT) {
				g_direction = DOWN;
			}
			else if (g_direction == p_cmd) {
				g_tick = GC_TICK_TIME / 10;
			}
			break;
		case RIGHT:
			if (g_direction == UP || g_direction == DOWN) {
				g_direction = RIGHT;
			}
			else if (g_direction == p_cmd) {
				g_tick = GC_TICK_TIME / 10;
			}
			break;
		case LEFT:
			if (g_direction == UP || g_direction == DOWN) {
				g_direction = LEFT;
			}
			else if (g_direction == p_cmd) {
				g_tick = GC_TICK_TIME / 10;
			}
			break;
		}

		// reconstruction of the window
		for (u_int8 i = 0; i < GC_N; i++) {
			if (i == 0 || i == GC_N - 1) {
				for (u_int8 j = 0; j < GC_M; j++) {
					g_graph[i][j] = '#';
				}
			}
			else {
				g_graph[i][0] = '#';
				for (u_int8 j = 1; j < GC_M - 1; j++) {
					g_graph[i][j] = ' ';
				}
				g_graph[i][GC_M - 1] = '#';
			}
		}

		// determining the fewd cordinates and increasing score after the snake has filled its tummy
		if (g_fewd.first == g_snake.first && g_fewd.second == g_snake.second) {
			g_fewd.first = rand() % (GC_N - 2) + 1;
			g_fewd.second = rand() % (GC_M - 2) + 1;
			g_tail_length++;	// gulp... ahhhhh!
			g_score += 10;
		}

		// determining the tail of da snaek
		std::pair<int, int> l_prev = std::make_pair(g_tail[0].first, g_tail[0].second);
		std::pair<int, int> l_prev_current;
		g_tail[0] = std::make_pair(g_snake.first, g_snake.second);
		for (int i = 1; i < g_tail_length; i++) {
			l_prev_current = g_tail[i];
			g_tail[i] = l_prev;
			l_prev = l_prev_current;
		}

		// determining the snaek's cordinates
		switch (g_direction)
		{
		case UP:
			g_snake.first--;
			break;
		case DOWN:
			g_snake.first++;
			break;
		case RIGHT:
			g_snake.second++;
			break;
		case LEFT:
			g_snake.second--;
			break;
		default:
			break;
		}

		// game over - cause: wall hitting - code : GC_WALL_HIT 
		if (g_snake.first <= 0 || g_snake.first >= GC_N - 1 || g_snake.second <= 0 || g_snake.second >= GC_M - 1) {
			return GC_WALL_HIT;
		}

		// game over - cause: stepping on yee self - code : GC_SELF_INTERSECT
		for (u_int8 i = 0; i < g_tail_length; i++) {
			if (g_snake == g_tail[i]) {
				return GC_SELF_INTERSECT;
			}
		}

		// spawning the fewd
		g_graph[g_fewd.first][g_fewd.second] = 'X';

		// spawning the snaek and its tail
		g_graph[g_snake.first][g_snake.second] = 'S';
		for (u_int8 i = 0; i < g_tail_length; i++) {
			g_graph[g_tail[i].first][g_tail[i].second] = 's';
		}

		// calculate hi-score
		if (g_score > g_hi_score)
			g_hi_score = g_score;

		// return input cmd
		return GC_RUNNING;
	}
	
}