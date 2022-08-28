#pragma once

#include "Display.h"
#include "text_renderer.h"
#include "Button.h"
#include <memory>

// class TextRenderer;
class About : public Display
{
public:
    About(unsigned int width, unsigned int height) noexcept;
    void Draw(SpriteRenderer &renderer) override;
    ~About(){ delete Text; }

public:
    void SetBack(bool isBack);
    bool GetBack() const;
    void ProcessInput(double xpos, double ypos);
    void Update(float dt);

private:
    TextRenderer   *Text{nullptr}; 
    TextRenderer   *TextBack{nullptr}; 
    std::unique_ptr<Button> BackButton;
    bool IsBack{false};

    unsigned int Width;
    unsigned int Height;
};