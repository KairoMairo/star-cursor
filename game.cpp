#include "game.h"

#include <SDL2/SDL.h>

#include <iostream>

Game::Game()
{

}

bool Game::execution()
{
        // запуск SDL и создание окна
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
            // флаг главного цикла
        bool quit = false;
            // обработчик событий
        SDL_Event e;
            // пока игра запущена
        while( !quit )
        {
                // обработка событий


            while( SDL_PollEvent( &e ) != 0 )
            {
                    // пользователь выходит из игры
                if( e.type == SDL_QUIT )
                {
                    quit = true;
                }
                    // обработка событий окна
                window.handle_event(e);
            }
                // выполняем действия внутри окна
            if (!window.execution())
            {
                quit = true;
            }
            else
            {
                    // выводим окно
                window.render();
            }
        }
    }
        // освобождаем ресурсы
    close();
    return 0;
}

bool Game::init()
{
        // инициализация SDL
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        return false;
    }
    else
    {
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }
            // инициализируем окно
        if( !window.init() )
        {
            printf( "Window 0 could not be created!\n" );
            close();
            return false;
        }
    }
    return true;
}

void Game::close()
{
        // уничтожаем окно
    window.free();
        // закрываем SDL
    SDL_Quit();
}
