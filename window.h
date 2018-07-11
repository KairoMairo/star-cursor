#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include "cursor.h"

class Window
{
public:
    Window();
    ~Window();

    bool init();
    bool execution();
        // обработчик событий
    void handle_event( SDL_Event& e );
        // вывести контент
    void render();
        // освободить все
    void free();

private:
        // данные окна
    Cursor cursor;
    SDL_Window* window;
    SDL_Renderer* renderer;
    unsigned int window_id;
};

#endif // WINDOW_H
