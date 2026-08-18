#include "raylibCpp.hh"
#include <assert.h>
#include <raylib.h>

void rayCpp::DrawRectangle(Vec2<int> pos, Vec2<int> dim, Color color)
{
	assert(pos.getX() >= 0 && pos.getY() >= 0 && pos.getX() < GetScreenWidth() && pos.getY() < GetScreenHeight()); //If assertion triggers : x or pos.GetY() is out of bounds
    DrawRectangle(pos.getX(), pos.getY(), dim.getX(), dim.getY(), color);
}

void rayCpp::DrawRectangleLinesEx(Vec2<int> pos, Vec2<int> dim, int lineThick, Color color)
{
	assert(pos.getX() >= 0 && pos.getY() >= 0 && pos.getX() < GetScreenWidth() && pos.getY() < GetScreenHeight()); //If assertion triggers : x or pos.GetY() is out of bounds
    assert(lineThick > 0); //If assertion triggers: lineThick is =< 0
    DrawRectangleLinesEx({(float)pos.getX(), (float)pos.getY(), (float)dim.getX(), (float)dim.getY()}, (float)lineThick, color);
}