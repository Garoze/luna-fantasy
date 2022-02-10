#pragma once

#include <cstdio>
#include <iostream>

#include "include/CPU/CPU.hpp"

#define STACK_START   0xFFFF
#define PROGRAM_START 0x0000

#define validOpcode(o) (opcode_t.count((Instructions)o) > 0)

CPU::CPU()
{
    reset();

    opcode_t[Instructions::NOP] = &CPU::NOP;
    opcode_t[Instructions::LDI] = &CPU::LDI;
    opcode_t[Instructions::LDA] = &CPU::LDA;
    opcode_t[Instructions::LDS] = &CPU::LDS;
    opcode_t[Instructions::STA] = &CPU::STA;
    opcode_t[Instructions::STS] = &CPU::STS;
    opcode_t[Instructions::ADD] = &CPU::ADD;
    opcode_t[Instructions::ADA] = &CPU::ADA;
    opcode_t[Instructions::ADS] = &CPU::ADS;
    opcode_t[Instructions::INC] = &CPU::INC;
    opcode_t[Instructions::DEC] = &CPU::DEC;
    opcode_t[Instructions::SHL] = &CPU::SHL;
    opcode_t[Instructions::SHR] = &CPU::SHR;
    opcode_t[Instructions::PSH] = &CPU::PSH;
    opcode_t[Instructions::AND] = &CPU::AND;
    opcode_t[Instructions::BOR] = &CPU::BOR;
    opcode_t[Instructions::XOR] = &CPU::XOR;
    opcode_t[Instructions::NOT] = &CPU::NOT;
    opcode_t[Instructions::POP] = &CPU::POP;
    opcode_t[Instructions::RET] = &CPU::RET;
    opcode_t[Instructions::HLT] = &CPU::HLT;
}

void CPU::reset()
{
    registers.SP = STACK_START;
    registers.PC = PROGRAM_START;

    registers.A = 0;
    registers.X = 0;
    registers.Y = 0;

    flags.C = 0;
    flags.N = 0;
    flags.V = 0;
    flags.Z = 0;

    status.running = true;
}

void CPU::loadToMemory(const std::vector<std::uint8_t>& code)
{
    auto PC = registers.PC;
    for (std::size_t i = 0; i < code.size(); ++i)
    {
        bus.write8(PC + i, code.at(i));
    }
}

void CPU::debugMemory(std::uint16_t address, int offset)
{
    bus.debugMemory(address, offset);
}

void CPU::run()
{
    while (status.running)
    {
        fetch();
        decode();
        execute();
    }
}

void CPU::step()
{
    do
    {
        fetch();
        decode();
        execute();
        printf("[ DEBUG ] Step -> PC: %02hX Opcode: %02hX\t", registers.PC, instruction);
    }
    while(std::cin.get() != 'q');
}

void CPU::fetch()
{
   opcode = bus.read8(registers.PC++);
}

void CPU::decode()
{
    instruction = (Instructions)opcode;
}

void CPU::execute()
{
    if (validOpcode(instruction))
        (this->*opcode_t[instruction])();
    else
        printf("[ Execute ] -> Invalid Opcode: %02hhX\n", instruction);
}

void CPU::NOP() {}

void CPU::LDI()
{
    auto value = bus.read16(registers.PC);
    registers.A = value;
    registers.PC += 2;
}

void CPU::LDA()
{
    auto address = bus.read16(registers.PC);
    registers.A = bus.read16(address);
    registers.PC += 2;
}

void CPU::LDS()
{
    registers.A = bus.read16(registers.SP);
    registers.SP += 2;
}

void CPU::STA()
{
    auto address = bus.read16(registers.PC);
    bus.write16(address, registers.A);
    registers.PC += 2;
}

void CPU::STS()
{
    auto address = bus.read16(registers.PC);
    auto value = bus.read16(registers.SP);
    bus.write16(address, value);
    registers.SP += 2;
    registers.PC += 2;
}

void CPU::ADD()
{
    auto value = bus.read16(registers.PC);
    registers.A += value;
    registers.PC += 2;
}

void CPU::ADA()
{
    auto address = bus.read16(registers.PC);
    registers.A += bus.read16(address);
    registers.PC += 2;
}

void CPU::ADS()
{
    auto value = bus.read16(registers.SP);
    registers.A += value;
    registers.SP += 2;
}

void CPU::INC()
{
    registers.A++;
}

void CPU::DEC()
{
    registers.A--;
}

void CPU::SHL()
{
    auto value = bus.read8(registers.PC++);
    registers.A <<= value;
}

void CPU::SHR()
{
    auto value = bus.read8(registers.PC++);
    registers.A >>= value;
}

void CPU::AND()
{
     auto value = bus.read16(registers.PC);
     registers.A &= value;
     registers.PC += 2;
}

void CPU::BOR()
{
    auto value = bus.read16(registers.PC);
    registers.A |= value;
    registers.PC += 2;
}

void CPU::XOR()
{
    auto value = bus.read16(registers.PC);
    registers.A ^= value;
    registers.PC += 2;
}

void CPU::NOT()
{
    registers.A = ~registers.A;
}

void CPU::PSH()
{
    registers.SP -= 2;
    auto value = bus.read16(registers.PC);
    bus.write16(registers.SP, value);
    registers.PC += 2;
}

void CPU::POP()
{
    // TODO: Find a better way to deal with the return value.
    registers.A = bus.read16(registers.SP);
    registers.SP += 2;
}

void CPU::RET()
{
    printf("Register A: %04X\n", registers.A);
}

void CPU::HLT()
{
    status.running = false;
}

