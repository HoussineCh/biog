#ifndef UPDATE
#define UPDATE

// System files includes
/*NONE*/

// User defined files includes
#include "Global_Variables.h"
#include "State_Engine.h"


// Signature of the function Update()
s_Game_info Update(s_Game_info, u_int8);

// Sub-functions signatures
void ud_snake(e_Direction);
uint8_t ud_game_state();
void ud_screen();

#endif // !UPDATE
