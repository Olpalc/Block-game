#pragma once

#include "SDL2/SDL.h"

const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;

const int GRAVITY = 1;

double DeltaTime;
class Renderer
{
public:
    SDL_Window *Window;
    SDL_Renderer *Renderer;

    CreateRendererAndWindow(const char *windowTitle, int windowWidth, int windowHeight);
    DestroyWindowAndRenderer();
    void clear(); // Clears the renderer
    void present(); // Presents the renderer
    void CalculateDeltaTime(double Start , double End );
};

Renderer::CreateRendererAndWindow(const char *windowTitle, int windowWidth, int windowHeight)
{
    // Create a window
    Window = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_BORDERLESS);

    // Create a renderer
    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);

    return 0;
}

Renderer::DestroyWindowAndRenderer() 
{
    // Destroy the renderer and window
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);

    return 0;
}

void Renderer::clear()
{
    // Set the renderer's draw color to black
    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);

    // Clear the renderer
    SDL_RenderClear(Renderer);
}

void Renderer::present()
{
    // Present the renderer to display the rendered content
    SDL_RenderPresent(Renderer);
}

void Renderer::CalculateDeltaTime(double Start ,double End)
{
    DeltaTime = End - Start ;
}

Renderer renderer;