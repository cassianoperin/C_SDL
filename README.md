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