#pragma once

#include "SDL2/SDL.h"
#include "Engine.h"

const int BLOCK_SIZE = 30;

struct Block
{
    int x;
    int y;
    int velocityX;
    int velocityY;
};

Block block;

void UpdateBlockPos()
{
    block.y += block.velocityY;
    block.velocityY += GRAVITY;

    if (block.y + BLOCK_SIZE >= SCREEN_HEIGHT)
    {
        block.y = SCREEN_HEIGHT - BLOCK_SIZE;
        block.velocityY = 0;
    }
}