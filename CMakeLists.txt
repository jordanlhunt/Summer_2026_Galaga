cmake_minimum_required(VERSION 3.21)
project(MOBY_OUTLAW_PIRATE C)
find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(SDL3_ttf REQUIRED)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
add_executable(MOBY_OUTLAW_PIRATE ${SOURCES})
target_include_directories(MOBY_OUTLAW_PIRATE PRIVATE src)
target_link_directories(MOBY_OUTLAW_PIRATE 
SDL3::SDL3 
SDL3_image::SDL3_image 
SDL3_ttf::SDL3_ttf)