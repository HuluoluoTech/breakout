#pragma once

#include <glm/glm.hpp>
#include <functional>
#include "Display.h"
#include "texture.h"
#include "text_renderer.h"
#include <learnopengl/filesystem.h>
#include <GLFW/glfw3.h>

// Define button types
enum class ButtonType
{
    Rectangle,
    Circle,
    RoundCorner,
};

using ButtonAction = std::function<void (GLFWwindow *window, glm::vec2 pos)>;

class Button : public Display
{
public:
    Button(){}
    Button(glm::vec2 position, glm::vec2 size, Texture2D sprite, ButtonAction action)
    : Position(position), Size(size), Sprite(sprite), Callback(action) {
        Text = new TextRenderer(800, 600);
        Text->Load(FileSystem::getPath("resources/fonts/OCRAEXT.TTF").c_str(), 24);
    }

public:
    void Draw(SpriteRenderer &renderer) override;

public:
    ButtonAction    Callback;
    glm::vec2       GetPosition();
    glm::vec2       GetSize();
    void            SetTitle(const std::string& title);
    std::string     GetTitle() const;
    void            UseTexture(); // texture or text
    void            UseText();

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
    TextRenderer   *Text{nullptr};
    std::string     Title;
    bool            IsUseText{true};
};