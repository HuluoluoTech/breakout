#include "Welcome.h"
#include <learnopengl/filesystem.h>
#include "resource_manager.h"

double _xpos = 0.;
double _ypos = 0.;

void Welcome::Init() noexcept
{
    std::cout << "Welcome Init" << std::endl;

    glfwSetCursorPosCallback(this->Window, [](GLFWwindow* window, double xposIn, double yposIn) {
        // std::cout << "x : " << xposIn << ", y: " << yposIn << std::endl;
    });

    glfwSetMouseButtonCallback(this->Window, [](GLFWwindow* window, int button, int action, int mods) {
        // click left mouse button
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
        {
            double xpos, ypos;
            //getting cursor position
            glfwGetCursorPos(window, &xpos, &ypos);
            std::cout << "Cursor Pressed Position at (" << xpos << " : " << ypos << ")" << std::endl;

            // Capture click position
            _xpos = xpos;
            _ypos = ypos;
        }
    });

    ResourceManager::LoadShader("../shaders/sprite.vs", "../shaders/sprite.fs", nullptr, "sprite");
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width), static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("sprite", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    ResourceManager::LoadTexture(FileSystem::getPath("resources/textures/background.jpg").c_str(),  false, "background");
    ResourceManager::LoadTexture(FileSystem::getPath("resources/textures/startbutton.png").c_str(), false, "startbutton");
    ResourceManager::LoadTexture(FileSystem::getPath("resources/textures/exitbutton.png").c_str(),  false, "exitbutton");
    ResourceManager::LoadTexture(FileSystem::getPath("resources/textures/aboutbutton.png").c_str(), false, "aboutbutton");

    Renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));
    
    const float padding = 30.0f;
    // start button
    glm::vec2 buttonSize        = glm::vec2(this->Width / 2.0f - 100 / 2.0f, 90.f);

    const float paddingToTop = (this->Height - buttonSize.y * 3 - padding * 2 ) / 2.f;

    glm::vec2 startButtonPos    = glm::vec2(this->Width / 2.0f - buttonSize.x / 2.0f, paddingToTop);
    Texture2D startButtonSprite = ResourceManager::GetTexture("startbutton");
    StartButton = std::make_unique<Button>(
        startButtonPos,
        buttonSize,
        startButtonSprite,
        [](glm::vec2 pos) {
            std::cout << "Start Action..." << std::endl;
        }
    );

    // exit button
    glm::vec2 exitButtonPos    = glm::vec2(this->Width / 2.0f - buttonSize.x / 2.0f, startButtonPos.y + buttonSize.y + padding);
    Texture2D exitButtonSprite = ResourceManager::GetTexture("exitbutton");
    ExitButton = std::make_unique<Button>(
        exitButtonPos,
        buttonSize,
        exitButtonSprite,
        [](glm::vec2 pos) {
            std::cout << "Exit Action..." << std::endl;
        }
    );

    // about button
    glm::vec2 aboutButtonPos    = glm::vec2(this->Width / 2.0f - buttonSize.x / 2.0f, exitButtonPos.y + buttonSize.y + padding);
    Texture2D aboutButtonSprite = ResourceManager::GetTexture("aboutbutton");
    AboutButton = std::make_unique<Button>(
        aboutButtonPos,
        buttonSize,
        aboutButtonSprite,
        [](glm::vec2 pos) {
            std::cout << "About Action..." << std::endl;
        }
    );
}

void Welcome::Render()
{
    this->Draw(*Renderer);
}

void Welcome::Draw(SpriteRenderer &renderer)
{
    // Draw background
    Texture2D texture2d = ResourceManager::GetTexture("background");
    renderer.DrawSprite(texture2d, glm::vec2(0.0f, 0.0f), glm::vec2(this->Width, this->Height), 0.0f);

    // Draw Buttons
    this->StartButton->Draw(renderer);
    this->ExitButton->Draw(renderer);
    this->AboutButton->Draw(renderer);
}

void Welcome::Update()
{
    // iff click position changed, then update
    if(this->m_xpos != _xpos && this->m_ypos != _ypos) 
    {
        this->m_xpos = _xpos;
        this->m_ypos = _ypos;

        this->_onButtonAction();
    }
}

void Welcome::_onButtonAction()
{
    glm::vec2 param = glm::vec2{m_xpos, m_ypos};

    // if click start button
    if(this->_onClickButton(StartButton))
    {
        StartButton->Callback(param);

        return;
    }

    // or if click exit button
    if(this->_onClickButton(ExitButton))
    {
        ExitButton->Callback(param);

        return;
    }

    // or if click about button
    if(this->_onClickButton(AboutButton))
    {
        AboutButton->Callback(param);

        return;
    }
}

bool Welcome::_onClickButton(std::unique_ptr<Button>& button)
{
    std::cout << "Welcome::_onClickButton" << std::endl;

    // Get button's AABB
    glm::vec2 pos  = button->GetPosition();
    glm::vec2 size = button->GetSize();

    if (m_xpos >= pos.x && 
        m_ypos >= pos.y && 
        m_xpos <= pos.x + size.x &&
        m_ypos <= pos.y + size.y)
    {
        return true;
    }

    return false;
}