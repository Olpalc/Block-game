#pragma once

#include "SDL2/SDL.h"

const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;

const int GRAVITY = 1;

class Renderer
{
public:
    SDL_Window *Window;
    SDL_Renderer *Renderer;
    CreateRendererAndWindow(const char *windowTitle, int windowWidth, int windowHeight);
    DestroyWindowAndRenderer();
    void clear();
    void present();
};

Renderer::CreateRendererAndWindow(const char *windowTitle, int windowWidth, int windowHeight)
{
    // Create a window
    Window = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);

    // Create a renderer
    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);

    return 0;
}

Renderer::DestroyWindowAndRenderer()
{
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);

    return 0;
}

void Renderer::clear()
{
    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
    SDL_RenderClear(Renderer);
}

void Renderer::present()
{
    SDL_RenderPresent(Renderer);
}