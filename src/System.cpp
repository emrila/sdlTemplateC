//
// Created by emmar on 11/20/2024.
//

#include "System.h"

System sys;

System::System()  {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
       return;
    }

    window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 1000, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
 }

System::~System() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}
