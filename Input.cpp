/*
	File: Input.cpp
	Author: H.CHERGUI
	First version: 1.0
	First version date: 22/01/2021
	current version: 1.0
	current version date: 22/01/2021
*/

// System files includes
/*NONE*/

// User defined files includes
 #include "Input.h"

/*Global Variables definition*/
/*NONE*/

/*Global Constants*/
/*NONE*/

// Definition of the function Input()
u_int8 Input(u_int8& p_prev_in) {
	//p_prev_in = 0;
	if (_kbhit() != 0) {
		return _getch();
	}
}

