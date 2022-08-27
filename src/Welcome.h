/************************
 * Welcome Front page
 ***********************/

#include "Display.h"
#include "Button.h"
#include <memory>
#include <iostream>

class Welcome : public Display
{
public:
    // received signal SIGSEGV, Segmentation fault
    // ---> Rendered Need to be initialized... 
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

private:
    unsigned int Width;
    unsigned int Height;

    std::unique_ptr<Button> StartButton;
    std::unique_ptr<Button> ExitButton;
    std::unique_ptr<Button> AboutButton;

    SpriteRenderer *Renderer;
};