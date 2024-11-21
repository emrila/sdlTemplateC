cmake_minimum_required(VERSION 3.29)
project(sdlTemplateC_)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)

set(SDL2_PATH "SDL2-2.30.9/x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)

add_executable(sdlTemplateC_ src/main.cpp
        src/System.cpp
        src/System.h
        src/Session.cpp
        src/Session.h
        src/Action.h
        src/Sprite.cpp
        src/Sprite.h
        include/Constants.h
)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})

