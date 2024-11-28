//
// Created by emmar on 11/20/2024.
//

#include "Session.h"
#include <SDL2/SDL.h>
#include "Sprite.h"
#include "System.h"
#include "../include/Constants.h"

void Session::run() {
    bool quit = false;
    const Uint32 tickInterval = 1000 / FPS;

    sprite = new Sprite(constants::gResPath + "images/hello_world.bmp");
    sprite->render();
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
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            SDL_Point point = {event.button.x, event.button.y};
            if (SDL_PointInRect(&point, &sprite->dst)) {
                sprite->drag = true;
            }
        }
        if (event.type == SDL_MOUSEMOTION) {
            if (sprite->drag) {
                sprite->move(event.motion.xrel, event.motion.yrel);
            }
        }
        if (event.type == SDL_MOUSEBUTTONUP) {
            sprite->drag = false;
        //    Action::fillScreenWithRandomColor();
        }
    }
}

void Session::updateRender() {
    SDL_RenderClear(sys.renderer);
    sprite->render();
    SDL_UpdateWindowSurface(sys.window );
    SDL_RenderPresent(sys.renderer);

   // SDL_RenderPresent(sys.renderer);
}
