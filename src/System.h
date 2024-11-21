//
// Created by emmar on 11/20/2024.
//

#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL.h>
#include <random>
//#include <SDL_mixer.h>

struct System {
    System();
    ~System();

    SDL_Window* window;
    SDL_Renderer* renderer;
 //   SDL_Surface* screenSurface;

    static Uint32  getRandomInt() {
        std::random_device rd;  // Seed for the random number engine
        std::mt19937 gen(rd()); // Mersenne Twister engine
        std::uniform_int_distribution<> dis(0, 255); // Distribution range

        return static_cast<Uint32>(dis(gen)); // Generate random number
    }

    //  Mix_Chunk* musik;
};

extern System sys;



#endif //SYSTEM_H
