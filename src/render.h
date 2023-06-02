#pragma once

#include "SDL2/SDL.h"
#include "cube.h"
#include <iostream>

const int FRAME_RATE = 60;

Block block;

int WindowAndRenderer()
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Block-Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    const int FRAME_DELAY = 1000 / FRAME_RATE;

    Block block;
    RectPos(block);

    bool _quit = false;

    Uint32 FrameStart, FrameTime;

    while (!_quit)
    {
        FrameStart = SDL_GetTicks();
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                _quit = true;
                break;
            case SDL_KEYDOWN:
                block.velocityY = -20;

            default:
                break;
            }
        }
        UpdateBlockPos(block);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
        SDL_Rect BlockRect = {block.x, block.y, BLOCK_SIZE, BLOCK_SIZE};
        SDL_RenderFillRect(renderer, &BlockRect);

        if (block.y <= 0)
        {
            block.y = 0;
        }
        else if (block.y + BLOCK_SIZE >= SCREEN_HEIGHT)
        {
            block.y = SCREEN_HEIGHT - BLOCK_SIZE;
        }

        FrameTime = SDL_GetTicks() - FrameStart;

        if (FrameTime < FRAME_DELAY)
        {
            SDL_Delay(FRAME_DELAY - FrameTime);
        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
