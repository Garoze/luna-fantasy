#pragma once

#include "../Memory/Memory.hpp"

class Bus
{
public:
    Bus() {};

    std::uint8_t readDataBus(std::uint16_t address);
    void writeDataBus(std::uint16_t address, std::uint8_t value);
private:
    Memory memory;
};
