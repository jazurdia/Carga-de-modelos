cmake_minimum_required(VERSION 3.26)
project(Flat_Shading)

set(CMAKE_CXX_STANDARD 20)
set(SDL2_INCLUDE_DIR C:/CODING/GC/SDL2-2.28.1/include)
set(SDL2_LIB_DIR C:/CODING/GC/SDL2-2.28.1/lib/x64)


include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

find_package(glm CONFIG REQUIRED)


add_executable(Flat_Shading
        src/main.cpp
        src/gl.h
)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2 glm::glm)
