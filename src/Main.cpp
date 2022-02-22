#include <vector>
#include <cstdint>
#include <iostream>

#include "include/CPU/CPU.hpp"

int main()
{
    CPU cpu;

    const std::vector<std::uint8_t> code = {
        (int)Instructions::LDI, 0x00, 0x0A, 0x00,
        (int)Instructions::STR, 0x10, 0x00, 0x00,
        (int)Instructions::HLT,
    };

    cpu.loadToMemory(code);
    cpu.step();
    printf("\nMain Memory:\n");
    cpu.debugMemory(0x0000, 2);

    return EXIT_SUCCESS;
}
