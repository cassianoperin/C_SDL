#include <SDL2/SDL.h>
#include <string>
#include "display.h"

// -------------------------------- main -------------------------------- //

int main( int argc, char* args[] )
{

	// Variables
	struct display display;
	int counter = 0;

	//Start up SDL and create window
	if( !display_init(&display) )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;

		// ----------------------- Infinite Loop  ----------------------- //
		while( !quit )
		{
			//Handle events on queue
			while( SDL_PollEvent( &e ) != 0 )
			{
				//User requests quit
				if( e.type == SDL_QUIT )
				{
					quit = true;
				}
			}


			// Draw
			display_draw(&display); 
		}
	}

	//Free resources and close SDL
	display_close(&display);

	return 0;
}