#ifndef TEXT_HPP
#define TEXT_HPP

#include <SDL2pp/Texture.hh>
#include <string>

class Text: public SDL2pp::Texture {
protected:
  static const SDL_Color textColor;
  std::string text;
public:
  Text(const std::string &text = "Text");
  void draw(SDL2pp::Rect rect);
};

#endif
