#pragma once

#include <array>
#include <cstdint>

struct Registers
{
    std::uint16_t PC;
    std::uint16_t SP;
    std::uint16_t A;
    std::array<std::uint16_t, 8> R;
};
