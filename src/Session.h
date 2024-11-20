//
// Created by emmar on 11/20/2024.
//

#ifndef SESSION_H
#define SESSION_H



class Session {
public:
    void run();
    void handleInput(bool& quit);
    void updateRender();

private:
    const int FPS = 60;
};



#endif //SESSION_H
