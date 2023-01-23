#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include "main.h"
#include "lib.h"
#include "display.h"
#include "font.h"

int main( int argc, char* args[] )
{
	// ------------ Variables ------------ //

	// SDL Event handler
	SDL_Event event;

	// Counters
	unsigned int cycle = 0;
	unsigned int frame = 0;
	unsigned int lastTime_second = 0;
	unsigned int lastTime_fps = 0;
	unsigned int currentTime = 0;

	// Main loop flag
	bool quit = false;

	// -------------------------- SDL Init -------------------------- //
	display_init();

	// ------------------------- Font Init -------------------------- //
	font_init(renderer);

	// ----------------------- Infinite Loop  ----------------------- //
	while( !quit )
	{
		// Current time
		currentTime = SDL_GetTicks();

		// Ticker Second
		if ( ticker_second(lastTime_second, currentTime) ) {

			// Cycles and FPS Measurement
			// char title_msg[50];
			// sprintf(title_msg, "Cycles per second: %d\t\tFPS: %d", cycle, frame+1);
			// SDL_SetWindowTitle(window, title_msg);

			// -------- Message slot 1 -------- //
			showCPS(cycle);
			font_update_msg1(renderer);

			// -------- Message slot 2 -------- //
			showFPS(frame+1);
			font_update_msg2(renderer);

			// Update timer variables
			lastTime_second = currentTime;

			// Reset counters
			cycle = 0;
			frame = 0;
		}

		// Ticker FPS (60 times per second)
		if ( ticker_fps(lastTime_fps, currentTime) ) {

			// Handle events on queue
			while( SDL_PollEvent( &event ) != 0 )
			{
				if (event.type == SDL_KEYDOWN)
				{
					const char* key = SDL_GetKeyName(event.key.keysym.sym);
					if (strcmp(key,"Q") == 0 || strcmp(key,"Escape") == 0)
					{
						quit = true;
					}
				}
				else if (event.type == SDL_QUIT)
				{
					quit = true;
				}

			}

			// Draw screen (game and text messages)
			display_draw(window, renderer, texture, frame, &scene);

			// Update timer variables
			lastTime_fps = currentTime;

			// Increment frame counter
			frame ++;
		}

		// Increment CPU Cycle
		cycle++;
	}

	//Free resources and close SDL
	SDL_close(window, renderer, texture);

	return 0;
}