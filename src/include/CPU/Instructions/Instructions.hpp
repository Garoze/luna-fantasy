#pragma once

#include <map>
#include <string>
#include <cstdint>
#include <utility>

enum class Instructions : std::uint8_t
{
    NOP,
    LDI, LDA, LDS, LDR,
    STA, STS,
    ADD, ADA, ADS,
    SUB, SUA, SUS,
    MUL, MUA, MUS,
    DIV, DIA, DIS,
    MOD, MOA, MOS,
    INC, DEC,
    SHL, SHR, AND,
    BOR, XOR, NOT,
    PSH, POP,
    CMP, CMA, CMS,
    JMP, JMZ, JNZ,
    CAL, RET,
    OUT,
    HLT
};

