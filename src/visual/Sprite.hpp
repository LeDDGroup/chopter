#include <SDL2pp/Texture.hh>
#include <SDL2pp/Rect.hh>

class Sprite {
  SDL2pp::Texture texture;
public:
  Sprite(const char * path);
  void draw(const SDL2pp::Rect &rect);
};
