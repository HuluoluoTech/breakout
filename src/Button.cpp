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
void Button::UseTexture()
{
    IsUseText = false;
}
void Button::UseText()
{
    IsUseText = true;
}

void Button::Draw(SpriteRenderer &renderer)
{
    if (IsUseText) {
        Text->RenderText(Title, 350, Position.y, 1.0f, {{(1.0F)}, {(1.0F)}, {(.0F)}});
    } else {
        renderer.DrawSprite(this->Sprite, this->Position, this->Size);
    }
}