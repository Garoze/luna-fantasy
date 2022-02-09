#include <vector>
#include <cstdint>
#include <iostream>

#include "include/CPU/CPU.hpp"
#include "include/CPU/Instructions.hpp"

int main()
{
    CPU cpu;

    const std::vector<std::uint8_t> code = {
        (int)Instructions::NOP,
        (int)Instructions::HLT,
    };

    cpu.loadToMemory(code);
    // cpu.step();
    cpu.run();

    return EXIT_SUCCESS;
}
