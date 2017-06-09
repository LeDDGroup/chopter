#include <SDL2pp/Texture.hh>
#include <SDL2pp/Rect.hh>

class Sprite {
  SDL2pp::Texture texture;
  SDL2pp::Rect drawRect;
  int amount;
  float x, y, w, h;
  float speed;
public:
  Sprite(const char * path, int amount = 1, float speed = 1);
  void draw(const SDL2pp::Rect &rect);
  void update();
  void setSpeed(float speed) { this->speed = speed; };
  float getSpeed() const { return this->speed; };
};
