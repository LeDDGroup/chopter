project(chopter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include(FindSDL2PP.cmake)
include_directories(${SDL2PP_INCLUDE_DIRS})
link_libraries(${SDL2PP_LIBRARIES})

add_executable(chopter
  src/control/Controller.cpp
  src/control/Environment.cpp
  src/control/Event.cpp
  src/control/Logic.cpp
  src/control/controllers/GameController.cpp
  src/control/controllers/GameController_Draw.cpp
  src/control/controllers/MainController.cpp
  src/control/score.cpp
  src/core/Chopter.cpp
  src/core/Game.cpp
  src/core/Map.cpp
  src/core/utils.cpp
  src/visual/Button.cpp
  src/visual/Label.cpp
  src/visual/Text.cpp
  src/visual/TextButton.cpp
  src/visual/utils.cpp
  src/main.cpp
  )
