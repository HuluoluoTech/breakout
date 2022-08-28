/************************
 * Welcome Front page
 ***********************/

#include "Display.h"
#include "Button.h"
#include <memory>
#include <iostream>
#include <GLFW/glfw3.h>
#include "game.h"

enum class State
{
    INIT,
    START,
    EXIT,
    ABOUT
};

class Welcome : public Display
{
public:
    // received signal SIGSEGV, Segmentation fault
    // ---> Rendered Need to be initialized... 
    Welcome(GLFWwindow *window, unsigned int width, unsigned int height) noexcept
    : Width(width), Height(height), Renderer(nullptr)
    {
        std::cout << "Welcome constructor..." << std::endl;
    }
    Welcome(unsigned int width, unsigned int height) noexcept
    : Width(width), Height(height), Renderer(nullptr)
    {
        std::cout << "Welcome constructor..." << std::endl;
    }
    ~Welcome() {}

    void Init() noexcept;

public:
    void Render();
    void Draw(SpriteRenderer &renderer) override;
    void Update(float dt);
    void ProcessInput(float dt);

public:
    Game* GetGame() { return this->m_game; }
    void SetWindow(GLFWwindow *window) { Window = window; }

private:
    void _onButtonAction();
    bool _onClickButton(std::unique_ptr<Button>& button);

private:
    GLFWwindow *Window;
    unsigned int Width;
    unsigned int Height;

    std::unique_ptr<Button> StartButton;
    std::unique_ptr<Button> ExitButton;
    std::unique_ptr<Button> AboutButton;

    SpriteRenderer *Renderer;
    double m_xpos{0.};
    double m_ypos{0.};

    State m_state{State::INIT};

private:
    //scenes
    Game *m_game{nullptr};
};