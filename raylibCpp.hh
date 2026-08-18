#pragma once
#include <raylib.h>
#include "vec2.hh"

namespace rayCpp 
{
    void DrawRectangle(Vec2<int> pos, Vec2<int> dim, Color color);
    void DrawRectangleLinesEx(Vec2<int> pos, Vec2<int> dim, int lineThick, Color color);
}