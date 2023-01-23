# C SDL2

Basic implementation of SDL, SDL_TTF anc C for emulators

**Window with game running and messages over the screen** |
:-------------------------:|
<img width="430" alt="C_SDL_TTF" src="https://github.com/cassianoperin/C_SDL/blob/main/src/Images/C_SDL_TTF.png">  |

## Docs

### SDL2-Starter

https://github.com/codingwithjulio/sdl2-starter

### MACOS SDL2 / SDL2_Image instructions

- Install SDL2 Framework:

https://www.libsdl.org/

- Install SDL2_Image (dmg) from:

http://www.libsdl.org/projects/SDL_image/

- Install SDL_TTF:

https://www.libsdl.org/projects/SDL_ttf/release/


All to /Library/Frameworks

Link the SDL_Image.h inside SDL2:

`cd /Library/Frameworks/SDL2.framework/Headers`

`ln -s /Library/Frameworks/SDL2_image.framework/Headers/SDL_image.h`
