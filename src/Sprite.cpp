//
// Created by emmar on 11/20/2024.
//

#include "Sprite.h"
#include "System.h"

Sprite::Sprite(): rectangle() {
}

Sprite::Sprite(const int x, const int y, const int w, const int h, const std::string &path = ""): rectangle{x,y, w, h}{
    if(std::empty(path)) {
       return;
    }
    surface = SDL_LoadBMP(path.c_str());
    texture = SDL_CreateTextureFromSurface(sys.renderer, surface);
    SDL_FreeSurface(surface);
}

Sprite::~Sprite() {
    SDL_DestroyTexture(texture);
}

void Sprite::render() const {
    SDL_RenderClear(sys.renderer);
    SDL_RenderCopy(sys.renderer, texture, &rectangle, nullptr);
    SDL_RenderPresent(sys.renderer);
}

