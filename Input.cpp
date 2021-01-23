/*
	File: Input.cpp
	Author: H.CHERGUI
	First verion: 1.0
	First verion date: 22/01/2021
	current verion: 1.0
	current verion date: 22/01/2021
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
	if (_kbhit() != 0) {
		return _getch();
	}
}

