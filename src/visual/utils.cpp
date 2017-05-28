#include "utils.hpp"

static int position(int x, int w, int w2, int v, int v1, int v2, int v3) {
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


SDL2pp::Rect align(const SDL2pp::Rect & rect, const SDL2pp::Point &size,
                   HAlign halign, VAlign valign) {
  SDL2pp::Rect pos = SDL2pp::Rect(SDL2pp::Point(),
                  size);
  pos.x = position(rect.x, rect.w, size.x, halign, Left, Center, Right);
  pos.y = position(rect.y, rect.h, size.y, valign, Top, Middle, Bottom);
  return pos;
}
