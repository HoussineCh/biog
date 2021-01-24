#ifndef GLOBAL_CONSTANTS
#define GLOBAL_CONSTANTS

// System files includes
/*None*/

// User defined files includes
#include "Types.h"


// Highest score
extern u_int16 GC_HI_SCORE ;

// dimensions of the game window
extern u_int16 GC_N ;
extern u_int16 GC_M ;

// max length of snake
extern u_int16 GC_MAX_LENGTH ;

// tick-time
extern u_int16 GC_TICK_TIME ;

// command codes
extern u_int8 GC_START		;
extern u_int8 GC_RUNNING	;
extern u_int8 GC_PAUSE		;
extern u_int8 GC_RESTART	;
extern u_int8 GC_GAME_OVER	;
extern u_int8 GC_SELF_INTERSECT ;
extern u_int8 GC_WALL_HIT	;

#endif // !GLOBAL_CONSTANTS
