#include "Renderer.hpp" 

Renderer renderer;

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