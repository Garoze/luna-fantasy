#pragma once

#include <cstdint>

struct Registers
{
    std::uint16_t PC;
    std::uint16_t SP;
    std::uint16_t A, X, Y;
};
