//
// Created by emmar on 11/20/2024.
//

#include "Session.h"
#include <SDL.h>

#include "Action.h"
#include "Sprite.h"
#include "System.h"
#include "../include/Constants.h"

void Session::run() {
    bool quit = false;
    const Uint32 tickInterval = 1000 / FPS;
    const Sprite sprite(0, 0, 640, 480, constants::gResPath+"images/hello_world.bmp");

    while (!quit) {
        const Uint32 nextTick = SDL_GetTicks() + tickInterval;
        handleInput(quit);
        updateRender();
      //  sprite.render();

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
            Action::fillScreenWithRandomColor();
        }
    }
}

void Session::updateRender() {
    SDL_UpdateWindowSurface(sys.window );
   // SDL_RenderPresent(sys.renderer);
}
