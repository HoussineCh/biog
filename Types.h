#ifndef TYPES
#define TYPES

// System files includes
/*None*/

// User defined files includes
/*None*/

// define signed types
#define s_int8 char

#define s_int16 short

#define s_int32 int

#define s_int64 long long

// define unsigned types
#define u_int8 unsigned char

#define u_int16 unsigned short

#define u_int32 unsigned int

#define u_int64 unsigned long long

// define direction enumeration
enum e_direction {
	UP = 'z',
	DOWN = 's',
	RIGHT = 'd',
	LEFT = 'q'
};

// redefining main just to be bada$$
#define main_game main

#endif // !TYPES
