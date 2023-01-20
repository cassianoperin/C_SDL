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

bool display_draw(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture, unsigned int frame, Scene *scene);
void SDL_close(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* texture);