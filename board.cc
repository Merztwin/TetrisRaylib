#include "board.hh"
#include "vec2.hh"
#include <assert.h>
#include <iostream>
#include <raylib.h>


Board::Board(Vec2<int> screenSizeinput, int cellSizeInput, Vec2<int> screenPosinput, int padding)
:
screenSize(screenSizeinput),
cellSize(cellSizeInput),
screenPos(screenPosinput),
padding(padding)
{
	assert(screenSizeinput.getX() > 0 && screenSizeinput.getY() > 0);
	assert(cellSize > 0);

	cells.resize(screenSizeinput.getX()*screenSizeinput.getY());
}
Board::~Board()
{

}

void Board::setCell(Vec2<int> cellPos, Color c)
{
	assert(cellPos.getX() >= 0 && cellPos.getY() >= 0 && cellPos.getX() < screenSize.getX() && cellPos.getY() < screenSize.getY()); //If assertion triggers : x or pos.GetY() is out of bounds
	cells[cellPos.getY() * screenSize.getX() + cellPos.getX()].setColor(c);
}

void Board::removeCell(Vec2<int> cellPos)
{
	assert(cellPos.getX() >= 0 && cellPos.getY() >= 0 && cellPos.getX() < screenSize.getX() && cellPos.getY() < screenSize.getY()); //If assertion triggers : x or pos.GetY() is out of bounds
	cells[cellPos.getY() * screenSize.getX() + cellPos.getX()].setColor(BLACK);
	cells[cellPos.getY() * screenSize.getX() + cellPos.getX()].remove();
}

void Board::drawCell(Vec2<int> cellPos, Color c) const
{
	assert(cellPos.getX() >= 0 && cellPos.getY() >= 0 && cellPos.getX() < screenSize.getX() && cellPos.getY() < screenSize.getY()); //If assertion triggers : x or pos.GetY() is out of bounds
	Vec2<int> topLeft = screenPos + cellPos*cellSize + padding;
	rayCpp::DrawRectangle(topLeft, Vec2{cellSize, cellSize} - padding, c);
}

void Board::drawCell(Vec2<int> cellPos) const
{
	assert(cellPos.getX() >= 0 && cellPos.getY() >= 0 && cellPos.getX() < screenSize.getX() && cellPos.getY() < screenSize.getY()); //If assertion triggers : x or pos.GetY() is out of bounds
	Color c = cells[cellPos.getY() * screenSize.getX() + cellPos.getX()].getColor();
	drawCell(cellPos, c);
}

void Board::drawBorder() const
{
	rayCpp::DrawRectangleLinesEx(screenPos - (cellSize/2), Vec2{screenSize.getX()*cellSize,screenSize.getY()*cellSize} + cellSize, cellSize/2, WHITE);
}

bool Board::cellExists(Vec2<int> cellPos) const
{
	// int aux = cellPos.getY() * screenSize.getX() + cellPos.getX();
	return cells[cellPos.getY() * screenSize.getX() + cellPos.getX()].exists();
}


//Cell
Board::Cell::Cell() : boardExists(false), color(WHITE)
{

}
Board::Cell::~Cell()
{

}
void Board::Cell::setColor(Color defaultColor)
{
	color = defaultColor;
	boardExists = true;
}

void Board::Cell::remove()
{
	boardExists = false;
}

bool Board::Cell::exists() const
{
	return boardExists;
}

Color Board::Cell::getColor() const
{
	return color;
}

Color Board::getCellColor(Vec2<int> cellPos)
{
	return cells[cellPos.getY() * screenSize.getX() + cellPos.getX()].getColor();
}

void Board::draw() const
{
	int cells = 0;
	for (int iY = 0; iY < screenSize.getY(); ++iY)
	{
		for (int iX = 0; iX < screenSize.getX(); ++iX)
		{
			// if (cellExists({iX, iY})) drawCell({iX, iY});
			if (cellExists({iX, iY})) 
			{
				drawCell({iX, iY});
				cells++;
			}
		}
	}
	if (cells) std::cout << cells << "\n";
	drawBorder();
}

int Board::getWidth() const
{
	return screenSize.getX();
}

int Board::getHeight() const
{
	return screenSize.getY();
}


// void Board::DrawCell(Vec2<int> pos) const
// {
// 	Color color = cells[pos.GetY() * width + pos.GetX()].GetColor();
// 	DrawCell(pos, color);
// }

// void Board::DrawCell(Vec2<int> pos, Color color) const
// {
// 	assert(pos.GetX() >= 0 && pos.GetX() < width && pos.GetY() >= 0 && pos.GetY() < height); //If assertion triggers : pos.GetX() or pos.GetY() is out of bounds
// 	Vec2<int> topLeft = screenPos + padding + (pos * cellSize);
// 	raycpp::rayCpp::DrawRectangle(topLeft, Vec2{ cellSize,cellSize } - padding, color);
// }

// void Board::DrawBorder() const
// {
// 	raycpp::rayCpp::DrawRectangleLinesEx(screenPos - (cellSize/2),
// 								 Vec2{width*cellSize,height*cellSize} + cellSize,
// 								 cellSize/2,
// 								 WHITE);
// }

// void Board::Draw() const
// {
// 	for (int iY = 0; iY < height; ++iY)
// 	{
// 		for (int iX = 0; iX < width; ++iX)
// 		{
// 			if (CellExists({ iX,iY }))
// 			{
// 				DrawCell({ iX,iY });
// 			}
// 		}
// 	}
// 	DrawBorder();
// }

// bool Board::CellExists(Vec2<int> pos) const
// {
// 	return cells[pos.GetY()*width + pos.GetX()].Exists();
// }

// int Board::GetWidth() const
// {
// 	return width;
// }

// int Board::GetHeight() const
// {
// 	return height;
// }