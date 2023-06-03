#include "SDL2/SDL.h"
#include "Engine.h"
#include "Block.h"

const int FRAME_RATE = 60;
const int FRAME_DELAY = 1000 / FRAME_RATE;

int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_EVERYTHING); // Initialize SDL2;

    block.y = (SCREEN_HEIGHT - BLOCK_SIZE) / 2;
    block.x = (SCREEN_WIDTH - BLOCK_SIZE) / 2;

    Renderer renderer;

    renderer.CreateRendererAndWindow("Block-Game", SCREEN_WIDTH, SCREEN_HEIGHT);

    Uint32 Start;
    int frameTime;

    bool _quit = false;
    SDL_Event Event;
    while (!_quit) // main loop
    {
        Start = SDL_GetTicks();

        while (SDL_PollEvent(&Event))
        {
            switch (Event.type)
            {
            case SDL_QUIT:
                _quit = true;
                break;
            case SDL_KEYDOWN:
                block.velocityY = -20;
                break;
            default:
                break;
            }
        }

        renderer.clear();

        SDL_SetRenderDrawColor(renderer.Renderer, 255, 255, 255, 255);
        SDL_Rect BlockRect = {block.x, block.y, BLOCK_SIZE, BLOCK_SIZE};
        SDL_RenderFillRect(renderer.Renderer, &BlockRect);

        UpdateBlockPos();

        renderer.present();

        frameTime = SDL_GetTicks() - Start;
        if (frameTime < FRAME_DELAY)
        {
            SDL_Delay(FRAME_DELAY - frameTime);
        }
    }

    renderer.DestroyWindowAndRenderer();

    return 0;
}