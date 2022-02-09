#pragma once

#include "../Memory/Memory.hpp"

class Bus
{
public:
    Bus() {};

    std::uint8_t readDataBus(std::uint16_t address);
    void writeDataBus(std::uint16_t address, std::uint8_t value);
    void debugMemory(std::uint16_t address, int offset);
private:
    Memory memory;
};
