#include "Label.hpp"
#include "../control/color.hpp"
#include "../control/Logic.hpp"
#include "../control/Environment.hpp"
using namespace SDL2pp;

extern Environment environment;

Label::Label(const char * str)
  : textComponent(str),
    valign(Top), halign(Left) {
}

void Label::setText(const char * str) {
  textComponent = Text(str);
}

int position(int x, int w, int w2, int v, int v1, int v2, int v3) {
  if (v == v1) {
    return x;
  }
  if (v == v2) {
    return x + (w - w2) / 2;
  }
  if (v == v3) {
    return x + (w - w2);
  }
  return -1;
}

SDL2pp::Rect Label::getDrawRect() {
  SDL2pp::Point diff = textComponent.GetSize() - SDL2pp::Point(rect.w, rect.h);
  const SDL2pp::Point size = textComponent.GetSize();
  Rect pos = Rect(SDL2pp::Point(),
                  size);
  pos.x = position(rect.x, rect.w, size.x, halign, Left, Center, Right);
  pos.y = position(rect.y, rect.h, size.y, valign, Top, Middle, Bottom);
  return pos;
}

void Label::draw() {
  textComponent.draw(getDrawRect());
}
