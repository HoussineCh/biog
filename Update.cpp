/*
	File: Update.cpp
	Author: H.CHERGUI
	First version: 1.0
	First version date: 22/01/2021
	current version: 2.6
	current version date: 29/01/2021
*/

// System files includes
/*NONE*/

// User defined files includes
#include "Update.h"

/*Global Variables definition*/
/*NONE*/

/*Global Constants*/
/*NONE*/


// Definition of the update function
s_Game_info Update(s_Game_info p_status, u_int8 p_in_cmd) {
	
	// Local variables
	s_Game_info l_status;
	
	// Determining the current state
	l_status.state = State_Engine(p_status, p_in_cmd);

	if (l_status.state == e_State::E_RUNNING) {
		
		// Updating the snake
		ud_snake((e_Direction)p_in_cmd);

		// Updating fewd cordinates and increasing score after the snake has filled its tummy
		if (g_fewd.first == g_snake.get_coordinates().first && g_fewd.second == g_snake.get_coordinates().second) {
			g_fewd.first = rand() % (GC_N - 2) + 1;
			g_fewd.second = rand() % (GC_M - 2) + 1;
			g_snake.tail_length_inc();	// gulp... ahhhhh!
			g_score += 10;
		}

		// Checking the status of the game
		l_status.code = ud_game_state();

		// Update the content of the sreen
		ud_screen();
	}

	// Return game status
	return l_status;
}

// Update the snake
void ud_snake(e_Direction p_cmd) {
	// Updating the direction with its speed
	g_tick = GC_TICK_TIME;
	switch (p_cmd) {
	case e_Direction::UP:
		if (g_snake.get_direction() == e_Direction::LEFT || g_snake.get_direction() == e_Direction::RIGHT) {
			g_snake.set_direction(e_Direction::UP);
		}
		else if (g_snake.get_direction() == p_cmd) {
			g_tick = GC_TICK_TIME / 10;
		}
		break;
	case e_Direction::DOWN:
		if (g_snake.get_direction() == e_Direction::LEFT || g_snake.get_direction() == e_Direction::RIGHT) {
			g_snake.set_direction(e_Direction::DOWN);
		}
		else if (g_snake.get_direction() == p_cmd) {
			g_tick = GC_TICK_TIME / 10;
		}
		break;
	case e_Direction::RIGHT:
		if (g_snake.get_direction() == e_Direction::UP || g_snake.get_direction() == e_Direction::DOWN) {
			g_snake.set_direction(e_Direction::RIGHT);
		}
		else if (g_snake.get_direction() == p_cmd) {
			g_tick = GC_TICK_TIME / 10;
		}
		break;
	case e_Direction::LEFT:
		if (g_snake.get_direction() == e_Direction::UP || g_snake.get_direction() == e_Direction::DOWN) {
			g_snake.set_direction(e_Direction::LEFT);
		}
		else if (g_snake.get_direction() == p_cmd) {
			g_tick = GC_TICK_TIME / 10;
		}
		break;
	}

	// Updating the tail of da snaek
	std::pair<int, int> l_prev_current;
	for (int i = 1; i < g_snake.get_tail_length(); i++) {
		l_prev_current = g_snake.get_tail()[i];
		g_snake.set_tail(g_snake.get_tail()[0], i);
		g_snake.set_tail(l_prev_current, 0);
	}
	g_snake.set_tail(g_snake.get_coordinates(), 0);


	// Determining the snaek's coordinates
	switch (g_snake.get_direction())
	{
	case e_Direction::UP:
		g_snake.set_coordinates(std::make_pair(g_snake.get_coordinates().first - 1, g_snake.get_coordinates().second));
		break;
	case e_Direction::DOWN:
		g_snake.set_coordinates(std::make_pair(g_snake.get_coordinates().first + 1, g_snake.get_coordinates().second));
		break;
	case e_Direction::RIGHT:
		g_snake.set_coordinates(std::make_pair(g_snake.get_coordinates().first, g_snake.get_coordinates().second + 1));
		break;
	case e_Direction::LEFT:
		g_snake.set_coordinates(std::make_pair(g_snake.get_coordinates().first, g_snake.get_coordinates().second - 1));
		break;
	default:
		break;
	}
}

// Check for a game-over
uint8_t ud_game_state() {
	// Game over - cause: wall hitting - code : GC_WALL_HIT 
	if (g_snake.get_coordinates().first <= 0 || g_snake.get_coordinates().first >= GC_N - 1 || \
		g_snake.get_coordinates().second <= 0 || g_snake.get_coordinates().second >= GC_M - 1)
	{
		return GC_WALL_HIT;
	}

	// Game over - cause: stepping on yee self - code : GC_SELF_INTERSECT
	for (u_int8 i = 0; i < g_snake.get_tail_length(); i++) {
		if (g_snake.get_coordinates() == g_snake.get_tail()[i]) {
			return GC_SELF_INTERSECT;
		}
	}

	// Game running
	return GC_RUNNING;
}

// Update screen's content
void ud_screen() {
	// Reconstruction of the window
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
	// Spawning the fewd
	g_graph[g_fewd.first][g_fewd.second] = 'X';

	// Spawning the snaek and its tail
	g_graph[g_snake.get_coordinates().first][g_snake.get_coordinates().second] = 'S';
	for (u_int8 i = 0; i < g_snake.get_tail_length(); i++) {
		g_graph[g_snake.get_tail()[i].first][g_snake.get_tail()[i].second] = 's';
	}

	// Calculate hi-score
	if (g_score > g_hi_score)
		g_hi_score = g_score;
}
