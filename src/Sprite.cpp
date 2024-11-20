//
// Created by emmar on 11/20/2024.
//

#include "Sprite.h"
#include "System.h"

Sprite::Sprite(): rectangle(), texture(nullptr) {
}

Sprite::Sprite(const int x, const int y, const int w, const int h, const std::string &path = ""){
    if(!std::empty(path)) {
        surface = SDL_LoadBMP(path.c_str());
        texture = SDL_CreateTextureFromSurface(sys.renderer, surface);
        rectangle = {x,y, w, h};
        SDL_FreeSurface(surface);
    }
}

Sprite::~Sprite() {
    SDL_DestroyTexture(texture);
}

void Sprite::render() const {
    SDL_RenderCopy(sys.renderer, texture, nullptr, &rectangle);
}

