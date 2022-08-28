/************************
 * Welcome Front page
 ***********************/

#include "Display.h"
#include "Button.h"
#include <memory>
#include <iostream>
#include <GLFW/glfw3.h>

class Welcome : public Display
{
public:
    // received signal SIGSEGV, Segmentation fault
    // ---> Rendered Need to be initialized... 
    Welcome(GLFWwindow *window, unsigned int width, unsigned int height) noexcept
    : Window(window), Width(width), Height(height), Renderer(nullptr)
    {
        std::cout << "Welcome constructor..." << std::endl;
    }
    ~Welcome() {}

    void Init() noexcept;

public:
    void Render();
    void Draw(SpriteRenderer &renderer) override;
    void Update();

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
};