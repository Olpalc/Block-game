#pragma once

#include "render.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int GRAVITY = 1;

const int BLOCK_SIZE = 30;

struct Block
{
    int x;
    int y;
    int velocityX;
    int velocityY;
};

void RectPos(Block &Block)
{
    Block.x = SCREEN_WIDTH / 2 - BLOCK_SIZE / 2;
    Block.y = SCREEN_HEIGHT / 2 - BLOCK_SIZE / 2;
}

void UpdateBlockPos(Block &Block)
{
    Block.y += Block.velocityY;
    Block.velocityY += GRAVITY;

    if (Block.y >= SCREEN_HEIGHT - BLOCK_SIZE)
    {
        Block.y = SCREEN_HEIGHT - BLOCK_SIZE;
        Block.velocityY = 0;
    }
    
}
