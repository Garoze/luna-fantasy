#pragma once

#include <array>
#include <cstdint>

#define MEMORY_SIZE 64 * 1024

class Memory
{
public:
    Memory() {};

    std::uint8_t& operator[](std::size_t i)
    {
        return data[i];
    }
private:
    std::array<std::uint8_t, MEMORY_SIZE> data;
};
