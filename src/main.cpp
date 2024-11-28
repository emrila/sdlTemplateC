#include <iostream>

#include "Session.h"
#include <SDL2/SDL.h>
//Screen dimension constants
constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[]) {
    std::cout << "Hello, World!" << std::endl;
    Session session;
    session.run();

    return 0;
}
