#pragma once
#include "vec2.hh"

//std
#include <cinttypes>


namespace settings 
{
    //Window Settings
    inline constexpr std::uint32_t windowWidth = 800;
    inline constexpr std::uint32_t windowHeight = 600;
    inline constexpr std::uint8_t fps = 165;

    //Board Settings
    inline constexpr int cellSize = 23;
    inline constexpr int padding = 2;

    inline constexpr Vec2<int> screenSizeinput{10, 20};
    inline constexpr Vec2<int> screenPos{250,70};
}