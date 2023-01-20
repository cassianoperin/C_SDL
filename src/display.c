#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "display.h"
#include "constant.h"

bool display_draw(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture, unsigned int frame, Scene *scene)
{
	//Initialization flag
	bool success = true;

	// Initialization - Clean pixels array
	memset(pixels, PIXEL_OFF_COLOR, sizeof(pixels));

	// Test turn on some pixels
	pixels[frame] = PIXEL_ON_COLOR;
	pixels[2048-frame] = PIXEL_ON_COLOR;

    /* Clear the background to background color */
    // SDL_SetRenderDrawColor(renderer, 0x33, 0x00, 0x40, 0xFF);
    SDL_RenderClear(renderer);

    // Update game texture
	SDL_UpdateTexture(texture, NULL, pixels, SCREEN_WIDTH * sizeof(uint32_t));
	SDL_RenderCopy(renderer, texture, NULL, NULL);

    // Update Text Messages
	SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderCopy(renderer, scene->caption, NULL, &scene->captionRect);
    SDL_RenderCopy(renderer, scene->message, NULL, &scene->messageRect);

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