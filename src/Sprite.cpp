//
// Created by emmar on 11/20/2024.
//

#include "Sprite.h"
#include "System.h"

Sprite::Sprite(): src{0,0,0,0}, dst{0,0,0,0} {}

Sprite::Sprite(const std::string &path): src{0,0,0,0}, dst{0,0,0,0} {
    load_and_create(path);
}

Sprite::Sprite(const Transform &src, const Transform &dst, const std::string &path) : src{src.x, src.y, src.width, src.height}, dst{dst.x, dst.y, dst.width, dst.height} {
 load_and_create(path);
}

Sprite::~Sprite() {
    SDL_DestroyTexture(texture);
}

void Sprite::render() const{
    if (texture == nullptr) {
        return;
    }

    SDL_RenderCopy(sys.renderer, texture, isRectangleEmpty(src) ? nullptr: &src, &dst);

}

void Sprite::move(const int x, const int y) {
    dst.x += x;
    dst.y += y;
}

void Sprite::load_and_create(const std::string &path) {
    SDL_Surface* surface = SDL_LoadBMP(path.c_str());
    texture = SDL_CreateTextureFromSurface(sys.renderer, surface);

    if (isRectangleEmpty(dst)) {
        dst.w = surface->w;
        dst.h = surface->h;
    }
    SDL_FreeSurface(surface);
}

bool Sprite::isRectangleEmpty(const SDL_Rect &rect) {

    return rect.w < 1 && rect.h < 1;
}
