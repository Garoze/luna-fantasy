#pragma once

#include <map>
#include <vector>

#include "Flags.hpp"
#include "Registers.hpp"
#include "Instructions.hpp"

#include "../Bus/Bus.hpp"

class CPU
{
public:
    CPU();

    void run();
    void step();
    void loadToMemory(const std::vector<std::uint8_t>&);
private:
    void fetch();
    void decode();
    void execute();
private:
    void NOP();
    void HLT();
private:
    Bus bus;
    Flags flags;
    Status status;
    Registers registers;
    Instructions instruction;
    std::map<Instructions, void(CPU::*)()> opcode_t;
};
