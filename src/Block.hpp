#pragma once

#include "SDL2/SDL.h"
#include "Engine.hpp"

const int BLOCK_SIZE = 35;
const int BLOCK_SPEED = 7.5;

struct Block
{
    int x; 
    int y; 
    int velocityX; 
    int velocityY; 

    void UpdateBlockPos(Block &Block); // Updates the position of the block based on its velocity
    void GetBlockPos(Block &Block); // Sets the initial position of the block
    void BlockLimit(Block &Block); // Limits the block within the window boundaries
    void BounceOff(Block &Block);
};

void Block::UpdateBlockPos(Block &Block)
{
    Block.y += Block.velocityY; // Update the y-coordinate based on the y-velocity

    Block.x += Block.velocityX; // Update the x-coordinate based on the x-velocity
}

void Block::GetBlockPos(Block &Block)
{
    // Set the initial position of the block at the center of the screen
    Block.y = (SCREEN_HEIGHT - BLOCK_SIZE) / 2;
    Block.x = (SCREEN_WIDTH - BLOCK_SIZE) / 2;
}

void Block::BlockLimit(Block &Block)
{
    // Limit the block's movement within the window boundaries

    // Check if the block reaches the top or bottom boundaries
    if (Block.y <= 0)
    {
        Block.y = 0;
    }
    else if (Block.y + BLOCK_SIZE >= SCREEN_HEIGHT)
    {
        Block.y = SCREEN_HEIGHT - BLOCK_SIZE;
    }

    // Check if the block reaches the left or right boundaries
    if (Block.x <= 0)
    {
        Block.x = 0;
    }
    else if (Block.x + BLOCK_SIZE >= SCREEN_WIDTH)
    {
        Block.x = SCREEN_WIDTH - BLOCK_SIZE;
    }
}

void Block::BounceOff(Block & Block)
{
    if (Block.x <= 0 || Block.x >= SCREEN_WIDTH - BLOCK_SIZE)
    {
        Block.velocityX = - Block.velocityX;
    }

    if (Block.y <= 0 || Block.y >= SCREEN_HEIGHT - BLOCK_SIZE)
    {
        Block.velocityY = -Block.velocityY;
    }
    
}
