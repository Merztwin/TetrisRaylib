#include "game.hh"
#include "raylib.h"
#include "settings.hh"

#include <assert.h>

Engine::Game::Game(std::uint32_t width, std::uint32_t height, std::uint8_t fps, std::string title)
:
board(settings::screenSizeinput, settings::cellSize, settings::screenPos, settings::padding)
{
    assert(!IsWindowReady()); //Window has already been created!

    srand(time(NULL));
    std::cout << "Hello Tetris! \n";

    SetTargetFPS(fps);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(width, height, title.c_str());

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist7(1,7);

    int tetrominoType = dist7(rng);

    switch(tetrominoType)
    {
        case 1:
            tetromino = new Straight(board);
            break;
        case 2:
            tetromino = new Square(board);
            break;
        case 3:
            tetromino = new Tee(board);
            break;
        case 4:
            tetromino = new Jay(board);
            break;
        case 5:
            tetromino = new El(board);
            break;
        case 6:
            tetromino = new SkewS(board);
            break;
        case 7:
            tetromino = new SkewZ(board);
            break;
        default:
            tetromino = new Jay(board);
    }

    // newTetromino();
    SetExitKey(KEY_NULL);
}

Engine::Game::~Game() noexcept
{
    assert(IsWindowReady()); //Window has already closed!
    CloseWindow();
}

bool Engine::Game::shouldGameClose() const
{
    return WindowShouldClose();
}

void Engine::Game::draw()
{
    ClearBackground(BLACK);
    board.draw();
    tetromino->draw();

    for(int i=0;i<tetrominoes.size();i++)
    {
        tetrominoes[i]->draw();
    }
}

void Engine::Game::update()
{
    if (tetromino->getState())
    {
        // for(int i=0;i<tetrominoes.size();i++)
        // {
        //     if (tetromino->getboardPos().getY() == (tetrominoes[i]->getboardPos().getY()))
        //     {
        //         tetromino->setState(false);
        //     }
        // }

        // if (board.cellExists({tetromino->getboardPos().getX(),tetromino->getboardPos().getY()+tetromino->checkLowpoint()}))
        if (tetromino->checkLowpoint())
        {
            // std::cout << "here\n";
            tetromino->fixToBoard();
            tetromino->setState(false);
            return;
            // std::cout << "COLLIDE\n";
        }

        if (IsKeyPressed(KEY_E)) tetromino->rotateClockwise();
        if (IsKeyPressed(KEY_Q)) tetromino->rotateCounterClockwise();

        if (IsKeyPressed(KEY_A)) tetromino->shiftLeft();
        if (IsKeyPressed(KEY_D)) tetromino->shiftRight();


        if ((deltaTime - fallTime) >= 1.0/fallSpeed)
        {
            tetromino->drop();
            fallTime = deltaTime;
        }
    }
    else 
    {
        // std::cout << board.cellExists(tetromino->getboardPos()) << "\n";
        newTetromino();
    }
}

void Engine::Game::tick()
{
    deltaTime = GetTime();
    BeginDrawing();
    update();
    draw();
    EndDrawing();
}

void Engine::Game::newTetromino()
{
    tetrominoes.push_back(tetromino->clone());

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist7(1,7);

    int tetrominoType = dist7(rng);

    switch(tetrominoType)
    {
        case 1:
            tetromino = new Straight(board);
            break;
        case 2:
            tetromino = new Square(board);
            break;
        case 3:
            tetromino = new Tee(board);
            break;
        case 4:
            tetromino = new Jay(board);
            break;
        case 5:
            tetromino = new El(board);
            break;
        case 6:
            tetromino = new SkewS(board);
            break;
        case 7:
            tetromino = new SkewZ(board);
            break;
        default:
            tetromino = new Jay(board);
    }
}