#pragma once

typedef int bool;
#define true 1
#define false 0

typedef struct {
    SDL_Texture *caption;
    SDL_Rect captionRect;
    SDL_Texture *message;
    SDL_Rect messageRect;
} Scene;

// Display (Screen size)
unsigned char display_SCREEN_WIDTH_X;
unsigned char display_SCREEN_HEIGHT_Y;
unsigned char display_SCALE;
unsigned int  display_pixel_ON_color;
unsigned int  display_pixel_OFF_color;

// Display Array
unsigned int pixels[2048];

void display_init();
bool display_draw(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture, unsigned int frame, Scene *scene);
void SDL_close(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture);