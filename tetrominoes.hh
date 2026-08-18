#pragma once
#include "vec2.hh"
#include "board.hh"
#include "raylibCpp.hh"
#include <raylib.h>
#include <assert.h>

class Tetromino
{
    public:
        enum class Rotation
        {
            UP,
            RIGHT,
            DOWN,
            LEFT
        };
        
        Tetromino(const bool* shape, int dimension, Color color, Board& board);
        void rotateClockwise();
	    void rotateCounterClockwise();

        void fixToBoard();

        void shiftLeft();
	    void shiftRight();

	    void drop();
        void draw() const;
        bool getState();
        Vec2<int> getboardPos();

        void setState(bool b);
        bool checkLowpoint();
        bool checkCollide(Vec2<int> newPos);
        bool checkCollideRot(Rotation newRot);




        Tetromino* clone() const { return new Tetromino(*this); }


    private:
        Board& board;
        Vec2<int> boardPos;

        Rotation currentRotation;

        const bool* shape;
        const int dimension;

        const Color color;

        bool active;
};

class Straight : public Tetromino
{
    public:
        Straight(Board& board)
        :
        Tetromino(shape, dimension, color, board)
        {
            static_assert(sizeof(shape)/sizeof(bool) == dimension*dimension);
        }

        Tetromino* clone() const { return new Straight(*this); }

    private:
        static constexpr bool shape[] = {
                                            0,0,0,0,
                                            0,0,0,0,
                                            1,1,1,1,
                                            0,0,0,0
                                        };
        
        static constexpr int dimension = 4;
        static constexpr Color color = SKYBLUE;

};

class Square : public Tetromino
{
    public:
        Square(Board& board)
        :
        Tetromino(shape, dimension, color, board)
        {
            static_assert(sizeof(shape)/sizeof(bool) == dimension*dimension);
        }

        Tetromino* clone() const { return new Square(*this); }

    private:
        static constexpr bool shape[] = {1,1,
                                        1,1};
        
        static constexpr int dimension = 2;
        static constexpr Color color = YELLOW;

};

class Tee : public Tetromino
{
    public:
        Tee(Board& board)
        :
        Tetromino(shape, dimension, color, board)
        {
            static_assert(sizeof(shape)/sizeof(bool) == dimension*dimension);
        }

        Tetromino* clone() const { return new Tee(*this); }

    private:
        static constexpr bool shape[] = {
                                            0,1,0,
                                            1,1,1,
                                            0,0,0
                                        };
        
        static constexpr int dimension = 3;
        static constexpr Color color = MAGENTA;

};

class Jay : public Tetromino
{
    public:
        Jay(Board& board)
        :
        Tetromino(shape, dimension, color, board)
        {
            static_assert(sizeof(shape)/sizeof(bool) == dimension*dimension);
        }

        Tetromino* clone() const { return new Jay(*this); }


    private:
        static constexpr bool shape[] = {
                                            1,0,0,
                                            1,1,1,
                                            0,0,0
                                        };
        
        static constexpr int dimension = 3;
        static constexpr Color color = DARKBLUE;

};

class El : public Tetromino
{
    public:
        El(Board& board)
        :
        Tetromino(shape, dimension, color, board)
        {
            static_assert(sizeof(shape)/sizeof(bool) == dimension*dimension);
        }

        Tetromino* clone() const { return new El(*this); }

    private:
        static constexpr bool shape[] = {
                                            0,0,1,
                                            1,1,1,
                                            0,0,0
                                        };
        
        static constexpr int dimension = 3;
        static constexpr Color color = ORANGE;

};

class SkewS : public Tetromino
{
    public:
        SkewS(Board& board)
        :
        Tetromino(shape, dimension, color, board)
        {
            static_assert(sizeof(shape)/sizeof(bool) == dimension*dimension);
        }

        Tetromino* clone() const { return new SkewS(*this); }

    private:
        static constexpr bool shape[] = {
                                            0,1,1,
                                            1,1,0,
                                            0,0,0
                                        };
        
        static constexpr int dimension = 3;
        static constexpr Color color = GREEN;

};

class SkewZ : public Tetromino
{
    public:
        SkewZ(Board& board)
        :
        Tetromino(shape, dimension, color, board)
        {
            static_assert(sizeof(shape)/sizeof(bool) == dimension*dimension);
        }

        Tetromino* clone() const { return new SkewZ(*this); }

    private:
        static constexpr bool shape[] = {
                                            1,1,0,
                                            0,1,1,
                                            0,0,0
                                        };
        
        static constexpr int dimension = 3;
        static constexpr Color color = RED;

};