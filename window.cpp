#include "window.h"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <string.h>
#include <sstream>
#include <iostream>


#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

Window::Window()
{
}

Window::~Window()
{

}

bool Window::init()
{
        // создаем окно
    window = SDL_CreateWindow( "Arkanoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if (window == nullptr)
    {
        printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
        return false;
    }
        // создаем renderer для окна
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    if( renderer == nullptr )
    {
        printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
        SDL_DestroyWindow( window );
        window = nullptr;
        return false;
    }
        // фон окна - черный
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        // инициализируем SDL_image
    int flags=IMG_INIT_PNG;
    int initted=IMG_Init(flags);
    if((initted&flags) != flags) {
        printf("IMG_Init: Failed to init required png support!\n");
        printf("IMG_Init: %s\n", IMG_GetError());
    }
        // инициализируем SDL_mixer
    /*if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }*/
     // инициализируем SDL_ttf
    if( TTF_Init() == -1 )
    {
        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
        return false;
    }
        // берем id окна
    window_id = SDL_GetWindowID( window );
        // скрываем курсор в окне
    SDL_ShowCursor(SDL_DISABLE);
        // загружаем медиафайлы
    /*media = new Media;
    if (!media->load_media(renderer, MAIN_MENU_CONTENT))
    {
        printf( "Media could not be loaded!\n");
        return false;
    }*/

    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);

    return window != NULL && renderer != NULL;
}

bool Window::execution()
{
    if (window == nullptr)
    {
        return false;
    }

    cursor.execution();
    return true;
}

void Window::handle_event(SDL_Event &e)
{
        // обрабатываем события
    if( e.type == SDL_WINDOWEVENT && e.window.windowID == window_id )
    {
        switch( e.window.event )
        {
            // скрыть по закрытия
        case SDL_WINDOWEVENT_CLOSE:
            SDL_HideWindow( window );
            break;
        }
    }

    if (e.type == SDL_KEYDOWN)
    {
        if( e.key.keysym.sym  == SDLK_ESCAPE)
        {
            free();
        }
    }


}

void Window::render()
{
        // отчистить изображение
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( renderer );
    cursor.render(renderer);
        // обновить изображение
    SDL_RenderPresent( renderer );
}

void Window::free()
{
        // уничтожить окно
    if( window != nullptr )
    {
        SDL_DestroyWindow( window );
        window = nullptr;
    }
        // закрыть библиотеки SDL
    TTF_Quit();
    IMG_Quit();

}
