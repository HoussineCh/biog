/*
	File: Snake.cpp
	Author: H.CHERGUI
	First version: 2.6
	First version date: xx/yy/2021
	current version: 2.6
	current version date: xx/yy/2021
*/

// System files includes
/*None*/

// User defined files includes
#include "Snake.h"

// Member methods definition


// Initializing position, tail and direction of da snaek
void Snake::Initialize(u_int8 p_init_lenght, e_Direction p_direction) {
	// init tail
	tail.resize(GC_MAX_LENGTH);

	// Generate random initial position
	coordinates = std::make_pair(time(0) % (GC_N / 3) + (GC_N / 3), time(0) % (GC_M / 3) + (GC_M / 3));

	// Setting the initial length
	tail_length = p_init_lenght;

	// Initializing snake direction
	direction = p_direction;

	// Initializing the tail
	if (p_direction == e_Direction::DOWN) {
		for (int i = 0; i < tail_length; i++) {
			tail[i] = std::make_pair(coordinates.first - i - 1, coordinates.second);
		}
	}
	else {
		for (int i = 0; i < tail_length; i++) {
			tail[i] = std::make_pair(coordinates.first + i + 1, coordinates.second);
		}
	}
}

// Increment lenght of tail
void Snake::tail_length_inc() {
	tail_length++;
}

// Getters and setters
std::pair<s_int8, s_int8> Snake::get_coordinates() {
	return coordinates;
}
std::vector<std::pair<s_int8, s_int8>> Snake::get_tail() {
	return tail;
}
u_int16 Snake::get_tail_length() {
	return tail_length;
}
e_Direction Snake::get_direction() {
	return direction;
}

void Snake::set_coordinates(std::pair<u_int8, u_int8> p_coordinates) {
	coordinates = p_coordinates;
}
void Snake::set_tail(std::pair<s_int8, s_int8> p_tail, uint8_t p_index) {
	tail[p_index] = p_tail;
}
void Snake::set_tail_length(u_int16 p_tail_length) {
	tail_length = p_tail_length;
}
void Snake::set_direction(e_Direction p_direction) {
	direction = p_direction;
}