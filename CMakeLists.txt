project(chopter)

find_library(SDL2 sdl2)

add_executable(chopter
  src/Event.cpp
  src/core/Chopter.cpp
  src/core/Game.cpp
  src/core/Map.cpp
  src/core/utils.cpp
  src/draw.cpp
  src/loop.cpp
  src/main.cpp
  )

target_link_libraries(chopter SDL2)
