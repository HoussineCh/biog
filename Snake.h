#pragma once

// System files includes
#include <iostream>
#include <vector>

// User defined files includes
#include "Types.h"
#include "Global_Constants.h"

// Defining snake class
class Snake {
	// pairs of cordinates for snake
	std::pair<s_int8, s_int8> coordinates;

	// pairs of cordinates for snake's tail
	std::vector<std::pair<s_int8, s_int8>> tail;

	// current length of the tail
	u_int16 tail_length;

	// direction of da snaek
	e_Direction direction;

public:
	// Initializing position, tail and direction of da snaek
	void Initialize(u_int8, e_Direction);

	// Increment lenght of tail
	void tail_length_inc();

	// Getters and setters
	std::pair<s_int8, s_int8> get_coordinates();
	std::vector<std::pair<s_int8, s_int8>> get_tail();
	u_int16 get_tail_length();
	e_Direction get_direction();

	void set_coordinates(std::pair<u_int8, u_int8>);
	void set_tail(std::pair<s_int8, s_int8>, uint8_t);
	void set_tail_length(u_int16);
	void set_direction(e_Direction);

};

