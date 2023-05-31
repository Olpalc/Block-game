#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int BLOCK_SIZE = 20;
const int GRAVITY = 1;

struct Block
{
    int x;
    int y;
    int velocityY;
};

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

int main()
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

    // Event loop
    bool quit = false;
    SDL_Event event;
    while (!quit)
    {
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
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
