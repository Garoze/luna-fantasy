#include <vector>
#include <cstdint>
#include <iostream>

#include "include/CPU/CPU.hpp"

int main()
{
    CPU cpu;

    const std::vector<std::uint8_t> code = {
        (int)Instructions::PSH, 0xCD, 0xAB,
        (int)Instructions::LDS,
        (int)Instructions::OUT,
        (int)Instructions::HLT,
    };

    cpu.loadToMemory(code);
    cpu.step();
    // cpu.run();
    // cpu.debugFlags("z");
    printf("Main Memory:\n");
    cpu.debugMemory(0x0000, 5);
    // printf("Stack Memory:\n");
    // cpu.debugMemory(0xFFFF, 5);

    return EXIT_SUCCESS;
}
