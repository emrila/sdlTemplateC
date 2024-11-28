//
// Created by emmar on 11/20/2024.
//

#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <SDL2/SDL_rect.h>

class Sprite {
     class SDL_Texture* texture= nullptr;;
public:
    SDL_Rect src;
    SDL_Rect dst;

    bool drag = false;

    Sprite();
    explicit Sprite(const std::string &path);
    Sprite(const SDL_Rect &src, const SDL_Rect &dst, const std::string &path);
    ~Sprite();

    void render() const;
    void move(int x, int y);

private:
    void load_and_create(const std::string &path);

    static bool isRectangleEmpty(const SDL_Rect &rect);
};

#endif //SPRITE_H
