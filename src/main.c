#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "lib.h"
#include "display.h"
#include "font.h"
#include "constant.h"

// Global Variables
unsigned int cycle = 0;
unsigned int frame = 0;
unsigned int lastTime_second = 0;
unsigned int lastTime_fps = 0;
unsigned int currentTime = 0;


int main( int argc, char* args[] )
{
	// ------------ Variables ------------ //
	// SDL Video
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Texture* texture = NULL;

	// Event handler
	SDL_Event event;

	// Main loop flag
	bool quit = false;

	// SDL TTF
    TTF_Font *font;
    SDL_Surface *text = NULL;

    Scene scene;

	// Colors
	SDL_Color white = { 0xFF, 0xFF, 0xFF, 1 };
	// SDL_Color black = { 0x00, 0x00, 0x00, 0 };
	SDL_Color red   = { 0xFF, 0x00, 0x00, 0 };
	SDL_Color *forecol;
	SDL_Color *backcol;

    // ------------ Font Background Color ------------ //
    forecol = &red;

    // ------------ Font Foreground Color ------------ //
    backcol = &white;


	// ---------------------- FONT INIT ----------------------- //
	font_init();


    font = TTF_OpenFont(font_path, ptsize);
    if (font == NULL) {
        SDL_Log("Couldn't load %d pt font from %s: %s\n",
                    ptsize, font_path, SDL_GetError());
        SDL_Quit();
		exit(2);
    }
    TTF_SetFontStyle(font, renderstyle);
    TTF_SetFontOutline(font, outline);
    TTF_SetFontKerning(font, kerning);
    TTF_SetFontHinting(font, hinting);


	// ----------------------- SDL INIT ----------------------- //
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        SDL_Quit();
		exit(2);
	}
	else
	{
		//Create window
		window = SDL_CreateWindow( "C_SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH * SCALE, SCREEN_HEIGHT * SCALE, SDL_WINDOW_SHOWN );
		
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
				texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
				if( renderer == NULL )
				{
					printf( "Texture could not be created! SDL Error: %s\n", SDL_GetError() );
					SDL_Quit();
					exit(2);
				}
			}
		}
	}

 	/* Show which font file we're looking at */
    SDL_snprintf(string, sizeof(string), "Font file: %s", "FIRST MESSAGE!!!");  /* possible overflow */


   switch (rendermethod) {
    case TextRenderSolid:
        text = TTF_RenderText_Solid(font, string, *forecol);                // LATIN1
        // text = TTF_RenderUTF8_Solid(font, message, *forecol);            // UTF8
        // text = TTF_RenderUNICODE_Solid(font, unicode_text, *forecol);    // Unicode
        break;
    case TextRenderShaded:
        text = TTF_RenderText_Shaded(font, string, *forecol, *backcol);      // LATIN1
        // text = TTF_RenderUTF8_Shaded(font, message, *forecol);            // UTF8
        // text = TTF_RenderUNICODE_Shaded(font, unicode_text, *forecol);    // Unicode
        break;
    case TextRenderBlended:
        text = TTF_RenderText_Blended(font, string, *forecol);                // LATIN1
        // text = TTF_RenderUTF8_Blended(font, message, *forecol);            // UTF8
        // text = TTF_RenderUNICODE_Blended(font, unicode_text, *forecol);    // Unicode
        break;
    }

    // DRAW FIXED MESSAGE
    if (text != NULL) {
        scene.captionRect.x = 50;
        scene.captionRect.y = 4;
        scene.captionRect.w = text->w;
        scene.captionRect.h = text->h;
        scene.caption = SDL_CreateTextureFromSurface(renderer, text);
        SDL_FreeSurface(text);
    }


    if (text == NULL) {
        SDL_Log("Couldn't render text: %s\n", SDL_GetError());
        TTF_CloseFont(font);
		SDL_Quit();
		exit(2);
    }

    message = "SECOND MESSAGE!!!";
    text = TTF_RenderText_Blended(font, message, *forecol);



    // SECOND MESSAGE

    scene.messageRect.x = ((SCREEN_WIDTH * SCALE) - text->w)/2;
    scene.messageRect.y = ((SCREEN_HEIGHT * SCALE) - text->h)/2;
    scene.messageRect.w = text->w;
    scene.messageRect.h = text->h;
    scene.message = SDL_CreateTextureFromSurface(renderer, text);
    // SDL_FreeSurface(text);







    if (text == NULL) {
        SDL_Log("Couldn't render text: %s\n", SDL_GetError());
        TTF_CloseFont(font);
		SDL_Quit();
		exit(2);
    }

    // draw_scene(renderer, &scene);






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
				else if  (event.type == SDL_MOUSEBUTTONDOWN){
                scene.messageRect.x = event.button.x - text->w/2;
                scene.messageRect.y = event.button.y - text->h/2;
                scene.messageRect.w = text->w;
                scene.messageRect.h = text->h;
                // draw_scene(renderer, &scene);
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