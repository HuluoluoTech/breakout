#pragma once

#include <glm/glm.hpp>
#include <functional>
#include "Display.h"
#include "texture.h"

// Define button types
enum class ButtonType
{
    Rectangle,
    Circle,
    RoundCorner,
};

using ButtonAction = std::function<void (glm::vec2 pos)>;

class Button : public Display
{
public:
    Button(){}
    Button(glm::vec2 position, glm::vec2 size, Texture2D sprite, ButtonAction action)
    : Position(position), Size(size), Sprite(sprite), Callback(action) {}

public:
    void Draw(SpriteRenderer &renderer) override;

public:
    ButtonAction    Callback;
    glm::vec2       GetPosition();
    glm::vec2       GetSize();

private:
    glm::vec2 Position;
    glm::vec2 Size;

    /***********************
     *  ________________
     * |                |
     * |                |
     * ********************/
    ButtonType      Type{ButtonType::Rectangle}; 
    Texture2D       Sprite;
    glm::vec3       Color;
    float           Rotation;
};