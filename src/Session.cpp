//
// Created by emmar on 11/20/2024.
//

#include "Session.h"

#include <iostream>
#include <SDL.h>

#include "Sprite.h"
#include "System.h"
#include "../include/Constants.h"

void Session::run() {
    bool quit = false;
    const Uint32 tickInterval = 1000 / FPS;

    SDL_Surface* surface = SDL_LoadBMP((constants::gResPath + "images/hello_world.bmp").c_str());
    if (!surface) {
        std::cout << "Failed to load BMP: " << SDL_GetError() << std::endl;
        return;
    }    SDL_Texture* imageTexture = SDL_CreateTextureFromSurface(sys.renderer, surface);
    SDL_FreeSurface( surface);
    const SDL_Rect src = {0, 0, 800, 800};
    const SDL_Rect dst = {0, 0, 100, 100};
    SDL_RenderCopy(sys.renderer, imageTexture, &src, &dst);
    SDL_RenderPresent(sys.renderer);

    while (!quit) {
        const Uint32 nextTick = SDL_GetTicks() + tickInterval;
        handleInput(quit);
        updateRender();

        if (const int delay = nextTick - SDL_GetTicks(); delay > 0) {
            SDL_Delay(delay);
        }
    }
    //Destroy window
    SDL_DestroyWindow(sys.window);
    SDL_DestroyRenderer(sys.renderer);

    SDL_Quit();
    //Quit SDL subsystems
    SDL_Quit();
}

void Session::handleInput(bool &quit) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quit = true;
            return;
        }
        if(event.type == SDL_MOUSEBUTTONUP) {
        //    Action::fillScreenWithRandomColor();
        }
    }
}

void Session::updateRender() {
    SDL_UpdateWindowSurface(sys.window );
   // SDL_RenderPresent(sys.renderer);
}
