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
    void reset();
    void loadToMemory(const std::vector<std::uint8_t>&);
    void debugMemory(std::uint16_t address, int offset = 10);
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
private:
    std::uint8_t opcode;
    std::map<Instructions, void(CPU::*)()> opcode_t;
};
