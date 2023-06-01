#include "SDL2/SDL.h"
#include "SDL2/SDL_keycode.h"
#include "Block.h"
#include <iostream>

const int FRAME_RATE = 120;

int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Block Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    const int FRAME_DELAY = 1000/FRAME_RATE;

    Block block;
    block.x = SCREEN_WIDTH /2 - BLOCK_SIZE/2;
    block.y = SCREEN_HEIGHT/2 - BLOCK_SIZE;
    block.velocityY = 0;

    bool quit = false;
    SDL_Event event;

    Uint32 FrameStart, FrameTime;

    while (!quit)
    {
        FrameStart = SDL_GetTicks();

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {   
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_SPACE);
                {
                    block.velocityY = -20;
                }
                
            default:
                break;
            }
        }

        UpdateBlockPositoin(block);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer , 255 , 255 , 255 ,255);
        SDL_Rect Block_Rect = {block.x , block.y ,BLOCK_SIZE , BLOCK_SIZE};
        SDL_RenderFillRect(renderer , &Block_Rect);

        FrameTime = SDL_GetTicks() - FrameStart;

        if(FrameTime < FRAME_DELAY)
        {
            SDL_Delay(FRAME_DELAY -FrameTime);
        }

        SDL_RenderPresent(renderer);
    }


    //clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
