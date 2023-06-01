#pragma once 
#include <SDL2/SDL.h>

const int BLOCK_SIZE = 20;
const int BLOCK_SPEED = 5;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int GRAVITY = 1;

struct Block
{
    int x ;
    int y;
    int velocityX;
    int velocityY;

};

void UpdateBlockPositoin(Block &Block)
{
    Block.y += Block.velocityY;
    Block.velocityY += GRAVITY;

    if (Block.y >= SCREEN_HEIGHT - BLOCK_SIZE) {
        Block.y = SCREEN_HEIGHT - BLOCK_SIZE;
        Block.velocityY = 0;
    }

    
}