project(chopter)

add_executable(chopter
  src/control/Controller.cpp
  src/control/Event.cpp
  src/control/Logic.cpp
  src/control/controllers/GameController.cpp
  src/control/controllers/MainController.cpp
  src/core/Chopter.cpp
  src/core/Game.cpp
  src/core/Map.cpp
  src/core/Score.cpp
  src/core/utils.cpp
  src/visual/Button.cpp
  src/main.cpp
  )

target_link_libraries(chopter SDL2 SDL2_ttf)
