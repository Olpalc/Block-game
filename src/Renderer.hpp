#pragma once

#include "SDL2/SDL.h"
#include "Block.hpp"

const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;

class Renderer
{
public:
    SDL_Window *Window;
    SDL_Renderer *Renderer;
    SDL_Event Event;

    CreateRendererAndWindow(const char *windowTitle, int windowWidth, int windowHeight);
    DestroyWindowAndRenderer();
    void clear(); // Clears the renderer
    void present(); // Presents the renderer
    void HandleInput();
};

extern Renderer renderer;