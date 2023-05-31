#include <SDL2/SDL.h>
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int BLOCK_SIZE = 20;
const int GRAVITY = 1;
const int FRAME_RATE = 60;
const int MAX_HEIGHT = SCREEN_HEIGHT - BLOCK_SIZE;
const int BLOCK_SPEED = 1;


struct Block
{
    int x;
    int y;
    int velocityY;
};

void UpdateBlockPosition(Block& block , int dx ,int dy)
{
    block.x = dx;
    block.y = dy;

    if (block.y < 0) {
        block.y = 0;
    }
    else if (block.y > SCREEN_HEIGHT - BLOCK_SIZE) {
        block.y = SCREEN_HEIGHT - BLOCK_SIZE;
    }
}

void updateBlock(Block &block)
{
    block.y += block.velocityY;
    block.velocityY += GRAVITY;

    if (block.y >= SCREEN_HEIGHT - BLOCK_SIZE)
    {
        block.y = SCREEN_HEIGHT - BLOCK_SIZE;
        block.velocityY = 0;
    }
}

int main(int argc, char **argv)
{
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create a window
    SDL_Window *window = SDL_CreateWindow("Block Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    // Create a renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Set the initial position of the block
    Block block;
    block.x = SCREEN_WIDTH / 2 - BLOCK_SIZE / 2;
    block.y = SCREEN_HEIGHT / 2 - BLOCK_SIZE / 2;
    block.velocityY = 0;

    const int FRAME_DELAY = 1000 / FRAME_RATE;

    Uint32 frameStart, frameTime;

    // Event loop
    bool quit = false;
    SDL_Event event;
    while (!quit)
    {
        frameStart = SDL_GetTicks(); // Get the current time at the start of the frame

        // Handle events
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_SPACE)
                {
                    block.velocityY = -10; // Jump by giving negative velocity
                }
            }
        }

        // Update block position
        updateBlock(block);

        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);        

        // Draw the block
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_Rect blockRect = {block.x, block.y, BLOCK_SIZE, BLOCK_SIZE};
        SDL_RenderFillRect(renderer, &blockRect);

        // Update the screen
        SDL_RenderPresent(renderer);
        
        frameTime = SDL_GetTicks() - frameStart;

        if (frameTime < FRAME_DELAY)
        {
            SDL_Delay(FRAME_DELAY - frameTime);
        }
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
