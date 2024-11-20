//
// Created by emmar on 11/20/2024.
//

#ifndef SPRITE_H
#define SPRITE_H

#include <SDL_image.h>
#include <string>


class Sprite {
    SDL_Rect rectangle;
    SDL_Surface* surface= nullptr;
    SDL_Texture* texture= nullptr;;

public:
    Sprite();
    Sprite(int x, int y, int w, int h, const std::string &path);

    ~Sprite();

    void render() const;
};



#endif //SPRITE_H
