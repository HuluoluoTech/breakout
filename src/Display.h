#pragma once

#include "sprite_renderer.h"

class Display
{
public:
    // Display(){}
    virtual void Draw(SpriteRenderer &renderer) = 0;
    virtual ~Display(){}
};