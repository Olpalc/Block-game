#include "SDL2/SDL.h"
#include "Engine.hpp"
#include "Block.hpp"


const int FRAME_RATE = 60;
const int FRAME_DELAY = 1000 / FRAME_RATE;

double DeltaTime;

int main(int argc, char **argv)
{
    Block block;

    SDL_Init(SDL_INIT_EVERYTHING); // Initialize SDL2;

    block.GetBlockPos(block); 

    renderer.CreateRendererAndWindow("Block-Game", SCREEN_WIDTH, SCREEN_HEIGHT);// Create renderer and window

    double Start , End;
    int frameTime;

    bool _quit = false;
    SDL_Event Event;
    while (!_quit) // Main loop
    {
        Start = SDL_GetTicks();

        while (SDL_PollEvent(&Event)) // Event loop
        {   
            switch (Event.type)
            {
            case SDL_QUIT:
                _quit = true; // Set flag to exit the main loop
                break;
            case SDL_KEYDOWN:
                switch (Event.key.keysym.sym)
                {
                case SDLK_RIGHT:
                    block.velocityX = BLOCK_SPEED; // Set velocity to move right
                    break;
                case SDLK_LEFT:
                    block.velocityX = -BLOCK_SPEED; // Set velocity to move left
                    break;
                case SDLK_UP:
                    block.velocityY = -BLOCK_SPEED; // Set velocity to move up
                    break;
                case SDLK_DOWN:
                    block.velocityY = BLOCK_SPEED; // Set velocity to move down
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }


        block.BounceOff(block);
        block.BlockLimit(block); // Apply block movement limits

        renderer.clear(); // Clear the renderer

        block.SpawnBlock(block);

        block.UpdateBlockPos(block); // Update the position of the block based on its velocity

        renderer.present(); // Present the renderer

        frameTime = SDL_GetTicks() - Start;
        if (frameTime < FRAME_DELAY)
        {
            SDL_Delay(FRAME_DELAY - frameTime); // Delay to achieve the desired frame rate
        }

        End = SDL_GetTicks();
        CalculateDeltaTime(Start , End ,DeltaTime );
    }


    renderer.DestroyWindowAndRenderer(); // Destroy the window and renderer

    return 0;
}
