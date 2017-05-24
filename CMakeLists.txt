project(chopter)

find_library(SDL2 sdl2)
add_executable(chopter
  src/main.cpp
  src/loop.cpp
  src/draw.cpp
  src/Event.cpp
  src/core/Game.cpp
  )
target_link_libraries(chopter SDL2)
