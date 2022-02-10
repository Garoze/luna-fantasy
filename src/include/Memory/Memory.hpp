#pragma once

#include <array>
#include <cstdio>
#include <cstdint>

#define MEMORY_SIZE 64 * 1024

class Memory
{
public:
    Memory() {};

    void viewAt(std::uint16_t address)
    {
        printf("0x%04X: ", address);
        for (int i = 1; i <= 16; ++i)
        {
            printf("%02X ", data[address++]);
        }
        printf("\n");
    }

public:
    std::uint8_t& operator[](std::size_t i)
    {
        return data[i];
    }
private:
    std::array<std::uint8_t, MEMORY_SIZE> data;
};
