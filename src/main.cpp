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

    renderer.CreateRendererAndWindow("Block-Game", SCREEN_WIDTH, SCREEN_HEIGHT);// Create renderer and window

    Uint32 Start;
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
                    block.velocityX = 20; // Set velocity to move right
                    break;
                case SDLK_LEFT:
                    block.velocityX = -20; // Set velocity to move left
                    break;
                case SDLK_UP:
                    block.velocityY = -20; // Set velocity to move up
                    break;
                case SDLK_DOWN:
                    block.velocityY = 20; // Set velocity to move down
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }

        block.BlockLimit(block); // Apply block movement limits

        renderer.clear(); // Clear the renderer

        SDL_SetRenderDrawColor(renderer.Renderer, 0, 255, 255, 255);
        SDL_Rect BlockRect = {block.x, block.y, BLOCK_SIZE, BLOCK_SIZE};// Render the block
        SDL_RenderFillRect(renderer.Renderer, &BlockRect);

        block.UpdateBlockPos(block); // Update the position of the block based on its velocity

        renderer.present(); // Present the renderer

        frameTime = SDL_GetTicks() - Start;
        if (frameTime < FRAME_DELAY)
        {
            SDL_Delay(FRAME_DELAY - frameTime); // Delay to achieve the desired frame rate
        }
    }

    renderer.DestroyWindowAndRenderer(); // Destroy the window and renderer

    return 0;
}
