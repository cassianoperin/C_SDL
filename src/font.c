#include "font.h"

bool font_init(){

    // ------------------ Font Path ------------------ //
    // font_path = "/Users/cassiano/Vscode/C_SDL2/src/Lazy.ttf";
    font_path = "/Users/cassiano/Vscode/FONT_OK/src/Zack and Sarah.ttf";

    // --------------- Font Point Size --------------- //
    ptsize = 16;

    // // ------------ Font Background Color ------------ //
    // forecol = &red;

    // // ------------ Font Foreground Color ------------ //
    // backcol = &white;

    // ---------------- Render Method ---------------- //
    // rendermethod = TextRenderSolid;
    // rendermethod = TextRenderShaded;
    rendermethod = TextRenderBlended;

    // ---------------- Render Style ----------------- //
    renderstyle = TTF_STYLE_NORMAL;
    // renderstyle |= TTF_STYLE_BOLD;
    // renderstyle |= TTF_STYLE_ITALIC;
    // renderstyle |= TTF_STYLE_UNDERLINE;
    // renderstyle |= TTF_STYLE_STRIKETHROUGH;

    // ----------------- Render Type ----------------- //
    // Used in Render Method
    // rendertype = RENDER_LATIN1;
    // rendertype = RENDER_UTF8;
    // rendertype = RENDER_UNICODE;

    // ------------------- Hinting ------------------- //
    // hinting = TTF_HINTING_NORMAL;
    // hinting = TTF_HINTING_LIGHT;
    // hinting = TTF_HINTING_MONO;
    hinting = TTF_HINTING_NONE;

    // ------------------- Kerning ------------------- //
    kerning = 1;
    // kerning = 0;

    // ------------------- Outline ------------------- //
    outline = 0;

    
    /* Initialize the TTF library */
    if (TTF_Init() < 0) {
        SDL_Log("Couldn't initialize TTF: %s\n",SDL_GetError());
        SDL_Quit();
		exit(2);
    }

    


    return(0);
}