#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef int bool;
#define true 1
#define false 0

// Text Render Methods
typedef enum
{
    TextRenderSolid,
    TextRenderShaded,
    TextRenderBlended
} TextRenderMethod;

// SDL TTF
// TTF_Font *font;
// SDL_Surface *text = NULL;
// Scene scene;
int ptsize;
TextRenderMethod rendermethod;
int renderstyle;
int outline;
int hinting;
int kerning;
char *message, string[128], *font_path;

// Colors
// SDL_Color white = { 0xFF, 0xFF, 0xFF, 1 };
// // SDL_Color black = { 0x00, 0x00, 0x00, 0 };
// SDL_Color red   = { 0xFF, 0x00, 0x00, 0 };
// SDL_Color *forecol;
// SDL_Color *backcol;


bool font_init();