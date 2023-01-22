#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "display.h"

void display_init()
{
	// Screen Variables
	display_SCREEN_WIDTH_X	= 64;
	display_SCREEN_HEIGHT_Y	= 32;
	display_SCALE			= 20;
	display_pixel_ON_color	= 0xFFFFFFFF;
	display_pixel_OFF_color	= 0xFF000000;
};

bool display_draw(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture, unsigned int frame, Scene *scene)
{
	//Initialization flag
	bool success = true;

	// Initialization - Clean pixels array
	for ( int i = 0 ; i < (int)( sizeof(pixels) / sizeof(pixels[0])) ; i++ ) {
			pixels[i] = display_pixel_OFF_color;
	}

	// Test turn on some pixels
	pixels[frame] = display_pixel_ON_color;
	pixels[2048-frame] = display_pixel_ON_color;

    /* Clear the background to background color */
    // SDL_SetRenderDrawColor(renderer, 0x33, 0x00, 0x40, 0xFF);
    SDL_RenderClear(renderer);

    // Update game texture
	SDL_UpdateTexture(texture, NULL, pixels, display_SCREEN_WIDTH_X * sizeof(uint32_t));
	SDL_RenderCopy(renderer, texture, NULL, NULL);

    // ----- Update Text Messages ----- //
	// Message Slot 1
	if ( string_msg1 != NULL && strcmp( string_msg1, "") != 0 ) {
		    SDL_RenderCopy(renderer, scene->message1, NULL, &scene->message1_Rect);
	}
	// Message Slot 2
	if ( string_msg2 != NULL && strcmp( string_msg2, "") != 0 ) {
    	SDL_RenderCopy(renderer, scene->message2, NULL, &scene->message2_Rect);
	}

    // Update the Screen
	SDL_RenderPresent(renderer);

	return success;
}

void SDL_close(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture)
{
	// Destroy window	
	SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow( window );
	window = NULL;
	renderer = NULL;

    // Destroy font
    TTF_Quit();

	//Quit SDL subsystems
	SDL_Quit();
}