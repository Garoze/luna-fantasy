#pragma once

#include <cstdint>

enum class Instructions : std::uint8_t
{
    NOP,
    LDI, LDA, LDS,
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
    JMP, RET,
    OUT,
    HLT
};

