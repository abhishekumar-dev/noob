cmake_minimum_required(VERSION 3.30)
project(noob C)

set(CMAKE_C_STANDARD 11)

include_directories("${CMAKE_SOURCE_DIR}/raylib/include")
link_directories("${CMAKE_SOURCE_DIR}/raylib/lib")

add_executable(noob main.c scene.c animation.c player.c utils.c)

target_link_libraries(noob raylib gdi32 winmm)