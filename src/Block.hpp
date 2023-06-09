#pragma once

#include "SDL2/SDL.h"
#include "Renderer.hpp"

const int BLOCK_SIZE = 35;
const int BLOCK_SPEED = 16000;

struct Block
{
    int x;
    int y;
    int velocityX;
    int velocityY;

    void UpdateBlockPos( double DeltaTime); // Updates the position of the block based on its velocity
    void GetBlockPos();    // Sets the initial position of the block
    void BlockLimit();     // Limits the block within the window boundaries
    void BounceOff();   //Bounces the Block off the screen border
    void SpawnBlock( Uint8 R , Uint8 G , Uint8 B);  //Spawns the Block
};

extern Block block;