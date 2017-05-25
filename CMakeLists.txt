project(chopter)

find_library(SDL2 sdl2)

add_executable(chopter
  src/control/Logic.cpp
  src/control/GameController.cpp
  src/control/Event.cpp
  src/control/draw.cpp
  src/control/loop.cpp
  src/core/Chopter.cpp
  src/core/Game.cpp
  src/core/Map.cpp
  src/core/utils.cpp
  src/main.cpp
  )

target_link_libraries(chopter SDL2)
