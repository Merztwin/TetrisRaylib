#pragma once
#include <cmath>
#include <iostream>
#include <cinttypes>
#include <string>
#include <random>

#include "board.hh"
#include "tetrominoes.hh"

namespace Engine 
{
    class Game
    {
        public:
            Game(std::uint32_t width, std::uint32_t height, std::uint8_t fps, std::string title); //Constructor
            ~Game() noexcept; //Destructor; Should trigger in crashes or in case the window closes

            //Deleting all of these as they are not useful or desirable for this application
            Game(const Game& other) = delete; //Copy constructor
            Game(const Game&& other) = delete; //Move constructor

            Game& operator=(const Game& other) = delete; //Copy assignment
            Game& operator=(const Game&& other) = delete; //Move assignment

            bool shouldGameClose() const; //const so it DOES NOT modify arguments; thread safe and prevents accidental data changes
            void tick();

            void newTetromino();

        private:
            std::uint32_t width;
            std::uint32_t height;

            std::uint32_t fallSpeed = 5;


            std::double_t deltaTime = 0.0;
            std::double_t fallTime = 0.0;

            void draw();
            void update();

            Board board;
            Tetromino* tetromino;
            std::vector<Tetromino*> tetrominoes;
    };
}
