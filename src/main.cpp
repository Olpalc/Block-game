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
    Block BarrierBlock;

    BarrierBlock.x = 400;
    BarrierBlock.y = 100;

    SDL_Init(SDL_INIT_EVERYTHING); // Initialize SDL2;

    block.GetBlockPos();

    renderer.CreateRendererAndWindow("Block-Game", SCREEN_WIDTH, SCREEN_HEIGHT); // Create renderer and window

    bool _quit = false;
    while (!_quit) // Main loop
    {
        std::chrono::time_point<std::chrono::high_resolution_clock> lastFrame = std::chrono::high_resolution_clock::now();

        while (SDL_PollEvent(&renderer.Event)) // Event loop
        {
            switch (renderer.Event.type)
            {
            case SDL_QUIT:
                _quit = true; // Set flag to exit the main loop
                break;
            case SDL_KEYDOWN:
                renderer.HandleInput();
                break;
            default:
                break;
            }
        }
        std::chrono::duration<double> DeltaTime;
        double value = DeltaTime.count();

        block.BounceOff();
        block.BlockLimit(); // Apply block movement limits

        renderer.clear(); // Clear the renderer

        block.SpawnBlock( 93, 63, 211);
        BarrierBlock.SpawnBlock( 150, 150, 150);

        block.UpdateBlockPos(value); // Update the position of the block based on its velocity

        renderer.present(); // Present the renderer

        std::chrono::time_point<std::chrono::high_resolution_clock> CurentFrame = std::chrono::high_resolution_clock::now();

        DeltaTime = CurentFrame - lastFrame;

        std::chrono::duration<double, std::milli> frameTime = CurentFrame - lastFrame;

        if (frameTime < std::chrono::milliseconds(FRAME_DELAY)) // puts the thread to sleep to achieve desired frame rate
        {
            std::chrono::duration<double, std::milli> sleepTime(std::chrono::milliseconds(FRAME_DELAY) - frameTime);
            std::this_thread::sleep_for(sleepTime);
        }
    }

    renderer.DestroyWindowAndRenderer(); // Destroy the window and renderer

    return 0;
}
