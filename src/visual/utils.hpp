#ifndef VISUAL_UTILS_HPP
#define VISUAL_UTILS_HPP

#include <SDL2pp/Rect.hh>

enum VAlign { Top, Middle, Bottom };
enum HAlign { Left, Center, Right };

SDL2pp::Rect align(const SDL2pp::Rect & rect, const SDL2pp::Point &size,
                   HAlign halign = Center, VAlign valign = Middle);

#endif
