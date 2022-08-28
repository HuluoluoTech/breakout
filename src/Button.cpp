#include "Button.h"
#include <iostream>

glm::vec2 Button::GetPosition()
{
    return this->Position;
}

glm::vec2 Button::GetSize()
{
    return this->Size;
}

void Button::SetTitle(const std::string& title)
{
    this->Title = title;
}

std::string Button::GetTitle() const
{
    return this->Title;
}

void Button::Draw(SpriteRenderer &renderer)
{
    renderer.DrawSprite(this->Sprite, this->Position, this->Size);
    // Text->RenderText(Title, 250., this->Position.y, 1.0f);
}