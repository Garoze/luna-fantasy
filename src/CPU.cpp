#pragma once

#include <map>
#include <string>
#include <cstdio>
#include <fstream>
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
    opcode_t[Instructions::LDR] = &CPU::LDR;
    opcode_t[Instructions::STA] = &CPU::STA;
    opcode_t[Instructions::STS] = &CPU::STS;
    opcode_t[Instructions::ADD] = &CPU::ADD;
    opcode_t[Instructions::ADA] = &CPU::ADA;
    opcode_t[Instructions::ADS] = &CPU::ADS;
    opcode_t[Instructions::SUB] = &CPU::SUB;
    opcode_t[Instructions::SUA] = &CPU::SUA;
    opcode_t[Instructions::SUS] = &CPU::SUS;
    opcode_t[Instructions::MUL] = &CPU::MUL;
    opcode_t[Instructions::MUA] = &CPU::MUA;
    opcode_t[Instructions::MUS] = &CPU::MUS;
    opcode_t[Instructions::DIV] = &CPU::DIV;
    opcode_t[Instructions::DIA] = &CPU::DIA;
    opcode_t[Instructions::DIS] = &CPU::DIS;
    opcode_t[Instructions::MOD] = &CPU::MOD;
    opcode_t[Instructions::MOA] = &CPU::MOA;
    opcode_t[Instructions::MOS] = &CPU::MOS;
    opcode_t[Instructions::INC] = &CPU::INC;
    opcode_t[Instructions::DEC] = &CPU::DEC;
    opcode_t[Instructions::SHL] = &CPU::SHL;
    opcode_t[Instructions::SHR] = &CPU::SHR;
    opcode_t[Instructions::AND] = &CPU::AND;
    opcode_t[Instructions::BOR] = &CPU::BOR;
    opcode_t[Instructions::XOR] = &CPU::XOR;
    opcode_t[Instructions::NOT] = &CPU::NOT;
    opcode_t[Instructions::PSH] = &CPU::PSH;
    opcode_t[Instructions::POP] = &CPU::POP;
    opcode_t[Instructions::CMP] = &CPU::CMP;
    opcode_t[Instructions::CMA] = &CPU::CMA;
    opcode_t[Instructions::CMS] = &CPU::CMS;
    opcode_t[Instructions::JMP] = &CPU::JMP;
    opcode_t[Instructions::JMZ] = &CPU::JMZ;
    opcode_t[Instructions::JNZ] = &CPU::JNZ;
    opcode_t[Instructions::CAL] = &CPU::CAL;
    opcode_t[Instructions::RET] = &CPU::RET;
    opcode_t[Instructions::OUT] = &CPU::OUT;
    opcode_t[Instructions::HLT] = &CPU::HLT;
}

void CPU::reset()
{
    registers.SP = STACK_START;
    registers.PC = PROGRAM_START;

    registers.A = 0;
    for (auto& r : registers.R) r = 0;

    flags.C = 0;
    flags.N = 0;
    flags.V = 0;
    flags.Z = 0;

    status.running = true;
}

void CPU::loadFromFile(const std::string& file_name)
{
    std::ifstream file(file_name, std::ios::binary | std::ios::in);

    if (file.good())
    {
        file.seekg(0, std::ios::end);
        size_t size = file.tellg();
        file.seekg(0, std::ios::beg);

        char* buffer = new char[size];

        file.read(buffer, size);
        file.close();

        for (int i = 0; i < size; ++i)
        {
            bus.write8(registers.PC + i, buffer[i]);
        }

        delete[] buffer;
    }
}

void CPU::loadToMemory(const std::vector<std::uint8_t>& code)
{
    for (std::size_t i = 0; i < code.size(); ++i)
    {
        bus.write8(registers.PC + i, code.at(i));
    }
}

void CPU::debugMemory(std::uint16_t address, int offset)
{
    bus.debugMemory(address, offset);
}

void CPU::executeCycle()
{
    opcode = fetch8();
    instruction = decode(opcode);
    execute(instruction);
}

std::uint8_t CPU::fetch8()
{
    return bus.read8(registers.PC++);
}

std::uint16_t CPU::fetch16()
{
    auto value = bus.read16(registers.PC);
    registers.PC += 2;
    return value;
}

Instructions CPU::decode(std::uint8_t opcode)
{
    return (Instructions)opcode;
}

void CPU::execute(Instructions inst)
{
    if (validOpcode(inst))
        (this->*opcode_t[inst])();
    else
        printf("[ Execute ] -> Invalid Opcode: %02hhX\n", inst);
}

void CPU::run()
{
    while (status.running)
    {
        executeCycle();
    }
}

void CPU::step()
{
    do
    {
        printf("[ DEBUG ] step -> ");
        opcode = fetch8();
        printf("PC: %04X ", registers.PC);
        instruction = decode(opcode);
        printf("Opcode: %02X Mnemonic: %s\t", opcode, Mnemonic_t.at(instruction).c_str());
        execute(instruction);
    }
    while(std::cin.get() != 'q');
}

void CPU::NOP() {}

void CPU::LDI()
{
    auto r = fetch8();
    registers.R[r] = fetch16();
}

void CPU::LDA()
{
    auto r = fetch8();
    auto address = fetch16();
    registers.R[r] = bus.read16(address);
}

void CPU::LDS()
{
    auto r = fetch8();
    registers.R[r] = bus.read16(registers.SP);
    registers.SP += 2;
}

void CPU::LDR()
{
    auto dst = fetch8();
    auto src = fetch8();
    registers.R[dst] = registers.R[src];
}

void CPU::STA()
{
    auto address = fetch16();
    bus.write16(address, registers.A);
}

void CPU::STS()
{
    auto address = fetch16();
    auto value = bus.read16(registers.SP);
    registers.SP += 2;
    bus.write16(address, value);
}

void CPU::ADD()
{
    auto value = fetch16();
    registers.A += value;
}

void CPU::ADA()
{
    auto address = fetch16();
    registers.A += bus.read16(address);
}

void CPU::ADS()
{
    auto value = bus.read16(registers.SP);
    registers.SP += 2;
    registers.A += value;
}

void CPU::SUB()
{
    auto value = fetch16();
    registers.A -= value;
}

void CPU::SUA()
{
    auto address = fetch16();
    registers.A -= bus.read16(address);
}

void CPU::SUS()
{
    auto value = bus.read16(registers.SP);
    registers.SP += 2;
    registers.A -= value;
}

void CPU::MUL()
{
    auto value = fetch16();
    registers.A *= value;
}

void CPU::MUA()
{
    auto address = fetch16();
    registers.A *= bus.read16(address);
}

void CPU::MUS()
{
    auto value = bus.read16(registers.SP);
    registers.SP += 2;
    registers.A *= value;
}

void CPU::DIV()
{
    auto value= fetch16();
    registers.A /= value;
}

void CPU::DIA()
{
    auto address = fetch16();
    registers.A /= bus.read16(address);
}

void CPU::DIS()
{
    auto value = bus.read16(registers.SP);
    registers.SP += 2;
    registers.A /= value;
}

void CPU::MOD()
{
    auto value = fetch16();
    registers.A %= value;
}

void CPU::MOA()
{
    auto address = fetch16();
    registers.A %= bus.read16(address);
}

void CPU::MOS()
{
    auto value = bus.read16(registers.SP);
    registers.SP += 2;
    registers.A %= value;
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
    auto value = fetch8();
    registers.A <<= value;
}

void CPU::SHR()
{
    auto value = fetch8();
    registers.A >>= value;
}

void CPU::AND()
{
    auto value = fetch16();
    registers.A &= value;
}

void CPU::BOR()
{
    auto value = fetch16();
    registers.A |= value;
}

void CPU::XOR()
{
    auto value = fetch16();
    registers.A ^= value;
}

void CPU::NOT()
{
    registers.A = ~registers.A;
}

void CPU::PSH()
{
    auto value = fetch16();
    registers.SP -= 2;
    bus.write16(registers.SP, value);
}

void CPU::POP()
{
    // TODO: Find a better way to deal with the return value.
    registers.A = bus.read16(registers.SP);
    registers.SP += 2;
}

void CPU::CMP()
{
    auto value = fetch16();
    flags.Z = (registers.A == value);
}

void CPU::CMA()
{
    auto address = fetch16();
    auto value = bus.read16(address);
    flags.Z = (registers.A == value);
}

void CPU::CMS()
{
    auto value = bus.read16(registers.SP);
    registers.SP += 2;
    flags.Z = (registers.A == value);
}

void CPU::JMP()
{
    auto address = fetch16();
    registers.PC = address;
}

void CPU::JNZ()
{
    auto address = fetch16();
    if (registers.A != 0)
        registers.PC = address;
}

void CPU::JMZ()
{
    auto address = fetch16();
    if (registers.A == 0)
        registers.PC = address;
}

void CPU::CAL()
{
    auto address = fetch16();
    registers.SP -= 2;
    bus.write16(registers.SP, registers.PC);
    registers.PC = address;
}

void CPU::RET()
{
    auto address = bus.read16(registers.SP);
    registers.SP += 2;
    registers.PC = address;
}

void CPU::OUT()
{
    auto index = fetch8();
    printf("R%d -> %04X", index, registers.R[index]);
}

void CPU::HLT()
{
    status.running = false;
}

