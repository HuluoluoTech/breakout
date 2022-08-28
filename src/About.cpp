#include "About.h"
#include <learnopengl/filesystem.h>
#include "resource_manager.h"

static std::string about = R"(This is breakout's about page.)";

About::About() noexcept
{
    Text = new TextRenderer(800, 600);
    Text->Load(FileSystem::getPath("resources/fonts/OCRAEXT.TTF").c_str(), 12);

    TextBack = new TextRenderer(800, 600);
    TextBack->Load(FileSystem::getPath("resources/fonts/OCRAEXT.TTF").c_str(), 12);

    glm::vec2 buttonSize       = glm::vec2(30.f, 30.f);
    glm::vec2 backButtonPos    = glm::vec2(0.f, 0.f);
    Texture2D aboutButtonSprite = ResourceManager::GetTexture("aboutbutton");
    BackButton = std::make_unique<Button>(
        backButtonPos,
        buttonSize,
        aboutButtonSprite,
        [](GLFWwindow *window, glm::vec2 pos) {
            std::cout << "Back Action..." << std::endl;
        }
    );
    BackButton->SetTitle("Back");
    BackButton->UseText();
}

void About::SetBack(bool isBack)
{
    IsBack = isBack;
}

bool About::GetBack() const
{
    return IsBack;
}

void About::ProcessInput(double xpos, double ypos)
{
    // Get button's AABB
    glm::vec2 pos  = BackButton->GetPosition();
    glm::vec2 size = BackButton->GetSize();

    std::cout << "xpos|ypos = " << xpos << "|" << ypos << std::endl;
    std::cout << "pos x|y = " << pos.x << "|" << pos.y << std::endl;
    std::cout << "pos w|h = " << pos.x + size.x << "|" << pos.y + size.y << std::endl;
    if (xpos >= pos.x && 
        ypos >= pos.y && 
        xpos <= pos.x + size.x &&
        ypos <= pos.y + size.y)
    {
        IsBack = true;
        return;
    }

    IsBack = false;
}

void About::Update(float dt)
{

}

void About::Draw(SpriteRenderer &renderer)
{
    // back button
    // TextBack->RenderText("<", 0, 0.0, 10.0f, {{(1.0F)}, {(1.0F)}, {(.0F)}});
    BackButton->Draw(renderer);

    // content
    Text->RenderText(about, 30, 100.0, 1.0f, {{(1.0F)}, {(1.0F)}, {(.0F)}});
}
