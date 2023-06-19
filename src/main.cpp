#include "SDL2/SDL.h"
#include "Renderer.hpp"
#include "Block.hpp"
#include <iostream>
#include <chrono>
#include <thread>

const int FRAME_RATE = 240;
const int FRAME_DELAY = 1000 / FRAME_RATE;

int main(int argc, char **argv)
{
    Block block;

    SDL_Init(SDL_INIT_EVERYTHING); // Initialize SDL2;

    block.GetBlockPos(block);

    renderer.CreateRendererAndWindow("Block-Game", SCREEN_WIDTH, SCREEN_HEIGHT); // Create renderer and window

    bool _quit = false;
    SDL_Event Event;
    while (!_quit) // Main loop
    {
        std::chrono::time_point<std::chrono::high_resolution_clock> lastFrame = std::chrono::high_resolution_clock::now();

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
        std::chrono::duration<double> DeltaTime;
        double value =  DeltaTime.count();

        block.BounceOff(block);
        block.BlockLimit(block); // Apply block movement limits

        renderer.clear(); // Clear the renderer

        block.SpawnBlock(block);

        block.UpdateBlockPos(block, value); // Update the position of the block based on its velocity

        renderer.present(); // Present the renderer

        std::chrono::time_point<std::chrono::high_resolution_clock> CurentFrame = std::chrono::high_resolution_clock::now();

        DeltaTime = CurentFrame - lastFrame;

        std::chrono::duration<double , std::milli> frameTime = CurentFrame - lastFrame;

        if (frameTime < std::chrono::milliseconds(FRAME_DELAY)) //puts the thread to sleep to achieve desired frame rate
        {
            std::chrono::duration<double , std::milli> sleepTime (std::chrono::milliseconds(FRAME_DELAY) - frameTime);
            std::this_thread::sleep_for(sleepTime);
        }
        
    }

    renderer.DestroyWindowAndRenderer(); // Destroy the window and renderer

    return 0;
}
