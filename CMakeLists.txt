project(hello)

find_library(SDL2 sdl2)
add_executable(hello
  src/main.cpp
  src/loop.cpp
  src/draw.cpp
  src/core/Game.cpp
  )
target_link_libraries(hello SDL2)