#include <iostream>
#include "SDL2/SDL.h"

int main(int argc, char **argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout<<"Failed loading SDL2", SDL_GetError();
        return 1;
    }
    
    SDL_Window *window;

    window = SDL_CreateWindow("SLD test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);

    if (!window)
    {
        std::cout<<"Failed to initialize window!\n" ;
        return 1;
    }
    
    bool running = true;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                running = false;
                break;
            
            default:
                break;
            }
        }
        
    }
    
    std::cout<<"The app is running!\n";
    return 0;
}