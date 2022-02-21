#include <vector>
#include <cstdint>
#include <iostream>

#include "include/CPU/CPU.hpp"

int main()
{
    CPU cpu;

    const std::vector<std::uint8_t> code = {
        (int)Instructions::LDI, 0x00, 0xCD, 0xAB,
        (int)Instructions::OUT, 0x00,
        (int)Instructions::PSH, 0xEF, 0xCD,
        (int)Instructions::LDS, 0x01,
        (int)Instructions::OUT, 0x01,
        (int)Instructions::LDA, 0x02, 0xFD, 0xFF,
        (int)Instructions::OUT, 0x02,
        (int)Instructions::HLT,
    };

    cpu.loadToMemory(code);
    cpu.step();
    printf("\nMain Memory:\n");
    cpu.debugMemory(0x0000, 2);

    return EXIT_SUCCESS;
}
