#pragma once

#include <map>
#include <string>
#include <vector>

#include "Flags.hpp"
#include "Registers.hpp"
#include "Instructions/Mnemonics.hpp"
#include "Instructions/Instructions.hpp"

#include "../Bus/Bus.hpp"

class CPU
{
public:
    CPU();

    void run();
    void step();
    void reset();
public:
    void executeCycle();
    void loadFromFile(const std::string&);
    void loadToMemory(const std::vector<std::uint8_t>&);
    void debugMemory(std::uint16_t address, int offset = 20);
private:
    std::uint8_t  fetch8();
    std::uint16_t fetch16();
    Instructions decode(std::uint8_t opcode);
    void execute(Instructions inst);
private:
    void NOP();
    void LDI();
    void LDA();
    void LDS();
    void LDR();
    void STA();
    void STR();
    void STS();
    void ADD();
    void ADA();
    void ADS();
    void SUB();
    void SUA();
    void SUS();
    void MUL();
    void MUA();
    void MUS();
    void DIV();
    void DIA();
    void DIS();
    void MOD();
    void MOA();
    void MOS();
    void INC();
    void DEC();
    void SHL();
    void SHR();
    void AND();
    void BOR();
    void XOR();
    void NOT();
    void PSA();
    void PSI();
    void PSR();
    void POA();
    void POR();
    void CMP();
    void CMA();
    void CMS();
    void JMP();
    void JMZ();
    void JNZ();
    void CAL();
    void RET();
    void OUT();
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
