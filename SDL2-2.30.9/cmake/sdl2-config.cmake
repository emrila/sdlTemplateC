# SDL2 CMake configuration file:
# This file is meant to be placed in a cmake subfolder of SDL2-devel-2.x.y-mingw

if(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(sdl2_config_path "../i686-w64-mingw32/lib/cmake/SDL2/SDL2Config.cmake")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(sdl2_config_path "../x86_64-w64-mingw32/lib/cmake/SDL2/SDL2Config.cmake")
else()
    set(SDL2_FOUND FALSE)
    return()
endif()

if(NOT EXISTS "${sdl2_config_path}")
    message(WARNING "${sdl2_config_path} does not exist: MinGW development package is corrupted")
    set(SDL2_FOUND FALSE)
    return()
endif()

include("${sdl2_config_path}")
