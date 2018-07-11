#include "cursor.h"

Cursor::Cursor()
    :star_second(12)
{
}

void Cursor::execution()
{
        // генерируем новые частицы
    for (int i = 0; i < star_second; i++)
    {
       stars.push_back(new StarPoint());
    }
        // двигаем частицы
    for (auto star = stars.begin(); star != stars.end(); star++)
    {
        if (!(*star)->move())
        {
            delete (*star);
            star = stars.erase(star);
        }
    }
}

void Cursor::render(SDL_Renderer *renderer)
{
    for (auto star = stars.begin(); star != stars.end(); star++)
    {
        (*star)->render(renderer);
    }
}
