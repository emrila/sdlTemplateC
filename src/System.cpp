//
// Created by emmar on 11/20/2024.
//

#include "System.h"

System sys;

int SCREEN_HEIGHT = 700;
int SCREEN_WIDTH = 500;

System::System() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
       return;
    }

    window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    screenSurface = SDL_GetWindowSurface(window);
}

System::~System() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}
