#ifndef GLOBAL_CONSTANTS
#define GLOBAL_CONSTANTS

// System files includes
/*None*/

// User defined files includes
#include "Types.h"


// Highest score
extern u_int16 GC_HI_SCORE ;

// Dimensions of the game window
extern u_int16 GC_N ;
extern u_int16 GC_M ;

// Max length of snake
extern u_int16 GC_MAX_LENGTH ;

// Tick-time
extern u_int16 GC_TICK_TIME ;

// Command codes
extern u_int8 GC_START			 ;
extern u_int8 GC_RUNNING		 ;
extern u_int8 GC_PAUSE			 ;
extern u_int8 GC_PAUSE2			 ;
extern u_int8 GC_RESTART		 ;
extern u_int8 GC_SELF_INTERSECT  ;
extern u_int8 GC_WALL_HIT		 ;

// Const messages
extern const std::string GC_GAME_NAME_S;
extern const std::string GC_START_MSG_S;
extern const std::string GC_PAUSE_MSG_S;
extern const std::string GC_HI_SCORE_S ;

#endif // !GLOBAL_CONSTANTS
