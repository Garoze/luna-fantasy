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
        (int)Instructions::INC,
        (int)Instructions::STA, 0x10, 0x00,
        (int)Instructions::STS, 0x20, 0x00,
        (int)Instructions::HLT,
    };

    cpu.loadToMemory(code);
    cpu.step();
    // cpu.run();
    cpu.debugMemory(0x0000, 3);
    // cpu.debugMemory(0xFFFD, 1);

    return EXIT_SUCCESS;
}
