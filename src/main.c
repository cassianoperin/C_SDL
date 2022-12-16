#include <SDL2/SDL.h>
#include "lib.h"
#include "display.h"

// Global Variables
unsigned int cycle = 0;
unsigned int frame = 0;
unsigned int lastTime_second = 0;
unsigned int lastTime_fps = 0;
unsigned int currentTime = 0;


// -------------------------------- main -------------------------------- //

int main( int argc, char* args[] )
{
	// Variables
	struct display display;

	//Start up SDL and create window
	if( !display_init(&display) )
	{
		printf( "Failed to initialize SDL!\n" );
	}
	else
	{
		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event event;

		// ----------------------- Infinite Loop  ----------------------- //
		while( !quit )
		{
			// Current time
			currentTime = SDL_GetTicks();


			// Ticker Second
			if ( ticker_second(lastTime_second, currentTime) ) {

				// Cycles and FPS Measurement
				// printf("CPS: %d\tFPS: %d\n", cycle, frame+1);
				char title_msg[30];
				sprintf(title_msg, "Cycles per second: %d\t\tFPS: %d", cycle, frame+1);
				SDL_SetWindowTitle(display.window, title_msg);

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

				// Draw screen
				display_draw(&display, frame);

				// Update timer variables
				lastTime_fps = currentTime;

				// Increment frame counter
				frame ++;
			}

			// Increment CPU Cycle
			cycle++;

			// Kill on first cycle for tests
			// break;
		}
	}

	//Free resources and close SDL
	display_close(&display);

	return 0;
}