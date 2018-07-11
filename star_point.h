#ifndef STAR_POINT_H
#define STAR_POINT_H

#include <SDL2/SDL.h>

class StarPoint
{
public:
    StarPoint();
    void render(SDL_Renderer *renderer);
    bool move();
private:
    float x;
    float y;
    float speed;
    int life;

    Uint8 r;
    Uint8 g;
    Uint8 b;
};

#endif // STAR_POINT_H
