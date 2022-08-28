#include "About.h"
#include <learnopengl/filesystem.h>
#include "resource_manager.h"

static std::string about = R"(This is breakout's about page.)";

About::About(unsigned int width, unsigned int height) noexcept
{
    this->Width = width;
    this->Height = height;

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
    
    ResourceManager::LoadTexture(FileSystem::getPath("resources/textures/background.jpg").c_str(),  false, "background");
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
    Texture2D texture2d = ResourceManager::GetTexture("background");
    renderer.DrawSprite(texture2d, glm::vec2(0.0f, 0.0f), glm::vec2(this->Width, this->Height), 0.0f);

    // back button
    // TextBack->RenderText("<", 0, 0.0, 10.0f, {{(1.0F)}, {(1.0F)}, {(.0F)}});
    BackButton->Draw(renderer);

    // content
    Text->RenderText(about, 30, 100.0, 1.0f, {{(1.0F)}, {(1.0F)}, {(.0F)}});
}
