#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include "main.h"
#include "lib.h"
#include "display.h"
#include "font.h"

// --------------------------------- External Variables --------------------------------- //
extern char *string_msg1, *string_msg2;

int main( int argc, char* args[] )
{
	// ------------ Variables ------------ //
	// SDL Video
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Texture* texture = NULL;

	// SDL Event handler
	SDL_Event event;

	// SDL TTF
    // TTF_Font *font = NULL;
    // SDL_Surface *text = NULL;

	// Counters
	unsigned int cycle = 0;
	unsigned int frame = 0;
	unsigned int lastTime_second = 0;
	unsigned int lastTime_fps = 0;
	unsigned int currentTime = 0;

	// Main loop flag
	bool quit = false;

	// ----------------------- SDL INIT ----------------------- //

	// Initialize Display Variables
	display_init();

	// SDL INIT
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        SDL_Quit();
		exit(2);
	}
	else
	{
		//Create window
		window = SDL_CreateWindow( "C_SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, display_SCREEN_WIDTH_X * display_SCALE, display_SCREEN_HEIGHT_Y * display_SCALE, SDL_WINDOW_SHOWN );
		
		if( window == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			SDL_Quit();
			exit(2);
		}
		else
		{
			//Create renderer for window
			renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
			if( renderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				SDL_Quit();
				exit(2);
			} else {
				//Create texture
				texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, display_SCREEN_WIDTH_X, display_SCREEN_HEIGHT_Y);
				if( renderer == NULL )
				{
					printf( "Texture could not be created! SDL Error: %s\n", SDL_GetError() );
					SDL_Quit();
					exit(2);
				}
			}
		}
	}

	// ---------------------- FONT INIT ----------------------- //
	
	
	font_init(renderer);




	// ----------------------- Infinite Loop  ----------------------- //
	while( !quit )
	{
		// Current time
		currentTime = SDL_GetTicks();

		// Ticker Second
		if ( ticker_second(lastTime_second, currentTime) ) {

			// Cycles and FPS Measurement
			// printf("CPS: %d\tFPS: %d\n", cycle, frame+1);
			char title_msg[50];
			sprintf(title_msg, "Cycles per second: %d\t\tFPS: %d", cycle, frame+1);
			SDL_SetWindowTitle(window, title_msg);

			// Handle Screen Messages
			// string_msg1 = atoa(1234567890);
			// string_msg1 = "UHULLLL";
			char* charint_str[20];
			string_msg1 = charint_str;
			sprintf(string_msg1, "%d", cycle );
			font_update_msg1(renderer);

			printfcomma(cycle);
			
			string_msg2 = "UHULLLL 22222";
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