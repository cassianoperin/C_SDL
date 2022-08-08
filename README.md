# C SDL2


# Docs

### SDL2-Starter

https://github.com/codingwithjulio/sdl2-starter

### MACOS SDL2 / SDL2_Image instructions

Install SDL2 Framework:

Install SDL2_Image (dmg) from:
http://www.libsdl.org/projects/SDL_image/

All to /Library/Frameworks

Link the SDL_Image.h inside SDL2:
`cd /Library/Frameworks/SDL2.framework/Headers`
`ln -s /Library/Frameworks/SDL2_image.framework/Headers/SDL_image.h`


# To-do

1. Migrate main functions to another files
2. Test main loop speed
3. Add FPS
4. Counter 60 FPS / delay timers
5. Just draw when @60FPS