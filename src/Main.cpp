#include <vector>
#include <cstdint>
#include <iostream>

#include "include/CPU/CPU.hpp"

int main()
{
    CPU cpu;

    cpu.loadFromFile("./__tests__/out.bin");
    cpu.step();
    printf("\nMain Memory:\n");
    cpu.debugMemory(0x0000, 2);

    return EXIT_SUCCESS;
}
