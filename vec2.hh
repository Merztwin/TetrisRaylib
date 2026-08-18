#pragma once

template <typename T> 
class Vec2
{
    public:
        Vec2() = default;
        constexpr Vec2(T x, T y)
            :
            x(x),
            y(y)
        {

        }

        constexpr T getX() const {return x;}
        constexpr T getY() const {return y;}

        constexpr void setX(T x_in) {x = x_in;}
        constexpr void setY(T y_in) {y = y_in;}

        constexpr bool operator==(const Vec2& rhs) 
        {
            return (x == rhs.x, y == rhs.y);
        }
        constexpr bool operator!=(const Vec2& rhs)
        {
            return !(this == rhs);
        }


        constexpr Vec2 operator+(const int rhs) const
        {
            return  {x + rhs, y + rhs};
        }
        constexpr Vec2 operator+(const Vec2& rhs) const
        {
            return  {x + rhs.x, y + rhs.y};
        }
        constexpr Vec2& operator+=(const Vec2& rhs)
        {
            x += rhs.x;
            y += rhs.y;
            return  *this;
        }

        constexpr Vec2 operator-(const int rhs) const
        {
            return  {x - rhs, y - rhs};
        }
        constexpr Vec2 operator-(const Vec2& rhs) const
        {
            return  {x - rhs.x, y - rhs.y};
        }
        constexpr Vec2& operator-=(const Vec2& rhs)
        {
            x -= rhs.x;
            y -= rhs.y;
            return  *this;
        }

        constexpr Vec2 operator*(const int rhs) const
        {
            return  {x * rhs, y * rhs};
        }
        constexpr Vec2 operator*(const Vec2& rhs) const
        {
            return  {x * rhs.x, y * rhs.y};
        }
        constexpr Vec2& operator*=(const Vec2& rhs)
        {
            x *= rhs.x;
            y *= rhs.y;
            return  *this;
        }



    private:
        T x;
        T y;

};