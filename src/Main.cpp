#include <vector>
#include <cstdint>
#include <iostream>

#include "include/CPU/CPU.hpp"

int main()
{
    CPU cpu;

    const std::vector<std::uint8_t> code = {
        (int)Instructions::LDI, 0x00, 0xAB,
        (int)Instructions::RET,
        (int)Instructions::BOR, 0xFF, 0x00,
        (int)Instructions::RET,
        (int)Instructions::HLT,
    };

    cpu.loadToMemory(code);
    cpu.step();
    // cpu.run();
    cpu.debugMemory(0x0000, 3);
    // cpu.debugMemory(0xFFFD, 1);

    return EXIT_SUCCESS;
}
