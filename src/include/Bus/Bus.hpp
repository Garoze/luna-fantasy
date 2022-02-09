#pragma once

#include "../Memory/Memory.hpp"

class Bus
{
public:
    Bus() {};

    void write8(std::uint16_t address, std::uint8_t value);
    void write16(std::uint16_t address, std::uint16_t value);
    std::uint8_t read8(std::uint16_t address);
    std::uint16_t read16(std::uint16_t address);

    void debugMemory(std::uint16_t address, int offset);
private:
    Memory memory;
};
