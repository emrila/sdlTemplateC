cmake_minimum_required(VERSION 3.29)
project(sdlTemplateC_)

set(CMAKE_CXX_STANDARD 17)

# Path to SDL2 libraries and includes
set(SDL2_PATH "${CMAKE_SOURCE_DIR}/SDL2-2.30.9/x86_64-w64-mingw32")
set(SDL2_INCLUDE_DIR "${SDL2_PATH}/include")
set(SDL2_LIB_DIR "${SDL2_PATH}/lib")

#find_package(SDL2 REQUIRED)

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
# Include directories
include_directories(${SDL2_INCLUDE_DIR} include)

# Libraries to link against
set(SDL2_IMAGE_LIBRARY "${SDL2_LIB_DIR}/libSDL2_image.dll.a")
set(SDL2_TTF_LIBRARY "${SDL2_LIB_DIR}/libSDL2_ttf.dll.a")
set(SDL2_MIXER_LIBRARY "${SDL2_LIB_DIR}/libSDL2_mixer.dll.a")

# Link libraries directly using full paths
target_link_libraries(${PROJECT_NAME}
        ${SDL2_LIBRARY}
        ${SDL2MAIN_LIBRARY}
        ${SDL2_IMAGE_LIBRARY}
        ${SDL2_TTF_LIBRARY}
        ${SDL2_MIXER_LIBRARY}
)
