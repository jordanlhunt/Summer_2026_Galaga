cmake_minimum_required(VERSION 3.16)
project(
    "MOBY - OUTLAW PIRATE STARFIGHTER"
    VERSION 1.0.0
    DESCRIPTION "A Galaga recreation using SDL3"
    LANGUAGES C
)

find_package(SDL3 REQUIRED)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(SOURCES 
src/main.c
src/engine/window.c
src/engine/timer.c)

add_executable(starfighterGame ${SOURCES})
target_link_libraries(starfighterGame PRIVATE SDL3::SDL3)