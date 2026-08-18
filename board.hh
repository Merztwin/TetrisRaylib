#pragma once
#include "raylibCpp.hh"
#include <vector>
#include "vec2.hh"

class Board
{
    public:
        Board(Vec2<int> screenSizeinput, int cellSizeInput, Vec2<int> screenPosinput, int padding);
        ~Board();

        void setCell(Vec2<int> cellPos, Color c);
        void drawCell(Vec2<int> cellPos) const;
        void drawCell(Vec2<int> cellPos, Color c) const;
        void removeCell(Vec2<int> cellPos);


        void drawBorder() const;
        void draw() const;
        bool cellExists(Vec2<int> cellPos) const;

        int getWidth() const;
        int getHeight() const;
        Color getCellColor(Vec2<int> cellPos);

    private:
        class Cell
        {
            public:
                Cell();
                ~Cell();

                Color getColor() const;
                void setColor(Color defaultColor);

                bool exists() const;
                void remove();
            private:
                bool boardExists = false;
                Color color;
        };

    const Vec2<int> screenSize;

    std::vector<Cell> cells;
    const int cellSize;
    const int padding;

    Vec2<int> screenPos;
};