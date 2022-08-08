/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, math, and strings
#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include "constant.h"

// ------------------------ function definitions ------------------------ //

//Starts up SDL and creates window
bool display_init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Loads individual image as texture
// SDL_Texture* loadTexture( std::string path );
SDL_Texture* gTexture = NULL;



// ----------------------------- functions ------------------------------ //

bool display_init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "C_SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH * SCALE, SCREEN_HEIGHT * SCALE, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			} else {
				//Create texture
				gTexture = SDL_CreateTexture(gRenderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
				if( gRenderer == NULL )
				{
					printf( "Texture could not be created! SDL Error: %s\n", SDL_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

void close()
{
	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}



// -------------------------------- main -------------------------------- //

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !display_init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		
		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;

		//While application is running
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


			// Initialization - Clean pixels array
			memset(pixels, PIXEL_OFF_COLOR, sizeof(pixels));

			// Test turn on some pixels
			pixels[5] = PIXEL_ON_COLOR;
			pixels[2047] = PIXEL_ON_COLOR;



			// Update the Screen
			SDL_UpdateTexture(gTexture, NULL, pixels, SCREEN_WIDTH * sizeof(uint32_t));
			SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
			SDL_RenderPresent(gRenderer);

			SDL_SetWindowTitle(gWindow, "test");





			

			// //Clear screen
			// SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
			// SDL_RenderClear( gRenderer );

			// //Render red filled quad
			// SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
			// SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );		
			// SDL_RenderFillRect( gRenderer, &fillRect );

			// //Render green outlined quad
			// SDL_Rect outlineRect = { SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3 };
			// SDL_SetRenderDrawColor( gRenderer, 0x00, 0xFF, 0x00, 0xFF );		
			// SDL_RenderDrawRect( gRenderer, &outlineRect );
			
			// //Draw blue horizontal line
			// SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0xFF, 0xFF );		
			// SDL_RenderDrawLine( gRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2 );

			// //Draw vertical line of yellow dots
			// SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0x00, 0xFF );
			// for( int i = 0; i < SCREEN_HEIGHT; i += 4 )
			// {
			// 	SDL_RenderDrawPoint( gRenderer, SCREEN_WIDTH / 2, i );
			// }

			// //Update screen
			// SDL_RenderPresent( gRenderer );
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}