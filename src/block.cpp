#include "Block.hpp"

Block block;

void Block::UpdateBlockPos(  double DeltaTime )
{
    this->y += this->velocityY * DeltaTime; // Update the y-coordinate based on the y-velocity

    this->x += this->velocityX*DeltaTime; // Update the x-coordinate based on the x-velocity
}

void Block::GetBlockPos()
{
    // Set the initial position of the block at the center of the screen
    this->y = (SCREEN_HEIGHT - BLOCK_SIZE) / 2;
    this->x = (SCREEN_WIDTH - BLOCK_SIZE) / 2;
}

void Block::BlockLimit()
{
    // Limit the block's movement within the window boundaries

    // Check if the block reaches the top or bottom boundaries
    if (this->y <= 0)
    {
        this->y = 0;
    }
    else if (this->y + BLOCK_SIZE >= SCREEN_HEIGHT)
    {
        this->y = SCREEN_HEIGHT - BLOCK_SIZE;
    }

    // Check if the block reaches the left or right boundaries
    if (this->x <= 0)
    {
        this->x = 0;
    }
    else if (this->x + BLOCK_SIZE >= SCREEN_WIDTH)
    {
        this->x = SCREEN_WIDTH - BLOCK_SIZE;
    }
}

void Block::BounceOff()
{
    if (this->x <= 0 || this->x >= SCREEN_WIDTH - BLOCK_SIZE)
    {
        this->velocityX = -this->velocityX;
    }

    if (this->y <= 0 || this->y >= SCREEN_HEIGHT - BLOCK_SIZE)
    {
        this->velocityY = -this->velocityY;
    }
}

void Block::SpawnBlock( Uint8 R , Uint8 G , Uint8 B)
{
    SDL_SetRenderDrawColor(renderer.Renderer, R, G, B, 255);
    SDL_Rect BlockRect = {this->x, this->y, BLOCK_SIZE, BLOCK_SIZE}; // Render the block
    SDL_RenderFillRect(renderer.Renderer, &BlockRect);
}