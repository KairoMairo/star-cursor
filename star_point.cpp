#include "star_point.h"
#include <math.h>
#include <SDL2/SDL.h>

StarPoint::StarPoint()
{
    int mouse_x = 0;
    int mouse_y = 0;
    SDL_GetMouseState(&mouse_x, &mouse_y);
    life = 10 + rand() % 30;
    speed = 0.01 + (rand() % 200) / 1000.0;
    int radius = 5 + rand() % 5;
    x = mouse_x - radius + rand() % (2 * radius + 2);
    y = sqrtf(pow(radius, 2) - pow(x - mouse_x, 2));
    if (rand() % 2 == 0)
    {
        y = mouse_y + y;
    }
    else
    {
        y = mouse_y - y;
    }
    r = rand() % 50;
    g = 255;
    b = 255 - rand() % 150;
}

void StarPoint::render(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderDrawPoint(renderer, x, y);
}

bool StarPoint::move()
{
    if (life <= 0)
    {
        return false;
    }
    else
    {
       g -= g / life;
    }

    life--;
    y -= speed;

    return true;
}
