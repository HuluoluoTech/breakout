#include "Button.h"

glm::vec2 Button::GetPosition()
{
    return this->Position;
}

glm::vec2 Button::GetSize()
{
    return this->Size;
}

void Button::Draw(SpriteRenderer &renderer)
{
    renderer.DrawSprite(this->Sprite, this->Position, this->Size, this->Rotation, this->Color);
}