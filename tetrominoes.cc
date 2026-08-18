#include "tetrominoes.hh"
#include "raylib.h"
#include "vec2.hh"
#include <iostream>

Tetromino::Tetromino(const bool* shape, int dimension, Color color, Board& board)
:
shape(shape),
dimension(dimension),
color(color),
boardPos(board.getWidth()/2 - dimension/2, 0),
board(board),
currentRotation(Rotation::UP)
{
	active = true;
}

bool Tetromino::getState()
{
	return active;
}

void Tetromino::rotateClockwise()
{
	currentRotation = Rotation((int(currentRotation) + 1) % 4);
	
	// if ((boardPos.getY() > 0) && (currentRotation == Rotation::RIGHT)) boardPos -= Vec2{0,1};
	// if ((boardPos.getY() < board.getHeight() - dimension) && (currentRotation == Rotation::UP)) boardPos += Vec2{0,1};
}

void Tetromino::rotateCounterClockwise()
{
	if (currentRotation == Rotation::UP)
	{
		currentRotation = Rotation::LEFT;
		// if (boardPos.getY() > 0) boardPos -= Vec2{0,1};
	}

	else currentRotation = Rotation(int(currentRotation) - 1);

	// if ((boardPos.getY() < (board.getHeight() - dimension)) && (currentRotation == Rotation::UP)) boardPos += Vec2{0,1};
}

void Tetromino::shiftLeft()
{
	// if (!board.cellExists(Vec2<int>{boardPos.getX()-1,boardPos.getY()})) boardPos -= Vec2{1,0};
	// boardPos -= Vec2{1,0};
	Vec2<int> oldPos = boardPos;
	boardPos -= Vec2{1,1};
	if (!checkLowpoint()) boardPos += Vec2{0,1};
	else boardPos = oldPos;
}

void Tetromino::shiftRight()
{
	// if (!board.cellExists(Vec2<int>{boardPos.getX()+1,boardPos.getY()})) boardPos += Vec2{1,0};
	Vec2<int> oldPos = boardPos;
	boardPos += Vec2{1,0};
	boardPos -= Vec2{0,1};
	if (!checkLowpoint()) boardPos += Vec2{0,1};
	else boardPos = oldPos;
	// else 
	// {
	// 	boardPos -= Vec2{1,0};
	// 	boardPos += Vec2{0,1};
	// }
}

void Tetromino::drop()
{
	// for (int y=0; y < dimension; y++)
    // {
    //     for (int x=0; x < dimension; x++)
    //     {
    //         bool cell = false;
    //         switch (currentRotation)
	// 		{
	// 		case Tetromino::Rotation::UP:
	// 			cell = shape[(y * dimension) + x];
	// 			break;
	// 		case Tetromino::Rotation::RIGHT:
	// 			cell = shape[dimension * (dimension - 1) - (dimension * x) + y];
	// 			break;
	// 		case Tetromino::Rotation::DOWN:
	// 			cell = shape[((dimension * dimension) - 1) - (dimension * y )- x];
	// 			break;
	// 		case Tetromino::Rotation::LEFT:
	// 			cell = shape[(dimension - 1) + (dimension * x) - y];
	// 			break;
	// 		default:
	// 			break;
	// 		}

	// 		if ((cell) && (currentRotation == Tetromino::Rotation::UP) && (dimension > 2))
	// 		{
	// 			board.drawCell(boardPos + Vec2<int>{x,y+1}, BLACK);
	// 			// board.removeCell(boardPos + Vec2<int>{x,y+1});
	// 		}
    //         else
	// 		{
	// 			if (cell) board.drawCell(boardPos + Vec2<int>{x,y}, BLACK);
	// 			// if (cell) board.removeCell(boardPos + Vec2<int>{x,y});

	// 		}
    //     }
    // }

	if (boardPos.getY() < (board.getHeight() - (dimension))) boardPos += Vec2{0,1};
	// if (((boardPos.getY() == (board.getHeight() - dimension))  && currentRotation != Rotation::UP ) || (boardPos.getY() == (board.getHeight() - (dimension-1)))) active = false;
	if (boardPos.getY() == (board.getHeight() - dimension)) 
	{
		active = false;
		fixToBoard();
	}
	// if (board.cellExists(boardPos+Vec2{0,1})) active = false;
}

void Tetromino::draw() const
{
    for (int y=0; y < dimension; y++)
    {
        for (int x=0; x < dimension; x++)
        {
            bool cell = false;
            switch (currentRotation)
			{
			case Tetromino::Rotation::UP:
				cell = shape[(y * dimension) + x];
				break;
			case Tetromino::Rotation::RIGHT:
				cell = shape[dimension * (dimension - 1) - (dimension * x) + y];
				break;
			case Tetromino::Rotation::DOWN:
				cell = shape[((dimension * dimension) - 1) - (dimension * y )- x];
				break;
			case Tetromino::Rotation::LEFT:
				cell = shape[(dimension - 1) + (dimension * x) - y];
				break;
			default:
				break;
			}

			if ((cell) && (currentRotation == Tetromino::Rotation::UP) && (dimension > 2))
			{
				board.drawCell(boardPos + Vec2<int>{x,y+1}, color);
				// board.setCell(boardPos + Vec2<int>{x,y+1}, color);
			}
            else
			{
				if (cell) board.drawCell(boardPos + Vec2<int>{x,y}, color);
				// if (cell) board.setCell(boardPos + Vec2<int>{x,y}, color);
			}
        }
    }
}

Vec2<int> Tetromino::getboardPos()
{
	return boardPos;
}

void Tetromino::setState(bool b)
{
	active = b;
}

void Tetromino::fixToBoard()
{
	for (int y=0; y < dimension; y++)
    {
        for (int x=0; x < dimension; x++)
        {
            bool cell = false;
            switch (currentRotation)
			{
			case Tetromino::Rotation::UP:
				cell = shape[(y * dimension) + x];
				break;
			case Tetromino::Rotation::RIGHT:
				cell = shape[dimension * (dimension - 1) - (dimension * x) + y];
				break;
			case Tetromino::Rotation::DOWN:
				cell = shape[((dimension * dimension) - 1) - (dimension * y )- x];
				break;
			case Tetromino::Rotation::LEFT:
				cell = shape[(dimension - 1) + (dimension * x) - y];
				break;
			default:
				break;
			}

			if ((cell) && (currentRotation == Tetromino::Rotation::UP) && (dimension > 2))
			{
				// board.drawCell(boardPos + Vec2<int>{x,y+1}, color);
				board.setCell(boardPos + Vec2<int>{x,y+1}, color);
			}
            else
			{
				// if (cell) board.drawCell(boardPos + Vec2<int>{x,y}, color);
				if (cell) board.setCell(boardPos + Vec2<int>{x,y}, color);
			}
        }
    }
}

bool Tetromino::checkLowpoint()
{
	int lowY = 0;
	for (int y=0; y < dimension; y++)
    {
        for (int x=0; x < dimension; x++)
        {
            bool cell = false;
            switch (currentRotation)
			{
			case Tetromino::Rotation::UP:
				cell = shape[(y * dimension) + x];
				break;
			case Tetromino::Rotation::RIGHT:
				cell = shape[dimension * (dimension - 1) - (dimension * x) + y];
				break;
			case Tetromino::Rotation::DOWN:
				cell = shape[((dimension * dimension) - 1) - (dimension * y )- x];
				break;
			case Tetromino::Rotation::LEFT:
				cell = shape[(dimension - 1) + (dimension * x) - y];
				break;
			default:
				break;
			}

			if ((cell) && (currentRotation == Tetromino::Rotation::UP) && (dimension > 2))
			{
				// board.drawCell(boardPos + Vec2<int>{x,y+1}, color);
				// board.setCell(boardPos + Vec2<int>{x,y+1}, color);
				// lowY  = y  - (dimension);
				if (board.cellExists(boardPos+Vec2<int>{x,y+2})) 
				{
					// lowY  = y  + 1;
					// break;
					return true;
				}
			}
            else
			{
				// if (cell) board.drawCell(boardPos + Vec2<int>{x,y}, color);
				// if (cell) board.setCell(boardPos + Vec2<int>{x,y}, color);
				// if (cell) board.setCell(boardPos + Vec2<int>{x,y}, color);
				if (cell) 
				{				
					if (board.cellExists(boardPos+Vec2<int>{x,y+1})) 
					{
						// lowY  = y  + 1;
						// break;
						return true;
					}
				}
			}
			// lowY  = y  + (dimension - 1);
			// lowY  = y  + 1;
			// lowY  = y;
			// lowY  = y  + 1;
        }

		// if (lowY) break;
    }

	return false;
}
