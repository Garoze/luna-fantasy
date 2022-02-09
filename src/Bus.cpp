#include "include/Bus/Bus.hpp"

std::uint8_t Bus::readDataBus(std::uint16_t address)
{
    return memory[address];
}

void Bus::writeDataBus(std::uint16_t address, std::uint8_t value)
{
    memory[address] = value;
}

