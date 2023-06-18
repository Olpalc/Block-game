#pragma once

#include "SDL2/SDL.h"
#include "Renderer.hpp"

const int BLOCK_SIZE = 35;
const int BLOCK_SPEED = 8000;

struct Block
{
    int x;
    int y;
    int velocityX;
    int velocityY;

    void UpdateBlockPos(Block &Block , double DeltaTime); // Updates the position of the block based on its velocity
    void GetBlockPos(Block &Block);    // Sets the initial position of the block
    void BlockLimit(Block &Block);     // Limits the block within the window boundaries
    void BounceOff(Block &Block);   //Bounces the Block off the screen border
    void SpawnBlock(Block &Block);  //Spawns the Block
};
