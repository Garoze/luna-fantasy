#include <vector>
#include <cstdint>
#include <iostream>

#include "include/CPU/CPU.hpp"

int main()
{
    CPU cpu;

    const std::vector<std::uint8_t> code = {
        (int)Instructions::PSH, 0xCD, 0xAB,
        (int)Instructions::LDA, 0xFD, 0xFF,
        (int)Instructions::STA, 0x10, 0x00,
        (int)Instructions::OUT,
        (int)Instructions::HLT,
    };

    cpu.loadToMemory(code);
    cpu.step();
    printf("\nMain Memory:\n");
    cpu.debugMemory(0x0000, 2);

    return EXIT_SUCCESS;
}
