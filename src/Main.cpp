#include <vector>
#include <cstdint>
#include <iostream>

#include "include/CPU/CPU.hpp"

int main()
{
    CPU cpu;

    const std::vector<std::uint8_t> code = {
        (int)Instructions::CAL, 0x05, 0x00,
        (int)Instructions::HLT,
        (int)Instructions::NOP,
        (int)Instructions::RET,
    };

    cpu.loadToMemory(code);
    cpu.step();
    printf("\nMain Memory:\n");
    cpu.debugMemory(0x0000, 2);

    return EXIT_SUCCESS;
}
