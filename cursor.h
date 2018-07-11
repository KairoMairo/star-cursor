#ifndef CURSOR_H
#define CURSOR_H

#include <list>
#include "star_point.h"

using namespace std;

class Cursor
{
public:
    Cursor();
    void execution();
    void render(SDL_Renderer* renderer);

private:
    list<StarPoint*> stars;

    int star_second;
};

#endif // CURSOR_H
