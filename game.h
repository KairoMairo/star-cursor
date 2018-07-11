#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <window.h>

class Game
{
public:
    Game();
        // выполнить игровые действия
    bool execution();

private:
    bool init();
    void close();

private:
    Window window;
};

#endif // GAME_WINDOW_H
