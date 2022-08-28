#pragma once

#include "Display.h"
#include "text_renderer.h"

// class TextRenderer;
class About : public Display
{
public:
    About() noexcept;
    void Draw(SpriteRenderer &renderer) override;
    ~About(){ delete Text; }

public:
    void Back();

private:
    TextRenderer   *Text{nullptr}; 
    TextRenderer   *TextBack{nullptr}; 
};