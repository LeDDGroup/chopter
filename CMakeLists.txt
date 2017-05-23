project(hello)

find_library(SDL2 sdl2)
add_executable(hello main.cpp)
target_link_libraries(hello SDL2)