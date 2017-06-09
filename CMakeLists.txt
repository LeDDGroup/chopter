project(chopter)
cmake_minimum_required(VERSION 2.8)

# The version number.
set(CHOPTER_VERSION_MAJOR 0)
set(CHOPTER_VERSION_MINOR 3)
set(CHOPTER_VERSION_MICRO 0)
set(CHOPTER_VERSION "${CHOPTER_VERSION_MAJOR}.${CHOPTER_VERSION_MINOR}.${CHOPTER_VERSION_MICRO}")

# Check for windows platform
if(WIN32)
  if(NOT WINDOWS)
    set(WINDOWS TRUE)
  endif()
endif()

configure_file(
  "${PROJECT_SOURCE_DIR}/Config.h.in"
  "${PROJECT_BINARY_DIR}/Config.h"
  )

include_directories("${PROJECT_BINARY_DIR}")

# Use standart c++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Do not display console on window
if(WINDOWS)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows")
  link_libraries(SDL2main)
endif()

# SDL2 and SDL2pp dependencies
include(FindSDL2PP.cmake)
include_directories(${SDL2PP_INCLUDE_DIRS})
link_libraries(SDL2pp SDL2 SDL2_ttf)

# Add build target
add_executable(chopter
  src/control/Config.cpp
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
  src/visual/Sprite.cpp
  src/visual/Text.cpp
  src/visual/TextButton.cpp
  src/visual/utils.cpp
  src/main.cpp
  )
