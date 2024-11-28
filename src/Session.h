//
// Created by emmar on 11/20/2024.
//

#ifndef SESSION_H
#define SESSION_H

class Session {
public:
    void run();
    void handleInput(bool& quit) const;
    void updateRender() const;

private:
    class Sprite* sprite = nullptr;
     const int FPS = 60;
};



#endif //SESSION_H
