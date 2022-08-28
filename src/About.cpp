#include "About.h"
#include <learnopengl/filesystem.h>

static std::string about = R"(This is breakout's about page.)";

About::About() noexcept
{
    Text = new TextRenderer(800, 600);
    Text->Load(FileSystem::getPath("resources/fonts/OCRAEXT.TTF").c_str(), 12);

    TextBack = new TextRenderer(800, 600);
    TextBack->Load(FileSystem::getPath("resources/fonts/OCRAEXT.TTF").c_str(), 12);
}

void About::Back()
{
}

void About::Draw(SpriteRenderer &renderer)
{
    // back button
    TextBack->RenderText("<", 0, 0.0, 10.0f, {{(1.0F)}, {(1.0F)}, {(.0F)}});

    // content
    Text->RenderText(about, 30, 100.0, 1.0f, {{(1.0F)}, {(1.0F)}, {(.0F)}});
}
