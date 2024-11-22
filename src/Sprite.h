//
// Created by emmar on 11/20/2024.
//

#ifndef SPRITE_H
#define SPRITE_H

#include <SDL_image.h>
#include <string>

struct Transform {
//Location
    int x = 0;
    int y = 0;

//Scale
    int width = -1;
    int height = -1;

    //Rotation
    int degrees = 0;


};

class Sprite {
    SDL_Texture* texture= nullptr;;
public:
    SDL_Rect src;
    SDL_Rect dst;

    bool drag = false;
public:
    Sprite();
    explicit Sprite(const std::string &path);
    Sprite(const Transform &src, const Transform &dst, const std::string &path);
    ~Sprite();

    void render() const;
    void move(int x, int y);

private:
    void load_and_create(const std::string &path);

    static bool isRectangleEmpty(const SDL_Rect &rect);
};

#endif //SPRITE_H
