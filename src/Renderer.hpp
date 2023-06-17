#pragma once

#include "SDL2/SDL.h"

const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;

class Renderer
{
public:
    SDL_Window *Window;
    SDL_Renderer *Renderer;

    CreateRendererAndWindow(const char *windowTitle, int windowWidth, int windowHeight);
    DestroyWindowAndRenderer();
    void clear(); // Clears the renderer
    void present(); // Presents the renderer
};

extern Renderer renderer;