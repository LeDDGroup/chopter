#include <SDL2/SDL_ttf.h>
#include "Label.hpp"
#include "../control/color.hpp"
#include "../control/Logic.hpp"
#include "../control/Environment.hpp"
using namespace SDL2pp;

extern Environment environment;

Label::Label()
  : text("Default"),
    texture(environment.renderer,
            environment.font.RenderText_Solid(text, SDL_Color{255, 255, 255, 255})) {
}

Label::~Label() {
}

void Label::setText(const char * str) {
  text = str;
  texture = Texture(environment.renderer,
                    environment.font.RenderText_Solid(text, SDL_Color{255, 255, 255, 255}));
}

void Label::draw() {
  environment.renderer.Copy(texture, NullOpt, Rect(rect));
}
