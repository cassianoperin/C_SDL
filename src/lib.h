#pragma once
#include "typedef.h"

// -------------------------------------- Functions ------------------------------------- //

// Use with actions that should be executed each second
bool ticker_second(unsigned int lastTime, unsigned int currentTime);

// Use with actions that should be executed 60 times per second
bool ticker_fps(unsigned int lastTime, unsigned int currentTime);

// Load rom into memory
void load_rom(char* filename, unsigned char *mem, unsigned int mem_size);