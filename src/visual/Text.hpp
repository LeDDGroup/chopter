#ifndef TEXT_HPP
#define TEXT_HPP

#include <SDL2pp/Texture.hh>

class Text: public SDL2pp::Texture {
protected:
  static const SDL_Color textColor;
  const char * text;
public:
  Text(const char * text = "Text");
  void draw(const SDL2pp::Rect &rect);
};

#endif
