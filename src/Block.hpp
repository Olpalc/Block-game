#pragma once

#include <iostream>
#include "SDL2/SDL.h"
#include "Engine.hpp"

const int BLOCK_SIZE = 30;
const int BLOCK_SPEED = 5;

struct Block
{
    int x ;
    int y ;
    int velocityX;
    int velocityY ;
    void UpdateBlockPos(Block &Block);
    void GetBlockPos(Block &Block);
    void BlockLimit(Block &Block);
};

void Block::UpdateBlockPos(Block &Block)
{
    Block.y += Block.velocityY;
    Block.velocityY += GRAVITY; //ads to the velocity the value of GRAVITY

    Block.x += Block.velocityX;

}

void Block::GetBlockPos(Block &Block) // the initial position of the block
{
    Block.y = (SCREEN_HEIGHT - BLOCK_SIZE) / 2;
    Block.x = (SCREEN_WIDTH - BLOCK_SIZE) / 2;
}

void Block::BlockLimit(Block &Block) //limits the block so it doesnt jump over the window
{
    if (Block.y <= 0)
    {
        Block.y = 0;
    }
    else if (Block.y + BLOCK_SIZE >= SCREEN_HEIGHT)
    {
        Block.y = SCREEN_HEIGHT - BLOCK_SIZE;
    }

    if (Block.x <=0)
    {
        Block.x = 0;
    }
    else if (Block.x + BLOCK_SIZE >= SCREEN_WIDTH)
    {
        Block.x = SCREEN_WIDTH - BLOCK_SIZE;
    }
    
}