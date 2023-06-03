#include "SDL2/SDL.h"
#include "Engine.hpp"
#include "Block.hpp"

const int FRAME_RATE = 60;
const int FRAME_DELAY = 1000 / FRAME_RATE; 


int main(int argc, char **argv)
{
    Renderer renderer;
    Block block;

    SDL_Init(SDL_INIT_EVERYTHING); // Initialize SDL2;

    block.GetBlockPos(block); 

    renderer.CreateRendererAndWindow("Block-Game", SCREEN_WIDTH, SCREEN_HEIGHT);//create renderer and window

    Uint32 Start;
    int frameTime;

    bool _quit = false;
    SDL_Event Event;
    while (!_quit) // main loop
    {
        Start = SDL_GetTicks();

        while (SDL_PollEvent(&Event)) // main loop
        {
            switch (Event.type)
            {
            case SDL_QUIT:
                _quit = true;
                break;
            case SDL_KEYDOWN:
                switch (Event.key.keysym.sym)
                {
                case SDLK_RIGHT:
                    block.velocityX = 20;
                    break;
                case SDLK_LEFT:
                    block.velocityX =-20;
                break;
                case SDLK_UP:
                    block.velocityY = -20;
                    break;
                case SDLK_DOWN:
                    block.velocityY = 20;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }

        block.BlockLimit(block);

        renderer.clear();

        SDL_SetRenderDrawColor(renderer.Renderer, 0, 255, 255, 255);
        SDL_Rect BlockRect = {block.x, block.y, BLOCK_SIZE, BLOCK_SIZE};//render the block
        SDL_RenderFillRect(renderer.Renderer, &BlockRect);

        block.UpdateBlockPos(block);

        renderer.present();

        frameTime = SDL_GetTicks() - Start;
        if (frameTime < FRAME_DELAY)
        {
            SDL_Delay(FRAME_DELAY - frameTime);
        }
    }

    renderer.DestroyWindowAndRenderer();//destroy and quit 

    return 0;
}