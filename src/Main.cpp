#include <vector>
#include <cstdint>
#include <iostream>

#include "include/CPU/CPU.hpp"

int main()
{
    CPU cpu;

    const std::vector<std::uint8_t> code = {
        (int)Instructions::LDI, 0x05, 0x00,
        (int)Instructions::SUB, 0x01, 0x00,
        (int)Instructions::OUT,
        (int)Instructions::JNZ, 0x03, 0x00,
        (int)Instructions::HLT,
    };

    cpu.loadToMemory(code);
    cpu.step();
    printf("\nMain Memory:\n");
    cpu.debugMemory(0x0000, 2);

    return EXIT_SUCCESS;
}
