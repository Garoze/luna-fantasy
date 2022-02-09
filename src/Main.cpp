#include <vector>
#include <cstdint>
#include <iostream>

#include "include/CPU/CPU.hpp"

int main()
{
    CPU cpu;

    const std::vector<std::uint8_t> code = {
        (int)Instructions::NOP,
        (int)Instructions::LDI, 0xCD, 0xAB,
        (int)Instructions::RET,
        (int)Instructions::HLT,
    };

    cpu.loadToMemory(code);
    cpu.debugMemory(0x0000);
    cpu.step();
    // cpu.run();

    return EXIT_SUCCESS;
}
