/*
	File: Input.cpp
	Author: H.CHERGUI
	First version: 1.0
	First version date: 22/01/2021
	current version: 2.6
	current version date: 29/01/2021
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
u_int8 Input() {

	// Get input if keyboard is pressed
	if (_kbhit() != 0) {
		return _getch();
	}
	else {
		return 0;
	}
}

