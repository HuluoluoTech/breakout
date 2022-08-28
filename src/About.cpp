#include "About.h"
#include <learnopengl/filesystem.h>

static std::string about = R"(This is breakout's about page.)";

About::About() noexcept
{
    Text = new TextRenderer(800, 600);
    Text->Load(FileSystem::getPath("resources/fonts/OCRAEXT.TTF").c_str(), 12);
}

void About::Draw(SpriteRenderer &renderer)
{
    Text->RenderText(about, 0, 10.0, 1.0f, {{(1.0F)}, {(1.0F)}, {(.0F)}});
}
