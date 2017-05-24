project(hello)

find_library(SDL2 sdl2)
add_executable(hello
  src/main.cpp
  src/core/Game.cpp
  src/core/Chopter.cpp
  src/core/Map.cpp
  )
target_link_libraries(hello SDL2)